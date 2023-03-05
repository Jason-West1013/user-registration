#include <iostream>
#include <string>

#include "../include/menu.h"

using namespace std;

void Menu::initialLoginOptions()
{
    char input;

    cout << "Welcome to SomeApp" << endl;
    cout << "A: Login" << endl;
    cout << "B: Create Account" << endl;
    cout << "E: Exit" << endl;

    cin >> input;
        
    switch(input)
    {
        case 'A' | 'a':
            login();
            break;
        case 'B' | 'b':
            createAccount();
            break;
        case 'E' | 'e':
            break;
        default:
            cout << endl << "****Not valid input****" << endl << endl;
            initialLoginOptions();
    }
}

void Menu::login()
{
    string username;
    string password;

    cout << endl << "Login" << endl;
    cout << "Username: ";
    cin >> username;

    // TODO: mask or hide input 
    // https://cplusplus.com/articles/E6vU7k9E/
    // create masked input helper? To use elsewhere
    cout << "Password: ";
    cin >> password;

    // TODO: check database
    cout << username << " : " << password << endl;
}

void Menu::createAccount()
{
    cout << "Create Account" << endl;
}
