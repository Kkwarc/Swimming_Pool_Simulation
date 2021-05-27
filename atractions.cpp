#include <iostream>
#include<vector>
#include"atractions.h"

using namespace std;

Atraction::Atraction()
{
    name = "";
    atraction_nr=0;
    people_limit=0;
    people={};
    Lifeguard t;
    lifeguard=t;
}

Atraction::Atraction
    (
        string nam,
        int atr_nr,
        int ppl_limit
    )
{
    name = nam;
    atraction_nr=atr_nr;
    people_limit=ppl_limit;
}

string Atraction::set_atraction_nr(int new_atraction_nr)
{
    if (new_atraction_nr >= 0)
    {
        atraction_nr = new_atraction_nr;
        return "ustawiono nr atrakcji";
    }
    return "nr atrakcji nie moze być ujemny";
}


string Atraction::set_people_limit(int new_people_limit)
{
    if (new_people_limit >= 0)
    {
        people_limit = new_people_limit;
        return "ustawiono limit ludzi";
    }
    return "limit ludzi nie moze być ujemny";
}


string Atraction::set_lifeguard(Lifeguard& new_lifeguard)
{
    lifeguard = new_lifeguard;
    return "ustawiono ratownika";
}


string Atraction::set_people(std::vector<Client> new_people)
{
    people = new_people;
    return "ustawiono klientow";
}


Atraction Atraction::operator=(Atraction atraction2)
{
    atraction_nr=atraction2.atraction_nr;
    people_limit=atraction2.people_limit;
    people=atraction2.people;
    lifeguard=atraction2.lifeguard;
    return *this;
}

int Atraction::search_list(int card_id)
{
    int index;
        for (long long unsigned int i = 0; i < people.size(); ++i)
        {
            if(people[i].get_carnet_id() == card_id)
            {
                index = i;
                return index;
            }
        }
        index = -1;
        return index;
}

string Atraction::remove_person(int card_id)
{
    int index = search_list(card_id);
    if (index == -1)
    {
        return "Nie ma takiej osoby";
    }
    people.erase(people.begin()+index);
    return "Usunieto osobe";
}

string Atraction::add_person(Client& person)
{
    people.push_back(person);
    return "dodano osobe";
}