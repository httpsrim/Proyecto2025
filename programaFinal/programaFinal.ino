//----------------------- LEDs -----------------------
    #include <Adafruit_NeoPixel.h>
  #define PIN   A3
  #define NUMPIXELS 15
  Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

  using namespace std;
//----------------  Colors ----------------
//FieryHorizon
int fieryR[15] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
int fieryG[15] = {69, 90, 110, 130, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250};
int fieryB[15] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 110, 120, 130, 140, 150};
//TwilightBliss
int twilightR[15] = {106, 130, 155, 180, 200, 210, 220, 230, 240, 245, 250, 252, 253, 254, 255};
int twilightG[15] = {90, 110, 130, 150, 165, 175, 185, 195, 205, 210, 215, 220, 225, 230, 235};
int twilightB[15] = {205, 200, 190, 180, 170, 160, 150, 140, 130, 120, 110, 100, 90, 80, 70};
//CoralDream
int coralR[15] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
int coralG[15] = {100, 115, 130, 145, 160, 170, 180, 190, 200, 210, 220, 225, 230, 235, 240};
int coralB[15] = {80, 70, 60, 50, 40, 35, 30, 25, 20, 15, 10, 5, 0, 0, 0};
//GoldenDusk
int goldenR[15] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
int goldenG[15] = {215, 202, 189, 176, 163, 150, 137, 124, 111, 98, 85, 72, 59, 39, 20};
int goldenB[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 73, 147};
//LavenderSunset
int lavenderR[15] = {180, 200, 220, 230, 240, 245, 250, 255, 255, 255, 255, 255, 255, 255, 255};
int lavenderG[15] = {100, 120, 140, 160, 180, 200, 210, 225, 235, 245, 250, 252, 254, 255, 255};
int lavenderB[15] = {200, 180, 160, 140, 120, 100, 90, 70, 50, 30, 20, 15, 10, 5, 0};
//OceanicGlow
int oceanicR[15] = {0, 17, 34, 51, 68, 85, 102, 119, 136, 170, 199, 227, 241, 248, 255};
int oceanicG[15] = {191, 186, 180, 175, 169, 164, 158, 153, 148, 181, 198, 206, 210, 212, 215};
int oceanicB[15] = {255, 245, 235, 224, 214, 204, 194, 183, 173, 143, 109, 76, 38, 19, 0};
//BlazingSky
int blazingR[15] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
int blazingG[15] = {69, 66, 63, 72, 81, 90, 99, 108, 117, 126, 135, 145, 155, 185, 215};
int blazingB[15] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 80, 80, 80, 80, 0, 0};
//SereneSunset
int sereneR[15] = {240, 244, 248, 250, 252, 253, 254, 255, 255, 255, 255, 255, 255, 255, 255};
int sereneG[15] = {128, 131, 134, 137, 140, 144, 148, 152, 157, 162, 167, 172, 176, 178, 180};
int sereneB[15] = {128, 132, 136, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195};
//BerrySunset
int berryR[15] = {138, 153, 168, 183, 198, 213, 228, 240, 245, 250, 253, 254, 255, 255, 255};
int berryG[15] = {43, 64, 85, 106, 127, 148, 162, 168, 174, 176, 178, 180, 182, 182, 182};
int berryB[15] = {226, 220, 214, 208, 202, 196, 190, 186, 184, 182, 180, 178, 176, 174, 172};
//CitrusTwilight
int citrusR[15] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
int citrusG[15] = {140, 160, 180, 200, 220, 220, 200, 180, 160, 140, 120, 100, 80, 60, 40};
int citrusB[15] = {0, 40, 80, 120, 160, 180, 160, 120, 80, 40, 0, 20, 40, 60, 80};
//MysticDawn
int mysticR[15] = {75, 91, 107, 123, 139, 155, 171, 187, 203, 219, 235, 245, 250, 252, 255};
int mysticG[15] = {0, 16, 32, 48, 64, 72, 80, 88, 96, 104, 112, 132, 157, 170, 182};
int mysticB[15] = {130, 145, 160, 175, 190, 195, 200, 205, 210, 215, 220, 225, 230, 240, 193};
//WarmEmbrace
int warmR[15] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
int warmG[15] = {127, 113, 99, 84, 69, 104, 122, 140, 155, 170, 187, 201, 210, 214, 215};
int warmB[15] = {80, 76, 71, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//EtherealGlow
int etherealR[15] = {240, 248, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
int etherealG[15] = {240, 230, 215, 199, 182, 157, 131, 116, 105, 94, 81, 75, 72, 70, 69};
int etherealB[15] = {0, 20, 0, 77, 193, 186, 183, 181, 180, 151, 121, 90, 45, 22, 0};


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

int modo = -1;

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

  pixels.begin();
}

void loop() {
  int cm = ping(TriggerPin, EchoPin);
  Serial.println(cm);
  while(cm < 20){
     bool actual1, actual2, actual3;
    actual1 = digitalRead(PIN_BOTON1);
    actual2 = digitalRead(PIN_BOTON2);
    actual3 = digitalRead(PIN_BOTON3);
    //Si ha cambiado de estado...
    if(actual1 != anterior1){
      modo--;
      if(modo < 0) modo = 9;
      sigAccion(modo);
    }else if(actual2 != anterior2){
      modo++;
      if(modo >= 10) modo = 0;
      sigAccion(modo);
    }else if(actual3 != anterior3){ 
        cancion();
      }
    anterior1 = actual1;
    anterior2 = actual2;
    anterior3 = actual3;
    
    cm = ping(TriggerPin, EchoPin);
  Serial.println(cm);
  }
  delay(1000);
  for(int i = 0; i < NUMPIXELS;i++)
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  pixels.show();
  lcd.clear();
  cm = ping(TriggerPin, EchoPin);
  Serial.println(cm);
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

//-------------- Funcion que cambia de modo ------------- 
void sigAccion(int modo){
  Serial.println("entro");
  //pixels.clear();
 // pixels.show();
  switch(modo){
    case 0:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo 1");
      lcd.setCursor(0,1);
      lcd.print("Fiery Horizon");
      fieryHorizon();
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo 2");
      lcd.setCursor(0,1);
      lcd.print("Twilight Bliss");
      twilightBliss();
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo 3");
      lcd.setCursor(0,1);
      lcd.print("Coral Dream");
      coralDream();
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo 4");
      lcd.setCursor(0,1);
      lcd.print("Golden Dusk");
      goldenDusk();
      break;
    case 4:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo 5");
      lcd.setCursor(0,1);
      lcd.print("Lavender Sunset");
      lavenderSunset();
      break;
    case 5:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo 6");
      lcd.setCursor(0,1);
      lcd.print("Oceanic Glow");
      oceanicGlow();
      break;
    case 6:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo 7");
      lcd.setCursor(0,1);
      lcd.print("Blazing Sky");
      blazingSky();
      break;
    case 7:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo 8");
      lcd.setCursor(0,1);
      lcd.print("Citrus Twilight");
      citrusTwilight();
      break;
    case 8:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo 9");
      lcd.setCursor(0,1);
      lcd.print("Warm Embrace");
      warmEmbrace();
      break;
    case 9:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo 10");
      lcd.setCursor(0,1);
      lcd.print("Ethereal Glow");
      etherealGlow();
      break;
  }
}

//-------------- Funciones para las luces --------------- 
void fieryHorizon(){
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(fieryR[i], fieryG[i], fieryB[i]));
  }
  pixels.show();
}

void twilightBliss(){
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(twilightR[i], twilightG[i], twilightB[i]));
  }
  pixels.show();
}

void coralDream(){
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(coralR[i], coralG[i], coralB[i]));
  }
  pixels.show();
}

void goldenDusk(){
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(goldenR[i], goldenG[i], goldenB[i]));
  }
  pixels.show();
}

void lavenderSunset(){
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(lavenderR[i], lavenderG[i], lavenderB[i]));
  }
  pixels.show();
}

void oceanicGlow(){
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(oceanicR[i], oceanicG[i], oceanicB[i]));
  }
  pixels.show();
}

void blazingSky(){
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(blazingR[i], blazingG[i], blazingB[i]));
  }
  pixels.show();
}

void citrusTwilight(){
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(citrusR[i], citrusG[i], citrusB[i]));
  }
  pixels.show();
}

void warmEmbrace(){
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(warmR[i], warmG[i], warmB[i]));
  }
  pixels.show();
}

void etherealGlow(){
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(etherealR[i], etherealG[i], etherealB[i]));
  }
  pixels.show();
}
//--------------- Funcion para la cancion --------------- 
int cancion(){
   for(int i = 0; i < 7; i++){ 
    if (duracion[i] == SILENCE) {
      noTone(buzzer);
      delay(duracion[i]);
      continue;
    }
    pos += 30;
    servo1.write(pos);
    tone(buzzer,notas[i]);
    delay(duracion[i]); 
    noTone(buzzer);
    delay(50);
    lcd.setCursor(0,0);
    lcd.print("Dunggeulge");
    lcd.setCursor(0,1);
    lcd.print("Dunggeulge");
  }
  pos = 0;
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
    pos += 30;
    servo2.write(pos);
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
  return 0;
}
