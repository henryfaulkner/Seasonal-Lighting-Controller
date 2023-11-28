#include "palette-factory.h"
#include "RTClib.h"
#include "../helpers/date-helper.h"
#include "./palettes/spring-palette.h"
#include "./palettes/fall-palette.h"
#include "./palettes/christmas-palette.h"
#include <Arduino.h>

DateHelper dateHelper;

PaletteFactory::PaletteFactory() {}

Palette *PaletteFactory::ConstructSeasonalPalette(DateTime now)
{
    Serial.println("month");
    Serial.println(now.month());
    Serial.println("day");
    Serial.println(now.day());
    Serial.println("hour");
    Serial.println(now.hour());
    Serial.println("minute");
    Serial.println(now.minute());

    Palette *result = nullptr;
    if (IsSpring(now))
    {
        Serial.println("IsSpring");
        result = new SpringPalette();
    }
    else if (IsFall(now))
    {
        Serial.println("IsFall");
        result = new ChristmasPalette();
    }
    else if (IsChristmas(now))
    {
        Serial.println("IsChristmas");
        result = new ChristmasPalette();
    }
    else
    {
        Serial.println("IsDefault");
        result = new Palette();
    }

    result->CheckPalette();
    return result;
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