#ifndef instructor_h
#define instructor_h
#include <iostream>
#include <vector>
#include <sstream>
#include "client.h"
#include "Lifeguard.h"
using namespace std;

class Instructor :public Lifeguard {
private:
    vector <string> skills;
    vector <Client> group;

public:
    Instructor(string na = "", string sur = "", int wid = 0, string ex = "", vector < string > sk = {}, vector < Client > gr = {});
    vector <string> get_skills();
    vector <Client> get_group();
    void show_worker_info();
    void add_persongroup(Client new_person);
    void remove_persongroup(int old_client_card_id);
    void add_skill(string new_skill);
    void remove_skill(string old_skill);

    friend class Testing;
};
#endif
