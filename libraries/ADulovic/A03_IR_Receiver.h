/*
    InfraRed Receiver

    minus to gnd
    S to pin (the data pin must be PWM)
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA3(A3, V_IR_SEND);
#include <IRremote.h>                   // the IR library
IRsend irsend;

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA3(){
    pinMode(pinA3, OUTPUT);
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopA3(){}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA3(const MyMessage &message){
	unsigned long sendCode = 0;
    if (message.type==V_IR_SEND) {
        Serial.print("Instruction Received: "); Serial.println( message.getString() );

		if ( strcmp(message.getString(), "brighter") == 0 ) 		{ sendCode = 0xFF3AC5; }
		else if ( strcmp(message.getString(), "darker") == 0 ) 		{ sendCode = 0xFFBA45; }
		else if ( strcmp(message.getString(), "play") == 0 )	 	{ sendCode = 0xFF827D; }
		else if ( strcmp(message.getString(), "power") == 0 ) 		{ sendCode = 0xFF02FD; }
		else if ( strcmp(message.getString(), "on") == 0 ) 			{ sendCode = 0xFF02FD; }
		else if ( strcmp(message.getString(), "off") == 0 ) 		{ sendCode = 0xFF02FD; }

		else if ( strcmp(message.getString(), "red") == 0 ) 		{ sendCode = 0xFF1AE5; }
		else if ( strcmp(message.getString(), "green") == 0 ) 		{ sendCode = 0xFF9A65; }
		else if ( strcmp(message.getString(), "blue") == 0 )	 	{ sendCode = 0xFFA25D; }
		else if ( strcmp(message.getString(), "white") == 0 ) 		{ sendCode = 0xFF22DD; }

		else if ( strcmp(message.getString(), "orange") == 0 ) 		{ sendCode = 0xFF2AD5; }
		else if ( strcmp(message.getString(), "lightgreen") == 0 ) 	{ sendCode = 0xFFAA55; }
		else if ( strcmp(message.getString(), "deepblue") == 0 ) 	{ sendCode = 0xFF926D; }
		else if ( strcmp(message.getString(), "milkwhite") == 0 ) 	{ sendCode = 0xFF12ED; }

		else if ( strcmp(message.getString(), "deepyellow") == 0 ) 	{ sendCode = 0xFF0AF5; }
		else if ( strcmp(message.getString(), "cyan") == 0 ) 		{ sendCode = 0xFF8A75; }
		else if ( strcmp(message.getString(), "bluepurple") == 0 ) 	{ sendCode = 0xFFB24D; }
		else if ( strcmp(message.getString(), "pinkwhite") == 0 ) 	{ sendCode = 0xFF32CD; }

		else if ( strcmp(message.getString(), "yellow") == 0 ) 		{ sendCode = 0xFF38C7; }
		else if ( strcmp(message.getString(), "lightblue") == 0 ) 	{ sendCode = 0xFFB847; }
		else if ( strcmp(message.getString(), "purple") == 0 ) 		{ sendCode = 0xFF7887; }
		else if ( strcmp(message.getString(), "greenwhite") == 0 ) 	{ sendCode = 0xFFF807; }

		else if ( strcmp(message.getString(), "lightyellow") == 0 ) { sendCode = 0xFF18E7; }
		else if ( strcmp(message.getString(), "skyblue") == 0 ) 	{ sendCode = 0xFF9867; }
		else if ( strcmp(message.getString(), "brown") == 0 ) 		{ sendCode = 0xFF58A7; }
		else if ( strcmp(message.getString(), "bluewhite") == 0 ) 	{ sendCode = 0xFFD827; }

		else if ( strcmp(message.getString(), "increasered") == 0 ) { sendCode = 0xFF28D7; }
		else if ( strcmp(message.getString(), "increasegreen") == 0){ sendCode = 0xFFA857; }
		else if ( strcmp(message.getString(), "increaseblue") == 0 ){ sendCode = 0xFF6897; }
		else if ( strcmp(message.getString(), "quicker") == 0 ) 	{ sendCode = 0xFFE817; }

		else if ( strcmp(message.getString(), "decreasered") == 0 )	{ sendCode = 0xFF08F7; }
		else if ( strcmp(message.getString(), "decreasegreen") == 0){ sendCode = 0xFF8877; }
		else if ( strcmp(message.getString(), "decreaseblue") == 0 ){ sendCode = 0xFF48B7; }
		else if ( strcmp(message.getString(), "slower") == 0 ) 		{ sendCode = 0xFFC837; }

		else if ( strcmp(message.getString(), "diy1") == 0 ) 		{ sendCode = 0xFF30CF; }
		else if ( strcmp(message.getString(), "diy2") == 0 ) 		{ sendCode = 0xFFB04F; }
		else if ( strcmp(message.getString(), "diy3") == 0 ) 		{ sendCode = 0xFF708F; }
		else if ( strcmp(message.getString(), "auto") == 0 ) 		{ sendCode = 0xFFF00F; }

		else if ( strcmp(message.getString(), "diy4") == 0 ) 		{ sendCode = 0xFF10EF; }
		else if ( strcmp(message.getString(), "diy5") == 0 ) 		{ sendCode = 0xFF906F; }
		else if ( strcmp(message.getString(), "diy6") == 0 ) 		{ sendCode = 0xFF50AF; }
		else if ( strcmp(message.getString(), "flash") == 0 ) 		{ sendCode = 0xFFD02F; }

		else if ( strcmp(message.getString(), "jump3") == 0 ) 		{ sendCode = 0xFF20DF; }
		else if ( strcmp(message.getString(), "jump7") == 0 ) 		{ sendCode = 0xFFA05F; }
		else if ( strcmp(message.getString(), "fade3") == 0 ) 		{ sendCode = 0xFF609F; }
		else if ( strcmp(message.getString(), "fade7") == 0 ) 		{ sendCode = 0xFFE01F; }

        Serial.print("Sending code: "); Serial.println( sendCode );
		irsend.sendNEC(sendCode,32);	// 32kHz carrier frequency for NEC
    }
}