#include "../include/main_menu.h"
#include "../include/user_profile.h"

void MainMenu::options()
{
    char input;

    std::cout << "Welcome to SomeApp" << std::endl;
    std::cout << "A: Login" << std::endl;
    std::cout << "B: Create Account" << std::endl;
    std::cout << "E: Exit" << std::endl;

    std::cin >> input;
        
    switch(input)
    {
        case 'A' | 'a':
            login();
            break;
        case 'B' | 'b':
            create_account();
            break;
        case 'E' | 'e':
            break;
        default:
            std::cout << std::endl << "****Not valid input****" << std::endl << std::endl;
            options();
    }
}

void MainMenu::login()
{
    UserProfile profile;
    std::string username;
    std::string password;

    std::cout << std::endl << "Login" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;

    // TODO: mask or hide input
    std::cout << "Password: ";
    std::cin >> password;

    bool result = profile.verify_user_profile(username, password);
    if(result)
    {
        std::cout << "You're logged in!!!" << std::endl;
    }
    else 
    {
        char input;
        std::cout << "Username and password combonation is incorrect" << std::endl;
        std::cout << "Try Again?" << std::endl;
        std::cin >> input;
        if(input == 'Y' || input == 'y')
        {
            login();
        }
        else 
        {
            options();
        }
    }
}

void MainMenu::create_account()
{
    UserProfile profile;
    std::string username;
    std::string password;

    // TODO: add a validator
    std::cout << "-----User Profile Creation-----" << std::endl;
    std::cout << "Enter a username: ";
    std::cin >> username;

    // TODO: force enter password twice and validate
    std::cout << "Enter a password: ";
    std::cin >> password;

    bool result = profile.set_user_profile(username, password);

    if(result)
    {
        std::cout << "User profile has been successfully created!" << std::endl;
    }
    else
    {
        std::cout << "Error: User profile not created" << std::endl;
    }
    options();
}