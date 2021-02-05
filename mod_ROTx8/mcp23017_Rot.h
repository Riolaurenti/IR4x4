void setup_mcp() {
  //TWBR = 12; // only for MEGA if needed to increade I2c bus speed to 400khz. (mcp23017 can use 1.7mhz, wasted on basic AT chipsets)
  mcp0.begin();    // 0 = i2c address 0x20
  // setup the pins using loops, saves coding when you have a lot of encoders and buttons
  for (int n = 0; n < encCount0; n++) {
    encPinsSetup(mcp0, encPins0[n]);
    encoders0[n] = 1;  // default state
  }
  currentTime = millis();
  loopTime = currentTime;
}

void update_mcp() {
  currentTime = millis();
  if (currentTime >= (loopTime + 5)) {
    for (int n = 0; n < encCount0; n++) {
      encoders0[n] = readEnc(mcp0, encPins0[n], encoders0[n], n);
    }
    loopTime = currentTime;  // Updates loopTime
  }
  // when an encoder has been rotated
  if (change == true) {
    if (encSelect[0] < 100) {
      /*
        DPRINT("Enc: ");
        DPRINT(encSelect[0]);
        DPRINT(" " );
      */
      switch (encSelect[1]) {
        case (1): // clockwise
          ROT_vals[encSelect[0]] += 1;
          if (ROT_vals[encSelect[0]] >= 127) ROT_vals[encSelect[0]] = 0;
          break;
        case (2): // counter-clockwise
          ROT_vals[encSelect[0]] -= 1;
          if (ROT_vals[encSelect[0]] <= 0) ROT_vals[encSelect[0]] = 100; // set as option - wrap or clamp
          break;
      }
      //DPRINTLN(ROT_vals[encSelect[0]]);
      debug_rot();

      // do something when a particular encoder has been rotated.
      if (encSelect[0] == 1) {
        DPRINTLN("Encoder One has been used");
      }

      // set the selection to 101 now we have finished doing things. Not 0 as there is an encoder 0.
      encSelect[0] = 101;
    }
    // ready for the next change
    change = false;
  }
}
