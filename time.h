#ifndef Time_H
#define Time_H

struct Time
{
    int hour;
    int minutes;
    Time operator+(int min)
    {
        minutes = minutes + min%60;
        hour = hour + min/60;
        return* this;
    }
};

#endif