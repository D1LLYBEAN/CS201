// collatz.cpp
// CS201_HW2_ExerciseB
// Dillon Mills
// Created on 9/21/17
// Repeatedly inputs a positive integer from the user and print the Collatz sequence.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
using std::ostringstream;

int main()
{
    cout << "Enter \\ at any time to exit!" << endl;
    string userString;
    string userInput;
    while(true)
    {
        cout << "Enter an integer to be Collatzed: ";
        getline(cin, userInput);
        if (!cin)
        {
            cout << endl << "! Error: cin failure!" << endl;
            return 1;
        }
        if (userInput == "\\")
        {
            cout << endl << "Exiting..." << endl;
            break;
        }
        istringstream iss(userInput);
        int userInt;
        iss >> userInt;
        if (!iss)
        {
            cout << endl << "! Error: iss not an integer !" << endl;
            return 2;
        }
        if (userInt <= 0)
        {
            cout << endl << "! Error: input length " << userInt << " less than one!" << endl << endl;
            continue;
        }

        string outputString;
        while(userInt > 1)
        {
            ostringstream ss;
            ss << userInt;
            outputString += ss.str();
            outputString += ", ";
            if (userInt % 2)
            {
                userInt = (3 * userInt) + 1;
            }
            else
            {
                userInt = userInt / 2;
            }
        }
        ostringstream ss;
        ss << userInt;
        outputString += ss.str();
        outputString += ".";

        cout << outputString << endl;
    }
    return 0;
}
