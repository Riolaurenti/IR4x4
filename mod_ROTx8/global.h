#include <Wire.h>
#include "Adafruit_MCP23017.h"  // https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library

//595 settings
int latchPin = 3;
int clockPin = 4;
int dataPin = 2;
byte dataRED;
byte dataGREEN;
byte dataBLUE;
byte c_R, c_G, c_B;
int a_R[8], a_G[8], a_B[8];

//timers
unsigned long t_A = 0;  // store
unsigned long t_Aint = 300;  // store
bool t_Af = false;
//menus
int no_states = 5;
int states_menu[8] = {0,0,0,0,0,0,0,0};
//4051 settings
int muxVal_A[8];
int muxMem_A[8];  
int muxA[8];
bool f_muxA[8]; //runtime flags
//int mux_arr[8] = {muxA[3],muxA[0],muxA[1],muxA[2],muxA[5],muxA[7],muxA[6],muxA[4]};
int mux_map[8]; 
const int x4051_Pins_A[3] = {14, 15, 16}; // S0~2, S1~3, S2~4
const int x4051_InputA = A0; // Connect common (Z) to A0 (analog input)

Adafruit_MCP23017 mcp0;
int ROT_vals[8] = {0,0,0,0,0,0,0,0};
int ROT_mem1[8] = {0,0,0,0,0,0,0,0};
boolean change=false;        // goes true when a change in the encoder state is detected
int encSelect[2] = {101, 0}; // stores the last encoder used and direction {encNo, 1=CW or 2=CCW}
unsigned long currentTime; // may not need...
unsigned long loopTime;
const int encCount0 = 8;  // number of rotary encoders
const int encPins0[encCount0][8] = {
  {0,8},   // enc:0 AA GPA0,GPA1 - pins 21/22 on MCP23017
  {1,9},    // enc:1 BB GPA3,GPA4 - pins 24/25 on MCP23017
  {2,10},
  {3,11},
  {4,12},
  {5,13},
  {6,14},
  {7,15}, 
}; 
unsigned char encoders0[encCount0];
// read the rotary encoder on pins X and Y, output saved in encSelect[encNo, direct]
unsigned char readEnc(Adafruit_MCP23017 mcpX, const int *pin, unsigned char prev, int encNo) {
  unsigned char encA = mcpX.digitalRead(pin[0]);    // Read encoder pins
  unsigned char encB = mcpX.digitalRead(pin[1]);
  if((!encA) && (prev)) { 
    encSelect[0] = encNo;
    if(encB) {
      encSelect[1] = 1;  // clockwise
    }
    else {
      encSelect[1] = 2;  // counter-clockwise
    }
    change=true;
  }
  return encA;
}
// setup the encoders as inputs. 
unsigned char encPinsSetup(Adafruit_MCP23017 mcpX, const int *pin) {
  mcpX.pinMode(pin[0], INPUT);  // A
  mcpX.pullUp(pin[0], HIGH);    // turn on a 100K pullup internally
  mcpX.pinMode(pin[1], INPUT);  // B
  mcpX.pullUp(pin[1], HIGH); 
}
