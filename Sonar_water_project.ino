int trig = 9;
int echo = 8;
int led = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  pinMode(led, OUTPUT); 
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
   if (cm>=20)
   {
 digitalWrite(led,HIGH);
 
 delay(1000);
}

}
