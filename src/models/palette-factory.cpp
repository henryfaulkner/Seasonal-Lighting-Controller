#include "palette-factory.h"
#include "RTClib.h"
#include "../helpers/date-helper.h"
#include "./palettes/spring-palette.h"
#include "./palettes/fall-palette.h"
#include "./palettes/christmas-palette.h"

RTC_DS1307 RTC;
Palette palette;
DateHelper dateHelper;

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
    else if (IsChristmas(now))
    {
        ChristmasPalette christmasPalette;
        palette = christmasPalette;
    }

    return palette;
}

bool PaletteFactory::IsSpring(DateTime datetime)
{
    int startMonth = 3; // March
    int startDay = 19;
    int endMonth = 6; // June
    int endDay = 20;
    return dateHelper.ContainsDates(datetime, startMonth, startDay, endMonth, endDay);
}

bool PaletteFactory::IsFall(DateTime datetime)
{
    int startMonth = 9; // September
    int startDay = 23;
    int endMonth = 12; // December
    int endDay = 21;
    return dateHelper.ContainsDates(datetime, startMonth, startDay, endMonth, endDay);
}

bool PaletteFactory::IsChristmas(DateTime datetime)
{
    int startMonth = 12; // December
    int startDay = 21;
    int endMonth = 3; // March
    int endDay = 19;
    return dateHelper.ContainsDates(datetime, startMonth, startDay, endMonth, endDay);
}