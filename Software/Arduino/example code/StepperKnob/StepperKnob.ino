//simple A4988 connection
//jumper reset and sleep together
//connect  VDD to Arduino 3.3v or 5v
//connect  GND to Arduino GND (GND near VDD)
//connect  1A and 1B to stepper coil 1
//connect 2A and 2B to stepper coil 2
//connect VMOT to power source (9v battery + term)
//connect GRD to power source (9v battery - term)

int analogPin = A0;   // potentiometer connected to analog pin 3
int stp = 9;  //connect pin 13 to step
int dir = 12;  // connect pin 12 to dir
int a = 0;     //  gen counter
int val = 0;         // variable to store the read value
int pre_val = 0;         // variable to store the read value
int inc = 0;         // amount to increment

void setup() 
{                
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);  
}


void loop() 
{
  val = analogRead(A0);   // read the input pin
  inc = val - pre_val;
  pre_val = val;
  if(inc > 3 ){
    dir = 1;
  }
  else if(inc < -3){
    dir = 0;
  }
  if((inc > 3) || (inc < -3)){
    digitalWrite(stp, HIGH);   
    delay(10);               
    digitalWrite(stp, LOW);  
    delay(10);
  }
  // print out the value you read:
  Serial.println(inc);
  delay(1000);
}
