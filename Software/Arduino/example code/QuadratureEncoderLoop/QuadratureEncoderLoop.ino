/* Read Quadrature Encoder
  * Connect Encoder to Pins encoderPinA, encoderPinB, and +5V.
  *
  * Sketch by max wolf / www.meso.net
  * v. 0.1 - very basic functions - mw 20061220
  *
  */
  
  
  //Code works but misses many pulses.


 int val; 
 int encoderPinA = 3;
 int encoderPinB = 4;
 int encoderPos = 0;
 int encoderPinALast = LOW;
 int n = LOW;

 void setup() { 
   pinMode (encoderPinA,INPUT);
   pinMode (encoderPinB,INPUT);
   Serial.begin (9600);
 } 

 void loop() { 
   n = digitalRead(encoderPinA);
   if ((encoderPinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoderPinB) == LOW) {
       encoderPos--;
     } else {
       encoderPos++;
     }
     Serial.print (encoderPos);
     Serial.print ("/");
   } 
   encoderPinALast = n;
 } 
