#include "./fall-palette.h"
#include "../../helpers/hex-to-rgb.h"
#include <Arduino.h>

FallPalette::FallPalette()
{
    Serial.println("FallPalette Constructor Start");
    // https://coolors.co/palette/780116-f7b538-db7c26-d8572a-c32f27
    deepRedRgb = hexToRgb.ConvertHexToRGBArray(0x780116);
    yellowRgb = hexToRgb.ConvertHexToRGBArray(0xF7B538);
    pumpkinRgb = hexToRgb.ConvertHexToRGBArray(0xDB7C26);
    burntOrangeRgb = hexToRgb.ConvertHexToRGBArray(0xD8572A);
    deepOrangeRgb = hexToRgb.ConvertHexToRGBArray(0xC32F27);
    paletteList = new int *[GetPaletteListLength()];
    paletteList[0] = deepRedRgb;
    paletteList[1] = yellowRgb;
    paletteList[2] = pumpkinRgb;
    paletteList[3] = burntOrangeRgb;
    paletteList[4] = deepOrangeRgb;
    Serial.println("FallPalette Constructor End");
    return;
}

int **FallPalette::GetPaletteList()
{
    return paletteList;
}

int FallPalette::GetPaletteListLength()
{
    return 5;
}

const char *FallPalette::CheckPalette()
{
    Serial.println("Fall Palette");
    return "Fall";
}

FallPalette::~FallPalette()
{
    delete (deepRedRgb);
    delete (yellowRgb);
    delete (pumpkinRgb);
    delete (burntOrangeRgb);
    delete (deepOrangeRgb);
    for (int i = 0; i < GetPaletteListLength(); i++)
    {
        delete[] paletteList[i];
    }
    delete[] paletteList;
}