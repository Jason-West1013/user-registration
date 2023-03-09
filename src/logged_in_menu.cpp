#include "../include/logged_in_menu.h"
#include "../include/user_profile.h"

void LoggedInMenu::options()
{
    char input;

    std::cout << "Welcome back, " << LoggedInMenu::username << "!" << std::endl;
    std::cout << "A: Update Password" << std::endl;
    std::cout << "B: Delete User Profile" << std::endl;
    std::cout << "E: Exit" << std::endl;
    std::cin >> input;

    switch(input)
    {
        case 'A' | 'a':
            change_password();
            break;
        case 'B' | 'b':
            delete_profile();
            break;
        case 'E' | 'e':
            break;
        default:
            std::cout << std::endl << "****Not valid input****" << std::endl << std::endl;
            options();
    }
}

void LoggedInMenu::change_password()
{
    UserProfile profile;
    std::string oldPassword;
    std::string newPassword;

    std::cout << "Enter Old Password: ";
    std::cin >> oldPassword;
    std::cout << "Enter New Password: ";
    std::cin >> newPassword;

    bool result = profile.update_password(LoggedInMenu::username, oldPassword, newPassword);
    if(result)
    {
        std::cout << "Password Successfully Updated" << std::endl;
    }
    else 
    {
        std::cout << "Error changing password" << std::endl;
    }
    options();
}

void LoggedInMenu::delete_profile()
{
    UserProfile profile;
    char input;

    std::cout << "Are you sure you want to delete your profile?" << std::endl;
    std::cin >> input;

    if(input == 'Y' || input == 'y')
    {
        std::string password;

        std::cout << "Password: ";
        std::cin >> password;

        bool result = profile.delete_profile(LoggedInMenu::username, password);
        if(result)
        {
            std::cout << "Your profile has been successfully deleted" << std::endl;
        }
        else
        {
            std::cout << "Error deleting profile" << std::endl;
        }
        options();
    }
}
