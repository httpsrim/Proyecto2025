  #include <Adafruit_NeoPixel.h>
  #define PIN   A3
  #define NUMPIXELS 29

  using namespace std;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();
  for(int i = 0; i < NUMPIXELS; i++){
    int colorR = random(0,250);
    int colorB = random(0,250);
    int colorG = random(0,250);
    pixels.setPixelColor(i, pixels.Color(colorR, colorG, colorB));
    pixels.show();  
  }
}

void loop() {
}
