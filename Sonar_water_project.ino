int trigPin = 9;
int echoPin= 8;
int led = 7;
int relay =10;
long duration;
int cm;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup()
{
  lcd.init();                  
  lcd.backlight();
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(led, OUTPUT); 
  pinMode(relay, OUTPUT); 
}

void loop()
{
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(4);
 digitalWrite(trigPin,LOW);
 pinMode(echoPin,INPUT);
 duration=pulseIn(echoPin,HIGH);
 cm=(duration/2)/29.1;
 delay(250);
 Serial.print(cm);
 Serial.print("cm");
 lcd.setCursor(2,1);
  
lcd.print(cm);
lcd.print("cm");
 
   if (cm<=5)
   {
 digitalWrite(led,HIGH);
 digitalWrite(relay,LOW);
 
 delay(1000);
}
   else 
   {
 digitalWrite(led,LOW);
  digitalWrite(relay,HIGH);
 
 delay(1000);
}

}
