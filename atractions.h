#ifndef ATRACTIONS_H
#define ATRACTIONS_H

#include <iostream>
#include <list>
#include<vector>
#include "Lifeguard.h"
#include "Instructor.h"
#include "client.h"

class Atraction
{
    std::string name;
    int atraction_nr;
    int people_limit;
    std::vector<Client> people;
    Lifeguard lifeguard;
public:
    Atraction();
    Atraction(std::string nam, int atraction_nr, int people_limit, std::vector<Client> people, Lifeguard lifeguard);
    Atraction(Atraction& other_atracction);
    std::string set_atraction_nr(int new_atraction_nr);
    int get_atraction_nr() const;
    std::string set_people_limit(int new_people_limit);
    int get_people_limit() const;
    std::string set_lifeguard(Lifeguard new_lifeguard);
    Lifeguard get_lifeguard() const;
    std::string set_people(std::vector<Client> new_people);
    const std::vector<Client> get_people() const;
    void operator<<(Client& person);
    Atraction operator=(Atraction& atraction2);
    int search_list(int card_id);
    std::string remove_person(int card_id);
    std::string add_person(Client person);
};

class Track: public Atraction
{
    int depth;
    int length;
    int track_nr;
    Instructor instructor;
    bool reserved;
public:
    Track();
    Track(int dpth, int lng, int tr_nr, int ppl_lim);
    Track(Track& another_track);
    bool is_reserved();
    int current_ppl();
    void reserve_track(Instructor inst, std::vector<Client> group);

};

class Swimming_Pool: public Atraction
{
    int tr_nr;
    int length;
    std::vector<Lifeguard> lifeguards;
    std::vector<Track> tracks;
public:
    Swimming_Pool();
    Swimming_Pool(int tr_nr, int length, int tr_limit, int begginer_tr=0, int intermeddiate_tr=0, int advanced_tr=0);
    void reserve_track(Track& track, Instructor& inst, std::vector<Client> group);
    void change_track(Client& cl, int tr1_nr, int tr2_nr);
    int min_ppl_tr();
    void add_to_track(int tr_nr, Client& clnt);
    void exit_pool(Client& clnt);
};

struct Time
{
    int hour;
    int minutes;
};

class Da_Pool
{
    std::vector<Atraction> atractions;
    int max_ppl;
    int attr_nr;
    std::vector<Lifeguard> staff_available;
    std::vector<Client> clients;
    Time start_time;
    Time closing_time;
    Time* reservations;
    int reservations_nr;
public:
    Da_Pool();
    Da_Pool(Time st_time, Time cl_time, int max_ppl, int attr_nr, std::vector<Atraction> atractions);
    void add_client(Client& client, Atraction& atr, int time);
    void change_atr(Client& client, Atraction& atr1, Atraction& atr2);
    void exit_da_pool(Client& client);
    void staff_come(Lifeguard& staff);
    void staff_exit(Lifeguard& staff);
    void assign_lifeguard(Lifeguard& lif, Atraction& atr);
    void reservation(std::string difficulty, Time start, Time stop, Instructor& inst);
};

#endif