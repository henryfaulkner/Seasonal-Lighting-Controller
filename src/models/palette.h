#include "../helpers/hex-to-rgb.h"

#ifndef PALETTE_H
#define PALETTE_H

class Palette
{
public:
    Palette();
    int **paletteList;
    virtual int **GetPaletteList();
    virtual int GetPaletteListLength();
    virtual const char *CheckPalette();
    // virtual void CheckPaletteListRgb();
    ~Palette();
};

#endif // PALETTE_H