#include <ResponsiveAnalogRead.h>

//#define DEBUG   //Comment this line to disable Debug output
#define MIDI_IO // comment this to disable MIDI serial

#include "global.h"
#include "macros.h"
#include "midiCtrls.h"
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
  blinkAll_2Bytes(2, 500);
}

void loop() {
  if (sinceTest1 >= 600) {
    sinceTest1 = sinceTest1 - 200;
    // DPRINTLN("Test1 (0.6 sec)");
    LED_A();
    switchOptions();
    read595(); //see notes
  }
  if (sinceTest2 >= 200) {
    sinceTest2 = sinceTest2 - 50;
    read4051(0);
    read4051(1);
    read4051(2);
    mapStates();
    checkStates();
    routeMsg();
    //DPRINTLN("             Test2 (.2 sec)");
  }
  if (sinceTest3 >= 100) {
    sinceTest3 = sinceTest3 - 30;
    read_IR();
    //routeIR_R();
    // DPRINTLN("                            Test3 (1.3 sec)");
  }

  if (debugLoop >= 1500) {
    debugLoop = debugLoop - 1500;
    //displayVals();
  }
  // MIDI Controllers should discard incoming MIDI messages.
  while (usbMIDI.read()) {
  }
}
