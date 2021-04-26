#ifndef client_h
#define client_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Client
{
public:
    Client()
    {
        name = "Unknown";
        surname = "Unknown";
        card_id = 0;
        carnet_id = 0;
        attractions = {};
    }

    Client(std::string name,
        std::string surname,
        int card_id,
        int carnet_id,
        std::vector <std::string> attractions);

    Client(const Client& client)
    {
        name = client.name;
        surname = client.surname;
        card_id = client.card_id;
        carnet_id = client.carnet_id;
        attractions = client.attractions;
    }

    friend std::ostream& operator << (std::ostream& output, const Client& c);

    bool operator == (const Client& c1);

    friend bool operator != (const Client& c1, const Client& c2);

    Client& operator=(const Client& s);

    void add_attraction(std::string title);

    void del_attraction(std::string title);

    void change_name(std::string new_name);

    void change_surname(std::string new_surname);

    void change_carnet_id(int new_carnet_id);

    void change_card_id(int new_card_id);


    std::string get_name() const;

    std::string get_surname() const;

    int get_card_id() const;

    int get_carnet_id() const;

    void get_attractions() const;

    std::vector <std::string> attractions;

    std::string name;

    std::string surname;

    int card_id;

    int carnet_id;
};
#endif