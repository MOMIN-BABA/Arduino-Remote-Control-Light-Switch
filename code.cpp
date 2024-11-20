#include <IRremote.h>

int RelayPin = 6;

const int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
 // Set RelayPin as an output pin
 pinMode(RelayPin, OUTPUT);
 irrecv.enableIRIn();

 digitalWrite(RelayPin, LOW);

}

void loop() {
  if (irrecv.decode(&results)){
    switch(results.value){
      case 0xFF30CF: //Keypad button "1"
        digitalWrite(RelayPin, HIGH);
       
    }
    
    switch(results.value){
      case 0XFF6897: //Keypad button "0"
        digitalWrite(RelayPin, LOW);
    }
      irrecv.resume();  
  }
}