#include <iostream>
#include <vector>
#include <sstream>
#include "Lifeguard.h"
using namespace std;

Lifeguard::Lifeguard(string na, string sur, int wid, string ex)
{
    name = na;
    surname = sur;
    work_id = wid;
    experience = ex;
}

int Lifeguard::get_int()
{
    int digit;
    while(true)
    {
        string line;
        char rest;
        if (!getline(cin, line))
        {
            cout<<"Recevied no input, try again: "<<endl;
        }
        istringstream user_input(line);
        if (user_input >> digit && !(user_input >> rest) && digit>=0)
        {
            break;
        }
        else
            cout<<"Enter a positive integer:"<<endl;
    }
    return digit;
}

string Lifeguard::get_name()
{
    return name;
}

string Lifeguard::get_surname()
{
    return surname;
}

int Lifeguard::get_work_id()
{
    return work_id;
}

void Lifeguard::change_name(string new_name)
{
    name=new_name;
}

void Lifeguard::change_surname(string new_surname)
{
    surname=new_surname;
}

void Lifeguard::change_work_id(int new_work_id)
{
    work_id=new_work_id;
}

void Lifeguard::change_experience(string new_experience)
{
    if ((new_experience!="beginner") || (new_experience!="intermediate") || (new_experience!="advanced")){
        experience = new_experience;
    }
    else{
        cout << "ERROR: There is no such experience level" << endl;
    }
}
void Lifeguard::show_worker_info()
{
    cout<<"Name: "<< get_name();
    cout<<"; Surname: "<< get_surname();
    cout<<"; Worker Id: "<< get_work_id()<<endl;
}
