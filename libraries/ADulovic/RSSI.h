
unsigned long RSSI_timer;                 		// last time loop fired
MyMessage RSSI_msg(1,V_VAR5);

/**
   Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupRSSI () {}

/**
   Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopRSSI(uint16_t frequency) {
	if ( millis()/1000 >= (frequency + RSSI_timer) ) {
        // set timer to now
		RSSI_timer = millis()/1000;
		// prepare string to send
		String RSSIstr = "rssi:";
		RSSIstr += transportGetSendingRSSI();
		RSSIstr += " dBm";
		if (Printout==true) {Serial.println( RSSIstr ); }
		// convert the string to chars
		char RSSIchar[RSSIstr.length()+1];   // add one for the char terminator string
		RSSIstr.toCharArray(RSSIchar, RSSIstr.length()+1);
		// prepare and send the message
		RSSI_msg.set( RSSIchar );
		send(RSSI_msg);
	}
}