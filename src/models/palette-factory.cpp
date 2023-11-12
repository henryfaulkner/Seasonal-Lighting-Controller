#include "palette-factory.h"
#include "RTClib.h"

RTC_DS1307 RTC;
Palette defaultPalette;

PaletteFactory::PaletteFactory() {}

Palette PaletteFactory::ConstructSeasonalPalette()
{
    DateTime now = RTC.now();

    if (IsSpring(now))
    {
    }
    else if (IsFall(now))
    {
    }

    return defaultPalette;
}

bool PaletteFactory::IsSpring(DateTime datetime)
{

    return false;
}

bool PaletteFactory::IsFall(DateTime datetime)
{

    return false;
}