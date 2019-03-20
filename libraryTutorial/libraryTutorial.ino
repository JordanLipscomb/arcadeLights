//Library-------------
#include <Adafruit_NeoPixel.h>

//Constants-----------
#define PIN 6
#define nLEDS 109
#define ledBright 255

//Variables-----------
Adafruit_NeoPixel strip = Adafruit_NeoPixel(nLEDS, PIN, NEO_RGBW + NEO_KHZ800);
char lightType[20];

void setup()
{
  Serial.begin(9600);
  //pinMode(PIN, OUTPUT);
  strip.setBrightness(ledBright);
  strip.begin();
  strip.show(); // Initialize all pixels to "off"
}

void loop()
{
  //Color Controls
  //The "if" statments below read the bytes being sent from the game.
  //Depending on the string sent from the game, the LEDS will change color.
  //The strings are labeled in quotes within the "if" statments.
  int lf = 10; 
  Serial.readBytesUntil(lf, lightType, 2);

  //LEDS are turned On
  if (strcmp(lightType, "on")==0){
    on(0,1);
  }
  //LEDS are turned Red
  if (strcmp(lightType, "rd")==0){
    red(0,1);
  }
  //LEDS are turned Rainbow
  if (strcmp(lightType, "rb")==0){
    rainbow(30, 25);
  }
  //LEDS are turned Off
  if (strcmp(lightType, "of")==0){
    off(0,1);
  }
}

//--------------------
//Light Patterns
//--------------------

void on(uint8_t wait, uint8_t cycles)
{
  uint16_t i, j;

  for(j=0; j<256*cycles; j++) {
    for(i=0; i<nLEDS; i++) {
     strip.setPixelColor(i, 255, 255, 255);
    }
    strip.show();
    delay(wait);
  }
}

void red(uint8_t wait, uint8_t cycles)
{
  uint16_t i, j;

  for(j=0; j<256*cycles; j++) {
    for(i=0; i<nLEDS; i++) {
     strip.setPixelColor(i, 0, 255, 0);
    }
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait, uint8_t cycles) {
  uint16_t i, j;

  for(j=0; j<256*cycles; j++) {
    for(i=0; i<nLEDS; i++) {
      strip.setPixelColor(i, rainbowWheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
  
}

void off(uint8_t wait, uint8_t cycles)
{
  uint16_t i, j;

  for(j=0; j<256*cycles; j++) {
    for(i=0; i<nLEDS; i++) {
     strip.setPixelColor(i, 0, 0, 0);
    }
    strip.show();
    delay(wait);
  }
}

//--------------------
//Color Pickers
//--------------------
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t rainbowWheel(byte WheelPos) {
  
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  
}

uint8_t red(uint32_t c) {
  return (c >> 16);
}
uint8_t green(uint32_t c) {
  return (c >> 8);
}
uint8_t blue(uint32_t c) {
  return (c);
}
