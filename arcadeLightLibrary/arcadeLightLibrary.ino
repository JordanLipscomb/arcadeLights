//Libraries-------------
#include <Adafruit_NeoPixel.h>
#include <SimpleTimer.h>

//Constants-----------
#define PIN 6 //This is the pin the LEDS are receiving information from.
#define nLEDS 109 //The number of LEDS in the series
#define ledBright 255 //How bright the leds get

//Global Variables-----------
//Neopixel
Adafruit_NeoPixel strip = Adafruit_NeoPixel(nLEDS, PIN, NEO_RGBW + NEO_KHZ800);

//Color Control
char lightType[20];
int lf = 10;

//Timer
SimpleTimer timer;
int timerId;
unsigned long resetLightDelay = 600000;
char resetLightChars[20] = "rb";





void setup(){
  Serial.begin(9600);
  
  timerId = timer.setInterval(resetLightDelay, mainPattern);
  
  strip.setBrightness(ledBright);
  strip.begin();
  strip.show(); // Initialize all pixels to "off"
}





void loop(){
  //Color Controls
  //The "if" statments below read the bytes being sent from the game.
  //Depending on the string sent from the game, the LEDS will change color.
  //The strings are labeled in quotes within the "if" statments.
  timer.run();
  Serial.readBytesUntil(lf, lightType, 2);

  //LEDS are turned Off
  if (strcmp(lightType, "of")==0){
    off(0,1);
  }
  //LEDS are turned On
  if (strcmp(lightType, "on")==0){
    on(0,1);
  }
  //LEDS are turned Red
  if (strcmp(lightType, "rd")==0){
    red(0,1);
  }
  //LEDS are turned Violet
  if (strcmp(lightType, "vo")==0){
    violet(0,1);
  }
  //LEDS are turned Blue
  if (strcmp(lightType, "bu")==0){
    blue(0,1);
  }
  //LEDS are turned Green
  if (strcmp(lightType, "gr")==0){
    green(0,1);
  }
  //LEDS are turned Yellow
  if (strcmp(lightType, "yl")==0){
    yellow(0,1);
  }
  //LEDS are turned Orange
  if (strcmp(lightType, "og")==0){
    orange(0,1);
  }
  //LEDS are turned Rainbow
  if (strcmp(lightType, "rb")==0){
    rainbow(30,1);
  }
}





//--------------------
//Light Colors and Patterns
//--------------------
//The RGB values are acutally GRB
//This is the default pattern that runs after a set time.
void mainPattern(){
  strncpy(lightType, resetLightChars, 20);
  timer.restartTimer(timerId);
}
//--------------------
//No Light
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
//White Light
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
//--------------------
//Red Light
void red(uint8_t wait, uint8_t cycles){
  uint16_t i, j;

  for(j=0; j<256*cycles; j++) {
    for(i=0; i<nLEDS; i++) {
     strip.setPixelColor(i, 0, 255, 0);
    }
    strip.show();
    delay(wait);
  }
}
//--------------------
//Violet Light
void violet(uint8_t wait, uint8_t cycles){
  uint16_t i, j;

  for(j=0; j<256*cycles; j++) {
    for(i=0; i<nLEDS; i++) {
     strip.setPixelColor(i, 0, 255, 148);
    }
    strip.show();
    delay(wait);
  }
}
//--------------------
//Blue Light
void blue(uint8_t wait, uint8_t cycles){
  uint16_t i, j;

  for(j=0; j<256*cycles; j++) {
    for(i=0; i<nLEDS; i++) {
     strip.setPixelColor(i, 0, 0, 255);
    }
    strip.show();
    delay(wait);
  }
}
//--------------------
//Green Light
void green(uint8_t wait, uint8_t cycles){
  uint16_t i, j;

  for(j=0; j<256*cycles; j++) {
    for(i=0; i<nLEDS; i++) {
     strip.setPixelColor(i, 255, 0, 0);
    }
    strip.show();
    delay(wait);
  }
}
//Yellow Light
void yellow(uint8_t wait, uint8_t cycles){
  uint16_t i, j;

  for(j=0; j<256*cycles; j++) {
    for(i=0; i<nLEDS; i++) {
     strip.setPixelColor(i, 255, 255, 0);
    }
    strip.show();
    delay(wait);
  }
}
//Orange Light
void orange(uint8_t wait, uint8_t cycles){
  uint16_t i, j;

  for(j=0; j<256*cycles; j++) {
    for(i=0; i<nLEDS; i++) {
     strip.setPixelColor(i, 140, 255, 0);
    }
    strip.show();
    delay(wait);
  }
}
//--------------------
//Rainbow Pattern
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





//--------------------
//Color Picker
//--------------------
//Functions that run the colors and patterns above
//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g - b - back to r.
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
