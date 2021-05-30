#include <iostream>
#include<vector>
#include"atractions.h"
#include "Instructor.h"
#include "Lifeguard.h"

Track::Track() : Atraction()
{
    depth = 0;
    length = 0;
    track_nr = -1;
    reserved = false;
}

Track::Track(
    int dpth,
    int lng,
    int tr_nr,
    int ppl_lim,
    int atraction_nr
) :Atraction("track", atraction_nr, ppl_lim)
{
    depth = dpth;
    length = lng;
    track_nr = tr_nr;
    reserved = false;
}

bool Track::is_reserved()
{
    return reserved;
}

int Track::current_ppl()
{
    return people.size();
}

void Track::reserve_track(Instructor& inst, std::vector<Client> group, int res_time)
{
    for(long long unsigned int i=0; i<group.size(); i++)
    {
        group[i].did_reserve = true;
    }
    instructor = inst;
    people = group;
    reserved = true;
    reservation_time = res_time;
}

void Track::add_person(Client& person)
{
    if (is_reserved() == false && (int)people.size() < people_limit)
    {
        people.push_back(person);
    }
    else
    {
        throw;
    }
}