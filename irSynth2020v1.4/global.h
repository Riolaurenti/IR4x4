//Rotary + Menu Setup
#include <Encoder.h>
Encoder knobLeft(2, 3);
Encoder knobRight(18, 19);
long positionLeft  = -999;
long positionRight = -999;
volatile int eOptL = 1;
int noOptsL = 9,eOptL_M;
volatile int eOptR = 1;
int noOptsR = 127,eOptR_M;
int vL = 0, vR = 0; //encoder value mapping
int vL_M = 0, vR_M = 0; // encoder memory
//pin settings
int irPinL = A0, irPinR = A3;
int switchL = 26 , switchR = 27;
int potPins[] = {A8,A9,A15,A11,A12,A13,A14,A7};
//global
int menu = 1;
int irValL_M = 0 , irValR_M = 0;
int potVals_M[] = {0,0,0,0, 0,0,0,0};
int snapshot = 1;
int readL = 0,readR = 0;
int potFlag = 0;
// LCD Flags
bool lcdFlag = false;
bool lcdFlag_A = false;
bool lcdFlag_B = false;
//Serial send
int irValL = 0 , irValR = 0; // [0] [1]
bool togL, togR; // [2] [3]
int potVals[] = {0,0,0,0, 0,0,0,0}; // [4] - [11]
int MODE = 1; // Controller mode send [12]
int irMODE = 1; // MIDI used to send CC number [13]
int fxMODE = 1; // MIDI - used to send pot page number [14]
int amp = 96; // volume [15]
int oct = 3; //Octave [16]
int numNote = 7; //No # Notes [17]
int chan = 1; //channel [18]
int arp = 1; // arptype [19]
int harm = 1; //harmony [20]
int scal = 1; //scale type [21]


#include <OneButton.h>
OneButton buttonA(A5,true);
OneButton buttonB(A6,true); 
//
#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header
hd44780_I2Cexp lcd; // declare lcd object: auto locate & auto config expander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 4;
void runSetupLCD() {
 lcd.lineWrap();
 lcd.noCursor();
 lcd.clear(); 
 lcd.print("  IR Synth v1.0  ");
 delay(2000);
 lcd.clear();
 lcdFlag=true;

}
