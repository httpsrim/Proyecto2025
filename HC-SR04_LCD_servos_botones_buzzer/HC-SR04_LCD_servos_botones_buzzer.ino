
//------------------------ LCD ------------------------

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 

//------------------------ Servo ------------------------
#include <Servo.h>

Servo servo1;
Servo servo2;

int pos = 0;


//----------------------- Buzzer ----------------------

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

//----------------------- HC-SR04 ----------------------- 
const int EchoPin = 5;
const int TriggerPin = 6;

//------------ Botones ------------
#define PIN_BOTON1 2
#define PIN_BOTON2 3
#define PIN_BOTON3 4
//Numero de pulsaciones
unsigned int Pulsaciones;
//¿Se ha pulsado?
bool anterior1,anterior2,anterior3;

void setup() {
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  pinMode(buzzer,OUTPUT);
  
  pinMode(PIN_BOTON1, INPUT_PULLUP);
  pinMode(PIN_BOTON2, INPUT_PULLUP);
  pinMode(PIN_BOTON3, INPUT_PULLUP);
    
  Pulsaciones = 0;
  anterior1 = 1;
  anterior2 = 1;
  anterior3 = 1;
  
  servo1.attach(9);
  servo2.attach(10);
  
  //inicializamos LCD
  lcd.init();
  //Ponemos un mensaje en la LCD:
  lcd.backlight();
}

void loop() {
  int cm = ping(TriggerPin, EchoPin);
  while(cm < 20){
     bool actual1, actual2, actual3;
    actual1 = digitalRead(PIN_BOTON1);
    actual2 = digitalRead(PIN_BOTON2);
    actual3 = digitalRead(PIN_BOTON3);
    //Si ha cambiado de estado...
    if(actual1 != anterior1 || actual2 != anterior2 || actual3 != anterior3){
      if(anterior1 == 1){
        pos = 50;
        servo1.write(pos);
        servo2.write(pos);
        cancion();
      }else if(anterior2 == 1){
        pos = 130;
        servo1.write(pos);
        servo2.write(pos);
        cancion();        
      }
      else{
        pos = 0;
        servo1.write(pos);
        servo2.write(pos); 
        cancion();
      }
    anterior1 = actual1;
    anterior2 = actual2;
    anterior3 = actual3;
    }
  }
}

//------------ Funcion que calcula distancia ------------ 
int ping(int TriggerPin, int EchoPin) {
  long duration, distanceCm;
  
  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  
  duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
  
  distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
  return distanceCm;
}

//--------------- Funcion para la cancion --------------- 
void cancion(){
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
