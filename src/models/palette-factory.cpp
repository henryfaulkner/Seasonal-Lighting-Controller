#include "palette-factory.h"
#include "RTClib.h"
#include "../helpers/date-helper.h"
#include "./palettes/spring-palette.h"
#include "./palettes/fall-palette.h"
#include "./palettes/christmas-palette.h"
#include <Arduino.h>

RTC_DS3231 RTC;
DateHelper dateHelper;

PaletteFactory::PaletteFactory() {}

Palette PaletteFactory::ConstructSeasonalPalette()
{
    if (!RTC.begin())
    {
        Serial.println("Couldn't find RTC");
        while (1)
            ;
    }

    if (RTC.lostPower())
    {
        Serial.println("RTC lost power, let's set the time!");
        RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

    DateTime now = RTC.now();
    Serial.println("month");
    Serial.println(now.month());
    Serial.println("day");
    Serial.println(now.day());

    if (IsSpring(now))
    {
        Serial.println("IsSpring");
        SpringPalette springPalette;
        springPalette.CheckPalette();
        return springPalette;
    }
    else if (IsFall(now))
    {
        Serial.println("IsFall");
        FallPalette fallPalette;
        fallPalette.CheckPalette();
        return fallPalette;
    }
    else if (IsChristmas(now))
    {
        Serial.println("IsChristmas");
        ChristmasPalette christmasPalette;
        christmasPalette.CheckPalette();
        return christmasPalette;
    }

    Palette defaultPalette;
    return defaultPalette;
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

PaletteFactory::~PaletteFactory()
{
}