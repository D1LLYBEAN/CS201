// sumnums.cpp
// CS201_HW3_ExerciseA
// Dillon Mills
// Created on 9/25/17
// Asks the user for a positive integer value, then uses a loop to get the sum of all the integers from 1 up to the number entered.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;


int SumToInt(int intToSum)
{
    if (intToSum > 1)
    {
        return intToSum + SumToInt(intToSum - 1);
    }
    else
    {
        return intToSum;
    }
}


int main()
{
    cout << "Enter \\ at any time to exit!" << endl;
    string userString;
    string userInput;
    while(true)
    {
        cout << "Enter an integer: ";
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
            cout << endl << "! Error: iss not an integer!" << endl;
            continue;
        }
        if (userInt < 1)
        {
            cout << endl << "! Error: " << userInt << " less than 1 !" << endl << endl;
            continue;
        }
        cout << "Sum = " << SumToInt(userInt) << endl;
    }
    return 0;
}
