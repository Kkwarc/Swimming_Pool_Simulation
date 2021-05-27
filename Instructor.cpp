#include <iostream>
#include <vector>
#include <sstream>
#include "Instructor.h"

using namespace std;

// czas, bool zajety

Instructor::Instructor(
        string na,
        string sur,
        int wid,
        int ex,
        Time s,
        Time f,
        vector <string> sk,
        vector <Client> gr
        ): Lifeguard(na,sur,wid,ex,s,f)
{
    name = na;
    surname = sur;
    work_id = wid;
    experience = ex;
    start=s;
    finish=f;
    skills = sk;
    group = gr;
}

//tutaj by sie podawalo sam id karty ludka i sie go dodaje wtedy git nie
void Instructor::add_persongroup(Client& new_person)
{
        group.push_back(new_person);
}

void Instructor::remove_persongroup(int old_client_card_id)
{
    for(long long unsigned int i = 0; i < group.size(); i++)
    {
        if(group[i].carnet_id == old_client_card_id)
        {
            group.erase(group.begin() + i);

        }
    }
    // na try

    // if (t == false)
    // {
    //     cout << "There is no such person in group" << endl;
    // }
    // else
    // {
    //     cout <<"Person has been removed from group" << endl;
    // }
}

ostream& operator << (ostream& output, Instructor& i)
{
    cout << "Name: " << i.name << endl;
    cout << "Surname: " << i.surname << endl;
    cout << "Worker id: " << i.work_id << endl;
    cout << "Experience level " << i.experience << endl;
    return output;
}

bool Instructor::operator == (Instructor& i1)
{
    if (i1.work_id == work_id)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Instructor::operator != (Instructor& i1)
{
    if ((i1.name ==name) &&
        (i1.surname == surname) &&
        (i1.work_id == work_id))
    {
        return false;
    }
    else
    {
        return true;
    }
}

Instructor Instructor::operator=(Instructor& i)
{

    name = i.name;
    surname = i.surname;
    work_id = i.work_id;
    experience = i.experience;
    start = i.start;
    finish = i.finish;
    skills = i.skills;
    group = i.group;
    return*this;
}
