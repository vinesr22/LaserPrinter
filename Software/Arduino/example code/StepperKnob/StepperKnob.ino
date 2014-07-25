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
//INPUTS
int StepperStepPin = 9;  //Pin that outputs PWM channel that controls stepper motor stepping
int StepperDirectionPin = 13;  //Pin that controls direction of stepper motor
int StepperAwakePin = 12; //Pin that controls whether the Stepper is awake or asleep
//OUTPUTS
int PotPin = A0;                       //Pin potentiometer is connected to


//Program variables
boolean bln_StepperAwakeState = LOW;   //HIGH=Awake, LOW=Asleep
int num_PotVoltage = 0;                //Current analog potentiometer read value
int num_PrePotVoltage = 0;            //Previous potentiometer read value
int num_DeltaPotReadings = 0;          //Saves the delta value between readings
const int num_PotVoltageArySize = 4;    //Constant declaring size of array below
int ary_PotVoltages[num_PotVoltageArySize] = {0,0,0,0};  //Array holding analog pot read values initializing all elements to zero
int num_PotVoltageIndex = 0;  //Starting index of array
int num_AvgPotVoltage = 0; //Averaged pot voltage reading


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
  ary_PotVoltages[num_PotVoltageIndex] = analogRead(A0); // read the analog voltage on the pin A0
  num_PotVoltageIndex = (num_PotVoltageIndex + 1) % 4;
  num_AvgPotVoltage = (ary_PotVoltages[0] + ary_PotVoltages[1] + ary_PotVoltages[2] + ary_PotVoltages[3])>>2; //sum elements and shift by two (same as divide by 4)
  num_DeltaPotReadings = num_AvgPotVoltage - num_PrePotVoltage; //take the difference between this averaged reading and the previous reading
  
  num_PrePotVoltage = num_AvgPotVoltage; //save current value to previous value
  if(num_DeltaPotReadings > 0 ){ //if moving in positive direction set stepper direction in positive
    digitalWrite(StepperDirectionPin, HIGH);
  }
  else if(num_DeltaPotReadings < 0){ //else if moving in negative direction
    digitalWrite(StepperDirectionPin, LOW);
  }
  num_DeltaPotReadings = abs(num_DeltaPotReadings); //get absolute value of delta reading now that direction has been handled
  if(num_DeltaPotReadings > 1){ //If doing nothing delta can be +/-1 due to noise so set slightly higher than noise to look for rotation
    bln_StepperAwakeState = HIGH;  
    digitalWrite(StepperAwakePin,bln_StepperAwakeState); //wake up stepper since movement is occuring 
    delay(1); //wait for charge pump //1 ms seems to be too fast
    num_DeltaPotReadings *= 3;
    //Send pwm to stepper motor. Each pulse causes the stepper to take one step. In this case 7.5/16 degrees.
    for(int i=0;i<num_DeltaPotReadings;i++){
      digitalWrite(StepperStepPin, HIGH);   
      delayMicroseconds(40);               
      digitalWrite(StepperStepPin, LOW);  
      delayMicroseconds(40);
    }
  }
  else{
    delay(1); //wait before turning stepper to sleep. If too short then driver cuts power to motor before it can move.
    bln_StepperAwakeState = LOW;
    digitalWrite(StepperAwakePin,bln_StepperAwakeState);//put stepper motor driver to sleep
  }
  // print out the value you read:
//  Serial.println(num_AvgPotVoltage);
//  delay(1000);
}
