void LED_A(){
  if(ledA == LOW) ledA = HIGH;
  else ledA = LOW;
  digitalWrite(ledApin,ledA);
  //DPRINT("led");
}

void displayVals () {
  for(int i = 0 ; i < 8 ; i ++) {
  DPRINT( muxA[i]);
  DPRINT(" / ");
  }
  DPRINTLN();
  for(int ib = 0 ; ib < 8 ; ib ++) {
  DPRINT( muxB[ib]);
  DPRINT(" / ");
  }
  DPRINTLN();
  for(int ic = 0 ; ic < 8 ; ic ++) {
  DPRINT( muxC[ic]);
  DPRINT(" / ");
  }
  DPRINTLN();
  DPRINTLN();
  DPRINTLN();
}
