#include "../palette.h"
#include "../../helpers/hex-to-rgb.h"

class SpringPalette : public Palette
{
public:
    HexToRgb hexToRgb;

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

    SpringPalette() {}
    // SpringPalette &operator=(const Palette &other) override;

    void Run()
    {
        pinkRgb = hexToRgb.ConvertHexToRGBArray(SpringPaletteEnum::PINK);
        yellowRgb = hexToRgb.ConvertHexToRGBArray(SpringPaletteEnum::YELLOW);
        greenRgb = hexToRgb.ConvertHexToRGBArray(SpringPaletteEnum::GREEN);
        blueRgb = hexToRgb.ConvertHexToRGBArray(SpringPaletteEnum::BLUE);
        purpleRgb = hexToRgb.ConvertHexToRGBArray(SpringPaletteEnum::PURPLE);

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