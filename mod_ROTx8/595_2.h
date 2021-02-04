void runSetup595(){
  pinMode(latchPin, OUTPUT);
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
  //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, 0); 
    shiftOut(dataPin, clockPin, dataGREEN); //move 'em out  
    shiftOut(dataPin, clockPin, dataRED); //move 'em out
    shiftOut(dataPin, clockPin, dataBLUE); //move 'em out
    digitalWrite(latchPin, 1); //return the latch pin high to signal chip that it 
    delay(300);
}
void debug(){
  dataRED = c_R; // [1] = all 0
  dataGREEN = 255;
  dataBLUE = 255;
  send595();
  delay(1000);
  dataRED = 255;
  dataGREEN = 0;
  dataBLUE = 255;
  send595();
  delay(1000);
  dataRED = 255;
  dataGREEN = 255;
  dataBLUE = 0;
  send595();
  delay(1000);
  
}
void read595() {
    dataRED = c_R;
    dataGREEN = c_G;
    dataBLUE = c_B;
    send595();
    }

void blinkAll_2Bytes(int n, int d) {
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, 0);
  shiftOut(dataPin, clockPin, 0);
  //shiftOut(dataPin, clockPin, 0);
  digitalWrite(latchPin, 1);
  delay(200);
  for (int x = 0; x < n; x++) {
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, 255);
    shiftOut(dataPin, clockPin, 255);
    //shiftOut(dataPin, clockPin, 255);
    digitalWrite(latchPin, 1);
    delay(d);
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, 0);
    shiftOut(dataPin, clockPin, 0);
    //shiftOut(dataPin, clockPin, 0);
    digitalWrite(latchPin, 1);
    delay(d);
  }
}
