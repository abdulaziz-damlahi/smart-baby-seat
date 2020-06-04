
#define heartratePin A0
#define gazPin 2
#include "DFRobot_Heartrate.h"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

// Declare the Servo pin  
DFRobot_Heartrate heartrate(DIGITAL_MODE);
SimpleTimer timer,timer1;
char auth[] = "xvZfxKzPTDIDwZrwmoetUBxvX8Kzt4VP";                                           
char ssid[] = "TurkTelekom_TCDB0";    
char pass[] = "AVA14789632"; 
void setup() {
  Wire.begin(D2, D1);
lcd.begin();
lcd.home();
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(20, sendUptime);
  timer1.setInterval(20, gazv);
}

void sendUptime()
{

  uint8_t rateValue;
  heartrate.getValue(heartratePin); 
  rateValue = heartrate.getRate(); 
  if(rateValue)  {
    Serial.println(rateValue);
    Blynk.virtualWrite(V0,rateValue);
    lcd.setCursor(0,0);
    lcd.print("BPM->");
    lcd.setCursor(5,0);
     lcd.print(rateValue);
  }
  }
  
 
  
void loop() {  
  Blynk.run();
  timer.run();
  timer1.run();
}
