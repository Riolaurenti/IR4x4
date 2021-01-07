void readIR(int a) {
  if (!a) {
    DPRINT(ir_L.getRawValue());
    DPRINT("\t");
    DPRINT(ir_L.getValue());
    // if the repsonsive value has change, print out 'changed'
    if (ir_L.hasChanged()) {
      DPRINT("\tchanged");
    }
  }
  else {
    DPRINT(ir_R.getRawValue());
    DPRINT("\t");
    DPRINT(ir_R.getValue());

    // if the repsonsive value has change, print out 'changed'
    if (ir_R.hasChanged()) {
      DPRINT("\tchanged");
    }
  }
}
