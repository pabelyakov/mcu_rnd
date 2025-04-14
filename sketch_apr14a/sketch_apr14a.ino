#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int time = 0;

void setup() {
  lcd.init();           // инициализация
  lcd.backlight();      // включить подсветку
  lcd.home();
  lcd.print("stuffiness lvl: ");
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
    lcd.print(analogRead(0));
    time = analogRead(0);
    lcd.print("   ");
  }
}