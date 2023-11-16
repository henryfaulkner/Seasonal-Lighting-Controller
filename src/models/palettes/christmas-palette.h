#include "../palette.h"

#ifndef CHRISTMAS_PALETTE_H
#define CHRISTMAS_PALETTE_H

class ChristmasPalette : public Palette
{
public:
    HexToRgb hexToRgb;
    int *deepRedRgb;
    int *dullRedRgb;
    int *deepGreenRgb;
    int *dullGreenRgb;
    int *snowWhiteRgb;

    ChristmasPalette();
    void Run();
    const char *CheckPalette();
    ~ChristmasPalette();
};

#endif // CHRISTMAS_PALETTE_H