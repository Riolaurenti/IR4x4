// Varidaic Debug Macro
 
#ifdef DEBUG    // Debug is on
#define DBEGIN(...)    Serial.begin(__VA_ARGS__)
#define DPRINT(...)    Serial.print(__VA_ARGS__)     //Sends our arguments to DPRINT()
#define DPRINTLN(...)  Serial.println(__VA_ARGS__)   //Sends our arguments to DPRINTLN()
#define DFLUSH(...)    Serial.flush()

#else // Debug is off
#define DBEGIN(...)
#define DPRINT(...)     //Nothing Happens
#define DPRINTLN(...)   //Nothing Happens
#define DFLUSH(...)

#endif // end macro

#ifdef MIDI_IO    // MIDI Debug is on

#define M_CTRL(...)    usbMIDI.sendControlChange(__VA_ARGS__)
#define M_SEND(...)    usbMIDI.send_now()
#define M_ON(...)      usbMIDI.sendNoteOn(__VA_ARGS__)  
#define M_OFF(...)      usbMIDI.sendNoteOn(__VA_ARGS__)  
#define M_PRG(...)      usbMIDI.sendProgramChange(__VA_ARGS__);

#else // MIDI Debug is off
#define M_CTRL(...)
#define M_SEND(...)     //Nothing Happens
#define M_ON(...)   //Nothing Happens
#define M_OFF(...)   //Nothing Happens
#define M_PRG(...)   //Nothing Happens

#endif // end macro
