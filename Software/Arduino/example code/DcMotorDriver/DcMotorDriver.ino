//Basic setup for controlling a DC motor driver

//set pin locations for controlling motor
int DcMotorEnablePin = 10;
int DcMotor1Pin = 7;
int DcMotor2Pin = 8;

void setup(){
  delay(1000);
  pinMode(DcMotorEnablePin,OUTPUT);
  pinMode(DcMotor1Pin,OUTPUT);
  pinMode(DcMotor2Pin,OUTPUT);
  //start with motor enabled..not really needed
  digitalWrite(DcMotorEnablePin,HIGH);
}

void loop(){
  
  //drive motor one direction
  digitalWrite(DcMotor1Pin,HIGH);  
  digitalWrite(DcMotor2Pin,LOW);
  delay(150);
  //stop motor
  digitalWrite(DcMotorEnablePin,LOW);
  delay(1000);
  //enable motor
  digitalWrite(DcMotorEnablePin,HIGH);
  //drive motor other direction
  digitalWrite(DcMotor1Pin,LOW);  
  digitalWrite(DcMotor2Pin,HIGH);
  delay(150);  
  //disable motor
  digitalWrite(DcMotorEnablePin,LOW);
  delay(1000);
  //enable motor
  digitalWrite(DcMotorEnablePin,HIGH);  
  
}
