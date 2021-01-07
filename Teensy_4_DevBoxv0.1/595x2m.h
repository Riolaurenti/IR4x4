
void runSetup595(){
  pinMode(lPin, OUTPUT);
  menuLEDa[0] = 0x80; //10000000
  menuLEDa[1] = 0x40; //01000000
  menuLEDa[2] = 0x20; //00100000
  menuLEDa[3] = 0x10; //00010000
  menuLEDa[4] = 0x08; //00001000
  menuLEDa[5] = 0x04; //00000100
  menuLEDa[6] = 0x02; //00000010
  menuLEDa[7] = 0x01; //00000001

  menuLEDb[0] = 0x80; //10000000
  menuLEDb[1] = 0x40; //01000000
  menuLEDb[2] = 0x20; //00100000
  menuLEDb[3] = 0x10; //00010000
  menuLEDb[4] = 0x08; //00001000
  menuLEDb[5] = 0x04; //00000100
  menuLEDb[6] = 0x02; //00000010
  menuLEDb[7] = 0x01; //00000001
  /*
  menuLEDa[0] = 0x88; // 10001000 
  menuLEDa[1] = 0x8C; // 10001100
  menuLEDa[2] = 0x8E; // 10001110
  menuLEDa[3] = 0x8F; // 10001111
  menuLEDa[4] = 0xC8; // 11001000 
  menuLEDa[5] = 0xCC; // 11001100
  menuLEDa[6] = 0xCE; // 11001110
  menuLEDa[7] = 0xCF; // 11001111
  menuLEDa[8] = 0xE8; // 11101000 
  menuLEDa[9] = 0xEC; // 11101100
  menuLEDa[10] = 0xEE; // 11101110
  menuLEDa[11] = 0xEF; // 11101111
  menuLEDa[12] = 0xF8; // 11111000 
  menuLEDa[13] = 0xFC; // 11111100
  menuLEDa[14] = 0xFE; // 11111110
  menuLEDa[15] = 0xFF; // 11111111
  
  menuLEDb[0] = 0xFF; //11111111
  menuLEDb[1] = 0x7F; //01111111
  menuLEDb[2] = 0x3F; //00111111
  menuLEDb[3] = 0x1F; //00011111
  menuLEDb[4] = 0x0F; //00001111
  menuLEDb[5] = 0x07; //00000111
  menuLEDb[6] = 0x03; //00000011
  menuLEDb[7] = 0x01; //00000001
  menuLEDb[8] = 0x00; //00000000
  menuLEDb[9] = 0x07; //00000111
*/
}

void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);
  for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, 0);
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }
    digitalWrite(myDataPin, pinState);
    digitalWrite(myClockPin, 1);
    digitalWrite(myDataPin, 0);
  }
  digitalWrite(myClockPin, 0);
}
void send595() {
  //ground lPin and hold low for as long as you are transmitting
    digitalWrite(lPin, 0); 
    shiftOut(dPin, cPin, dataGREEN); //move 'em out  
    shiftOut(dPin, cPin, dataRED); //move 'em out
    digitalWrite(lPin, 1); //return the latch pin high to signal chip that it 
    // delay(300); // debug
}
void read595() { // replace J and loop with button read Global values
    menuM_A = menu_A;
    menuM_B = menu_B;
    dataRED = menuLEDa[menu_A];
    dataGREEN = menuLEDb[menu_B];
    if(menu_A != menuM_A || menu_B != menuM_B ) send595(); // if anything has changed, send new values
}
void blinkAll_2Bytes(int n, int d) {
  digitalWrite(lPin, 0);
  shiftOut(dPin, cPin, 0);
  shiftOut(dPin, cPin, 0);
  digitalWrite(lPin, 1);
  delay(200);
  for (int x = 0; x < n; x++) {
    digitalWrite(lPin, 0);
    shiftOut(dPin, cPin, 255);
    shiftOut(dPin, cPin, 255);
    digitalWrite(lPin, 1);
    delay(d);
    digitalWrite(lPin, 0);
    shiftOut(dPin, cPin, 0);
    shiftOut(dPin, cPin, 0);
    digitalWrite(lPin, 1);
    delay(d);
  }
}
