#include "DC_Driver.h"

//Encoder A pin, B pin, DcEnable pin, DC A pin, B pin
DC_Driver dc_driver(2, 3, 10, 7, 8);
int f = 0;

void setup() { 
    attachInterrupt(0, UpdateEncoderPositionA, CHANGE); 
    attachInterrupt(1, UpdateEncoderPositionB, CHANGE); 
    dc_driver.setPosition(0);
    Serial.begin (9600);
    Serial.println("start");
} 

void loop(){
  delay(100);
  // send data only when you receive data:
  if (Serial.available()){
    f = Serial.parseInt();  
    if (f >= 0){
      //echo back
      //Serial.println(f);
      dc_driver.gotoPosition(f);
    } 
  }
  delay(900);
  Serial.println(dc_driver.getPosError());
}

void UpdateEncoderPositionA(){
    dc_driver.update_enc_A();
}
void UpdateEncoderPositionB(){
    dc_driver.update_enc_B();
}
