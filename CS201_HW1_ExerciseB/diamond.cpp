// diamond.cpp
// CS201_HW1_ExerciseB
// Dillon Mills
// Created on 9/8/17
// Inputs a positive integer from the user - using line-oriented input with proper error handling - and then prints a correspondingly sized diamond made of pound signs.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;

int main()
{
    cout << "Enter a positive diamond size integer: ";

    string userInput;
    getline(cin, userInput);
    if (!cin)
    {
        cout << "! Error: cin failure!" << endl;
        return 1;
    }

    istringstream iss(userInput);
    int userInt;
    iss >> userInt;
    if (!iss)
    {
        cout << "! Error: iss not an integer !" << endl;
        return 1;
    }

    if (userInt <= 0)
    {
        cout << "! Error: input length " << userInt << " !" << endl;
        return 1;
    }

    cout << endl; // for personal formatting preferences
    for(int i = 0; i < userInt; i++) // counting up this time
    {
        for(int j = 1; j <= (2 * userInt) - 1; j++) // j needs to start at 1
        {
            if(j < userInt - i || j > userInt + i) // not diamond
            {
                cout << " ";
            }
            else if ((i % 2) == (j % 2)) // periods
            {
                cout << ".";
            }
            else
            {
                cout << "#"; // diamond
            }
        }
        cout << endl;
    }
    for(int i = userInt - 2; i >= 0; i--) // counting down this time
    {
        for(int j = 1; j <= (2 * userInt) - 1; j++) // j needs to start at 1
        {
            if(j < userInt - i || j > userInt + i ) // not diamond
            {
                cout << " ";
            }
            else if ((i % 2) == (j % 2)) // periods
            {
                cout << ".";
            }
            else // diamond
            {
                cout << "#";
            }
        }
        cout << endl;
    }

    return 0;
}
