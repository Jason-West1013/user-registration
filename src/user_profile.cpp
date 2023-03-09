#include "../include/user_profile.h"

bool UserProfile::set_user_profile(std::string username, std::string password)
{
    bool result = handler.add_user(username, password);
    return result;
}

bool UserProfile::verify_user_profile(std::string username, std::string password)
{
    std::string result = handler.get_password(username);
    return result == password;
}

bool UserProfile::update_password(std::string username, std::string oldPassword, std::string newPassword)
{
    bool passwordVerified = verify_user_profile(username, oldPassword);
    if(passwordVerified)
    {
        bool result = handler.update_password(username, newPassword);
        return result;
    }

    return false;
}

bool UserProfile::delete_profile(std::string username, std::string password)
{
    bool passwordVerified = verify_user_profile(username, password);
    if(passwordVerified)
    {
        bool result = handler.remove_user(username);
        return result;
    }

    return false;
}