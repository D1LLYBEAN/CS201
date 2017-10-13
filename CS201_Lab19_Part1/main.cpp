// main.cpp
// CS201_Lab19_Part1
// Dillon Mills
// Created on 10/13/17

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <cmath>
using std::abs;


int main()
{
    while (true)
    {
        string userInput;
        cout << "Enter a string: ";
        getline(cin, userInput);
        if (!cin){return 0;}
        if (userInput == ""){break;}

        for(int i = -((userInput.size() - 1) / 2); i <= ((int)userInput.size() - 1) / 2; i++)
        {
            int j = abs(i);
            cout << string(j,' ') << userInput.substr(j, userInput.size() - (2 * j)) << string(j,' ') << endl;
        }
    }

    return 0;
}
