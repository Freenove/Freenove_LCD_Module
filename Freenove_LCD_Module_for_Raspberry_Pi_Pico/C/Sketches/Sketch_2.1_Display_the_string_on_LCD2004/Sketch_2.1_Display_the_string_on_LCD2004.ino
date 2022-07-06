/**********************************************************************
  Filename    : Drive LiquidCrystal I2C to display characters
  Description : I2C is used to control the display characters of LCD2004.
  Auther      : www.freenove.com
  Modification: 2022/06/28
**********************************************************************/
#include <LiquidCrystal_I2C.h>
/*
* note:If lcd2004 uses PCF8574T, IIC's address is 0x27,
* or lcd2004 uses PCF8574AT, IIC's address is 0x3F.
*/
LiquidCrystal_I2C lcd(0x27,20,4);
void setup() {
  lcd.init(); // LCD driver initialization
  lcd.backlight(); // Open the backlight
  lcd.setCursor(0,0);             // Move the cursor to row 0, column 0
  lcd.print("FREENOVE");          // The print content is displayed on the LCD
  lcd.setCursor(0,1);             // Move the cursor to row 1, column 0
  lcd.print("www.freenove.com");  // The print content is displayed on the LCD
  lcd.setCursor(0,2);             // Move the cursor to row 2, column 0
  lcd.print("hello world");       // The print content is displayed on the LCD
}
void loop() {
  lcd.setCursor(0,3); // Move the cursor to row 3, column 0
  lcd.print("Counter:"); // The count is displayed every second
  lcd.print(millis() / 1000);
  delay(1000);
}
