#include <Arduino.h>
#include "models/palette.h"
#include "models/palette-factory.h"

Palette currentPalette;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  PaletteFactory pf;
  currentPalette = pf.ConstructSeasonalPalette();
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("hello world");
  return;
}