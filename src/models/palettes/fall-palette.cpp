#include "./fall-palette.h"
#include "../../helpers/hex-to-rgb.h"
#include <Arduino.h>

FallPalette::FallPalette()
{
    Serial.println("FallPalette Constructor Start");
    // https://coolors.co/palette/780116-f7b538-db7c26-d8572a-c32f27
    deepRedRgb = new int[222, 231, 111];     // hexToRgb.ConvertHexToRGBArray(0x780116);
    yellowRgb = new int[222, 231, 111];      // hexToRgb.ConvertHexToRGBArray(0xF7B538);
    pumpkinRgb = new int[222, 231, 111];     // hexToRgb.ConvertHexToRGBArray(0xDB7C26);
    burntOrangeRgb = new int[222, 231, 111]; // hexToRgb.ConvertHexToRGBArray(0xD8572A);
    deepOrangeRgb = new int[222, 231, 111];  // hexToRgb.ConvertHexToRGBArray(0xC32F27);
    paletteList = new int *[5];
    paletteList[0] = deepRedRgb;
    paletteList[1] = yellowRgb;
    paletteList[2] = pumpkinRgb;
    paletteList[3] = burntOrangeRgb;
    paletteList[4] = deepOrangeRgb;
    Serial.println("FallPalette Constructor End");
    return;
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
    for (int i = 0; i < sizeof(paletteList); ++i)
    {
        delete[] paletteList[i];
    }
    delete[] paletteList;
}