void read_IR(){
  //if the latch is off, do not update, keeping previous value
  if(!f_latch_L)  ir_L.update(); // update value
  if(!f_latch_R)  ir_R.update();
   //get the values
  irVals[0] = ir_L.getValue();
  irVals[1] = ir_R.getValue();
  
  if(ir_L.hasChanged()){
      irMAP[0] = map(irVals[0],150,725,0,127);
      irUSE[0] = irMAP[0];
      //clamp lower and higher floating values from mapped values to 0/1 
      if(irMAP[0] < 30) irUSE[0] = 0;
      if(irMAP[0] > 122) irUSE[0] = 127;
      // check values to prevent midi hangs
      if(irUSE[0] < 0) return; //safety
      if(irUSE[0] > 127) return; //safety
      routeIR_L();
    }

  if(ir_R.hasChanged()){
      irMAP[1] = map(irVals[1],150,725,0,127);
      irUSE[1] = irMAP[1];
      //clamp lower and higher floating values from mapped values to 0/1 
      if(irMAP[1] < 30) irUSE[1] = 0;
      if(irMAP[1] > 122) irUSE[1] = 127;
      // check values to prevent midi hangs
      if(irUSE[1] < 0) return; //safety
      if(irUSE[1] > 127) return; //safety
      routeIR_R();
      
    }
    /*
    DPRINT("  IR - L =   ");
    DPRINTLN(irUSE[0]);
    DPRINT("  IR - R =   ");
    DPRINTLN(irUSE[1]);
    DPRINTLN();DPRINTLN();
    */
  }
 
