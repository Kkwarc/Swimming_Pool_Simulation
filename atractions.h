#ifndef ATRACTIONS_H
#define ATRACTIONS_H

#include <iostream>
#include <list>
#include<vector>
#include "Lifeguard.h"
#include "Instructor.h"
#include "client.h"


// poziom




class Atraction
{
protected:
    std::string name;
    int atraction_nr;
    int people_limit;
    std::vector<Client> people;
    Lifeguard lifeguard; // wsadzic do wektora - moze
public:
    friend class Da_Pool;

    Atraction();
    Atraction(
        std::string nam,
        int atraction_nr,
        int people_limit
    );
    Atraction(const Atraction& other_atracction)
    {
        name = other_atracction.name;
        atraction_nr = other_atracction.atraction_nr;
        people_limit = other_atracction.people_limit;
        people = other_atracction.people;
        lifeguard = other_atracction.lifeguard;
    }
    std::string set_atraction_nr(int new_atraction_nr);
    std::string set_people_limit(int new_people_limit);
    std::string set_lifeguard(Lifeguard& new_lifeguard);
    std::string set_people(std::vector<Client> new_people);
    Atraction operator=(Atraction atraction2);
    int search_list(int card_id);
    virtual void remove_person(int card_id);
    virtual void add_person(Client& person);
};

class Track : public Atraction
{
protected:
    int depth;
    int length;
    int track_nr;
    Instructor instructor;
    bool reserved;
    int reservation_time;
public:

    friend class Swimming_Pool;

    Track();
    Track(int dpth, int lng, int tr_nr, int ppl_lim, int atraction_nr);

    Track(Track& another_track)
    {
        depth = another_track.depth;
        length = another_track.length;
        track_nr = another_track.track_nr;
        instructor = another_track.instructor;
        reserved = another_track.reserved;
        name = another_track.name;
        atraction_nr = another_track.atraction_nr;
        people_limit = another_track.people_limit;
        people = another_track.people;
        lifeguard = another_track.lifeguard;
    }
    bool is_reserved();
    int current_ppl();
    void reserve_track(Instructor& inst, std::vector<Client> group, int res_time);
    void add_person(Client& person);
};

class Swimming_Pool : public Atraction
{
    int tr_nr;
    int length;
    std::vector<Track> tracks;
public:
    Swimming_Pool();
    Swimming_Pool(
        int atraction_nr,
        int length,
        int tr_limit,
        int begginer_tr = 0,
        int intermeddiate_tr = 0,
        int advanced_tr = 0
    );
    void reserve_track(int track_nr, Instructor& inst, std::vector<Client> group, int res_time);
    void change_track(Client& cl, int tr1_nr, int tr2_nr);
    void add_person(int tr_nr, Client& clnt);
    void remove_person(int car_id);
};
#endif
