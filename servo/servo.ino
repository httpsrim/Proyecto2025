#include <Servo.h>

Servo servo1;  // crea el objeto servo
Servo servo2; //crea objeto servo(el segundo que se utiliza)

int pos = 0;    // posicion de los servos

void setup() {
  servo1.attach(3);  // vincula el servo al pin digital 3
  servo2.attach(6);  // vincula el servo al pin digital 6
}

void loop() {
  //varia la posicion de 0 a 180, con esperas de 15ms
  for (pos = 0; pos <= 180; pos += 1) 
  {
    servo1.write(pos);            
    servo2.write(pos);
    delay(15);                       
  }

  //varia la posicion de 180 a 0, con esperas de 15ms
  for (pos = 180; pos >= 0; pos -= 1) 
  {
    servo1.write(pos);
    servo2.write(pos);               
    delay(15);                       
  }
}
