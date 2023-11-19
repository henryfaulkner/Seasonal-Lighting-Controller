#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "models/palette.h"
#include "models/palette-factory.h"

#define LED_PIN 6
#define LED_COUNT 150
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

Palette *currentPalette = nullptr;
int *pixelIndexArr;

void setup()
{
  Serial.begin(9600);
  PaletteFactory pf;
  currentPalette = pf.ConstructSeasonalPalette();
  Serial.println("After ConstructSeasonalPalette");
  currentPalette->CheckPalette();

  // initialize pixel array's palette list index
  pixelIndexArr = new int[LED_COUNT];
  int palleteListSize = sizeof(currentPalette->GetPaletteList());
  for (int i = 0; i < LED_COUNT; i++)
  {
    pixelIndexArr[i] = i % palleteListSize;
  }

  strip.begin();
  strip.show();
}

void loop()
{
  int len = sizeof(currentPalette->GetPaletteList());
  for (int i = 0; i < LED_COUNT; i++)
  {
    strip.setPixelColor(i, strip.Color(currentPalette->GetPaletteList()[pixelIndexArr[i]][0], currentPalette->GetPaletteList()[pixelIndexArr[i]][1], currentPalette->GetPaletteList()[pixelIndexArr[i]][2]));
    strip.show();
    // delay(10);

    pixelIndexArr[i] = (pixelIndexArr[i] + 1) % len;
  }
  return;
}