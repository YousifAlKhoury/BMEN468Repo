//This is a comment!

// You can make comments quickly by just highlighting text and clicking CTRL+/

#include <LiquidCrystal.h>

void setup() {
  // put your setup code here, to run once:

  // Setup the speed that your serial communication communicates in, this is called the baud rate.
  // This is 9600 bits/s
  Serial.begin(9600);

  //print hello world statement
  Serial.println("Hello World");

  // next print statement has no ln. This means it does not go to the next line after printing.
  // The following will print "My name is Yousif and I am a biomedical engineer." in one line.
  Serial.print("My name is Yousif");
  Serial.println(" and I am a biomedical engineer.")

  // initialize an integer variable called x and set it to -2.
  int x = -2;

  // If-else if-else statements
  if (x > 0) {
    // indentation matters here
    Serial.println("x is positive");
  } 
  else if (x < 0) {
    Serial.println("x is negative");
  } 
  else {
    Serial.println("x is zero");
  }

  // For loop example.
  // note i++ only appends with 1. i-- will decrement with 1. 
  // if you want to append with more than 1. replace i++ with i=i+2
  for (int i = 0; i < 10; i++) {
    Serial.println(i);
  }

  //Same as above loop but implemented in a while loop
  int i = 0;
  while (i < 10) {
    Serial.println(i);
    i++;
  }

  // Calling the below defined function.
  int s = add2Numbers(2, 1);
  // This will do the same thing.
  int f = 2 + 1;
}

void loop() {
  // put your main code here, to run repeatedly:
}

int add2Numbers(int a, int b) {
  /*
   * This function simply adds 2 integers.
   * 
   * Args:
   *  a -> Integer, value of first integer.
   *  b -> Integer, value of second integer.
   *
   * Return:
   *  sum -> Integer, contains the sum of both arguments.
   */

  int sum = a + b;

  return sum;
}
