
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

void setup() {
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);

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
    servo1.write(pos);
    servo2.write(pos);
    pos++;
    if(pos == 180) pos = 0;
    delay(15);
    cm = ping(TriggerPin,EchoPin);
    lcd.setCursor(0,0);
    lcd.print("Distancia: ");
    lcd.print(cm);
    delay(1000);
    lcd.clear();
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
