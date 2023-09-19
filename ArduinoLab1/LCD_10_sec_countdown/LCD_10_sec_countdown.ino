#include <LiquidCrystal.h> 

int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

void setup() {
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
} 
void loop() { 
  for (int i=10; i>0; i--) {
    lcd.setCursor(0, 0);
    lcd.print(i);
    delay(1000);
    lcd.clear();
  }
}
