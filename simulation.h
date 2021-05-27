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
    // std::vector < Atraction > list_of_atractions;
    std::vector < Lifeguard > list_of_lifeguards;
    std::vector < Instructor > list_of_instructors;
    int begginer_tr; // ilosc dla beginerow
    int intermeddiate_tr; // ilosc dla srednich
    int advanced_tr; // ilosc dla zaawansowanych
    int n_of_t = begginer_tr + intermeddiate_tr + advanced_tr; // ilosc torow
    int n_of_a; // ilosc atrakcji
    int max_ppl; // maksymalna ilosc ludzi
    int n_of_c; // ilosc klientow
    int n_of_i; // ilosc instruktorow
    int n_of_l; // ilosc ratownikow
    int length; // dlugosc toru
    int tr_limit; // ilosc ludzi na tor
    Time start_time; // godzina otwarcia
    Time closing_time; // godzina zamkniecia
    void create_pool(); // inicjator poola
    void summary_of_day(); // podsumowanie dnia
};
#endif