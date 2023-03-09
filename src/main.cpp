#include "mongocxx/instance.hpp"

#include "../include/main_menu.h"

using namespace std;

int main()
{
    mongocxx::instance instance;
    
    MainMenu main_menu;
    main_menu.options();
}