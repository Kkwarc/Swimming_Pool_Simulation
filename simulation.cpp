#include "simulation.h"
#include "reading.h"
#include <random>
#include<time.h>
#include <windows.h>
#include <string>
#include <fstream>

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
    int rand3 = give_random_number(3) + 1;
    bool correct_time = false;
    while (correct_time == false)
    {
        Time E1 = gowno.current_time;
        E1 = E1 + 91;
        Time E2 = gowno.current_time;
        E2 = E2 + 151;
        if (gowno.closing_time < E1)
        {
            rand3 = 1;
            correct_time = true;
        }
        else if (gowno.closing_time < E2)
        {
            rand3 = give_random_number(2) + 1;
            correct_time = true;
        }
        else
        {
            rand3 = give_random_number(3) + 1;
            correct_time = true;
        }
    }
    for (int i = 0; i < rand; i++)
    {
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
        Time L = gowno.current_time;
        list_of_clients[rand1].time_spent += rand3;
        list_of_clients[rand1].time_spent_hours.push_back(L);
        list_of_clients[rand1].time_spent_hours.push_back(L + rand3 * 60);
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
        gowno.add_client(list_of_clients[rand1], gowno.atractions[rand2].atraction_nr, rand3 * 60); // jak wylosuje swimming pool to trzeba losować jeszcze tory
        list_of_clients[rand1].curent_atr_nr = gowno.atractions[rand2].atraction_nr;
    }
    return rand;
}

void Simulation::exit_client()
{
    for (long long unsigned int i = 0; i < gowno.exiting.size(); i++)
    {

        for (long long unsigned int j = 0; j < list_of_clients.size(); j++)
        {
            if (list_of_clients[j].carnet_id == gowno.exiting[i])
            {
                list_of_clients[j].curent_atr_nr = -1;
            }
        }
    }
}

//void Simulation::summary_of_tick(int random_number)
//{
//    int y = (int)list_of_atractions.size();
//    Time m = gowno.current_time;
//    Time k = m + tick_length;
//    cout << "Time: " << gowno.current_time << " to " << k << endl;
//    cout << "Number of enters: " << random_number << endl;
//    for (int i = 0; i < y; i++)
//    {
//        cout << "Atraction name: " << list_of_atractions[i].name << 
//            "; Artaction number: " << list_of_atractions[i].atraction_nr << endl;
//        cout << " Lifeguards: " << gowno.atractions[i].lifeguard.name <<
//            "  " << gowno.atractions[i].lifeguard.surname << endl;
//        cout << " Number of clients: " << gowno.atractions[i].people.size() << endl;
//    }
//}

//void Simulation::summary_of_day()
//{
//    cout << "SUMMARY OF DAY" << endl;
//    for (int i = 0; i < list_of_clients.size(); i++)
//    {
//        if (list_of_clients[i].time_spent > 0)
//        {
//            cout << "Client: " << list_of_clients[i].name << " " << list_of_clients[i].surname << endl;
//            cout << "Time spent: "<< list_of_clients[i].time_spent << endl;
//            if (list_of_clients[i].discount == true)
//            {
//                cout << "Payment: " << list_of_clients[i].time_spent*20/2 << endl; // cena za godzine do modyfikacji
//            }
//            else
//            {
//                cout << "Payment: " << list_of_clients[i].time_spent * 20 << endl; // to co wyzej
//            }
//            for (int j = 0; j < list_of_clients[i].time_spent_hours.size(); j = j + 2)
//            {
//                cout << "Enter time: " << list_of_clients[i].time_spent_hours[j] << endl;
//                cout << "Exit time: " << list_of_clients[i].time_spent_hours[j+1] << endl;
//            }
//        }
//        Sleep(100);
//    }
//}

void Simulation::summary_of_tick(int random_number)
{
    int y = (int)list_of_atractions.size();
    Time m = gowno.current_time;
    Time k = m + tick_length;
    cout << "Time: " << gowno.current_time << " to " << k << endl;
    cout << "Number of enters: " << random_number << endl;
    for (int i = 0; i < y; i++)
    {
        cout << "Atraction name: " << list_of_atractions[i].name <<
            "; Artaction number: " << list_of_atractions[i].atraction_nr << endl;
        cout << " Lifeguards: " << gowno.atractions[i].lifeguard.name <<
            "  " << gowno.atractions[i].lifeguard.surname << endl;
        cout << " Number of clients: " << gowno.atractions[i].people.size() << endl;
    }

    ofstream out("logi.txt", ios_base::app);
    streambuf* coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
    cout << "Time: " << gowno.current_time << " to " << k << endl;
    cout << "Number of enters: " << random_number << endl;
    for (int i = 0; i < y; i++)
    {
        cout << "Atraction name: " << list_of_atractions[i].name <<
            "; Artaction number: " << list_of_atractions[i].atraction_nr << endl;
        cout << " Lifeguards: " << gowno.atractions[i].lifeguard.name <<
            "  " << gowno.atractions[i].lifeguard.surname << endl;
        cout << " Number of clients: " << gowno.atractions[i].people.size() << endl;
    }

    cout.rdbuf(coutbuf); //reset to standard output again
}

void Simulation::summary_of_day()
{
    cout << "SUMMARY OF DAY" << endl;
    for (int i = 0; i < list_of_clients.size(); i++)
    {
        if (list_of_clients[i].time_spent > 0)
        {
            cout << "Client: " << list_of_clients[i].name << " " << list_of_clients[i].surname << endl;
            cout << "Time spent: " << list_of_clients[i].time_spent << endl;
            if (list_of_clients[i].discount == true)
            {
                cout << "Payment: " << list_of_clients[i].time_spent * 20 / 2 << endl; // cena za godzine do modyfikacji
            }
            else
            {
                cout << "Payment: " << list_of_clients[i].time_spent * 20 << endl; // to co wyzej
            }
            for (int j = 0; j < list_of_clients[i].time_spent_hours.size(); j = j + 2)
            {
                cout << "Enter time: " << list_of_clients[i].time_spent_hours[j] << endl;
                cout << "Exit time: " << list_of_clients[i].time_spent_hours[j + 1] << endl;
            }
        }
        Sleep(100);
    }

    ofstream out("podsumowania.txt", ios_base::app);
    streambuf* coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    cout << "SUMMARY OF DAY" << endl;
    for (int i = 0; i < list_of_clients.size(); i++)
    {
        if (list_of_clients[i].time_spent > 0)
        {
            cout << "Client: " << list_of_clients[i].name << " " << list_of_clients[i].surname << endl;
            cout << "Time spent: " << list_of_clients[i].time_spent << endl;
            if (list_of_clients[i].discount == true)
            {
                cout << "Payment: " << list_of_clients[i].time_spent * 20 / 2 << endl; // cena za godzine do modyfikacji
            }
            else
            {
                cout << "Payment: " << list_of_clients[i].time_spent * 20 << endl; // to co wyzej
            }
            for (int j = 0; j < list_of_clients[i].time_spent_hours.size(); j = j + 2)
            {
                cout << "Enter time: " << list_of_clients[i].time_spent_hours[j] << endl;
                cout << "Exit time: " << list_of_clients[i].time_spent_hours[j + 1] << endl;
            }
        }
    }
    cout.rdbuf(coutbuf); //reset to standard output again
}

void Simulation::main_simulation()
{
    // clear plikow tekstowych
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
        int a;
        Time e = gowno.current_time;
        if (e + 59 < gowno.closing_time)
        {
            a = client_enters();
        }
        else
        {
            a = 0;
        }
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
    int random_number = rand() % (tick_length / 5 + 1) + 1;
    return random_number;
}

int Simulation::give_random_number(int zakres)
{
    srand(time(NULL));
    int random_number = rand() % zakres;
    return random_number;
}
