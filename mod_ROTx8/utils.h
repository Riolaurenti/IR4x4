void displayVals () {
  for(int i = 0 ; i < 8 ; i ++) {
  /*
  DPRINT( states_menu[i]);
  DPRINT(" / ");
  DRPINTLN();
  //DPRINT( f_muxA[i]);
  //DPRINT(" / ");
  //DRPINTLN();
  //DPRINT( mux_map[i]);
  //DPRINT(" / ");
  //DRPINTLN();  
  */
  
  DPRINT( a_R[i]);
  DPRINT(" / ");
    
  //DPRINT( a_G[i]);
  //DPRINT(" / ");
  
  //DPRINT( a_B[i]);
  //DPRINT(" / ");
  
  }
  DPRINTLN();
}

void bit_bash(){
  for(int i=0;i<8;i++){
    bitWrite(c_R, i, a_R[i]);
    bitWrite(c_G, i, a_G[i]);
    bitWrite(c_B, i, a_B[i]);
  }
  //Serial.println(x, BIN);
}
void menu_LED() {
  for(int i=0;i<8; i++){
    if(states_menu[i] == 0){
      a_R[i] = 0;
      a_G[i] = 1;
      a_B[i] = 1;
    }
    if(states_menu[i] == 1){
      a_R[i] = 1;
      a_G[i] = 0;
      a_B[i] = 1;
    }
    if(states_menu[i] == 2){
      a_R[i] = 1;
      a_G[i] = 1;
      a_B[i] = 0;
    }
    if(states_menu[i] == 3){
      a_R[i] = 0;
      a_G[i] = 0;
      a_B[i] = 1;
    }
    if(states_menu[i] == 4){
      a_R[i] = 1;
      a_G[i] = 0;
      a_B[i] = 0;
    }
    if(states_menu[i] == 5){
      a_R[i] = 0;
      a_G[i] = 1;
      a_B[i] = 0;
    }
  }
  bit_bash();
}
