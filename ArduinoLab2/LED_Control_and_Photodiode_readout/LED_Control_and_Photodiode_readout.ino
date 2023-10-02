//Include Wire Communication Library
#include <Wire.h>

//Declare Pin Numbers
const int LED_RED = 4;
const int LED_IR = 8;

const int detectorPin = A0;

void setup() {
  Serial.begin(9600); //Start Serial Communication with 9600 Baud Rate
  analogReference(INTERNAL); //Sets Reference to 1.1V
  
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_IR, OUTPUT);
  pinMode(detectorPin, INPUT); //Sets detectorPin as an input pin
}

void loop() {
  
  int redVal = readRed()

  delay(20);

  int irVal = readIR();

  Serial.print("Red: ");
  Serial.println(redVal);

  Serial.print("IR: ");
  Serial.println(irVal);

  Serial.println("*************");
  delay(500);
}

int readRed()
{
  digitalWrite(LED_RED, HIGH);
  delay(10);

  int reading = analogRead(detectorPin);
  digitalWrite(LED_RED, LOW);

  return reading;
}

int readIR()
{
  digitalWrite(LED_IR, HIGH);
  delay(10);

  int reading = analogRead(detectorPin);
  digitalWrite(LED_IR, LOW);

  return reading;
}
