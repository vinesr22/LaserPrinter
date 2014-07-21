//simple A4988 connection
//jumper reset and sleep together
//connect  VDD to Arduino 3.3v or 5v
//connect  GND to Arduino GND (GND near VDD)
//connect  1A and 1B to stepper coil 1
//connect 2A and 2B to stepper coil 2
//connect VMOT to power source (9v battery + term)
//connect GRD to power source (9v battery - term)

int analogPin = A0;   // potentiometer connected to analog pin 0
int stp = 9;  //connect pin 9 to step
int dir = 13;  // connect pin 13 to dir
int val = 0;         // variable to store the read value
int pre_val = 0;         // variable to store the read value
int inc = 0;         // amount to increment
int awakePin = 12;
int awake = 0;

void setup() 
{                
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(awakePin, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);  
}


void loop() 
{

  val = analogRead(A0);   // read the input pin
  inc = val - pre_val;
  pre_val = val;
  if(inc > 0 ){
    digitalWrite(dir, HIGH);
  }
  else if(inc < 0){
    digitalWrite(dir, LOW);
  }
  inc = abs(inc);
  if(inc > 3){
    digitalWrite(awakePin, HIGH);
    delay(10); //wait for charge pump //1 ms seems to be too fast

    for(int i=0;i<inc;i++){
    digitalWrite(stp, HIGH);   
    delay(0.2);               
    digitalWrite(stp, LOW);  
    delay(0.2);
    }
  }
  else{
    delay(10); //wait before turning stepper to sleep. If too short then driver cuts power to motor before it can move.
    digitalWrite(awakePin, LOW);//put stepper motor driver to sleep
  }
  // print out the value you read:
//  Serial.println(inc);
//  delay(1000);
}
