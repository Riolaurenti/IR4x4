
int[] vals = {};
//int[] useVals;
//useVals = new int[16]; // allocate memory?

int testVal = 0;
int testVal_M = 0;
int Mode = 1, Mode_M = 0;

int irL, irR;
int irL_M, irR_M;
int irGateThresh = 220;
int irJitter = 30;
int sL, sR;
int sL_M, sR_M;
int pots[] = {0,0,0,0, 0,0,0,0};
int pots_M[] = {0,0,0,0, 0,0,0,0};
int potJitter = 3; 
boolean potFlag = false;
int pc_A, pc_M, pc_B;

int curPot = 0;
int lastPot = 0;
int curSnap = 1;
int curSnap_M = 1;
int irMode,fxMode;
int irMode_M,fxMode_M;
int arp,oct,harm,scal,chan,noNote,amp;
int arp_M,oct_M,harm_M,scal_M,chan_M,noNote_M,amp_M;
