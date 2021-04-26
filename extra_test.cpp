#include <iostream>
#include <sstream>

using namespace std;

int get_int() {
    int Number;
    while (true)
    {
        cout << "Please enter an correct value: " << endl;
        string line;
        if (!getline(cin, line))
        {
            cout << "Invalid input" << endl;
        }
        istringstream input(line);
        char extra;
        if (input >> Number && !(input >> extra))
            break;
        else
        {
            cout << "Invalid input" << endl;
        }
    }
    return Number;
}

string get_string() {
    string word;
    while (true)
    {
        cout << "Please enter an correct value: " << endl;
        string line;
        if (!getline(cin, line))
        {
            cout << "Invalid input" << endl;
        }
        istringstream input(line);
        char extra;
        if (input >> word && !(input >> extra))
            break;
        else
        {
            cout << "Invalid input" << endl;
        }
    }
    return word;
}

