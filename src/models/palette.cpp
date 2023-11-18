#include "./palette.h"
#include <Arduino.h>

Palette::Palette()
{
    paletteList = new int *[5];
    paletteList[0] = new int[3]{222, 231, 111}; // hexToRgb.ConvertHexToRGBArray(0x780116);
    paletteList[1] = new int[3]{231, 222, 111}; // hexToRgb.ConvertHexToRGBArray(0xF7B538);
    paletteList[2] = new int[3]{111, 231, 111}; // hexToRgb.ConvertHexToRGBArray(0xDB7C26);
    paletteList[3] = new int[3]{222, 231, 111}; // hexToRgb.ConvertHexToRGBArray(0xD8572A);
    paletteList[4] = new int[3]{222, 111, 111}; // hexToRgb.ConvertHexToRGBArray(0xC32F27);
    return;
}

const char *Palette::CheckPalette()
{
    Serial.println("Default Palette");
    return "default";
}

Palette::~Palette()
{
    for (int i = 0; i < sizeof(paletteList); ++i)
    {
        delete[] paletteList[i];
    }
    delete[] paletteList;
}