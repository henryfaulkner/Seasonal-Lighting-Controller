#include "./fall-palette.h"
#include "../../helpers/hex-to-rgb.h"

FallPalette::FallPalette() {}

void FallPalette::Run()
{
    // https://coolors.co/palette/780116-f7b538-db7c26-d8572a-c32f27
    deepRedRgb = hexToRgb.ConvertHexToRGBArray(0x780116);
    yellowRgb = hexToRgb.ConvertHexToRGBArray(0xF7B538);
    pumpkinRgb = hexToRgb.ConvertHexToRGBArray(0xDB7C26);
    burntOrangeRgb = hexToRgb.ConvertHexToRGBArray(0xD8572A);
    deepOrangeRgb = hexToRgb.ConvertHexToRGBArray(0xC32F27);

    return;
}

const char *FallPalette::CheckPalette()
{
    return "Fall";
}

FallPalette::~FallPalette()
{
    delete (deepRedRgb);
    delete (yellowRgb);
    delete (pumpkinRgb);
    delete (burntOrangeRgb);
    delete (deepOrangeRgb);
}