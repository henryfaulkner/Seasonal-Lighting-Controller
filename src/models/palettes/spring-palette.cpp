#include "./spring-palette.h"
#include "../../helpers/hex-to-rgb.h"
#include <Arduino.h>

SpringPalette::SpringPalette()
{
    Serial.println("SpringPalette Constructor Start");
    // https://coolors.co/palette/ff99c8-fcf6bd-d0f4de-a9def9-e4c1f9
    pinkRgb = hexToRgb.ConvertHexToRGBArray(0xFF99C8);
    yellowRgb = hexToRgb.ConvertHexToRGBArray(0xFCF6BD);
    greenRgb = hexToRgb.ConvertHexToRGBArray(0xD0F4DE);
    blueRgb = hexToRgb.ConvertHexToRGBArray(0xA9DEF9);
    purpleRgb = hexToRgb.ConvertHexToRGBArray(0xE4C1F9);
    paletteList = new int *[5];
    paletteList[0] = pinkRgb;
    paletteList[1] = yellowRgb;
    paletteList[2] = greenRgb;
    paletteList[3] = blueRgb;
    paletteList[4] = purpleRgb;
    Serial.println("SpringPalette Constructor End");
    return;
}

int **SpringPalette::GetPaletteList()
{
    return paletteList;
}

const char *SpringPalette::CheckPalette()
{
    Serial.println("Spring Palette");
    return "Spring";
}

SpringPalette::~SpringPalette()
{
    delete (pinkRgb);
    delete (yellowRgb);
    delete (greenRgb);
    delete (blueRgb);
    delete (purpleRgb);
    for (int i = 0; i < 5; i++)
    {
        delete[] paletteList[i];
    }
    delete[] paletteList;
}