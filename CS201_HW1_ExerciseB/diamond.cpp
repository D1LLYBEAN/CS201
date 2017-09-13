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
#include<stdlib.h>

int main()
{
    cout << "Enter a positive diamond size integer: ";

    string userInput;
    getline(cin, userInput);
    if (!cin)
    {
        cout << endl << "! Error: cin failure!" << endl;
        return 1;
    }

    istringstream iss(userInput);
    int userInt;
    iss >> userInt;
    if (!iss)
    {
        cout << endl << "! Error: iss not an integer !" << endl;
        return 1;
    }

    if (userInt <= 0)
    {
        cout << endl << "! Error: input length " << userInt << " less than one!" << endl;
        return 1;
    }

    string outputString = "\n";
    for (int i = -userInt; i <= userInt; i++)
    {
        for (int j = -userInt; j <= userInt; j ++)
        {
            if (abs(i) + abs(j) > userInt) // form diamond outline with " "
            {
                outputString += " ";
            }
            else if ((abs(i) % 2) == (abs(j) % 2)) // checkerboard "." within diamond zone
            {
                outputString += ".";
            }
            else
            {
                outputString += "#"; // fill in remaining spaces within diamond with "#"
            }
        }
        outputString += "\n";
    }
    cout << outputString;

    return 0;
}
