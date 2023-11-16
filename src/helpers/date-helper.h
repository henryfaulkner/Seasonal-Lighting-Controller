#include "RTClib.h"

#ifndef DATE_HELPER_H
#define DATE_HELPER_H

class DateHelper
{
public:
    bool ContainsDates(DateTime datetime, int startMonth, int startDay, int endMonth, int endDay)
    {
        return datetime.month() >= startMonth && datetime.day() >= startDay && datetime.month() < endMonth && datetime.day() < endDay;
    }
};

#endif // DATE_HELPER_H