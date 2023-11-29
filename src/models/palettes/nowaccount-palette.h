#ifndef NOWACCCOUNT_PALETTE_H
#define NOWACCOUNT_PALEETTE_H

#include "../palette.h"

class NowAccountPalette : public Palette
{
public:
    int **paletteList;
    HexToRgb hexToRgb;
    int *primaryGreenRgb;
    int *secondaryGreenRgb;
    int *orangeRgb;
    int *softWhiteRgb;

    NowAccountPalette();
    int **GetPaletteList() override;
    int GetPaletteListLength() override;
    const char *CheckPalette() override;
    void CheckPaletteListRgb();
    ~NowAccountPalette();
};

#endif NOWACCOUNT_PALETTE_H