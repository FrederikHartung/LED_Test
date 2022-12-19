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

void loop() {
  // put your main code here, to run repeatedly:
  //setLedOn(0);
  //setLedOn(2);
  //setLedOff(1);
  //setLedOff(3);
  //pixels.show();

  //delay(500); //delay for milli sec

  //setLedOff(1);
  //setLedOff(2);
  //setLedOn(1);
  //setLedOn(3);
  //pixels.show();

  //delay(500); //delay for milli sec
  //for (int i = 0; i < NUM_LEDS; i++) {
  //if(i % 2 == 0){
     // setLedOn(i);
   // }
 // else{
    //setLedOff(i);
   // }
  //}

  //pixels.show();
  //delay(500);
 // for (int i = 0; i < NUM_LEDS; i++) {
  //if(i % 2 == 0){
    //  setLedOff(i);
   // }
  //else{
    //setLedOn(i);
   // }
  //}
  setLed(0, 100, 0, 0, 0);
  setLed(1, 0, 100, 0, 0);
  setLed(2, 0, 0, 100, 0);
  setLed(3, 100, 100, 100, 0);
  pixels.show();
  delay(2000);
  pixels.clear();

  setLed(0, 0, 0, 0, 0);
  setLed(2, 0, 0, 0, 0);
  setLed(2, 0, 0, 0, 0);
  setLed(3, 0, 0, 0, 0);
  pixels.show();
  delay(500);
}
