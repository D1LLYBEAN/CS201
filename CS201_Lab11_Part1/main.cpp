// main.cpp
// CS201_Lab11_Part1
// Dillon Mills
// Created on 9/25/17
// Repeatedly does the following: input a number from the user, and print the number’s square, cube, and fourth power.

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


void SquareCubeFourth(int intToMult, int &square, int &cube, int &fourth, bool &isNegative, string &outputString)
{
    square = intToMult * intToMult;
    cube = intToMult * intToMult * intToMult;
    fourth = cube * intToMult;

    if (intToMult < 0)
    {
        isNegative = true;
    }

    ostringstream ss1;
    ss1 << square;
    outputString += "Square = " + ss1.str() + "\n";
    ostringstream ss2;
    ss2 << cube;
    outputString += "Cube = " + ss2.str() + "\n";
    ostringstream ss3;
    ss3 << fourth;
    outputString += "Fourth = " + ss3.str() + "\n";

    return;
}


int main()
{
    cout << "Enter \\ at any time to exit!" << endl;
    string userString;
    string userInput;
    int square, cube, fourth;
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
        bool isNegative;
        string outputString;
        SquareCubeFourth(userInt, square, cube, fourth, isNegative, outputString);
        if(isNegative)
        {
            cout << endl << "! Warning: " << userInt << " is negative !" << endl << endl;
        }
        cout << outputString << endl;
    }
    return 0;
}
