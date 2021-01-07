byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,150);
IPAddress outIp(192, 168, 1,4 ); //the destination IP
const unsigned int inPort = 8888;
const unsigned int outPort = 10000;

const int ledPin = 13;      // LED connected to digital pin 13
const int Sensor[4] = {A0,A1,A2,A3}; // the piezo is connected to analog pin 0
const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not

int sRead[4] = {0,0,0,0};      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

char rVal;
bool rFlag = false;
