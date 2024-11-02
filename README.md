# I2C LCD Library

This is a simple Arduino library for controlling I2C LCDs. It provides functions to initialize the LCD, clear the display, set the cursor position, and print text.

## Features

- **Initialization**: Easily initialize your I2C LCD with a simple command.
- **Text Display**: Print strings to the LCD.
- **Clear Display**: Clear the LCD screen and reset the cursor position.
- **Cursor Control**: Set the cursor position for precise text placement.

## Requirements

- Arduino IDE
- Wire library (included with the Arduino IDE)
- Compatible I2C LCD (e.g., HD44780)

## Installation

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/I2C-LCD-Library.git

2. Open sketch folder and paste I2CLCD.cpp and I2CLCD.h.
3. And include I2CLCD.h in your sketch file.

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
4. Enjoy!
