void updateLCD() {
  //if (lcdFlag_A) return;
  if (lcdFlag) {
    lcd.setCursor(0, 0);
    switch (MODE) {
      case 1:      
        lcd.print("CC#");
        lcd.print(irMODE);
        lcd.print("    CH#");
        lcd.print(chan);
        break;
      case 2:     lcd.print("aNCS_PWSynthV1.0");    break;
      case 3:     lcd.print("aNCS FX Controls");    break;
    }

    lcd.setCursor(0, 1);
    switch (MODE) {
      //MIDI mode
      case 1:
        if(scal==1)lcd.print("cSeq");
        else if(scal==2)lcd.print("Maj");
        else if(scal==1)lcd.print("Min");
        else lcd.print("Chro");
        lcd.print(" FX=");
        if(fxMODE==1)lcd.print("CC#64-71");
        else if(fxMODE==2)lcd.print("CC#72-79");
        else if(fxMODE==3)lcd.print("CC#80-87");
        break;
      //OSC MODE
      case 2:
        lcd.print("IR =");
        lcd.print(eOptL);
        switch (irMODE) {
          case 1:   lcd.print("Speed");    break;
          case 2:   lcd.print("Detune");    break;
          case 3:   lcd.print("PitchL");    break;
          case 4:   lcd.print("PitchR");    break;
          case 5:   lcd.print("FX Ctrl");    break;
          case 6:   lcd.print("Wheel");    break;
          case 7:   lcd.print("Fine L");    break;
          case 8:   lcd.print("Fine R");    break;
        }
        lcd.print(" FX=");
        lcd.print(fxMODE);
        break;
      case 3:     lcd.print("aNCS FX Controls");    break;
    }

    lcd.setCursor(0, 2);
    switch (MODE) {
      //MIDI mode
      case 1: 
        lcd.print("Oct#");
        lcd.print(oct);
        if(harm == 1)lcd.print(" Solo");
        else if(harm == 2)lcd.print(" 3rd");
        else if(harm == 3)lcd.print(" 5th");
        lcd.print(" Arp#");
        lcd.print(arp);
        lcd.setCursor(0, 3);
        lcd.print(" No#Notes = ");
        lcd.print(numNote);
        
        break;
        
      case 2: //OSC synth Mode
        switch (fxMODE) {
          case 1:
            lcd.print("A   D   S   R   ");
            lcd.print("  vL vR vM Oct  ");
            break;
          case 2:
            lcd.print("lowX hiX Sym Phs");
            lcd.print("Key Cut  Vel Env");
            break;
          case 3:
            lcd.print("Res   Hi Med Low");
            lcd.print("Gli Fil Shpe Fil");
            break;
          case 4:
            lcd.print("WaveT P/W    X X");
            lcd.print("Harm   WaveT P/W");
            break;
        }
    }
  }
  lcdFlag = false;
}
void updateLCDrun() {
  //Flag A called? Left Rot
  if (lcdFlag_A) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.print("                ");
    lcd.print("                ");
    
    lcd.setCursor(0, 2); // edit 1st line
    //MIDI MODE
    if(MODE==1){
      switch(menu){
        case 1:        lcd.print("Volume = ");          break;
        case 2:        lcd.print("Octave = ");          break;
        case 3:        lcd.print("# Notes = ");          break;
        case 4:        lcd.print("Channel = ");          break;
        case 5:        lcd.print("FX MODE = ");          break;
        case 6:        lcd.print("IR_L CC# = ");          break;
        case 7:        lcd.print("Sequence = ");          break;
        case 8:        lcd.print("Harmony = ");          break;
        case 9:        lcd.print("Scale = ");          break;  
      }
      lcd.print(eOptR);
      lcd.print("?"); 
    }
  }
  lcdFlag_A = false;
  /*
  //Flag B called? Right Rot
  if (lcdFlag_B) {
    
  }
  lcdFlag_B = false;
  */
}
