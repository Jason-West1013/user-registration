#include "mongocxx/instance.hpp"

#include "../include/main_menu.h"

int main()
{
    mongocxx::instance instance;
    
    MainMenu main_menu;
    main_menu.options();
}