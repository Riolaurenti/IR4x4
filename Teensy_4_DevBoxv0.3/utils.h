void LED_A(){
  if(ledA == LOW) ledA = HIGH;
  else ledA = LOW;
  digitalWrite(ledApin,ledA);
  //DPRINT("led");
}

void mapStates () {
  for(int i=0 ; i < 8 ; i++){
     muxVal_A[i]=map(muxA[i],0,1024,0,127);
     muxVal_B[i]=map(muxB[i],0,1024,0,127);
     //muxVal_C[i]=map(muxC[i],0,1024,0,127);
  }
  muxVal_C[0]=map(muxC[5],0,1024,0,127);
  muxVal_C[1]=map(muxC[2],0,1024,0,127);
  muxVal_C[2]=map(muxC[3],0,1024,0,127);
}

void checkStates() {
  for(int i=0 ; i < 8 ; i++){ // set memory values
    if(muxVal_A[i] != muxMem_A[i]) f_muxA[i] = HIGH;
    if(muxVal_B[i] != muxMem_B[i]) f_muxB[i] = HIGH;
    //if(muxVal_C[i] != muxMem_C[i]) f_muxC[i] = HIGH;
  }
  if(muxVal_C[2] > 120) {
     f_latch_R = HIGH;
  }
  else f_latch_R = LOW;
   
 if(muxVal_C[1] > 70) {
     f_switch[1] = HIGH;
  }
  else f_switch[1] = LOW;
  routeSwitches();
  
  for(int i=0 ; i < 8 ; i++){ // set memory values
    muxMem_A[i] = muxVal_A[i];  
    muxMem_B[i] = muxVal_B[i];  
    muxMem_C[i] = muxVal_C[i];  
  }
  
}

void switchOptions(){
  if(muxC[4]> 900) { // Top Right Button
    menu_B = menu_B + 1 ; 
    if(menu_B > 7) menu_B = 0;
  }
  if(muxC[1] > 900) { // Bottom Right Button
    if(menu_A >= 7) menu_A = menu_A ;
    else menu_A = menu_A + 1 ; 
    }
  if(muxC[6] > 900)  { // Bottom Left Button
    if(menu_A <= 0) ;
    else menu_A = menu_A - 1 ; 
  }
  if(muxC[5]) ; // Bottom Left Switch
  if(muxC[2]) ; // Bottom Right Switch
}

void displayVals () {
  for(int i = 0 ; i < 8 ; i ++) {
  DPRINT( muxVal_A[i]);
  DPRINT(" / ");
  }
  DPRINTLN();
  for(int ib = 0 ; ib < 8 ; ib ++) {
  DPRINT( muxVal_B[ib]);
  DPRINT(" / ");
  }
  DPRINTLN();
  for(int ic = 0 ; ic < 8 ; ic ++) {
  DPRINT( muxVal_C[ic]);
  DPRINT(" / ");
  }
  DPRINTLN();
  DPRINTLN();
  DPRINTLN();
}
