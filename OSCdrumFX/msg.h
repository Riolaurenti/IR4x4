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
