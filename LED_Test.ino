#include <Adafruit_NeoPixel.h>
#include <RTClib.h>

#define NUM_LEDS 11 //Count of LEDs
#define DATA_PIN 23 //ID of the Pin for data transfer from ESP32 to NeoPixlel LED strip

Adafruit_NeoPixel pixels(NUM_LEDS, DATA_PIN, NEO_RGB + NEO_KHZ800);
RTC_DS3231 rtc;
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;

void setLed(int number, int value_r, int value_g, int value_b){
  pixels.setPixelColor(number, pixels.Color(value_g, value_r, value_b, 0));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();
  pixels.show();

  bool result = rtc.begin();
  if(result){
    Serial.println("rtc begin true"));
  }
  else{
    Serial.println("rtc begin false"));
  }

  if (rtc.lostPower())
  {
    Serial.println("RTC lost power. Battery was removed or is empty.");
  }

  DateTime time = DateTime(2022, 12, 22, 19, 11, 0);
  rtc.adjust(time);
}

void getTime()
{
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  delay(1000);

  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    delay(4000);
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    delay(3000);
    if (!getLocalTime(&timeinfo))
    {
      setLedOn(2);
      FastLED.show();
    }
  }
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



int posi1 = 0;
int posi2 = 1;
int posi3 = 2;

void showRunningLights(){
  Serial.println("posi1, current value:" + String(posi1));
  Serial.println("posi2, current value:" + String(posi2));
  Serial.println("posi3, current value:" + String(posi3));
  setLed(posi1, 50, 0, 0);
  setLed(posi2, 0, 50, 0);
  setLed(posi3, 0, 0, 50);
  if(posi1 == 0){
   setLed(NUM_LEDS - 1, 0, 0, 0);  
  }
  else{
    setLed(posi1 - 1, 0, 0, 0); 
  }

  pixels.show();

  posi1++;
  if(posi1 == NUM_LEDS){
    Serial.println("reset posi1, current value:" + String(posi1));
    posi1 = 0;
  }

  posi2++;
  if(posi2 == NUM_LEDS){
    Serial.println("reset posi2, current value:" + String(posi2));
    posi2 = 0;
  }

  posi3++;
  if(posi3 == NUM_LEDS){
    Serial.println("reset posi3, current value:" + String(posi3));
    posi3 = 0;
  }
}

void loop() {
  DateTime now = rtc.now();
  Serial.println("year: " + String(now.year()));
  Serial.println("hour: " + String(now.hour()));
  Serial.println("minute: " + String(now.minute()));
  Serial.println("second: " + String(now.second()));
  delay(3000);
}

