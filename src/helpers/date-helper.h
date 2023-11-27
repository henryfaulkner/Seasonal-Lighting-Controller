#ifndef DATE_HELPER_H
#define DATE_HELPER_H

class DateHelper
{
public:
    bool ContainsDates(DateTime datetime, int startMonth, int startDay, int endMonth, int endDay)
    {
        int currentMonth = datetime.month();
        int currentDay = datetime.day();
        if (currentMonth > startMonth && datetime.month() < endMonth)
            return true;
        if (currentMonth == startMonth && currentDay >= startDay && currentDay < endDay)
            return true;
        return false;
    }
};

#endif // DATE_HELPER_H