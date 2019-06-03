#ifndef DATE_H
#define DATE_H

#include <ctime>

class Date : public tm
{
public:
    Date();

    unsigned getYear() const;
    unsigned getMonth() const;
    unsigned getDay() const;
    unsigned getHour() const;
    unsigned getMinute() const;
    unsigned getSecond() const;
};

#endif // DATE_H
