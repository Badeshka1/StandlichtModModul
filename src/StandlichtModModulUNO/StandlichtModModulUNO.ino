const int relayPinLinks = 8;
const int relayPinRechts = 7;
String IncomingString;


#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); //Rx, Tx


void setup() {
  // put your setup code here, to run once:

pinMode(relayPinLinks, OUTPUT);
pinMode(relayPinRechts, OUTPUT);                                                                                                                 
digitalWrite(relayPinLinks, LOW);
digitalWrite(relayPinRechts, LOW);

Serial.begin(9600);
mySerial.begin(9600);
delay(5000);



}


void loop() {
  // put your main code here, to run repeatedly:


boolean StringReady;

while(mySerial.available()){
  IncomingString=mySerial.readString();
  StringReady = true;
  }

  if(StringReady && IncomingString != '\0'){
    Serial.println("Recieved String: " + IncomingString);
    
    }


 while(IncomingString == "Police"){  
      
    digitalWrite(relayPinLinks,LOW);
    delay(90);
    digitalWrite(relayPinLinks, HIGH);
    delay(50);
    digitalWrite(relayPinLinks,LOW);
    delay(90);
    digitalWrite(relayPinLinks, HIGH);
    delay(50);
    digitalWrite(relayPinLinks,LOW);
    delay(90);
    digitalWrite(relayPinLinks, HIGH);
    delay(50);
    digitalWrite(relayPinLinks,LOW);
    delay(90);
    digitalWrite(relayPinLinks, HIGH);
    delay(20);

    
    digitalWrite(relayPinRechts,LOW);
    delay(90);
    digitalWrite(relayPinRechts, HIGH);
    delay(50);
    digitalWrite(relayPinRechts,LOW);
    delay(90);
    digitalWrite(relayPinRechts, HIGH);
    delay(50);
    digitalWrite(relayPinRechts,LOW);
    delay(90);
    digitalWrite(relayPinRechts, HIGH);
    delay(50);
    digitalWrite(relayPinRechts,LOW);
    delay(90);
    digitalWrite(relayPinRechts, HIGH);

    if(mySerial.available()){
      
        IncomingString = mySerial.readString();
        
    } 
 } 

 while(IncomingString == "Normal"){
  digitalWrite(relayPinLinks, LOW);
  digitalWrite(relayPinRechts, LOW);

  if(mySerial.available()){
      
        IncomingString = mySerial.readString();
        
    }
  
  }

  while(IncomingString == "BlinkerSpam"){

    digitalWrite(relayPinLinks,LOW);
    delay(230);
    digitalWrite(relayPinLinks, HIGH);
    delay(20);
     
    digitalWrite(relayPinRechts,LOW);
    delay(230);
    digitalWrite(relayPinRechts, HIGH);
    delay(20);
    if(mySerial.available()){
      
        IncomingString = mySerial.readString();
    }
  }
} 
