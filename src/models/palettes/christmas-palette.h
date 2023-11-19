#include "../palette.h"

#ifndef CHRISTMAS_PALETTE_H
#define CHRISTMAS_PALETTE_H

class ChristmasPalette : public Palette
{
public:
    int **paletteList;
    HexToRgb hexToRgb;
    int *deepRedRgb;
    int *dullRedRgb;
    int *deepGreenRgb;
    int *dullGreenRgb;
    int *snowWhiteRgb;

    ChristmasPalette();
    int **GetPaletteList() override;
    const char *CheckPalette() override;
    ~ChristmasPalette();
};

#endif // CHRISTMAS_PALETTE_H