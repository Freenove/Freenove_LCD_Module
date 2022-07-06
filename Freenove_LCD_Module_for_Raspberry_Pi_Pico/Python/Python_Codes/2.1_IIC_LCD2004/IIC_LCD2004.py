import time
from machine import I2C, Pin
from I2C_LCD import I2CLcd

i2c = I2C(0, sda=Pin(4), scl=Pin(5), freq=400000)
devices = i2c.scan()

try:
    if devices != []:
        lcd = I2CLcd(i2c, devices[0], 4, 20)
        lcd.move_to(0, 0)
        lcd.putstr("FREENOVE")
        lcd.move_to(0, 1)
        lcd.putstr("www.freenove.com")
        lcd.move_to(0, 2)
        lcd.putstr("Hello, world!")
        count = 0
        while True:
            lcd.move_to(0, 3)
            lcd.putstr("Counter:%d" %(count))
            time.sleep(1)
            count += 1
    else:
        print("No address found")
except:
    pass
