#include "../palette.h"

#ifndef SPRING_PALETTE_H
#define SPRING_PALETTE_H

class SpringPalette : public Palette
{
public:
    int **paletteList;
    HexToRgb hexToRgb;
    int *pinkRgb;
    int *yellowRgb;
    int *greenRgb;
    int *blueRgb;
    int *purpleRgb;

    SpringPalette();
    const char *CheckPalette() override;
    ~SpringPalette();
};

#endif // SPRING_PALETTE_H