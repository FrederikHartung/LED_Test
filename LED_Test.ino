#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 114 //Count of LEDs
#define DATA_PIN 23 //ID of the Pin for data transfer from ESP32 to NeoPixlel LED strip

Adafruit_NeoPixel pixels(NUM_LEDS, DATA_PIN, NEO_GRBW + NEO_KHZ800);

void setLedOn(int number){
  pixels.setPixelColor(number, pixels.Color(0, 0, 0, 100));

}
void setLedOff(int number){
  pixels.setPixelColor(number, pixels.Color(0, 0, 0, 0));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //Test
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();
  pixels.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  setLedOn(0);
  setLedOn(2);
  setLedOff(1);
  setLedOff(3);
  pixels.show();

  delay(500); //delay for milli sec

  setLedOff(1);
  setLedOff(2);
  setLedOn(1);
  setLedOn(3);
  pixels.show);

  delay(500); //delay for milli sec
}
