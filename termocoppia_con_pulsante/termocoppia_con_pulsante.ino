#include "max6675.h"
#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11

int lastState= 0;
int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;
int ledPin = 8;
int ledPin1 = 9;
float leggitempo = 0;
float templim = 30;
int i = 0;
int now;
int buttonPin=10;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
int vccPin = 3;
int gndPin = 2;
unsigned long old_millis = 0;
unsigned long delta = 1000;
int minuti = 1;
DHT dht (DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  Serial.println("Millis(),Temp termocoppia,Temp DHT11");
  delay(500);
}

void loop()
{
int state= digitalRead(buttonPin);
   
      
   if (state==HIGH && state!=lastState)
   {
     if (i < 50)
  {
    
    unsigned long now = millis ();
    float t = dht.readTemperature();
      float h = dht.readHumidity();
     Serial.print(now);
      Serial.print(",");
      Serial.print(t);
      Serial.print(",");
      Serial.print(thermocouple.readCelsius());
      Serial.print(",");
      Serial.println(h);  int state= digitalRead(buttonPin);
      leggitempo = thermocouple.readCelsius();
      old_millis = now;
      minuti = minuti + 1;
      digitalWrite(ledPin, HIGH);
    i++;
    delay (200);
  }
   }
   lastState =state;
   digitalWrite(ledPin, LOW);
   delay(1);
 
 
 }

