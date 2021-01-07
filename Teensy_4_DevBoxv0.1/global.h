const int ledApin = 29;
int ledA;

elapsedMillis sinceTest1;
elapsedMillis sinceTest2;
elapsedMillis sinceTest3;

//IR input
ResponsiveAnalogRead ir_L(A10, true);
ResponsiveAnalogRead ir_R(A11, true);

//595 settings
int menu_A, menu_B;
int menuM_A, menuM_B;
int lPin = 30;
int cPin = 28;
int dPin = 32;
byte dataRED;
byte dataGREEN;
byte dataArrayRED[8];
byte dataArrayGREEN[8];
byte menuLEDa[16];
byte menuLEDb[10];

//4051 settings
int muxA[8], muxB[8], muxC[8];
const int x4051_Pins_A[3] = {2, 3, 4}; // S0~2, S1~3, S2~4
const int x4051_Pins_B[3] = {5, 6, 7}; // S0~2, S1~3, S2~4
const int x4051_Pins_C[3] = {8, 9, 10}; // S0~2, S1~3, S2~4
//const int zOutput = 5; // unneeded? 
const int x4051_InputA = A1; // Connect common (Z) to A0 (analog input)
const int x4051_InputB = A0; // Connect common (Z) to A0 (analog input)
const int x4051_InputC = A2; // Connect common (Z) to A0 (analog input)
