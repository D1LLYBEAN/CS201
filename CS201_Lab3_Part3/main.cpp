// main.cpp
// CS201_Lab3_Part3
// Dillon Mills
// Created on 9/6/17
// Do something fancier with line-oriented input.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
using std::find;
using std::tolower;
#include <locale>
using std::locale;

int main()
{
    cout << "Enter a food: ";
    string userFood;
    getline(cin, userFood);
    for( int i = 0; i < userFood.size(); i++)
    {
        userFood[i] = tolower(userFood[i]);
    }
    //cout << userFood << endl; prints input out in lowercase, for debugging.
    if (userFood.find("pizza") != null)
    {
        cout << "I think " << userFood << " tastes good." << endl;
    }
    else
    {
        cout << userFood << " is not pizza." << endl;
    }

    return 0;
}
