// main.cpp
// CS201_Lab20_Part1
// Dillon Mills
// Created on 10/16/17

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;


void changeInt(int * ip)
{
    (*ip) *= (*ip);
}


int main()
{
    cout << "Enter a NULL line to exit." << endl;
    cout << "Function changeInt() squares an int." << endl;
    while (true)
    {
        string userInput;
        cout << "\nEnter an integer: ";
        getline(cin, userInput);
        if (!cin){return 0;}
        if (userInput == ""){break;}

        int userInt;
        istringstream iss(userInput);
        iss >> userInt;
        if(!iss){continue;}

        cout << "You Entered: " << userInt << endl;
        changeInt(&userInt);
        cout << "New Value:   " << userInt << endl;
    }
    cout << "\nExiting...\n";
    return 0;
}
