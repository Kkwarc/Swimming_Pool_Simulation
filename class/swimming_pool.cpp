#include "atractions.h"
#include "client.h"
#include "Lifeguard.h"
#include "Instructor.h"


using namespace std;


Swimming_Pool::Swimming_Pool()
{
    name = "Swimming_Pool";
    atraction_nr = -1;
    people_limit = 0;
    people = {};
    lifeguard = Lifeguard();
    tr_nr = 0;
    length = 0;

}
Swimming_Pool::Swimming_Pool
(
    int atraction_nr,
    int length,
    int tr_limit,
    int begginer_tr,
    int intermeddiate_tr,
    int advanced_tr
) : Atraction("Swimming_pool", atraction_nr, tr_limit* (begginer_tr + intermeddiate_tr + advanced_tr))
{
    tr_nr = begginer_tr + intermeddiate_tr + advanced_tr;
    atraction_nr = atraction_nr;
    length = length;
    int current_tr = 0;
    for (int i = 0; i < begginer_tr; i++)
    {
        Track tr(100, length, current_tr, tr_limit, atraction_nr);
        tracks[current_tr] = tr;
        current_tr = current_tr + 1;
    }
    for (int i = 0; i < intermeddiate_tr; i++)
    {
        Track tr(200, length, current_tr, tr_limit, atraction_nr);
        tracks[current_tr] = tr;
        current_tr = current_tr + 1;
    }
    for (int i = 0; i < advanced_tr; i++)
    {
        Track tr(300, length, current_tr, tr_limit, atraction_nr);
        tracks[current_tr] = tr;
        current_tr = current_tr + 1;
    }
}
void Swimming_Pool::reserve_track(int track_nr, Instructor& inst, std::vector<Client> group, int res_time)
{
    int index;
    for (int i = 0; i < tr_nr; i++)
    {
        if (tracks[i].track_nr == track_nr)
        {
            index = i;
            break;
        }
        throw; // zrob cos z tym
    }
    for (long long unsigned int i = 0; i < tracks[index].people.size(); i++)
    {
        change_track(tracks[index].people[0], track_nr, min_tr());
    }
    if (tracks[index].is_reserved() != false)
    {
        tracks[index].reserve_track(inst, group, res_time);
    }
    for (long long unsigned int i = 0; i < group.size(); i++)
    {
        people.push_back(group[i]);
    }
}
void Swimming_Pool::change_track(Client& cl, int tr1_nr, int tr2_nr)
{
    int index1;
    int index2;
    for (int i = 0; i < tr_nr; i++)
    {
        if (tracks[i].track_nr == tr1_nr)
        {
            index1 = i;
            break;
        }
    }
    for (int i = 0; i < tr_nr; i++)
    {
        if (tracks[i].track_nr == tr1_nr)
        {
            index2 = i;
            break;
        }
    }
    tracks[index1].remove_person(cl.carnet_id);
    tracks[index2].add_person(cl);
}

void Swimming_Pool::add_person(int tr1_nr, Client& clnt)
{
    int index;
    if ((int)people.size() < people_limit)
        for (int i = 0; i < tr_nr; i++)
        {
            if (tracks[i].track_nr == tr1_nr)
            {
                index = i;
                break;
            }
            throw; // zrob cos z tym
        }
    tracks[index].add_person(clnt);
    people.push_back(clnt);
}

void Swimming_Pool::remove_person(int car_id)
{
    int index1;
    for (long long unsigned int i = 0; i < people.size(); i++)
    {
        if (people[i].carnet_id == car_id)
        {
            index1 = i;
            break;
        }
        throw; // zrob cos z tym
    }
    for (int i = 0; i < tr_nr; i++)
    {
        for (long long unsigned int j = 0; j < tracks[i].people.size(); j++)
        {
            if (tracks[i].people[j].carnet_id == car_id)
            {
                tracks[i].remove_person(car_id);
            }
        }
    }
    people.erase(people.begin() + index1);
}

int Swimming_Pool::min_tr()
{
    int min = 500;
    Track t;
    for (int i = 0; i < tr_nr; i++)
    {
        if (tracks[i].people.size() < tracks[i - 1].people.size())
        {
            min = tracks[i].track_nr;
            t = tracks[i];
        }
    }
    return min;
}
