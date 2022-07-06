/**********************************************************************
  Filename    : Drive LiquidCrystal I2C to display characters
  Description : I2C is used to control the display characters of LCD2004.
  Auther      : www.freenove.com
  Modification: 2022/06/28
**********************************************************************/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 13                    //Define SDA pins
#define SCL 14                    //Define SCL pins

/*
 * note: If lcd2004 uses PCF8574T, IIC's address is 0x27,
 *      or lcd2004 uses PCF8574AT, IIC's address is 0x3F.
*/
LiquidCrystal_I2C lcd(0x27,20,4); 

void setup() {
  Wire.begin(SDA, SCL);           // attach the IIC pin
  lcd.init();                     // LCD driver initialization
  lcd.backlight();                // Turn on the backlight
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);// set the cursor to column 0, line 0
  // print the number of seconds since reset:
  lcd.print("FREENOVE");
  lcd.setCursor(0, 1);// set the cursor to column 0, line 1
  // print the number of seconds since reset:
  lcd.print("www.freenove.com");
  lcd.setCursor(0, 2);// set the cursor to column 0, line 2
  lcd.print("hello, world!");// Print a message to the LCD

}

void loop() {
  lcd.setCursor(0,3);             // Move the cursor to  column 0, row 3
  lcd.print("Counter:");          // The count is displayed every second
  lcd.print(millis() / 1000);
  delay(1000);
}
