import processing.serial.Serial;
import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress myRemoteLocation;


void setup() {
  noLoop();
  new Serial(this, "COM5", 115200).bufferUntil(ENTER);
  oscP5 = new OscP5(this, 12000);
  myRemoteLocation = new NetAddress("192.168.0.11", 10000);
}

void draw() {
  //println(vals[0]);
  s_IR();
  s_Switches();
  s_Pots();
  //sendPot();
  s_Options();
}

void serialEvent(final Serial s) {
  vals = int(splitTokens(s.readString()));
  redraw();
}
void s_IR() { //unfiltered
  irL = vals[0];
  irR = vals[1];     
  OscMessage myMessage = new OscMessage("/irL"); 
  myMessage.add(irL); 
  oscP5.send(myMessage, myRemoteLocation);
  OscMessage mzMessage = new OscMessage("/irR"); 
  mzMessage.add(irR); 
  oscP5.send(mzMessage, myRemoteLocation);  
  irL_M = irL;
  irR_M = irR;
} 

void s_Switches() {
  sL = vals[2]; 
  sR = vals[3];
  if (sL!=sL_M) {
    OscMessage myMessage = new OscMessage("/switchL"); 
    myMessage.add(sL); 
    oscP5.send(myMessage, myRemoteLocation);
  }
  if (sR!=sR_M) {
    OscMessage myMessage = new OscMessage("/switchR"); 
    myMessage.add(sR); 
    oscP5.send(myMessage, myRemoteLocation);
  }
  sL_M = sL;
  sR_M = sR;
}
void s_Pots() {
 for (int i = 0 ; i<8 ; i++) {
  int useMe = i+4;
  pots[i] = vals[useMe];
  if(pots[i] > pots_M[i] + potJitter || pots[i] < pots_M[i] - potJitter){
    String tempS = "/pot" + i;
    OscMessage myMessage = new OscMessage(tempS); 
    myMessage.add(pots[i]); 
    oscP5.send(myMessage, myRemoteLocation);
    pots_M[i] = pots[i];
    }
  }
}
/*
void sendPot() {
  if (!potFlag)return; //if no runtime
  //send message
  String tempS = "/pot" + curPot;
  OscMessage myMessage = new OscMessage(tempS); 
  myMessage.add(pots[curPot]); 
  oscP5.send(myMessage, myRemoteLocation);
  print(curPot);
  println("sent!");
  if (pots[curPot]!=lastPot)pc_A = pc_A+1; //add one to primary counter
  lastPot = pots[curPot];
  if (pc_A == pc_M)pc_B = pc_B+1; // if primary = memory, secondary ++
  else pc_B = 0; // else reset secondary
  pc_M = pc_A; // make the memory value
  if (pc_B >= 100) {
    potFlag=false;
    println("stopped!");  
  }
}
*/
void s_Options() {
  Mode = vals[12];
  if (Mode!=Mode_M) {
    OscMessage myMessage = new OscMessage("/Mode"); 
    myMessage.add(Mode); 
    oscP5.send(myMessage, myRemoteLocation);
  }
  Mode_M = Mode;

  irMode = vals[13];
  if (irMode!=irMode_M) {
    OscMessage meMessage = new OscMessage("/irMODE"); 
    meMessage.add(irMode); 
    oscP5.send(meMessage, myRemoteLocation);
  }
  irMode_M = irMode;

  fxMode = vals[14];
  if (fxMode!=fxMode_M) {
    OscMessage meMessage = new OscMessage("/fxMODE"); 
    meMessage.add(fxMode); 
    oscP5.send(meMessage, myRemoteLocation);
  }
  fxMode_M = fxMode;

  amp = vals[15];
  if (amp!=amp_M) {
    OscMessage meMessage = new OscMessage("/irVol"); 
    meMessage.add(amp); 
    oscP5.send(meMessage, myRemoteLocation);
  }
  amp_M = amp;

  oct = vals[16];
  if (oct!=oct_M) {
    OscMessage meMessage = new OscMessage("/irOct"); 
    meMessage.add(oct); 
    oscP5.send(meMessage, myRemoteLocation);
  }
  oct_M = oct;

  noNote = vals[17];
  if (noNote!=noNote_M) {
    OscMessage meMessage = new OscMessage("/irNotes"); 
    meMessage.add(noNote); 
    oscP5.send(meMessage, myRemoteLocation);
  }
  noNote_M = noNote;

  chan = vals[18];
  if (chan!=chan_M) {
    OscMessage meMessage = new OscMessage("/irChan"); 
    meMessage.add(chan); 
    oscP5.send(meMessage, myRemoteLocation);
  }
  chan_M = chan;

  arp = vals[19];
  if (arp!=arp_M) {
    OscMessage meMessage = new OscMessage("/irArp"); 
    meMessage.add(arp); 
    oscP5.send(meMessage, myRemoteLocation);
  }
  arp_M = arp;

  harm = vals[20];
  if (harm!=harm_M) {
    OscMessage meMessage = new OscMessage("/irHarmony"); 
    meMessage.add(harm); 
    oscP5.send(meMessage, myRemoteLocation);
  }
  harm_M = harm;

  scal = vals[21];
  if (scal!=scal_M) {
    OscMessage meMessage = new OscMessage("/irScale"); 
    meMessage.add(scal); 
    oscP5.send(meMessage, myRemoteLocation);
  }
  scal_M = scal;
}
/* incoming osc message are forwarded to the oscEvent method. */
void oscEvent(OscMessage theOscMessage) {
  /* print the address pattern and the typetag of the received OscMessage */
  print("### received an osc message.");
  print(" addrpattern: "+theOscMessage.addrPattern());
  println(" typetag: "+theOscMessage.typetag());
}
