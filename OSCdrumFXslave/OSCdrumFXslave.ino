#include <SPI.h>
#include "global.h"
#include "macros.h"

void setup() {
  DBEGIN(9600);       // use the serial port

}

void loop() {
 sense();
}

void sense() {
  for(int i=0;i<4;i++) {
    sRead[i] = analogRead(Sensor[i]); // read + store
    if (sRead[i] >= threshold) {   // if greater than threshold:
      //ledState = !ledState;
      //digitalWrite(ledPin, ledState);
      DPRINTLN("Knock!" + i); // Debug
      switch(i){
        case 0: Serial.write('1'); break;
        case 1: Serial.write('2'); break;
        case 2: Serial.write('3'); break;
        case 3: Serial.write('4'); break;
      }
   }
  delay(100);  // delay to avoid overloading the serial port buffer (debug)
  }
}
