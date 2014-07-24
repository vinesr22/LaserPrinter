//Simple example for controlling a stepper motor with a A4988 driver and an atmega328 chip breadboarded.

//simple A4988 connection
//jumper reset and sleep together
//connect  VDD to Arduino 3.3v or 5v
//connect  GND to Arduino GND (GND near VDD)
//connect  1A and 1B to stepper coil 1
//connect 2A and 2B to stepper coil 2
//connect VMOT to power source (9v battery + term)
//connect GRD to power source (9v battery - term)


//Atmel pin layout-------------------------------------
//Digital Outputs
int StepperStepPin = 9;  //Pin that outputs PWM channel that controls stepper motor stepping
int StepperDirectionPin = 13;  //Pin that controls direction of stepper motor
int StepperAwakePin = 12; //Pin that controls whether the Stepper is awake or asleep

//Digital Inputs
//none yet

//Analog Outputs
//none yet

//Analog Inputs
int PotPin = A0;                       //Pin potentiometer is connected to

//Program variables
boolean bln_StepperAwakeState = LOW;   //HIGH=Awake, LOW=Asleep
int num_PotVoltage = 0;                // variable to store the read value
int num_pre_PotVoltage = 0;        // variable to store the read value
int num_DeltaPotReadings = 0;          // num_DeltaPotReadingsamount to num_DeltaPotReadings


void setup() 
{                
  pinMode(StepperStepPin, OUTPUT);
  pinMode(StepperDirectionPin, OUTPUT);
  pinMode(StepperAwakePin, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);  
}


void loop() 
{

  num_PotVoltage = analogRead(A0);   // read the analog voltage on the pin
  num_DeltaPotReadings = num_PotVoltage - num_pre_PotVoltage; //take the difference between this reading and the previous reading
  num_pre_PotVoltage = num_PotVoltage; //save current value to previous value
  if(num_DeltaPotReadings > 0 ){ //if moving in positive direction set stepper direction in positive
    digitalWrite(StepperDirectionPin, HIGH);
  }
  else if(num_DeltaPotReadings < 0){ //else if moving in negative direction
    digitalWrite(StepperDirectionPin, LOW);
  }
  num_DeltaPotReadings = abs(num_DeltaPotReadings); //get absolute value of delta reading now that direction has been handled
  if(num_DeltaPotReadings > 3){ //If doing nothing delta can be +/-1 or +/-2 so set slightly higher than noise to look for rotation
    bln_StepperAwakeState = HIGH;  
    digitalWrite(StepperAwakePin,bln_StepperAwakeState); //wake up stepper since movement is occuring 
    delay(10); //wait for charge pump //1 ms seems to be too fast

    //Send pwm to stepper motor. Each pulse causes the stepper to take one step. In this case 7.5/16 degrees.
    for(int i=0;i<num_DeltaPotReadings;i++){
      digitalWrite(StepperStepPin, HIGH);   
      delay(0.5);               
      digitalWrite(StepperStepPin, LOW);  
      delay(0.5);
    }
  }
  else{
    delay(10); //wait before turning stepper to sleep. If too short then driver cuts power to motor before it can move.
    bln_StepperAwakeState = LOW;
    digitalWrite(StepperAwakePin,bln_StepperAwakeState);//put stepper motor driver to sleep
  }
  // print out the value you read:
//  Serial.println(num_DeltaPotReadings);
//  delay(1000);
}
