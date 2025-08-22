#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 

#define F4 349
#define D4 293
#define G5 783
#define Eb4 311
#define C6 523
#define Bb6 932
#define A6 1760
#define NO_NOTE 0

#define QUARTER 300
#define EIGHTH 150
#define SILENCE 1000
//Pin de buzzer
int buzzer = 11;
int numNotas = 26;
//Notas
int notas[]={
  F4, F4, F4, D4, Eb4, F4, NO_NOTE, F4, F4, F4, D4, Eb4, F4, NO_NOTE,
  G5, G5, G5, C6, Bb6, A6, G5, A6, Bb6, Bb6, Bb6, NO_NOTE
};
//duración de cada nota

int duracion[]={
  EIGHTH, EIGHTH, EIGHTH, QUARTER, EIGHTH, QUARTER, SILENCE,
  EIGHTH, EIGHTH, EIGHTH, QUARTER, EIGHTH, QUARTER, SILENCE,
  QUARTER, EIGHTH, QUARTER, EIGHTH, QUARTER, EIGHTH, QUARTER, EIGHTH, QUARTER + 50,
  QUARTER + 50, QUARTER + 50, SILENCE
};

void setup() {
  pinMode(buzzer, OUTPUT);
  //inicializamos LCD
  lcd.init();
  //Ponemos un mensaje en la LCD:
  lcd.backlight();
  
}

void loop() {
  for(int i = 0; i < 7; i++){ 
    if (duracion[i] == SILENCE) {
      noTone(buzzer);
      delay(duracion[i]);
      continue;
    }

    tone(buzzer,notas[i]);
    delay(duracion[i]); 
    noTone(buzzer);
    delay(50);
    lcd.setCursor(0,0);
    lcd.print("Dunggeulge");
    lcd.setCursor(0,1);
    lcd.print("Dunggeulge");
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("(jjak)");
  delay(100);
   lcd.clear();
  for(int i = 7; i < 13; i++){ 
    if (duracion[i] == SILENCE) {
      noTone(buzzer);
      delay(duracion[i]);
      continue;
    }
    tone(buzzer,notas[i]);
    delay(duracion[i]); 
    noTone(buzzer);
    delay(50);
    lcd.setCursor(0,0);
    lcd.print("Dunggeulge");
    lcd.setCursor(0,1);
    lcd.print("Dunggeulge");
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("(jjak)");
  delay(100);
  lcd.clear();
  for(int i = 13; i < numNotas; i++){ 
    if (duracion[i] == SILENCE) {
      noTone(buzzer);
      delay(duracion[i]);
      continue;
    }
    tone(buzzer,notas[i]);
    delay(duracion[i]); 
    noTone(buzzer);
    delay(50);
    lcd.setCursor(0,0);
    lcd.print("Binggeulbinggeul");
    lcd.setCursor(0,1);
    lcd.print("chumeul chupsida");
  }
  lcd.clear();

}
