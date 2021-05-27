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
    int max_ppl,
    Time start_time,
    Time closing_time,
    std::vector<Atraction> atractions,
    std::vector<Lifeguard> staff_available,
    std::vector<Client> clients
    )
{
    name = name;
    max_ppl = max_ppl;
    atractions = atractions;
    staff_available = staff_available;
    clients = clients;
    start_time = start_time;
    closing_time = closing_time;
}

// Da_Pool:: add_client()
// {
// ;
// }

// Da_Pool:: change_atr()
// {
// ;
// }

// Da_Pool:: exit_da_pool()
// {
// ;
// }

// Da_Pool:: staff_come()
// {
// ;
// }

// Da_Pool:: staff_exit()
// {
// ;
// }

// Da_Pool:: assign_lifeguard()
// {
// ;
// }

// Da_Pool:: reservation()
// {
// ;
// }