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
    int GetPaletteListLength() override;
    const char *CheckPalette() override;
    void CheckPaletteListRgb();
    ~ChristmasPalette();
};

#endif // CHRISTMAS_PALETTE_H