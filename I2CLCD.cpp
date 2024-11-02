#include "I2CLCD.h"

// LCD Commands
#define LCD_CLEAR 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_ENTRY_MODE_SET 0x04
#define LCD_DISPLAY_CONTROL 0x08
#define LCD_CURSOR_SHIFT 0x10
#define LCD_FUNCTION_SET 0x20
#define LCD_SET_CGRAM_ADDR 0x40
#define LCD_SET_DDRAM_ADDR 0x80

// Flags for display on/off control
#define LCD_DISPLAY_ON 0x04
#define LCD_CURSOR_ON 0x02
#define LCD_BLINK_ON 0x01

// LCD Backlight Control
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00

// Enable bit
#define En 0b00000100
#define Rs 0b00000001

void lcdInit() {
  Wire.begin();
  delay(50);
  
  lcdCommand(0x03);
  lcdCommand(0x03);
  lcdCommand(0x03);
  lcdCommand(0x02); // Set to 4-bit mode
  
  lcdCommand(LCD_FUNCTION_SET | 0x08); // 4-bit, 2-line, 5x8 font
  lcdCommand(LCD_DISPLAY_CONTROL | LCD_DISPLAY_ON); // Display on, cursor off
  lcdCommand(LCD_CLEAR); // Clear display
  lcdCommand(LCD_ENTRY_MODE_SET | 0x02); // Increment cursor
  delay(2);
}

// Send command to LCD
void lcdCommand(uint8_t cmd) {
  sendI2C(cmd, 0);
}

// Send data to LCD
void lcdData(uint8_t data) {
  sendI2C(data, Rs);
}

// Low-level function to send data/commands
void sendI2C(uint8_t data, uint8_t mode) {
  uint8_t highNib = data & 0xF0;
  uint8_t lowNib = (data << 4) & 0xF0;

  writeNibble(highNib | mode | LCD_BACKLIGHT);
  writeNibble(lowNib | mode | LCD_BACKLIGHT);
}

// Writes a single nibble to the LCD
void writeNibble(uint8_t nibble) {
  Wire.beginTransmission(LCD_ADDRESS);
  Wire.write(nibble | En);   // Enable HIGH
  Wire.endTransmission();
  delayMicroseconds(1);
  
  Wire.beginTransmission(LCD_ADDRESS);
  Wire.write(nibble & ~En);  // Enable LOW
  Wire.endTransmission();
  delayMicroseconds(50);
}

// Set the cursor to a specific row and column
void setCursor(uint8_t col, uint8_t row) {
  int row_offsets[] = {0x00, 0x40}; // Memory addresses for rows
  lcdCommand(LCD_SET_DDRAM_ADDR | (col + row_offsets[row]));
}

// Print a string on the LCD
void printLCD(const char* str) {
  while (*str) {
    lcdData(*str++);
  }
}

// Clear the LCD screen
void clear() {
  lcdCommand(LCD_CLEAR); // Send clear command to the LCD
  delay(2); // Wait for the clear command to complete
}
