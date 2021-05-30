#ifndef Da_Pool_H
#define Da_Pool_H

// lista wyszukiwania ludzi na atrakcji
#include <iostream>
#include <list>
#include<vector>
#include "client.h"
#include "Lifeguard.h"
#include "Instructor.h"
#include "time.h"
#include "atractions.h"

// rachunek
// bilety tylko godzinowe - stala cena z dodatkiem na ewentualna ulge
// odnosniki do klienta po id
// aktualna godzina

class Da_Pool
{
    friend class Simulation;
    std::string name;
    int max_ppl; // to tzreba jakos przeliczyc
    int attr_nr; // ilosc atrkcji
    std::vector<Atraction> atractions; // swiming pool
    std::vector<Lifeguard> staff_available;
    std::vector<Client> clients;
    Time start_time;
    Time closing_time;
    Time current_time;
public:
    Da_Pool();
    Da_Pool(
        std::string name,
        std::vector<Atraction> atractions,
        Time start_time,
        Time closing_timev
    );
    void add_client(Client& client, int atraction_nr, int time);
    void add_client(Client& client, int atraction_nr, int tr_number, int time);
    void change_atr(Client& client, int atraction_nr1, int atraction_nr2); //przejscie z jednego basenu do 2
    void exit_da_pool(Client& client);
    void staff_come(Lifeguard& staff);
    void staff_exit(Lifeguard& staff);
    void assign_lifeguard(Lifeguard& lif, int atraction_nr);
    void reservation(int tr_nr, Time start, int duration, Instructor& inst, std::vector<Client> group); // duration w 60 min -> czas biletu
    bool the_time_is_passing(int tick);
};
#endif
