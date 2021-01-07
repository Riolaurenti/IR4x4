#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <OSCBundle.h>
#include <OSCBoards.h>
#include "global.h"
#include "macros.h"
//#include "msg.h";
EthernetUDP Udp;

void setup() {
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  DBEGIN(9600);       // use the serial port
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
  DPRINTLN("Starting w5100");
  Ethernet.begin(mac,ip);
  Udp.begin(inPort);
  DPRINTLN(Ethernet.localIP());
}

void loop() {
 sense();
 getVal();
 useVal();
 
}
void getVal(){
  if(Serial.available() > 0) {
    rVal = Serial.read();
    rFlag = true;
  }
}
void useVal() {
  if(rFlag == true) {
    switch(rVal){
      case '1':      sendD5(1);      break;
      case '2':      sendD6(1);      break;
      case '3':      sendD7(1);      break;
      case '4':      sendD8(1);      break;
    }
    rFlag = false;
  }
}

void sendD1(int val) {
   OSCMessage msg("/D1");      
  msg.add((int32_t)(val)); 
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  //delay(50); // Delay between actions - Debugger
  DPRINTLN("D1 sent");
}

void sendD2(int val) {
    OSCMessage msg("/D2");      
  msg.add((int32_t)(val)); 
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  //delay(50); // Delay between actions - Debugger
  DPRINTLN("D2 sent");
}

void sendD3(int val) {
    OSCMessage msg("/D3");      
  msg.add((int32_t)(val)); 
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  //delay(50); // Delay between actions - Debugger
  DPRINTLN("D3 sent");
}

void sendD4(int val) {
  OSCMessage msg("/D4");      
  msg.add((int32_t)(val)); 
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  //delay(50); // Delay between actions - Debugger
  DPRINTLN("D4 sent");
}

void sendD5(int val) {
   OSCMessage msg("/D5");      
  msg.add((int32_t)(val)); 
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  //delay(50); // Delay between actions - Debugger
  DPRINTLN("D5 sent");
}

void sendD6(int val) {
    OSCMessage msg("/D6");      
  msg.add((int32_t)(val)); 
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  //delay(50); // Delay between actions - Debugger
  DPRINTLN("D6 sent");
}

void sendD7(int val) {
    OSCMessage msg("/D7");      
  msg.add((int32_t)(val)); 
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  //delay(50); // Delay between actions - Debugger
  DPRINTLN("D7 sent");
}

void sendD8(int val) {
  OSCMessage msg("/D8");      
  msg.add((int32_t)(val)); 
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  //delay(50); // Delay between actions - Debugger
  DPRINTLN("D8 sent");
}

void sense() {
  for(int i=0;i<4;i++) {
    sRead[i] = analogRead(Sensor[i]); // read + store
    if (sRead[i] >= threshold) {   // if greater than threshold:
      //ledState = !ledState;
      //digitalWrite(ledPin, ledState);
      DPRINTLN("Knock!" + i); // Debug
      switch(i){
        case 0: sendD1(1); break;
        case 1: sendD2(1); break;
        case 2: sendD3(1); break;
        case 3: sendD4(1); break;
      }
   }
  delay(100);  // delay to avoid overloading the serial port buffer (debug)
  }
}
