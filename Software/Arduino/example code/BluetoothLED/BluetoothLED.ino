// This program shown how to control arduino from PC Via Bluetooth
// Code originally copied from
//http://www.instructables.com/id/Arduino-AND-Bluetooth-HC-05-Connecting-easily/step3/Arduino-Code/
// arduino>>bluetooth
// D11   >>>  Rx
// D10   >>>  Tx
// you will need arduino 1.0.1 or higher to run this sketch

#include <SoftwareSerial.h>// import the serial library

SoftwareSerial MySerial(5,6); // RX, TX
int ledpin=12; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer
int numLoops=0;

void setup() {
  // put your setup code here, to run once:
  MySerial.begin(9600);
  MySerial.println("Bluetooth On. Please press 1 or 0 to enable or disable the LED ..");
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (MySerial.available()){
BluetoothData=MySerial.read();
   if(BluetoothData=='1'){   // if number 1 pressed ....
   digitalWrite(ledpin,1);
   MySerial.println("LED ON");
   }
  if (BluetoothData=='0'){// if number 0 pressed ....
  digitalWrite(ledpin,0);
   MySerial.println("LED OFF");
  }
}
delay(100);
//delay(1000);// prepare for next data ...
//MySerial.print(numLoops, DEC);
//numLoops += 1;
}
