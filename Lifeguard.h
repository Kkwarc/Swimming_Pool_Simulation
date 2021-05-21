#ifndef lifeguard_h
#define lifeguard_h
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Lifeguard{
    protected:
    string name, surname;
    int work_id;
    string experience;

    public:
    Lifeguard(string na="", string sur="", int wid=0, string ex="");
    int get_int();
    string get_name();
    string get_surname();
    int get_work_id();
    string get_experience();
    void change_name(string new_name);
    void change_surname(string new_surname);
    void change_work_id(int new_work_id);
    void change_experience(string new_experience);
    void show_worker_info();

    friend class Testing;
};
#endif
