#include "palette.h"
#include "RTClib.h"

#ifndef PALETTE_FACTORY_H
#define PALETTE_FACTORY_H

class PaletteFactory
{
public:
    PaletteFactory();
    Palette *ConstructSeasonalPalette();
    bool IsSpring(DateTime now);
    bool IsFall(DateTime now);
    bool IsWinter(DateTime now);
    bool IsChristmas(DateTime now);
    bool IsFourthOfJuly(DateTime now);
    bool IsSaintPatricksDay(DateTime now);
    bool IsHalloween(DateTime now);
    bool IsRasta(DateTime now);
    ~PaletteFactory();
};

#endif // PALETTE_FACTORY_H
