#include <iostream>
#include "simulation.h"
// klienci siedza na basenie tyle ile wczesniej wykupi lub mniej
// cykl 5 minutowy

int main()
{
    Simulation s("databaze.txt");
    s.main_simulation();
}

