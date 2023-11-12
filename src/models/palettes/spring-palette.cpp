#include "../palette.h"
#include "../../helpers/hex-to-rgb.h"

class SpringPalette : Palette
{
    int *pinkRgb;
    int *yellowRgb;
    int *greenRgb;
    int *blueRgb;
    int *purpleRgb;

    // https://coolors.co/palette/ff99c8-fcf6bd-d0f4de-a9def9-e4c1f9
    enum SpringPaletteEnum
    {
        PINK = 0xFF99C8,
        YELLOW = 0xFCF6BD,
        GREEN = 0xD0F4DE,
        BLUE = 0xA9DEF9,
        PURPLE = 0xE4C1F9,
    };

    void Run()
    {
        pinkRgb = ConvertHexToRGBArray(SpringPaletteEnum::PINK);
        yellowRgb = ConvertHexToRGBArray(SpringPaletteEnum::YELLOW);
        greenRgb = ConvertHexToRGBArray(SpringPaletteEnum::GREEN);
        blueRgb = ConvertHexToRGBArray(SpringPaletteEnum::BLUE);
        purpleRgb = ConvertHexToRGBArray(SpringPaletteEnum::PURPLE);

        return;
    }

    ~SpringPalette()
    {
        delete (pinkRgb);
        delete (yellowRgb);
        delete (greenRgb);
        delete (blueRgb);
        delete (purpleRgb);
    }
};