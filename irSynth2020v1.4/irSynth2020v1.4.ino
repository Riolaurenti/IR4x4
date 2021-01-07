/*
   IR synth 2020 - Modular design
   This code is for the host MCU which now connects directly to USINE.
   2 Rotary Encoders, 8 Potentiometers, 2 latch switches, 2 IR sensors and and LCD.
   i2c and Pjon bus required
*/
#include "global.h"
#include "macros.h"
#include "timers.h"
#include "displays.h"
#include "utils.h"
#include "msgSend.h"

void setup() {
  Serial.begin(115200);
  pinMode(switchL, INPUT);
  pinMode(switchR, INPUT);
  digitalWrite(switchL, HIGH); //enable pullup resistors
  digitalWrite(switchR, HIGH);
  buttonA.attachDoubleClick(doubleclickA);
  buttonA.attachClick(singleclickA);
  buttonA.attachPress(longclickA);
  buttonB.attachDoubleClick(doubleclickB);
  buttonB.attachClick(singleclickB);
  buttonB.attachPress(longclickB);
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if (status) { // non zero status means it was unsuccesful
    status = -status; // convert negative status value to positive number
    hd44780::fatalError(status); // does not return
  }
  lcdFlag_A = false;
  lcdFlag_B = false;
  runSetupLCD();
}

void loop() {
  checkStates();
  readEncoders();
  updateLCD();
  updateLCDrun();
  sendValues();
  if (tCheck(&runTime_B)) {
    checkIR();
    //checkIR();
    checkPots();
    tRun(&runTime_B);
  }
  
  if (tCheck(&runTime_A)) {
    checkSwitches();
    tRun(&runTime_A);
  }
  
  buttonA.tick();
  buttonB.tick();
  
}
