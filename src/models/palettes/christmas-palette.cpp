#include "./christmas-palette.h"
#include "../../helpers/hex-to-rgb.h"
#include <Arduino.h>

ChristmasPalette::ChristmasPalette()
{
    Serial.println("ChristmasPalette Constructor Start");
    // https://coolors.co/palette/bb010b-cd1624-006f57-23856d-faf8f8
    deepRedRgb = hexToRgb.ConvertHexToRGBArray(0xFF0000);
    dullRedRgb = hexToRgb.ConvertHexToRGBArray(0xDE1624);
    deepGreenRgb = hexToRgb.ConvertHexToRGBArray(0x00FF00);
    dullGreenRgb = hexToRgb.ConvertHexToRGBArray(0x1DFF00);
    snowWhiteRgb = hexToRgb.ConvertHexToRGBArray(0xFAF8F8);
    paletteList = new int *[GetPaletteListLength()];
    paletteList[0] = deepRedRgb;
    paletteList[1] = deepGreenRgb;
    paletteList[2] = snowWhiteRgb;
    paletteList[3] = dullRedRgb;
    paletteList[4] = dullGreenRgb;
    paletteList[5] = snowWhiteRgb;
    Serial.println("ChristmasPalette Constructor End");

    for (int i = 0; i < GetPaletteListLength(); i++)
    {
        Serial.print("Rgb(");
        Serial.print(paletteList[i][0]);
        Serial.print(", ");
        Serial.print(paletteList[i][1]);
        Serial.print(", ");
        Serial.print(paletteList[i][2]);
        Serial.println(")");
    }
    return;
}

int **ChristmasPalette::GetPaletteList()
{
    return paletteList;
}

int ChristmasPalette::GetPaletteListLength()
{
    return 6;
}

const char *ChristmasPalette::CheckPalette()
{
    Serial.println("Christmas Palette");
    return "Christmas";
}

void ChristmasPalette::CheckPaletteListRgb()
{
    int len = sizeof(paletteList);
    for (int i = 0; i < len; i++)
    {
        Serial.print("Rgb(");
        Serial.print(paletteList[i][0]);
        Serial.print(", ");
        Serial.print(paletteList[i][1]);
        Serial.print(", ");
        Serial.print(paletteList[i][2]);
        Serial.println(")");
    }
}

ChristmasPalette::~ChristmasPalette()
{
    delete (deepRedRgb);
    delete (dullRedRgb);
    delete (deepGreenRgb);
    delete (dullGreenRgb);
    delete (snowWhiteRgb);
    for (int i = 0; i < GetPaletteListLength(); i++)
    {
        delete[] paletteList[i];
    }
    delete[] paletteList;
}