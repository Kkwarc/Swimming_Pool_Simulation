#ifndef simualtion_h
#define simualtion_h

#include "client.h"
#include "da_Pool.h"
#include "atractions.h"
#include "Lifeguard.h"
#include "Instructor.h"
#include <vector>
#include <iostream>
#include <sstream>

class Simulation {
public:
    std::vector < Client > list_of_clients;
    std::vector < Track > list_of_tracks;
    std::vector < Atraction > list_of_atractions;
    std::vector < Lifeguard > list_of_lifeguards;
    std::vector < Instructor > list_of_instructors;
    int n_of_c; // ilosc klientow
    int n_of_t; // ilosc torow
    int n_of_a; // ilosc atrakcji
    int n_of_i; // ilosc instruktorow
    int n_of_l; // ilosc ratownikow
    Time start_time; // godzina otwarcia
    Time closing_time; // godzina zamkniecia
    void create_pool();
    void summary_of_day();
};
#endif