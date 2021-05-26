#ifndef client_h
#define client_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// dodac ile czasu jeszcze siedzi na basenie
// wersja ulgowa?
// gdzie teraz plywa
// # 2 rozne id

class Client
{
public:
    Client();

    Client(
        std::string name,
        std::string surname,
        int carnet_id,
        bool discount,
        int remaining_time
        );

    Client(const Client& client)
    {
        name = client.name;
        surname = client.surname;
        carnet_id = client.carnet_id;
        discount = client.discount;
        remaining_time = client.remaining_time;
    }

    friend std::ostream& operator << (std::ostream& output, const Client& c);

    bool operator == (const Client& c1);

    bool operator != (const Client& c1);

    Client& operator=(const Client& s);

    std::string get_name() const;

    std::string get_surname() const;

    int get_carnet_id() const;

    std::string name;

    std::string surname;

    int carnet_id;

    bool discount;

    int remaining_time;
};
#endif
