#include "I2CLCD.h"

void setup() {
  lcdInit();
  printLCD("Hello, World!");
  delay(2000); 

  clear();                  
  printLCD("New Message");  
  delay(4000);
  clear();
}

void loop() {
  setCursor(1, 0);
  printLCD(" its 16x2 LCD  ");

  setCursor(0, 1);
  printLCD("No Library");
  delay(2000);
  clear();

  setCursor(1, 0);
  printLCD("My Working LCD");

  setCursor(0, 1);
  printLCD(" NO Library");
  delay(2000);
}
