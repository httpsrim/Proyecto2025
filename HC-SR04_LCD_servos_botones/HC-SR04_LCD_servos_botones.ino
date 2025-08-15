
//------------------------ LCD ------------------------

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 

//------------------------ Servo ------------------------
#include <Servo.h>

Servo servo1;
Servo servo2;

int pos = 0;

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
    if(actual1 != anterior1){
      if(anterior1 == 1){
        lcd.setCursor(0,0);
        lcd.print("Pulsaciones: ");
        lcd.print(++Pulsaciones);
        lcd.setCursor(0,1);
        lcd.print("Pulsado boton 1");
        
        pos += 1;
        servo1.write(pos);
        servo2.write(pos);
      }
    anterior1 = actual1;
    }
    //Si se ha cambiado de estado...
    if(actual2 != anterior2){
        if(anterior2 == 1){
        lcd.setCursor(0,0);
        lcd.print("Pulsaciones: ");
        lcd.print(++Pulsaciones);
        lcd.setCursor(0,1);
        lcd.print("Pulsado boton 2");
        pos += 2;
        servo1.write(pos);
        servo2.write(pos);
      }
      anterior2 = actual2;
    }
    //Si se ha cambiado de estado...
    if(actual3 != anterior3){
        if(anterior3 == 1){
        lcd.setCursor(0,0);
        lcd.print("Pulsaciones: ");
        lcd.print(++Pulsaciones);
        lcd.setCursor(0,1);
        lcd.print("Pulsado boton 3");
        pos += 3;
        servo1.write(pos);
        servo2.write(pos);
      }
      anterior3 = actual3;
    }
    if(pos == 180) pos = 0;
    delay(500);
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
