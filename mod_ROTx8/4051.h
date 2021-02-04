
void run4051setup () {
  for (int i = 0; i < 3; i++)
  {
    pinMode(x4051_Pins_A[i], OUTPUT);
    digitalWrite(x4051_Pins_A[i], HIGH);
  }
  pinMode(x4051_InputA, INPUT); // Set up Z as an input
  // Print the header:
  DPRINTLN("Y0\tY1\tY2\tY3\tY4\tY5\tY6\tY7");
  DPRINTLN("---\t---\t---\t---\t---\t---\t---\t---");
}
void selectMuxPin(byte pin) {
  for (int i = 0; i < 3; i++)  {
    if (pin & (1 << i))
      digitalWrite(x4051_Pins_A[i], HIGH);
    else
      digitalWrite(x4051_Pins_A[i], LOW);
  }
}
void menu_states() { // run every n seconds seperate to update global states_menu
  for (int i = 0 ; i < 8 ; i++) {
    if (states_menu[i] > no_states) states_menu[i] = 0;
      if (f_muxA[i] == HIGH) {
        states_menu[i] += 1;
        f_muxA[i] = LOW;
      }
        //states_menu[i] = states_menu[i] + 1;
      if (states_menu[i] > no_states) states_menu[i] = 0;  
      }
  }

void map_4051() {
  for (int i = 0; i < 8; i++) {
    mux_map[i] = map(muxA[i], 0, 1023, 0, 127);
    if (mux_map[i] == 127 ) f_muxA[i] = HIGH;
    //else f_muxA[i] = LOW;
    //DPRINT(mux_map[i]);
   // DPRINT(" /t ");

  }
  //DPRINTLN();
  //menu_states();
}
void read4051() {
  for (byte pin = 0; pin <= 7; pin++)  {
    selectMuxPin(pin); // Select one at a time
    int inputValue = analogRead(A0);
    //DPRINT(String(inputValue) + "\t");
    muxA[pin] = inputValue;
  }
   //DPRINTLN();
  map_4051();
}
