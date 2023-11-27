#include "./palette.h"
#include <Arduino.h>

Palette::Palette()
{
    Serial.println("Palette Constructor Start");
    paletteList = new int *[5];
    paletteList[0] = new int[3]{222, 231, 111}; // hexToRgb.ConvertHexToRGBArray(0x780116);
    paletteList[1] = new int[3]{231, 222, 111}; // hexToRgb.ConvertHexToRGBArray(0xF7B538);
    paletteList[2] = new int[3]{111, 231, 111}; // hexToRgb.ConvertHexToRGBArray(0xDB7C26);
    paletteList[3] = new int[3]{222, 231, 111}; // hexToRgb.ConvertHexToRGBArray(0xD8572A);
    paletteList[4] = new int[3]{222, 111, 111}; // hexToRgb.ConvertHexToRGBArray(0xC32F27);
    Serial.println("Palette Constructor End");
    return;
}

int **Palette::GetPaletteList()
{
    return paletteList;
}

int Palette::GetPaletteListLength() {
    return 5;
}

const char *Palette::CheckPalette()
{
    Serial.println("Default Palette");
    return "default";
}

// void Palette::CheckPaletteListRgb()
// {
//     int len = sizeof(paletteList);
//     for (int i = 0; i < len; i++)
//     {
//         Serial.print("Rgb(");
//         Serial.print(paletteList[i][0]);
//         Serial.print(", ");
//         Serial.print(paletteList[i][1]);
//         Serial.print(", ");
//         Serial.print(paletteList[i][2]);
//         Serial.println(")");
//     }
// }

Palette::~Palette()
{
    for (int i = 0; i < sizeof(paletteList); ++i)
    {
        delete[] paletteList[i];
    }
    delete[] paletteList;
}