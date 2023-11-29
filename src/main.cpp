#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "models/palette.h"
#include "models/palette-factory.h"
#include "helpers/rainbox-spin.h"

#define LED_PIN 6
#define LED_COUNT 50
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Palette *currentPalette = nullptr;
int *pixelIndexArr;
RTC_DS3231 RTC;

void setup()
{
  if (!RTC.begin())
  {
    Serial.println("Couldn't find RTC");
    while (1)
      ;
  }

  if (RTC.lostPower())
  {
    Serial.println("RTC lost power, let's set the time!");
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  DateTime now = RTC.now();

  Serial.begin(9600);
  PaletteFactory pf;
  currentPalette = pf.ConstructSeasonalPalette(now);
  Serial.println("After ConstructSeasonalPalette");
  currentPalette->CheckPalette();

  // initialize pixel array's palette list index
  pixelIndexArr = new int[LED_COUNT];
  int palleteListSize = currentPalette->GetPaletteListLength();
  Serial.println("after GetPaletteListLength");
  Serial.println(palleteListSize);
  for (int i = 0; i < LED_COUNT; i++)
  {
    int adjustedIndex = i % palleteListSize;
    pixelIndexArr[i] = adjustedIndex;
  }
  Serial.println("after init loop");

  strip.begin();
  strip.show();
}

void loop()
{
  if (RTC.now().minute() > 5)
  {
    int len = currentPalette->GetPaletteListLength();
    for (int i = 0; i < LED_COUNT; i++)
    {
      strip.setPixelColor(i, strip.Color(currentPalette->GetPaletteList()[pixelIndexArr[i]][0], currentPalette->GetPaletteList()[pixelIndexArr[i]][1], currentPalette->GetPaletteList()[pixelIndexArr[i]][2]));
      strip.show();
      pixelIndexArr[i] = (pixelIndexArr[i] + 1) % len;
    }
    delay(2000);
  }
  else
  {
    RainbowSpin rs;
    rs.Rainbow(strip, LED_COUNT);
    delay(50);
  }

  return;
}