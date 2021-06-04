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
    ofs1.open("logi.txt", ofstream::out | ofstream::trunc);
    ofs1.close();
    ofstream ofs2;
    ofs2.open("podsumowania.txt", ofstream::out | ofstream::trunc);
    ofs2.close();
    Simulation s("../class/Databaze.txt");
    s.main_simulation();
}
