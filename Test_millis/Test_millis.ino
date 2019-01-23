


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 4; // Analog output pin that the LED is attached to
unsigned long T;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  T=millis();
  sensorValue = analogRead(analogInPin);
   outputValue = map(sensorValue, 0, 1023, 0, 255);
   analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor:
  Serial.print("T = ");
  Serial.println(T);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(100);
}
