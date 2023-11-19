#include "../helpers/hex-to-rgb.h"

#ifndef PALETTE_H
#define PALETTE_H

class Palette
{
public:
    Palette();
    int **paletteList;
    virtual int **GetPaletteList();
    virtual const char *CheckPalette();
    ~Palette();
};

#endif // PALETTE_H