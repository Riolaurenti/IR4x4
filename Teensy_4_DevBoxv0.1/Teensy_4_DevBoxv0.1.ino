#include <ResponsiveAnalogRead.h>
#include "global.h" 
#include "macros.h"
//#include "timers.h" 
#include "utils.h" 
#include "4051x3.h"
#include "595x2m.h"
#include "ir.h"


void setup() {
  DBEGIN(9600);
  DPRINT("Setup");
  pinMode(ledApin, OUTPUT);
  runSetup595();
  run4051setup();
  blinkAll_2Bytes(2,500); 
}

void loop() {
 // ir_L.update();
 // readIR(0);
 // ir_R.update();
 // readIR(1);
 // read595(); //see notes
if (sinceTest1 >= 1000) {
    sinceTest1 = sinceTest1 - 1000;
   // DPRINTLN("Test1 (1 sec)");
    LED_A();
  }
  if (sinceTest2 >= 200) {
    sinceTest2 = sinceTest2 - 200;
    read4051(0);
    read4051(1);
    read4051(2);
    //DPRINTLN("             Test2 (.2 sec)");
    
  }
  if (sinceTest3 >= 1300) {
    sinceTest3 = sinceTest3 - 1300;
    displayVals();
   // DPRINTLN("                            Test3 (1.3 sec)");
  }
  
}
