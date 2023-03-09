#pragma once

#include <iostream>
#include <string>

class LoggedInMenu
{
private:
    std::string username;

public:
    void options();
    void change_password();
    void delete_profile();
};