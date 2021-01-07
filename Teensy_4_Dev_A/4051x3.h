
void run4051setup () {
  for (int i=0; i<3; i++)
  {
    pinMode(x4051_Pins_A[i], OUTPUT);
    digitalWrite(x4051_Pins_A[i], HIGH);
  }
  pinMode(x4051_InputA, INPUT); // Set up Z as an input
  pinMode(x4051_InputB, INPUT); // Set up Z as an input
  pinMode(x4051_InputC, INPUT); // Set up Z as an input
  // Print the header:
  DPRINTLN("Y0\tY1\tY2\tY3\tY4\tY5\tY6\tY7");
  DPRINTLN("---\t---\t---\t---\t---\t---\t---\t---");
}
void selectMuxPin(byte pin, int b) {
  for (int i=0; i<3; i++)  {
    if (pin & (1<<i))
     switch(b){
      case 0: digitalWrite(x4051_Pins_A[i], HIGH);break;
      case 1: digitalWrite(x4051_Pins_B[i], HIGH);break;
      case 2: digitalWrite(x4051_Pins_C[i], HIGH);break;
     }
    else
      switch(b){
      case 0: digitalWrite(x4051_Pins_A[i], LOW);break;
      case 1: digitalWrite(x4051_Pins_B[i], LOW);break;
      case 2: digitalWrite(x4051_Pins_C[i], LOW);break;
     }
  }
 }

void read4051( int a){
  for (byte pin=0; pin<=7; pin++)  {
    selectMuxPin(pin,a); // Select one at a time
    int inputValue;
    switch(a){
      case 0:
        inputValue= analogRead(A1);
        muxA[pin] = inputValue;
        break; // and read Z
      case 1:
        inputValue= analogRead(A0);
        muxB[pin] = inputValue;
        break; // and read Z
      case 2:
        inputValue= analogRead(A2);
        muxC[pin] = inputValue;
        break; // and read Z
    }
    //DPRINT(String(inputValue) + "\t");
  }
  //Serial.print("MUX VALUE =");
  //Serial.print(muxC[7]);
  //DPRINTLN();
  //delay(200); //debug
}
