#include "./christmas-palette.h"
#include "../../helpers/hex-to-rgb.h"
#include <Arduino.h>

ChristmasPalette::ChristmasPalette()
{
    // https://coolors.co/palette/bb010b-cd1624-006f57-23856d-faf8f8
    deepRedRgb = hexToRgb.ConvertHexToRGBArray(0xBB010B);
    dullRedRgb = hexToRgb.ConvertHexToRGBArray(0xCD1624);
    deepGreenRgb = hexToRgb.ConvertHexToRGBArray(0x006F57);
    dullGreenRgb = hexToRgb.ConvertHexToRGBArray(0x23856D);
    snowWhiteRgb = hexToRgb.ConvertHexToRGBArray(0xFAF8F8);

    return;
}

const char *ChristmasPalette::CheckPalette()
{
    Serial.println("Christmas Palette");
    return "Christmas";
}

ChristmasPalette::~ChristmasPalette()
{
    delete (deepRedRgb);
    delete (dullRedRgb);
    delete (deepGreenRgb);
    delete (dullGreenRgb);
    delete (snowWhiteRgb);
    for (int i = 0; i < sizeof(paletteList); ++i)
    {
        delete[] paletteList[i];
    }
    delete[] paletteList;
}