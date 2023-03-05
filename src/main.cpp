#include<iostream>

#include "mongocxx/instance.hpp"

#include "../include/menu.h"
#include "../include/mongodb_handler.h"

using namespace std;

int main()
{
    mongocxx::instance instance;
    MongoDBHandler handler;
    // Menu menu;
    // menu.initialLoginOptions();
    // handler.AddUser("mario", "peach1234");

    std::string result = handler.GetPassword("mario");
    std::cout << result << std::endl;
}