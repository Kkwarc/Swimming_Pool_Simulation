#ifndef lifeguard_h
#define lifeguard_h

#include <iostream>
#include <vector>
#include <sstream>
#include "time.h"

class Lifeguard
{
protected:
    std::string name, surname;
    int work_id, experience;
    Time start, finish;

public:

    friend class Atraction;

    Lifeguard();

    Lifeguard(
        std::string na,
        std::string sur,
        int wid,
        int ex,
        Time start,
        Time finish);
    Lifeguard(const Lifeguard& L)
    {
        name = L.name;
        surname = L.surname;
        work_id = L.work_id;
        experience = L.experience;
        start = L.start;
        finish = L.finish;
    }
    std::string get_name();
    std::string get_surname();
    int get_work_id();
    int get_experience();
    Time get_starting_time();
    Time get_finish_time();

    friend std::ostream& operator << (std::ostream& output, Lifeguard& l);

    bool operator == (Lifeguard& l1);

    bool operator != (Lifeguard& l1);

    Lifeguard operator=(Lifeguard l);
};
#endif
