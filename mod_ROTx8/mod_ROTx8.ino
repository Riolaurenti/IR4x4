#define DEBUG   //Comment this line to disable Debug output
#define D_A   10000 // goes in global
#include "global.h"
#include "macros.h"
#include "utils.h"
#include "595_2.h"
#include "4051.h"
#include "mcp23017_Rot.h"


void setup() {
  DBEGIN(9600);
  DPRINTLN("setup...");
  setup_mcp();
  run4051setup();
  runSetup595();
  blinkAll_2Bytes(3,500);
  DPRINTLN("setup complete");
}

void loop() {

  
  update_mcp(); // stable alone only? try timers...
  
  unsigned long cur_A = millis();
  read4051();
  read595(); // send to LEDs
 
  if (cur_A - t_A >= t_Aint) {
    t_A = cur_A; // reset timer...
    //displayVals(); // debug
    menu_states(); // mux >> menu states ---- edit to store and recall on MENU change!
      //if(MENU == 0 / switch(MENU){
      menu_LED(); // prepare LED
  } 
   
}
