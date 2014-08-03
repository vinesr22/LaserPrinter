#ifndef __DC_DRIVER_H__
#define __DC_DRIVER_H__

#include "Arduino.h"

class DC_Driver {
  /*  
    wraps dc_driver setup and update functions in a class

    !!! NOTE : user must call the dc_drivers update method from an
    interrupt function himself! i.e. user must attach an interrupt to the
    encoder pin A and call the encoder update method from within the 
    interrupt

    uses Arduino pullups on A & B channel outputs
    turning on the pullups saves having to hook up resistors 
    to the A & B channel outputs 

    // ------------------------------------------------------------------------------------------------
    // Example usage :
    // ------------------------------------------------------------------------------------------------
        #include "DC_Driver.h"

        DC_Driver dc_driver(2, 4);

        void setup() { 
            attachInterrupt(0, doEncoder, CHANGE); 
            Serial.begin (115200);
            Serial.println("start");
        } 

        void loop(){
            // do some stuff here - the joy of interrupts is that they take care of themselves
        }

        void doEncoder(){
            dc_driver.update();
            Serial.println( dc_driver.getPosition() );
        }    
    // ------------------------------------------------------------------------------------------------
    // Example usage end
    // ------------------------------------------------------------------------------------------------
  */
public:

    // constructor : sets pins as inputs and turns on pullup resistors

    DC_Driver( int8_t PinEncA, int8_t PinEncB, int8_t DcEnable, int8_t PinDcA, int8_t PinDcB) : pin_enc_a(PinEncA), pin_enc_b(PinEncB), pin_dc_enable(DcEnable), pin_dc_a( PinDcA ), pin_dc_b( PinDcB ) {

        // set dc_driver pins a and b to be input for position feedback
        pinMode(pin_enc_a, INPUT); 
        pinMode(pin_enc_b, INPUT);
		//set dc motor pins to output for control
		pinMode(pin_dc_enable, OUTPUT);
		pinMode(pin_dc_a, OUTPUT);
		pinMode(pin_dc_b, OUTPUT);
        // and turn on pullup resistors
        digitalWrite(pin_enc_a, HIGH);    
        digitalWrite(pin_enc_b, HIGH);
		//start with motor disabled
        digitalWrite(pin_dc_enable, LOW);

		//init vars
		counter = 0;
		dir = 0;
		error = 0;
    };

    // call this from your interrupt function

    void update_enc_A () {
        if (digitalRead(pin_enc_a)) digitalRead(pin_enc_b) ? position-- : position++;
        else digitalRead(pin_enc_b) ? position++ : position--;
		//might need to add modulus so it checks less often
		//disables motor once position is reached
		atPosition();
    };
    void update_enc_B () {
        if (digitalRead(pin_enc_b)) digitalRead(pin_enc_a) ? position++ : position--;
        else digitalRead(pin_enc_a) ? position-- : position++;
		//disables motor once position is reached
		//atPosition();
    };

	// returns current position
    long int getPosition () { return position; };

	// returns last known position error
    long int getPosError () { return position - gotoposition; };

    // set the position value
    void setPosition ( const long int p) { position = p; };

	// set the position for the motor to go to
	void gotoPosition( const long int p) { 
		gotoposition = p; 

		//set direction of motor travel
		if( gotoposition > position ){ goRight(); }
		else{ goLeft(); }
		//Now that direction has been set enable motor
		digitalWrite(pin_dc_enable, HIGH);
		offset = getOffset(position, gotoposition);
	};

private:

    long int position;
	long int gotoposition;
	long int error;
	long int offset;
    int8_t pin_enc_a;
    int8_t pin_enc_b;
	int8_t pin_dc_enable;
	int8_t pin_dc_a;
	int8_t pin_dc_b;
	long int counter;
	int8_t dir; //direction 0=na, 1=right, 2=left

	void goRight(){
		dir = 1;
		digitalWrite(pin_dc_a, LOW);
		digitalWrite(pin_dc_b, HIGH);
	}
	void goLeft(){
		dir = 2;
		digitalWrite(pin_dc_a, HIGH);
		digitalWrite(pin_dc_b, LOW);
	}
	long int getOffset(long int targetPos, long int currentPos){
		if((targetPos - currentPos > 1000)||(currentPos - targetPos > 1000)){
			offset = 990;
		}
		else{
			offset = 100;
		}
		return offset;
	}
	void atPosition() { 
		//dir == 0 case is not handled as nothing would be done anyway if it were checked
		if(dir == 1){
			//going right so continue till have passed position
			if(position>(gotoposition-offset)){
				//have passed position so disable motor
				digitalWrite(pin_dc_enable, LOW);
				//done moving
				dir = 0;
			}
		}
		else if(dir == 2){
			//going left so continue till have passed position
			if(position<(gotoposition+offset)){
				//have passed position so disable motor
				digitalWrite(pin_dc_enable, LOW);
				//done moving
				dir = 0;
			}
		}
	};
};

#endif // __DC_DRIVER_H__