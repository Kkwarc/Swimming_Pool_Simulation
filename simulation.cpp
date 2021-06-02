#include "simulation.h"
#include "reading.h"
#include <random>
#include<time.h>

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
 		int rand_nummber = give_random_number(5);
 		if (rand_nummber == 0)
 		{
            int rand2 = give_random_number(list_of_atractions.size());
 			gowno.change_atr(gowno.clients[i], gowno.clients[i].curent_atr_nr, rand2);
 		}
 	}
 }

 void Simulation::lifeguards_enters()
 {
     for (long long unsigned int i = 0; i < gowno.staff_available.size(); i++)
     {
         if (gowno.staff_available[i].start == gowno.current_time)
         {
             bool allocation = false;
             while (allocation == false)
             {
                 int rand = give_random_number(list_of_atractions.size());
                 if (gowno.staff_available[i].busy == true)
                 {
                     continue;
                 }
                 else
                 {
                     list_of_atractions[rand].set_lifeguard(gowno.staff_available[i]);
                 }
             }
         }
     }
 }

//  void Simulation::client_enters()
//  {
//  	int rand = number_of_enters();
//  	for (int i = 0; i < rand; i++)
//  	{
//  		int rand1 = give_random_number(list_of_clients.size());
//  		int rand2 = give_random_number(list_of_atractions.size());
//  		gowno.add_client(list_of_clients[rand1],rand2, 1, 60); // jak wylosuje swimming pool to trzeba losować jeszcze tory
//         list_of_clients[rand1].curent_atr_nr = rand2;
//  	}
//  }

 void Simulation::summary_of_tick()
 {
 	int y = (int)list_of_atractions.size();
    Time m=gowno.current_time;
    Time k = m +tick_length;
 	for (int i = 0; i < y; i++)
 	{
        // do dopisania operator strumienia w Time
        cout << "Time: " << gowno.current_time << " "<< k << endl;
        cout << "Artaction number: " << list_of_atractions[i].atraction_nr <<
            " Lifeguards data [name and surname: " << list_of_atractions[i].lifeguard.name <<
             "/" << list_of_atractions[i].lifeguard.surname <<
            " Number of clients: " << list_of_atractions[i].people.size() << endl;
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
     // pobranie i zainiciowanie obiektów z databaze
     // rorpoczecie pętli
     // -> rozklad ratownikow na basenie w godzinie startowej i czasie zmiany (u nas 14)
     // -> przejscia klientow
     // -> wchodzenie klientow
     // -> summary of tick
     // -> thetimeispassing
     // koniec petli
     // -> summary of day
     Time b = gowno.start_time;
     Time l = b + 360;
     while (gowno.current_time < gowno.closing_time)
     {
         if (gowno.current_time == gowno.start_time || gowno.current_time == l)
         {
             lifeguards_enters();
         }
         if (list_of_clients.size() != 0)
         {
             customers_movements(par);
         }
        // client_enters();
        summary_of_tick();
        gowno.the_time_is_passing(tick_length); // nwm co mial bartek na mysli piszac int tick
     }
     summary_of_day();
 }

  int Simulation::number_of_enters()
  {
  	srand(time(NULL));
  	int random_number = rand() % (tick_length%3 + 1);
  	return random_number;
  }

  int Simulation::give_random_number(int zakres)
  {
  	srand(time(NULL));
  	int random_number = rand() % zakres;
  	return random_number;
  }

