//Include Wire Communication Library
#include <Wire.h>
#include <Servo.h>

const int servoPin = 9;
int servoAngle = 0;

Servo motor;

void setup() {
  Serial.begin(9600); //Start Serial Communication with 9600 Baud Rate

  motor.attach(servoPin);
}

void loop() {

  if(servoAngle > 180) {
    servoAngle = 0;
  }
  
  motor.write(servoAngle);
  Serial.println(servoAngle);
  servoAngle++;
  
  delay(250);
}
