#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 11 //Count of LEDs
#define DATA_PIN 23 //ID of the Pin for data transfer from ESP32 to NeoPixlel LED strip

Adafruit_NeoPixel pixels(NUM_LEDS, DATA_PIN, NEO_RGB + NEO_KHZ800);

void setLed(int number, int value_r, int value_g, int value_b){
  pixels.setPixelColor(number, pixels.Color(value_g, value_r, value_b, 0));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();
  pixels.show();
}

void showEverySecondLed(){
  for (int i = 0; i < NUM_LEDS; i++) {

    if(i % 2 == 0){
      setLed(i, 100, 0, 0);
    }
    else{
      setLed(i, 0, 0, 0);
    }
  }

  pixels.show();
  delay(500);

  for (int i = 0; i < NUM_LEDS; i++) {
   if(i % 2 == 0){
      setLed(i, 0, 0, 0);
    }
   else{
      setLed(i, 100, 0, 0);
    }
  }

  pixels.show();
  delay(500);
}

void showSpecificLed(){
  setLed(0, 100, 0, 0);
  setLed(1, 0, 100, 0);
  setLed(2, 0, 0, 100);
  setLed(3, 100, 100, 100);
  pixels.show();
  delay(2000);
  pixels.clear();

  setLed(0, 0, 0, 0);
  setLed(2, 0, 0, 0);
  setLed(2, 0, 0, 0);
  setLed(3, 0, 0, 0);
  pixels.show();
  delay(500);
}

int RED = 0;
int GREEN = 0;
int BLUE = 0;

void showRainbow(){
  if(RED < 256){
    RED = RED + 5;
  }
  else
  {
    RED = 0;
  }

  for (int i = 0; i < NUM_LEDS; i++) {
    setLed(i, RED, GREEN, BLUE);
  }

  pixels.show();
  delay(10);
}

void showBrightness(){
  for(int i = 0; i < 11; i++){
        setLed(i, i * 25, 0, 0);
  }
  setLed(10, 255, 0, 0);
  pixels.show();
  delay(1000);
}

void loop() {
  setLed(0, 1, 0, 0);
  setLed(1, 1, 50, 0);
  setLed(2, 1, 1, 50);
  setLed(3, 255, 0, 0);
  pixels.show();
  delay(1000);
}
