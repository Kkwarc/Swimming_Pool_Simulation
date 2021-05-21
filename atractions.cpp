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
    lifeguard=Lifeguard();
}

Atraction::Atraction(string nam, int atr_nr, int ppl_limit, std::vector<Client> ppl, Lifeguard lfguard)
{
    name = nam;
    atraction_nr=atr_nr;
    people_limit=ppl_limit;
    people=ppl;
    lifeguard=lfguard;
}

Atraction::Atraction(Atraction& other_atracction)
{
    atraction_nr=other_atracction.get_atraction_nr();
    people_limit=other_atracction.get_people_limit();
    people=other_atracction.get_people();
    lifeguard=other_atracction.get_lifeguard();
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

int Atraction::get_atraction_nr() const
{
    return atraction_nr;
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

int Atraction::get_people_limit() const
{
    return people_limit;
}

string Atraction::set_lifeguard(Lifeguard new_lifeguard)
{
    lifeguard = new_lifeguard;
    return "ustawiono ratownika";
}

Lifeguard Atraction::get_lifeguard() const
{
    return lifeguard;
}

string Atraction::set_people(std::vector<Client> new_people)
{
    people = new_people;
    return "ustawiono klientow";
}

const std::vector<Client> Atraction::get_people() const
{
    return people;
}

void Atraction::operator<<(Client& person)
{
    people.push_back(person);
}

Atraction Atraction::operator=(Atraction& atraction2)
{
    atraction_nr=atraction2.get_atraction_nr();
    people_limit=atraction2.get_people_limit();
    people=atraction2.get_people();
    lifeguard=atraction2.get_lifeguard();
    return *this;
}

int Atraction::search_list(int card_id)
{
    int index;
        for (long long unsigned int i = 0; i < people.size(); ++i)
        {
            if(people[i].get_card_id() == card_id)
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

string Atraction::add_person(Client person)
{
    people.push_back(person);
    return "dodano osobe";
}