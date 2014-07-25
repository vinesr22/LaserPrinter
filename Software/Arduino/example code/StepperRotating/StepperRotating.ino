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


void setup() 
{                
  pinMode(StepperStepPin, OUTPUT);
  pinMode(StepperDirectionPin, OUTPUT);
  pinMode(StepperAwakePin, OUTPUT);
  digitalWrite(StepperAwakePin,HIGH); //wake up stepper since movement is occuring 
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);  
}


void loop() 
{
    digitalWrite(StepperStepPin, HIGH);   
    delayMicroseconds(40);
    //delay(1);               
    digitalWrite(StepperStepPin, LOW);  
    delayMicroseconds(40);
    //delay(1);

  // print out the value you read:
//  Serial.println(num_DeltaPotReadings);
//  delay(1000);
}
