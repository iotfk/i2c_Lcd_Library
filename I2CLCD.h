#ifndef I2CLCD_H
#define I2CLCD_H

#include <Wire.h>
#include <Arduino.h> // Include Arduino core for delay functions

// I2C Address (adjust if necessary)
#define LCD_ADDRESS 0x27

// Function Declarations
void lcdInit();
void setCursor(uint8_t col, uint8_t row);
void printLCD(const char* str);
void clear(); // Add this line for clear function

// Internal Functions
void lcdCommand(uint8_t cmd);
void sendI2C(uint8_t data, uint8_t mode);
void writeNibble(uint8_t nibble);

#endif
