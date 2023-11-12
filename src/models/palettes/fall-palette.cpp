#include "../palette.h"
#include "../../helpers/hex-to-rgb.h"

class FallPalette : public Palette
{
public:
    HexToRgb hexToRgb;

    int *deepRedRgb;
    int *yellowRgb;
    int *pumpkinRgb;
    int *burntOrangeRgb;
    int *deepOrangeRgb;

    // https://coolors.co/palette/780116-f7b538-db7c26-d8572a-c32f27
    enum FallPaletteEnum
    {
        DEEP_RED = 0x780116,
        YELLOW = 0xF7B538,
        PUMPKIN = 0xDB7C26,
        BURNT_ORANGE = 0xD8572A,
        DEEP_ORANGE = 0xC32F27,
    };

    FallPalette() {}
    // FallPalette &operator=(const Palette &other) override;

    void Run()
    {
        deepRedRgb = hexToRgb.ConvertHexToRGBArray(FallPaletteEnum::DEEP_RED);
        yellowRgb = hexToRgb.ConvertHexToRGBArray(FallPaletteEnum::YELLOW);
        pumpkinRgb = hexToRgb.ConvertHexToRGBArray(FallPaletteEnum::PUMPKIN);
        burntOrangeRgb = hexToRgb.ConvertHexToRGBArray(FallPaletteEnum::BURNT_ORANGE);
        deepOrangeRgb = hexToRgb.ConvertHexToRGBArray(FallPaletteEnum::DEEP_ORANGE);

        return;
    }

    ~FallPalette()
    {
        delete (deepRedRgb);
        delete (yellowRgb);
        delete (pumpkinRgb);
        delete (burntOrangeRgb);
        delete (deepOrangeRgb);
    }
};