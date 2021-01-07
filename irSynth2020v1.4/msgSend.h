void sendValues() {
    Serial.print(irValL); //[0]
    Serial.print("\t");
    Serial.print(irValR); //[1]
    Serial.print("\t");
    Serial.print(togL); //[2]
    Serial.print("\t");
    Serial.print(togR); // [3]
    Serial.print("\t"); 
    Serial.print(potVals[7]);    // [4] 
    Serial.print("\t");
    Serial.print(potVals[6]);    // [5] 
    Serial.print("\t");
    Serial.print(potVals[5]);    // [6] 
    Serial.print("\t");
    Serial.print(potVals[4]);    // [7] 
    Serial.print("\t");
    Serial.print(potVals[3]);    // [8] 
    Serial.print("\t");
    Serial.print(potVals[2]);    // [9] 
    Serial.print("\t");
    Serial.print(potVals[1]);    // [10] 
    Serial.print("\t");
    Serial.print(potVals[0]);    // [11] 
    Serial.print("\t");
    
    Serial.print(MODE); // [12]
    Serial.print("\t");
    Serial.print(irMODE); // [13]
    Serial.print("\t");
    Serial.print(fxMODE); // [14]
    Serial.print("\t");
    Serial.print(amp); // [15]
    Serial.print("\t");
    Serial.print(oct); // [16]
    Serial.print("\t");
    Serial.print(numNote); // [17]
    Serial.print("\t");
    Serial.print(chan); // [18]
    Serial.print("\t");
    Serial.print(arp); // [19]
    Serial.print("\t");
    Serial.print(harm); // [20]
    Serial.print("\t");
    Serial.print(scal); // [21]
    Serial.print("\t");
    
    Serial.println();  
}
