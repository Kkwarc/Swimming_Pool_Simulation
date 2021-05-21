#include <iostream>
#include <list>
#include<vector>
#include "client.h"
#include "Lifeguard.h"
#include "Instructor.h"

class Da_Pool
{
    std::vector<Atraction> atractions;
    int max_ppl;
    int attr_nr;
    std::vector<Lifeguard> staff_available;
    std::vector<Client> clients;
    Time start_time;
    Time closing_time;
    Time* reservations;
    int reservations_nr;
public:
    Da_Pool();
    Da_Pool(Time st_time, Time cl_time, int max_ppl, int attr_nr, std::vector<Atraction> atractions);
    void add_client(Client& client, Atraction& atr, int time);
    void change_atr(Client& client, Atraction& atr1, Atraction& atr2);
    void exit_da_pool(Client& client);
    void staff_come(Lifeguard& staff);
    void staff_exit(Lifeguard& staff);
    void assign_lifeguard(Lifeguard& lif, Atraction& atr);
    void reservation(std::string difficulty, Time start, Time stop, Instructor& inst);
};
