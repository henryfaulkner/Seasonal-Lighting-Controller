#include "../palette.h"

#ifndef FALL_PALETTE_H
#define FALL_PALETTE_H

class FallPalette : public Palette
{
public:
    int **paletteList;
    HexToRgb hexToRgb;
    int *deepRedRgb;
    int *yellowRgb;
    int *pumpkinRgb;
    int *burntOrangeRgb;
    int *deepOrangeRgb;

    FallPalette();
    const char *CheckPalette() override;
    ~FallPalette();
};

#endif // FALL_PALETTE_H