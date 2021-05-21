#include <iostream>
#include <vector>
#include <sstream>
#include "Instructor.h"
using namespace std;

Instructor::Instructor(string na, string sur, int wid, string ex, vector <string> sk, vector <Client> gr) :Lifeguard(na, sur, wid, ex) {
    name = na;
    surname = sur;
    work_id = wid;
    experience = ex;
    skills = sk;
    group = gr;
}

//tutaj by sie podawalo sam id karty ludka i sie go dodaje wtedy git nie 
void Instructor::add_persongroup(Client new_person) {
    group.push_back(new_person);
}

void Instructor::remove_persongroup(int old_client_card_id) {
    bool t = false;
    for (int i = 0; i < group.size(); i++) {
        if (group[i].card_id == old_client_card_id) {
            group.erase(group.begin() + i);
            t = true;
        }
    }
    if (t == false) {
        cout << "There is no such person in group" << endl;
    }
    else {
        cout << "Person has been removed from group" << endl;
    }
}

void Instructor::add_skill(string new_skill) {
    skills.push_back(new_skill);
}

void Instructor::remove_skill(string old_skill) {
    bool t = false;
    for (int i = 0; i < skills.size(); i++) {
        if (skills[i] == old_skill) {
            skills.erase(skills.begin() + i);
            t = true;
        }
    }
    if (t == false) {
        cout << "There is no such skill to remove" << endl;
    }
    else {
        cout << "Skill has been removed" << endl;
    }
}

void Instructor::show_worker_info() {
    cout << "Name: " << get_name();
    cout << "; Surname: " << get_surname();
    cout << "; Worker Id: " << get_work_id() << endl;
    cout << "Current Skills: " << endl;
    if (skills.size() == 0) {
        cout << "None" << endl;
    }
    else {
        for (int i = 0; i < skills.size(); i++) {
            if (i == skills.size() - 1) {
                cout << skills[i];
            }
            else {
                cout << skills[i] << ", ";
            }
        }
        cout << endl;
    }
    cout << "Group of students:" << endl;
    if (group.size() == 0) {
        cout << "None" << endl;
    }
    else {
        for (int i = 0; i < group.size(); i++) {
            if (i == group.size() - 1) {
                cout << group[i].name << ": " << group[i].card_id;
            }
            else {
                cout << group[i].name << ": " << group[i].card_id << " ; ";
            }
        }
        cout << endl;
    }
}

