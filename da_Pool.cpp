#include "da_Pool.h"
#include "client.h"
#include "Lifeguard.h"
#include "Instructor.h"
#include "time.h"
#include "atractions.h"

using namespace std;


Da_Pool::Da_Pool()
{
    name = "";
    max_ppl = 0;
    atractions = {};
    staff_available = {};
    clients = {};
    start_time = {0, 0};
    closing_time = {0,0};
}

Da_Pool::Da_Pool(
    string name,
    std::vector<Atraction> atractions,
    Time start_time,
    Time closing_time
    )
{
    name = name;
    atractions = atractions;
    start_time = start_time;
    closing_time = closing_time;
}

void Da_Pool::add_client(Client& client, int atraction_nr, int time)
{
    int index;
    client.set_time(time);
    clients.push_back(client);
    for(long long unsigned int i=0; i < atractions.size(); i++)
    {
        if(atractions[i].atraction_nr == atraction_nr)
        {
            index =i;
            break;
        }
    }
    atractions[index].add_person(client);
}

void Da_Pool::change_atr(Client& client, int atraction_nr1, int atraction_nr2)
{
    int index1;
    int index2;
    for(long long unsigned int i=0; i < atractions.size(); i++)
    {
        if(atractions[i].atraction_nr == atraction_nr1)
        {
            index1 =i;
            break;
        }
    }
    for(long long unsigned int i=0; i < atractions.size(); i++)
    {
        if(atractions[i].atraction_nr == atraction_nr2)
        {
            index2 =i;
            break;
        }
    }
    atractions[index1].remove_person(client.carnet_id);
    atractions[index2].add_person(client);
}

void Da_Pool::exit_da_pool(Client& client)
{
    // nie wiem
}

void Da_Pool::staff_come(Lifeguard& staff)
{
    staff_available.push_back(staff);
}

void Da_Pool::staff_exit(Lifeguard& staff)
{
    int index;
    for(long long unsigned int i=0; i < staff_available.size(); i++)
    {
        if(staff_available[i] == staff)
        {
            index =i;
            break;
        }
    }
    staff_available.erase(staff_available.begin()+index);
}

void Da_Pool::assign_lifeguard(Lifeguard& lif, int atraction_nr)
{
    int index1;
    for(long long unsigned int i=0; i < atractions.size(); i++)
    {
        if(atractions[i].atraction_nr == atraction_nr)
        {
            index1 =i;
            break;
        }
    }
    atractions[index1].set_lifeguard(lif);
}

void Da_Pool::reservation(std::string difficulty, Time start, int duration, Instructor& inst)
{
;
}

void the_time_is_passing(int tick)
{
    cout << "Jebac proi" << endl;
}