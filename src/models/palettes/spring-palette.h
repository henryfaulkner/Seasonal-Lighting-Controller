#include "../palette.h"

#ifndef SPRING_PALETTE_H
#define SPRING_PALETTE_H

class SpringPalette : public Palette
{
public:
    HexToRgb hexToRgb;
    int *pinkRgb;
    int *yellowRgb;
    int *greenRgb;
    int *blueRgb;
    int *purpleRgb;

    SpringPalette();
    void Run();
    const char *CheckPalette();
    ~SpringPalette();
};

#endif // SPRING_PALETTE_H