#define PIN_BOTON1 2
#define PIN_BOTON2 3
#define PIN_BOTON3 4
//Numero de pulsaciones
unsigned int Pulsaciones;
//¿Se ha pulsado?
bool anterior1,anterior2,anterior3;

void setup(){
  pinMode(PIN_BOTON1, INPUT_PULLUP);
  pinMode(PIN_BOTON2, INPUT_PULLUP);
  pinMode(PIN_BOTON3, INPUT_PULLUP);

  Serial.begin(9600);
  Pulsaciones = 0;
  anterior1 = 1;
  anterior2 = 1;
  anterior3 = 1;
}

void loop(){
  bool actual1, actual2, actual3;
  actual1 = digitalRead(PIN_BOTON1);
  actual2 = digitalRead(PIN_BOTON2);
  actual3 = digitalRead(PIN_BOTON3);

  //Si ha cambiado de estado...
  if(actual1 != anterior1){
    if(anterior1 == 1){
      Serial.print("Pulsaciones: ");
      Serial.println(++Pulsaciones);
    }
  anterior1 = actual1;
  }
  //Si se ha cambiado de estado...
  if(actual2 != anterior2){
      if(anterior2 == 1){
      Serial.print("Pulsaciones: ");
      Serial.println(++Pulsaciones);
    }
    anterior2 = actual2;
  }
  //Si se ha cambiado de estado...
  if(actual3 != anterior3){
      if(anterior3 == 1){
      Serial.print("Pulsaciones: ");
      Serial.println(++Pulsaciones);
    }
    anterior3 = actual3;
  }
}
