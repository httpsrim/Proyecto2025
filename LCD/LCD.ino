#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 

void setup() {
  //inicializamos LCD
  lcd.init();
  //Ponemos un mensaje en la LCD:
  lcd.backlight();
  lcd.setCursor(3,0); //Columna 3, fila 0
  lcd.print("Hello World!");
  lcd.setCursor(2,1);
  lcd.print("Nyehehe");
}

void loop() {
  // put your main code here, to run repeatedly:
}
