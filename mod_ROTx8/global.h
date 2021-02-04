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
