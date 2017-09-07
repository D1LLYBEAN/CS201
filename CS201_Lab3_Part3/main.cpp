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

int main()
{
    cout << "Enter a food: ";
    string userFood;
    getline(cin, userFood);
    for( int i = 0; i < userFood.size(); i++)   // loop converts entire string to lowercase
    {
        userFood[i] = tolower(userFood[i]); // converts single character to lowercase
    }
    int found = userFood.find("pizza"); // returns position of first "pizza" in string, -1 if nothing is found
    userFood[0] = toupper(userFood[0]); // converts first character back to uppercase, for grammar purposes
    if (found != -1)    // if "pizza" is found...
    {
        cout << userFood << " tastes good." << endl;
    }
    else
    {
        cout << userFood << " is not pizza." << endl;
    }

    return 0;
}
