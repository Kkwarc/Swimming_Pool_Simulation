#include "test.h"
#include "extra_test.cpp"

using namespace std;

void Test::starting_title() {
    cout << "#########################" << endl;
    cout << "Client Class" << endl;
    cout << "#########################" << endl;
}

void Test::main_menu() {
    cout << "#########################" << endl;
    cout << "Options: " << endl;
    cout << "[1] Create Client" << endl;
    cout << "[2] Select Client" << endl;
    cout << "[3] List of Clients" << endl;
    cout << "[0] Exit" << endl;
}

void Test::change_client() {
    bool runner = true;
    cout << "#########################" << endl;
    list_client();
    cout << "Choose client: " << endl;
    if (list_of_clients.size() == 0) {
        cout << "There are no clients to select" << endl;
        cout << "You must create client first" << endl;
    }
    else {
        int x = get_int();
        if (x < 0 or x >= list_of_clients.size()) {
            cout << "Incorect imput" << endl;
        }
        else {
            while (runner == true) {
                cout << "#########################" << endl;
                Client client = list_of_clients[x];
                cout << "Options: " << endl;
                cout << "[1] change name" << endl;
                cout << "[2] change surname" << endl;
                cout << "[3] change card id" << endl;
                cout << "[4] change carnet id" << endl;
                cout << "[5] add attractions" << endl;
                cout << "[6] remove attractons" << endl;
                cout << "[0] Back" << endl;
                int y = get_int();
                if (y == 1) {
                    string name = get_string();
                    client.change_name(name);
                }
                else if (y == 2) {
                    string surname = get_string();
                    client.change_surname(surname);
                }
                else if (y == 3) {
                    int card_id = get_int();
                    client.change_card_id(card_id);
                }
                else if (y == 4) {
                    int carnet_id = get_int();
                    client.change_carnet_id(carnet_id);
                }
                else if (y == 5) {
                    string add = get_string();
                    client.add_attraction(add);
                }
                else if (y == 6) {
                    string del = get_string();
                    client.del_attraction(del);
                }
                else if (y == 0) {
                    runner = false;
                }
                else {
                    cout << "Incoret imput" << endl;
                }
                list_of_clients.erase(list_of_clients.begin() + x);
                list_of_clients.push_back(client);
            }
        }
    }
}

void Test::view_client() {
    cout << "#########################" << endl;
    list_client();
    cout << "Choose client: " << endl;
    if (list_of_clients.size() == 0) {
        cout << "There are no clients to select" << endl;
        cout << "You must create client first" << endl;
    }
    else {
        int x = get_int();
        cout << "#########################" << endl;
        cout << "Name: " << list_of_clients[x].name << endl;
        cout << "Surname: " << list_of_clients[x].surname << endl;
        cout << "Card Id: " << list_of_clients[x].card_id << endl;
        cout << "Carnet Id: " << list_of_clients[x].carnet_id << endl;
        cout << "Attractions: " << endl;
        if (list_of_clients[x].attractions.size() == 0) {
            cout << "List of attraction is empty" << endl;
        }
        else {
            for (int i = 0; i < list_of_clients[x].attractions.size(); i++) {
                cout << list_of_clients[x].attractions[i] << endl;
            }
        }
        cout << endl;
    }
}

void Test::create_client() {
    bool copie = false;
    cout << "#########################" << endl;
    cout << "Enter client name: ";
    string name = get_string();
    cout << "Enter client surname: ";
    string surname = get_string();
    cout << "Enter client card id: ";
    int card_id = get_int();
    cout << "Enter client carnet id: ";
    int carnet_id = get_int();
    vector <string> attractions = {};
    Client ourclient(name, surname, card_id, carnet_id, attractions);
    for (int i = 0; i < list_of_clients.size(); i++) {
        Client c = list_of_clients[i];
        if (c == ourclient) {
            copie = true;
        }
    }
    if (copie == true) {
        cout << "The given card/carnet number is already taken" << endl;
    }
    else {
        list_of_clients.push_back(ourclient);
    }
}

void Test::remove_client() {
    list_client();
    cout << "#########################" << endl;
    if (list_of_clients.size() == 0) {
        cout << "There are no clients to select" << endl;
        cout << "You must create client first" << endl;
    }
    else {
        cout << "Choose client to remove: " << endl;
        int x = get_int();
        list_of_clients.erase(list_of_clients.begin() + x);
    }
}

void Test::list_client() {
    cout << "#########################" << endl;
    if (list_of_clients.size() == 0) {
        cout << "None" << endl;
    }
    else {
        for (int i = 0; i < list_of_clients.size(); i++) {
            cout << i << ". Surname: " << list_of_clients[i].surname << " / Card Id: " << list_of_clients[i].card_id << " / Carnet Id: " << list_of_clients[i].carnet_id << endl;
        }
    }
}

void Test::select_client() {
    bool selecting = true;

    if (list_of_clients.size() == 0) {
        cout << "There are no clients to select" << endl;
        cout << "You must create client first" << endl;
    }
    else {
        while (selecting == true) {
            cout << "#########################" << endl;
            cout << "Options: " << endl;
            cout << "Viev [1]\nChange [2]\nRemove [3]\nBack [0]\n" << endl;
            int input = get_int();
            switch (input) {
            case 1:
                view_client(); 
                break;
            case 2:
                change_client();
                break;
            case 3:
                remove_client();
                break;
            case 0:
                selecting = false;
                break;
            default:
                cout << "Incorect input" << endl;
                break;
            }
        }
    }
}

void Test::test() {
    starting_title();
    bool runner = true;
    while (runner == true) {
        main_menu();
        int input = get_int();
        switch (input)
        {
        case 1:
            create_client();
            break;
        case 2:
            select_client();
            break;
        case 3:
            list_client();
            break;
        case 0:
            cout << "Goodbye" << endl;
            runner = false;
            break;
        default:
            cout << "Incorect input" << endl;;
        }
    }
}