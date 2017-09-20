// main.cpp
// CS201_Lab9_Part1
// Dillon Mills
// Created 9/20/17
//computes and returns the square of an integer.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;


string DivideInt(int intToDivide)
{
    string returnString;
    for (int i = 1; i < intToDivide / 2 + 1; i++)
    {
        if ((intToDivide % i) == 0)
        {
            returnString += i + '0';
            returnString += ", ";
        }
    }
    return returnString;
}


int main()
{
    cout << "Enter \\ to exit!" << endl << endl;
    string userString;
    while(true)
    {
        cout << "Enter integer to be squared: ";
        getline(cin, userString);
        if (!cin)
        {
            cout << "! Error: cin failure !" << endl;
            return 1;
        }
        if (userString == "\\")
        {
            cout << endl << "Exiting..." << endl;
            break;
        }
        istringstream iss(userString);
        int userInt;
        iss >> userInt;
        if (!iss)
        {
            cout << endl << "! Error: iss not an integer !" << endl;
            return 1;
        }
        cout << DivideInt(userInt) << endl;
    }
    return 0;
}
