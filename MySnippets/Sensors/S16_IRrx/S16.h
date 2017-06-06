/*
    InfraRed Receiver
    
    - should display data when exposed to the light of a remote controller.
    
    G - ground
    R - VCC 3.3-5
    Y - data
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS16(S16, V_IR_RECEIVE);
#include <IRremote.h>
IRrecv irrecv(pinS16);                  // create a receiver object
decode_results results;                 // decode the results 

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS16(){
    irrecv.enableIRIn();                // Start the receiver
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS16(){
    if (irrecv.decode(&results)){
        Serial.print("IR: "); Serial.println(results.value, HEX);
        send(msgS16.set(results.value));
        irrecv.resume();                // Receive the next value
    }
}

/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
    // nothing to receive


/*
void loop()
{
  if (irrecv.decode(&results))
  { 
    extractRaw(&results);
    
    // Displays the raw codes
    for (int i = 0; i < codeLen; i ++)
    {
      Serial.print(rawCodes[i]);
      Serial.print(", ");
    }
    Serial.println(); 
 
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
 
// Extracts the raw data
void extractRaw (decode_results *results) {
  codeLen = results->rawlen - 1;
  // To store raw codes:
  // Drop first value (gap)
  // Convert from ticks to microseconds
  // Tweak marks shorter, and spaces longer
  // to cancel out IR receiver distortion
  for (int i = 1; i <= codeLen; i++)
    if (i % 2)
      // Mark
      rawCodes[i - 1] = results->rawbuf[i]*USECPERTICK - MARK_EXCESS;
    else
      // Space
      rawCodes[i - 1] = results->rawbuf[i]*USECPERTICK + MARK_EXCESS;
}

If working correctly, it should now display something like this:
    1800, 400, 200, 400, 250, 350, 250,
    1800, 400, 200, 400, 250, 350, 250,
    1800, 400, 200, 400, 250, 350, 250,
*/
