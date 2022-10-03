#include <Arduino.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <FastLED.h>
#define NUM_LEDS 120
#define COLOR_ORDER RGB // Define color order for your strip
#define LED_PIN 5       // Data pin for led comunication
#define DST_PIN 4       // Define DST adjust button pin
#define MIN_PIN 3       // Define Minutes adjust button pin
#define HUR_PIN 2       // Define Hours adjust button pin
CRGB leds[NUM_LEDS];
int analogPin = A6;
int cursorPos[4] = {96, 70, 31, 5};
int timeAsArray[4] = {0, 0, 0, 0};
int last_digit = 0;
int cursor = 0;
int hours = 0;
int minutes = 0;
int seconds = 0;
long timeAsNumber = 0;
byte digitAdresses[50];
byte digitAdressCount = 0;
byte brightness = 2;
byte brightnessMax = 255;
byte symbolMap[12][19] = {
    {0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0},  // 0
    {0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},  // 1
    {0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0},  // 2
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0},  // 3
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0},  // 4
    {0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0},  // 5
    {0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0},  // 6
    {0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0},  // 7
    {0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0},  // 8
    {0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0},  // 9
    {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},  //
    {0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}}; //
bool dot = true;                                                // dot state
bool DST = true;                                                // DST state // false to true
bool tempShow = false;

void setup()
{
  delay(200);
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);
  delay(200);
  LEDS.setBrightness(brightness); // Set initial brightness
  delay(200);
  pinMode(DST_PIN, INPUT_PULLUP); // Define DST adjust button pin
  pinMode(MIN_PIN, INPUT_PULLUP); // Define Minutes adjust button pin
  pinMode(HUR_PIN, INPUT_PULLUP); // Define Hours adjust button pin
}

#include "colors.h"
#include "calcTime.h"
#include "temp.h"
#include "dst.h"
#include "dot.h"
#include "snake.h"

void loop()
{
  potToBrightness();
  rainbow_beat();
  getTime();
  // dot ? dotOn() : dotOff(); // regular blinky dot
  animateCenterSnake();
  darkenDigits();
  // reversed_rainbow();
  FastLED.show(); // Display leds array
}
