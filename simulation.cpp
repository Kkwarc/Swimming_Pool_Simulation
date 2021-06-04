#include "simulation.h"
#include "reading.h"
#include <random>
#include<time.h>
#include <windows.h>

using namespace std;

Simulation::Simulation(string using_databaze)
{
    string databaze = using_databaze;
    Reading r = da_read(using_databaze); //"Databaze.txt"
    list_of_clients = r.clients;
    list_of_lifeguards = r.staff_available;
    list_of_atractions = r.atractions;

    par = r.rand;
    tick_length = r.tick;
    gowno = r.dapool;
    max_number_of_enters_per_tick = tick_length % 3 + 1;
}

void Simulation::customers_movements(int par)
{
    for (long long unsigned int i = 0; i < gowno.clients.size(); i++)
    {
        int rand_nummber = give_random_number(5) + 1;
        if (rand_nummber == 0)
        {
            int rand2;
            bool overcrowded = true;
            while (overcrowded == true)
            {
                rand2 = give_random_number(list_of_atractions.size());
                if (gowno.atractions[rand2].people_limit > (int)gowno.atractions[rand2].people.size())
                {
                    overcrowded = false;
                }
            }
            gowno.change_atr(gowno.clients[i], gowno.clients[i].curent_atr_nr, gowno.atractions[rand2].atraction_nr);
        }
    }
}

void Simulation::lifeguards_enters()
{
    for (long long unsigned int i = 0; i < list_of_atractions.size(); i++)
    {
        int rand;
        bool buzy = true;
        while (buzy == true)
        {
            rand = give_random_number(list_of_lifeguards.size());
            if (list_of_lifeguards[rand].busy == true)
            {
                continue;
            }
            else
            {
                buzy = false;
            }
        }
        gowno.assign_lifeguard(list_of_lifeguards[rand], list_of_atractions[i].atraction_nr);
        list_of_lifeguards[rand].busy = true;
    }
}

int Simulation::client_enters()
{
    int rand = number_of_enters();
    int rand1;
    for (int i = 0; i < rand; i++)
    {
        rand1;
        bool buzy = true;
        while (buzy == true)
        {
            rand1 = give_random_number(list_of_clients.size());
            if (list_of_clients[rand1].curent_atr_nr != -1)
            {
                continue;
            }
            else
            {
                buzy = false;
            }
        }
        int rand2;
        bool overcrowded = true;
        while (overcrowded == true)
        {
            rand2 = give_random_number(list_of_atractions.size());
            if (gowno.atractions[rand2].people_limit > (int)gowno.atractions[rand2].people.size())
            {
                overcrowded = false;
            }
        }
        gowno.add_client(list_of_clients[rand1], gowno.atractions[rand2].atraction_nr, 60); // jak wylosuje swimming pool to trzeba losować jeszcze tory
        list_of_clients[rand1].curent_atr_nr = gowno.atractions[rand2].atraction_nr;

    }
    return rand;
}

void Simulation::exit_client()
{
    for (int i = 0; i < gowno.exiting.size(); i++)
    {

        for (int j = 0; j < list_of_clients.size(); j++)
        {
            if (list_of_clients[j].carnet_id == gowno.exiting[i])
            {
                list_of_clients[j].curent_atr_nr = -1;
            }
        }
    }
}

void Simulation::summary_of_tick(int random_number)
{
    int y = (int)list_of_atractions.size();
    Time m = gowno.current_time;
    Time k = m + tick_length;
    cout << "Time: " << gowno.current_time << " to " << k << endl;
    cout << "Number of enters: " << random_number << endl;
    for (int i = 0; i < y; i++)
    {
        cout << "Atraction name: " << list_of_atractions[i].name << "; Artaction number: " << list_of_atractions[i].atraction_nr << endl;
        cout << " Lifeguards data [name and surname]: " << gowno.atractions[i].lifeguard.name <<
            "  " << gowno.atractions[i].lifeguard.surname <<
            "; Number of clients: " << gowno.atractions[i].people.size() << endl;
    }
}

void Simulation::summary_of_day()
{
    // cos do zapisywania -> wektor strukow (jak time) -> operator wypisywania
    // trzeba zapisywac te dane przy wejsciu clienta
    // godzina wyjsca = curent time + 60

    // dane klienta
    // godzina przyjsca
    // godzina wyjscia
    // ile zapłacił
}

void Simulation::main_simulation()
{
    Time b = gowno.start_time;
    Time l = b + 360;
    while (gowno.current_time < gowno.closing_time)
    {
        if (gowno.current_time == gowno.start_time || gowno.current_time == l)
        {
            lifeguards_enters();
        }
        if (gowno.clients.size() != 0)
        {
            customers_movements(par);
        }
        int a = client_enters();
        summary_of_tick(a);
        gowno.the_time_is_passing(tick_length);
        exit_client();
        Sleep(300);
    }
    summary_of_day();
}

int Simulation::number_of_enters()
{
    srand(time(NULL));
    int random_number = rand() % (tick_length / 5 + 1);
    //random_number = 4;
    return random_number;
}

int Simulation::give_random_number(int zakres)
{
    srand(time(NULL));
    int random_number = rand() % zakres;
    return random_number;
}
