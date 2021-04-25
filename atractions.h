#ifndef ATRACTIONS_H
#define ATRACTIONS_H

#include <iostream>
#include <list>
#include<vector>

class Lifeguard
{
    public:
    Lifeguard();
    bool operator==(Lifeguard other_lifguard);
};

class Client
{
    public:
    int get_card_id();
};


class Atraction
{
    int atraction_nr;
    int people_limit;
    std::vector<Client> people;
    Lifeguard lifeguard;
public:
    Atraction();
    Atraction(int atraction_nr, int people_limit, std::vector<Client> people, Lifeguard lifeguard);
    Atraction(Atraction& other_atracction);
    std::string set_atraction_nr(int new_atraction_nr);
    int get_atraction_nr() const;
    std::string set_people_limit(int new_people_limit);
    int get_people_limit() const;
    std::string set_lifeguard(Lifeguard new_lifeguard);
    Lifeguard get_lifeguard() const;
    std::string set_people(std::vector<Client> new_people);
    const std::vector<Client> get_people() const;
    bool operator==(Atraction atraction2);
    bool operator!=(Atraction atraction2);
    void operator<<(Client& person);
    Atraction operator=(Atraction& atraction2);
    int search_list(int card_id);
    std::string remove_person(int card_id);
    std::string add_person(Client person);
};
#endif