#include "Encoder.h"

Encoder encoder(2, 3);

void setup() { 
    attachInterrupt(0, doEncoderA, CHANGE); 
    attachInterrupt(1, doEncoderB, CHANGE); 
    Serial.begin (9600);
    Serial.println("start");
} 

void loop(){
  delay(1000);
  Serial.println( encoder.getPosition() );
}

void doEncoderA(){
    encoder.updateA();
}
void doEncoderB(){
    encoder.updateB();
}
