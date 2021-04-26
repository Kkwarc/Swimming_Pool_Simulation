#ifndef test_h
#define test_h
#include "client.h"
#include <vector>
#include <iostream>
#include <sstream>

class Test {
public:
    std::vector < Client > list_of_clients;
    void starting_title();
    void main_menu();
    void change_client();
    void view_client();
    void create_client();
    void remove_client();
    void select_client();
    void list_client();
    void test();

};
#endif