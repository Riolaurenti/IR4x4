typedef struct t  { // build timer structure
    unsigned long tStart; //unsigned long for safety
    unsigned long tTimeout;
};
t runTime_A = {0, 800}; //Run every 800ms
t runTime_B = {0, 10}; //Run every 10 milliseconds. // irStabilkity check!
t runTime_C = {0, 50000}; //Run every 5000ms
bool tCheck (struct t *t ) {
  if (millis() > t->tStart + t->tTimeout) return true;    
}
void tRun (struct t *t) {
    t->tStart = millis();
}
