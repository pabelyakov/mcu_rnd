#include <LiquidCrystal_I2C.h>
#define _LCD_TYPE 1 
#include <LCD_1602_RUS_ALL.h>
LCD_1602_RUS lcd(0x27, 16, 2);

int time = 0;

void setup() {
  lcd.init();       
  lcd.backlight();    
  lcd.home();
  lcd.print("Уровень: ");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
   digitalWrite(LED_BUILTIN, 0);
   delay(time);
   digitalWrite(LED_BUILTIN, 1);
   delay(time);
  static uint32_t tmr;
  if (millis() - tmr >= 100) {
    tmr = millis();
    lcd.setCursor(0, 1);
    
    time = analogRead(0);
    lcd.print(String(time));
    lcd.print("   ");
  }
}