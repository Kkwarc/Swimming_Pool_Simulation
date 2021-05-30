#include "simulation.h"
#include <random>

using namespace std;


 Simulation::Simulation(string using_databaze)
 {
 	string databaze = using_databaze;
 	max_number_of_enters_per_tick = tick_length % 3 + 1;
 }

 void Simulation::customers_movements(int par)
 {
 	for (long long unsigned int i = 0; i <= gowno.clients.size(); i++)
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
     for (long long unsigned int i = 0; i <= gowno.staff_available.size(); i++)
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

 void Simulation::client_enters()
 {
 	int rand = number_of_enters();
 	for (int i = 0; i < rand; i++)
 	{
 		int rand1 = give_random_number(list_of_clients.size());
 		int rand2 = give_random_number(list_of_atractions.size());
 		gowno.add_client(list_of_clients[rand1],rand2, 1);
        list_of_clients[rand1].curent_atr_nr = rand2;
 	}
 }

 void Simulation::summary_of_tick()
 {
 	int y = n_of_a;
 	for (int i = 0; i < y; i++)
 	{
 		// prin atraction -> lifeguards -> clients
 		// numer atrakcji -> dane ratownika(imie, nazawisko) -> ilosc klientow
 		// ...
 	}
 }

 void Simulation::summary_of_day()
 {
 	// print -> godzina -> odpowiednia lista z ticku
 	// Bartek naaaaaaaaaaaaapisz
 }

 void Simulation::main_simulation()
 {

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

