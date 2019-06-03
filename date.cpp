#include "date.h"

Date::Date()
{
    time_t t;
    time (&t);

    tm local = * localtime (& t);

    tm_year = local.tm_year;
    tm_mon = local.tm_mon;
    tm_mday = local.tm_mday;
    tm_hour = local.tm_hour;
    tm_min = local.tm_min;
    tm_sec = local.tm_sec;

    tm_year += 1900;
    tm_mon += 1;
}

unsigned Date::getYear() const
{
    return tm_year;
}

unsigned Date::getMonth() const
{
    return tm_mon;
}

unsigned Date::getDay() const
{
    return tm_mday;
}

unsigned Date::getHour() const
{
    return tm_hour;
}

unsigned Date::getMinute() const
{
    return tm_min;
}

unsigned Date::getSecond() const
{
    return tm_sec;
}
