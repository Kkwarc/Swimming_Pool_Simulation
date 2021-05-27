#ifndef Instructor_h
#define Instructor_h

#include <iostream>
#include <vector>
#include <sstream>
#include "client.h"
#include "Lifeguard.h"
#include "time.h"
//#include "atractions.h"

// operatory porownania- dziedziczy po ratowniku (czesciowo)
// gdzie teraz plywa
// godziny pracy - dziedziczy po ratowniku
// j###c zw###ki za####we => pracujemy caly czas
// poziom umiejetnosci chyba na int?  dziedziczy po ratowniku

class Instructor :public Lifeguard
{
    private:
    std::vector <std::string> skills;
    std::vector <Client> group;

    public:
    Instructor(
        std::string na="",
        std::string sur="",
        int wid=0,
        int ex=1,
        Time start={-1,-1},
        Time finish={-1,-1},
        std::vector <std::string> sk = {},
        std::vector <Client> gr = {}
        );
    std::vector<std::string> get_skills();
    std::vector<Client> get_group();
    void add_persongroup(Client& new_person);
    void remove_persongroup(int old_client_card_id);

    friend std::ostream& operator << (std::ostream& output, Instructor& i);

    bool operator == (Instructor& i1);

    bool operator != (Instructor& i1);

    Instructor operator=(Instructor& i);

};
#endif