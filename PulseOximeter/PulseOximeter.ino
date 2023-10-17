//Include Wire Communication Library
#include <Wire.h>
#include <Servo.h>

//Input Parameters
const int stabilityDelay = 5; //Delay between turning LED on and reading detector
const int collectedSamples = 100; //Number of samples collected before calculating/printing SO2
const float fitFactor = 0.3; //Factor to multiply by R to fit SO2 to the device
const boolean serialDisplay = true; //Turn on/off serial display

//Declare Pin Numbers
const int LED_RED = 4;
const int LED_IR = 8;

const int detectorPin = A0;

const int servoPin = 9;

//Declare Variables for Calculation
float redMax = 0;
float redMin = 1023;
float irMax = 0;
float irMin = 1023;
int count = 0;
float rVal;
float SpO2;

Servo motor;

void setup() {
  Serial.begin(9600); //Start Serial Communication with 9600 Baud Rate
  analogReference(INTERNAL); //Sets Reference to 1.1V
  
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_IR, OUTPUT);
  pinMode(detectorPin, INPUT); //Sets detectorPin as an input pin

  motor.attach(servoPin);
}

void loop() {
  
  int redVal = readRed()*1.9; //Store absorbance voltage for red LED in "redVal"
  if (redVal>1023) {
    redVal = 1023;
  }

  delay(20);

  int irVal = readIR(); //Store absorbance voltage for IR LED in "irVal"

  // Serial.print("Red: ");
  // Serial.println(redVal);

  // Serial.print("IR: ");
  // Serial.println(irVal);

  // Serial.println(count);
  // delay(500);
  // Serial.println("*************");
  
  if((redVal == irVal) || (redVal == 1023) || (irVal == 1023) || (redVal == 0) || (irVal == 0)) {
    return;
  }
  
  if(redVal > redMax) {
    redMax = redVal; //Makes redAC the max value for the red LED
  }

  if(redVal < redMin) {
    redMin = redVal; //Makes redMin the min value for the red LED
  }
  
  if(irVal > irMax) {
    irMax = irVal; //Makes redAC the max value for the red LED
  }

  if(irVal < irMin) {
    irMin = irVal; //Makes redMin the min value for the red LED
  }

  count++; //Increments the count variable

  if(count >= collectedSamples)
  {
    rVal = ( (redMax - redMin) / redMin ) / ( (irMax-irMin) / irMin ); //Calculates R for the data
    SpO2 = 1.1-0.3*rVal; //Calculates SpO2 for the data

    if (SpO2 > 1) {
      SpO2 = 1;
    }
    else if (SpO2<0.8) {
      SpO2 = 0.8;
    }

    int servoAngle = (SpO2-0.8) * 180/0.2;
    Serial.println(servoAngle);
    motor.write(servoAngle);

    if(serialDisplay) //Checks display boolean
    {
      Serial.print("Red Max: ");
      Serial.println(redMax);
      Serial.print("Red Min: ");
      Serial.println(redMin);

      Serial.print("IR Max: ");
      Serial.println(irMax);
      Serial.print("IR Min: ");
      Serial.println(irMin);

      Serial.print(rVal);
      Serial.print(",");
      Serial.println(SpO2); //Prints rVal and Sp02 to the serial monitor/plotter
    }

    //Reset all variables
    count = 0;
    redMax = 0;
    redMin = 1023;
    irMax = 0;
    irMin = 1023;
  }
}

int readRed()
{
  digitalWrite(LED_RED, HIGH);
  delay(stabilityDelay);

  int reading = analogRead(detectorPin);
  digitalWrite(LED_RED, LOW);

  return reading;
}

int readIR()
{
  digitalWrite(LED_IR, HIGH);
  delay(stabilityDelay);

  int reading = analogRead(detectorPin);
  digitalWrite(LED_IR, LOW);

  return reading;
}
