#include <iostream>
#include "simulation.h"
#include <string>
#include <fstream>

using namespace std;

// klienci siedza na basenie tyle ile wczesniej wykupi lub mniej
// cykl 30 minutowy
// mamy najlepszych ratownikow w polsce -> jeden na atrakcje

int main()
{
    ofstream ofs1;
    ofs1.open("Logi.txt", ofstream::out | ofstream::trunc);
    ofs1.close();
    ofstream ofs2;
    ofs2.open("Podsumowania.txt", ofstream::out | ofstream::trunc);
    ofs2.close();
    Simulation s("Databaze.txt","Reservations.txt");
    s.main_simulation();
}
