#include "client.h"

// #include <iostream>
// #include <cstdlib>
// #include <cstdio>
// #include <string>
// #include <sstream>
// #include <vector>

using namespace std;

Client::Client(string name,
    string surname,
    int card_id,
    int carnet_id,
    vector <string> attractions)
{
    this->name = name;
    this->surname = surname;
    this->card_id = card_id;
    this->carnet_id = carnet_id;
    this->attractions = attractions;
}

void Client::add_attraction(string attraction)
{
    attractions.push_back(attraction);
    cout << "The attraction: " << attraction << " has been added" << endl;

}
void Client::del_attraction(string attraction)
{
    if (find(attractions.begin(), attractions.end(), attraction) != attractions.end())
    {
        attractions.erase(remove(attractions.begin(), attractions.end(), attraction));
        cout << "The attraction: " << attraction << " has been deleted" << endl;
    }
    else
    {
        cout << "There is no such a attraction" << endl;
    }
}

void Client::change_name(string new_name)
{
    name = new_name;
    cout << "The new client name is: " << name << endl;
}

void Client::change_surname(string new_surname)
{
    surname = new_surname;
    cout << "The new client surname is: " << surname << endl;
}

void Client::change_card_id(int new_card_id)
{
    card_id = new_card_id;
    cout << "The new client card_id is: " << card_id << endl;
}

void Client::change_carnet_id(int new_carnet_id)
{
    carnet_id = new_carnet_id;
    cout << "The new client carnet_id is: " << carnet_id << endl;
}

string Client::get_name() const
{
    return name;
}

string Client::get_surname() const
{
    return surname;
}

int Client::get_card_id() const
{
    return card_id;
}

int Client::get_carnet_id() const
{
    return carnet_id;
}

void Client::get_attractions() const
{
    if (attractions.empty())
    {
        cout << "There are no attractions" << endl;
    }
    else
    {
        cout << "Available attractions: " << endl;
        for (long long unsigned int i = 0; i < attractions.size(); i++)
        {
            cout << attractions[i] << endl;
        }
    }
}

ostream& operator << (ostream& output, const Client& c)
{
    cout << "Name: " << c.name << endl;
    cout << "Surname: " << c.surname << endl;
    cout << "card_id: " << c.card_id << endl;
    cout << "carnet_id: " << c.carnet_id << endl;
    return output;
}

bool Client::operator == (const Client& c1)
{
    if ((c1.card_id == card_id) or
        (c1.carnet_id == carnet_id))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator != (const Client& c1, const Client& c2)
{
    if ((c1.name == c2.name) &&
        (c1.surname == c2.surname) &&
        (c1.card_id == c2.card_id) &&
        (c1.carnet_id == c2.carnet_id))
    {
        return false;
    }
    else
    {
        return true;
    }
}

Client& Client::operator=(const Client& c)
{
    if (this != &c)
    {
        name = c.name;
        surname = c.surname;
        card_id = c.card_id;
        carnet_id = c.carnet_id;
    }
    return*this;
}