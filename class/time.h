#ifndef Time_H
#define Time_H

struct Time
{
    int hour;
    int minutes;
    Time operator+(int min)
    {
        minutes = minutes + min % 60;
        hour = hour + min / 60;
        return*this;
    }
    bool operator== (Time& tim)
    {
        if (hour == tim.hour && minutes == tim.minutes)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif
