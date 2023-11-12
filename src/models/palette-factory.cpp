#include "palette-factory.h"
#include "RTClib.h"
#include "./palettes/spring-palette.cpp"
#include "./palettes/fall-palette.cpp"

RTC_DS1307 RTC;
Palette palette;

PaletteFactory::PaletteFactory() {}

Palette PaletteFactory::ConstructSeasonalPalette()
{
    DateTime now = RTC.now();

    if (IsSpring(now))
    {
        SpringPalette springPalette;
        palette = springPalette;
    }
    else if (IsFall(now))
    {
        FallPalette fallPalette;
        palette = fallPalette;
    }

    return palette;
}

bool PaletteFactory::IsSpring(DateTime datetime)
{

    return false;
}

bool PaletteFactory::IsFall(DateTime datetime)
{

    return false;
}