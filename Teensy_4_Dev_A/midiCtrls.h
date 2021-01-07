void sendMIDIctrl(int ctrl, int value, int chan) {
  //if(value > 127 || value < 0) return;
  M_CTRL(ctrl,value,chan);
  //DPRINTLN("sent");
}

void routeSwitches(){
  if( f_switch[0] != f_switchMEM[0] ) {
    M_CTRL(127,(f_switch[0]*127) ,1);
  } 
  f_switchMEM[0] = f_switch[0];
  
  if( f_switch[1] != f_switchMEM[1] ) {
    M_CTRL(127,(f_switch[1]*127) ,1);
  } 
  f_switchMEM[1] = f_switch[1];
}

void routeIR_L() {
  int mathCC_C = 63 - menu_B;
  sendMIDIctrl( mathCC_C , irUSE[0] , 1 );  
  /*
  DPRINT("sent - CC ");
  DPRINT(mathCC_C);
  DPRINT(" with value - ");
  DPRINT(irUSE[1]);
  DPRINTLN();
  */
}

void routeIR_R() {
 if(!irUSE[1]) {  // if the sensor is inactive
    M_OFF(last_IR, 0 , (menu_A + 1) );// turn all notes off
    }
 
 else { 
  M_ON(32 + (irUSE[1] / 2), 100 , (menu_A + 1) );
  last_IR = 32 + (irUSE[1] / 2); 
 } 
}
void routeMsg() {
  /*
  int mathCC = (64 + (menu_A*8));
  int mathCC_B = (96 + (menu_A*8));
  */
  int mathCC = (64);
  int mathCC_B = (96);
  
  for(int i = 0; i < 8 ; i++){
    if(f_muxA[i]){
      sendMIDIctrl( mathCC + i , muxVal_A[i] , 1 );
      f_muxA[i] = LOW;
      /*
      DPRINT("sent - CC ");
      DPRINT(mathCC + i);
      DPRINT(" with value - ");
      DPRINT(muxVal_A[i]);
      DPRINTLN();
      */
    }
    for(int j = 0; j < 8 ; j++){
    if(f_muxB[j]){
      sendMIDIctrl( mathCC_B + j , muxVal_B[j] , 1 );
      f_muxB[j] = LOW;
      /*
      DPRINT("sent - CC ");
      DPRINT(mathCC_B + j);
      DPRINT(" with value - ");
      DPRINT(muxVal_B[j]);
      DPRINTLN();
      */
    }
    }
  }
}
