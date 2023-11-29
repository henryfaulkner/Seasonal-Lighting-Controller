#include "./nowaccount-palette.h"
#include "../../helpers/hex-to-rgb.h"
#include <Arduino.h>

NowAccountPalette::NowAccountPalette()
{
    Serial.println("NowAccountPalette Constructor Start");
    primaryGreenRgb = hexToRgb.ConvertHexToRGBArray(0x244538);
    secondaryGreenRgb = hexToRgb.ConvertHexToRGBArray(0xC1D2C7);
    orangeRgb = hexToRgb.ConvertHexToRGBArray(0xFF8700);
    softWhiteRgb = hexToRgb.ConvertHexToRGBArray(0xEBEBEB);
    paletteList = new int *[GetPaletteListLength()];
    paletteList[0] = primaryGreenRgb;
    paletteList[1] = secondaryGreenRgb;
    paletteList[2] = orangeRgb;
    paletteList[3] = softWhiteRgb;
    Serial.println("NowAccountPalette Constructor End");

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

int **NowAccountPalette::GetPaletteList()
{
    return paletteList;
}

int NowAccountPalette::GetPaletteListLength()
{
    return 4;
}

const char *NowAccountPalette::CheckPalette()
{
    Serial.println("Christmas Palette");
    return "Christmas";
}

void NowAccountPalette::CheckPaletteListRgb()
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

NowAccountPalette::~NowAccountPalette()
{
    delete (primaryGreenRgb);
    delete (secondaryGreenRgb);
    delete (orangeRgb);
    delete (softWhiteRgb);
    for (int i = 0; i < GetPaletteListLength(); i++)
    {
        delete[] paletteList[i];
    }
    delete[] paletteList;
}