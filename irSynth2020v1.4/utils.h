void checkStates(){
  //if Midi mode, irL has 127 CC options, if OSC mode, irL has 8 options.
  switch(MODE){
    case 1: noOptsL = 9; break; //MIDI MODE
    case 2: noOptsL = 8; break; // OSC MODE
  }  
  switch(menu){
    case 1: noOptsR = 127; break; //Amplitude
    case 2: noOptsR = 3; break; //Octave
    case 3: noOptsR = 11; break; //No # Notes
    case 4: noOptsR = 8; break; //Channel
    case 5: noOptsR = 8; break; //FX Mode #
    case 6: noOptsR = 127; break; //IR CC#
    case 7: noOptsR = 2; break; //ArpType A/B/C
    case 8: noOptsR = 4; break; //ScaleType cSeq/Major/Minor/Chro **improve later
    case 9: noOptsR = 3; break; //Harmony None/3rd/5th/Oct
  } 
}

void encoderOptions() {
  // map and select menu options, use single click to confirm
  int val = map(positionLeft,-999,999,0,499);
  int valR = map(positionRight,-999,999,0,499); 
  vL = val;
  vR = valR;
  if(vL>vL_M){ 
     eOptL = eOptL+1;
     lcdFlag_A=true;
     if(eOptL > noOptsL)eOptL = noOptsL;
  }
  if(vL<vL_M){
    eOptL = eOptL-1;
    lcdFlag_A=true;
    if(eOptL <= 1)eOptL=1;
  }
  menu = eOptL;
  vL_M = val;
  
  if(vR>vR_M){
     eOptR = eOptR+1;
     lcdFlag_A=true;
     if(eOptR > noOptsR)eOptR = noOptsR;
  }
  if(vR<vR_M){
    eOptR = eOptR-1;
    lcdFlag_A=true;
    if(eOptR > noOptsR)eOptR = noOptsR;
    if(eOptR <= 1)eOptR=1;
  }
  vR_M = valR;
  //Serial.println(eOptL);
}

void readEncoders(){
  long newLeft, newRight;
  newLeft = knobLeft.read();
  newRight = knobRight.read();
  if (newLeft != positionLeft || newRight != positionRight) {
    positionLeft = newLeft;
    positionRight = newRight;
    encoderOptions();
  }
}



void checkIR() {
  irValL =  analogRead(irPinL);
  irValR =  analogRead(irPinR);
  irValL_M = irValL;
  irValR_M = irValR;
}
void checkPots(){
  for(int i=0 ; i < 8 ; i++){
     potVals[i]=map(analogRead(potPins[i]),0,1024,0,127);
  }
}
void checkSwitches(void) {
  readL = digitalRead(switchL);
  readR = digitalRead(switchR);
  togL = readL; 
  togR = readR;
}

void doubleclickA() {  
    //Serial.println("DOUBLE_A");  //Cannot send text to console
 }  
 void singleclickA() {  
  
 }

 void longclickA() {
  //Change Controller to MIDI / FX / OSC MODES  
    MODE = MODE +1;
    if(MODE > 3) MODE = 1;
    lcdFlag=true;
 }  
 void doubleclickB() {  
    //Serial.println("DOUBLE_B");  
 }  
 void singleclickB() {  
    switch (menu) {
      case 1: amp = eOptR; break;
      case 2: oct = eOptR; break;
      case 3: numNote = eOptR; break;
      case 4: chan = eOptR; break;
      case 5: fxMODE = eOptR; break;
      case 6: irMODE = eOptR; break;
      case 7: arp = eOptR; break;
      case 8: harm = eOptR; break;
      case 9: scal = eOptR; break;
   } 
   lcdFlag=true;  
 }  
 void longclickB() {  
    snapshot = eOptR ;
    lcdFlag=true;
 }  
