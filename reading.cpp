#include <fstream>
#include "time.h"
#include "Lifeguard.h"
#include "Instructor.h"
#include "client.h"
#include "atractions.h"
#include "da_Pool.h"
#include "simulation.h"

using namespace std;

vector<Atraction> atractions;
vector<Lifeguard> staff_available;
vector<Client> clients;


void read()
{
    ifstream file("Databaze.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            size_t pos = 0;
            string token;
            string delimiter = ",";
            vector<string> obiekt;
            while ((pos = line.find(delimiter)) != string::npos)
            {
                token = line.substr(0, pos);
                obiekt.push_back(token);
                line.erase(0, pos + delimiter.length());
            }
            if (obiekt[0] == "klient")
            {
                string name = obiekt[1];
                string surname = obiekt[2];
                int id = stoi(obiekt[3]);
                int z = stoi(obiekt[4]);
                if (z == 0)
                {
                    Client klient(name, surname, id, false, 0);
                    clients.push_back(klient);
                }
                if (z == 1)
                {
                    Client klient(name, surname, id, true, 0);
                    clients.push_back(klient);
                }
            }
            if (obiekt[0] == "Lifeguard")
            {
                string name = obiekt[1];
                string surname = obiekt[2];
                int id = stoi(obiekt[3]);
                int exp = stoi(obiekt[4]);
                int starth = stoi(obiekt[5]);
                Time sh = { starth,00 };
                int finish = stoi(obiekt[6]);
                Time fh = { finish,00 };

                Lifeguard ratownik(name, surname, id, exp, sh, fh);
                staff_available.push_back(ratownik);
            }
            if (obiekt[0] == "Instructor")
            {
                string name = obiekt[1];
                string surname = obiekt[2];
                int id = stoi(obiekt[3]);
                int exp = stoi(obiekt[4]);
                int starth = stoi(obiekt[5]);
                Time sh = { starth,00 };
                int finish = stoi(obiekt[6]);
                Time fh = { finish,00 };

                Instructor instr(name, surname, id, exp, sh, fh);
                staff_available.push_back(instr);
            }
            if (obiekt[0] == "pool")
            {
                int atraction_nr = stoi(obiekt[1]);
                int length = stoi(obiekt[2]);
                int tr_limit = stoi(obiekt[3]);
                int begginer_tr = stoi(obiekt[4]);
                int intermeddiate_tr = stoi(obiekt[5]);
                int advanced_tr = stoi(obiekt[6]);

                Swimming_Pool swipool(atraction_nr, length, tr_limit, begginer_tr, intermeddiate_tr, advanced_tr);
                atractions.push_back(swipool);
            }
            if (obiekt[0] == "track")
            {
                int dpth = stoi(obiekt[1]);
                int lng = stoi(obiekt[2]);
                int tr_nr = stoi(obiekt[3]);
                int ppl_lim = stoi(obiekt[4]);
                int atraction_nr = stoi(obiekt[5]);

                Track track(dpth, lng, tr_nr, ppl_lim, atraction_nr);
                atractions.push_back(track);
            }
            if (obiekt[0] == "attraction")
            {
                string name = obiekt[1];
                int attraction_num = stoi(obiekt[2]);
                int people_limit = stoi(obiekt[3]);

                Atraction atraction(name, attraction_num, people_limit);
                atractions.push_back(atraction);
            }
            if (obiekt[0] == "da_pool")
            {
                string name = obiekt[1];
                int max_ppl = stoi(obiekt[2]);
                int attr_nr = stoi(obiekt[3]);
                int start = stoi(obiekt[4]);
                Time starth = { start,00 };
                Time currenth = { start,00 };
                int finish = stoi(obiekt[5]);
                Time finishh = { finish,00 };

                //Da_Pool dapool(name, max_ppl,attr_nr, atractions, staff_available, clients, starth,finishh,currenth);

            }
            if (obiekt[0] == "rand")
            {
                //nwm
            }
            if (obiekt[0] == "tick")
            {
                //nwm
            }
        }
    }
}