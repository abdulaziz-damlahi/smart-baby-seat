#include <Servo.h> 
int servoPin = A0; 
int pushButton = A1;
int gazpin = A2; 
int gazpinout = A3;
Servo Servo1;
void setup() {
     Servo1.attach(servoPin);
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
    pinMode(gazpinout,OUTPUT);
  pinMode(gazpin,INPUT);
  gazpinout=LOW;
}
void loop() {
   int gazpin1,gazpinout1;
   gazpin1 = analogRead(gazpin);
     Serial.print("gaz");
     Serial.println(gazpin1);
   if(gazpin1>200){
   gazpinout=HIGH;
       Serial.print("gazpinout");
     Serial.println(gazpinout);
   }
   
  int buttonState = analogRead(pushButton);
  Serial.println(buttonState);
if(buttonState<200){
servo();
  }
  delay(100);  
}  

void servo(){
   Servo1.write(0); 
   delay(1000); 
   Servo1.write(160); 
   delay(1000);
   }


   
