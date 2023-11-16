#include "./spring-palette.h"
#include "../../helpers/hex-to-rgb.h"

SpringPalette::SpringPalette() {}

void SpringPalette::Run()
{
    // https://coolors.co/palette/ff99c8-fcf6bd-d0f4de-a9def9-e4c1f9
    pinkRgb = hexToRgb.ConvertHexToRGBArray(0xFF99C8);
    yellowRgb = hexToRgb.ConvertHexToRGBArray(0xFCF6BD);
    greenRgb = hexToRgb.ConvertHexToRGBArray(0xD0F4DE);
    blueRgb = hexToRgb.ConvertHexToRGBArray(0xA9DEF9);
    purpleRgb = hexToRgb.ConvertHexToRGBArray(0xE4C1F9);

    return;
}

const char *SpringPalette::CheckPalette()
{
    return "Spring";
}

SpringPalette::~SpringPalette()
{
    delete (pinkRgb);
    delete (yellowRgb);
    delete (greenRgb);
    delete (blueRgb);
    delete (purpleRgb);
}