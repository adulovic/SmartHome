/* Radio Quality Testing 
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage counterMsg(0, V_PERCENTAGE);          // Send value

// send constants and variables
int messageCounter = 0 ; 
const int messageCounterMax = 100 ;                     // maximum message counter value 
const unsigned counterUpdateDelay = 500 ;               // send every x ms and sleep in between

// receive constants and variables
boolean failStore[messageCounterMax] ;                  // moving average stores & pointers
int failStorePointer = 0 ;
boolean missedStore[messageCounterMax] ;
int missedStorePointer = 0 ;
int newMessage = 0 ;
int lastMessage = -1 ;
int missedMessageCounter = 0 ;                          // total number of messages in range (messageCounterMax)
int failMessageCounter = 0 ;                            // total number of messages in range (messageCounterMax)
uint8_t parent = 0 ;                                    // parent node-id 

/* Functions
=========1=========2=========3=========4=========5=========6=========7========*/
// calculate number of false values in array
int getCount(boolean countArray[], int size){
    int falseCount = 0 ;
    for (int i = 0 ; i < size ; i++){
        falseCount += countArray[i]?0:1 ;
    }
    return falseCount ;
}
