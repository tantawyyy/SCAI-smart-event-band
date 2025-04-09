#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int bt1=2,bt2=3,bt3=4,bt4=5,bt5=6,bt6=9,bt7=A3,bt8=A0,bt9=A1,bt10=A2;
//bt7=10 has issues
#define CE_PIN 7
#define CSN_PIN 8
int number=0;
RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";  // Must match the receiver

void setup() {
    Serial.begin(9600);
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_LOW);
    radio.stopListening(); // Set as Transmitter
    pinMode(bt1,INPUT);
    pinMode(bt2,INPUT);
    pinMode(bt3,INPUT);
    pinMode(bt4,INPUT);
    pinMode(bt5,INPUT);
        pinMode(bt6,INPUT);
    pinMode(bt7,INPUT);
    pinMode(bt8,INPUT);
    pinMode(bt9,INPUT);
    pinMode(bt10,INPUT);
}

void loop() {
    //int number = random(0, 100); // Generate a random number between 0 and 99
   
    if(digitalRead(bt1)==1){
      number=1;
    }
    else if(digitalRead(bt2)==1){
      number=2;
    }
else if(digitalRead(bt3)==1){
      number=3;
    }
    else if(digitalRead(bt4)==1){
      number=4;
    }
    else if(digitalRead(bt5)==1){
      number=5;
    }
    else if(digitalRead(bt6)==1){
      number=6;
    }
    else if(digitalRead(bt7)==1){
      number=7;
    }
    else if(digitalRead(bt8)==1){
      number=8;
    }
    else if(digitalRead(bt9)==1){
      number=9;
    }
    else if(digitalRead(bt10)==1){
      number=10;
    }
    else {
      number=0;
    }



    
    radio.write(&number, sizeof(number)); // Send the integer
    Serial.print("Sent: ");
    Serial.println(number);
    delay(10);
}
