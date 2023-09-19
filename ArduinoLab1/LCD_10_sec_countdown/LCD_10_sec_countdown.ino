#include <LiquidCrystal.h> 

// Initialize the LCD and the pins that it is connected to on the arduino
// notice that it is a global variable because we want to use it in both setup and loop.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

void setup() {
  // Set the screen's contrast
  analogWrite(6, 75);
  // set up the number of (columns, rows)
  lcd.begin(16, 2);
} 
void loop() { 
  // create for loop to count down the numbers and print them on the LCD
  for (int i=10; i>0; i--) {
    // Set cursor to top left of LCD screen
    lcd.setCursor(0, 0);
    // print number
    lcd.print(i);
    // wait 1 second
    delay(1000);
    // clear the display
    lcd.clear();
  }
}
