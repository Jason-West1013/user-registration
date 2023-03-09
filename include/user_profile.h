#pragma once 

#include <string>

#include "../include/mongodb_handler.h"

class UserProfile
{
private:
    MongoDBHandler handler;

public:
    bool set_user_profile(std::string username, std::string password);
    bool verify_user_profile(std::string username, std::string password);
    bool update_password(std::string username, std::string oldPassword, std::string newPassword);
    bool delete_profile(std::string username, std::string password);
};