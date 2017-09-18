// main.cpp
// CS201_Lab8_Part1
// Dillon Mills
// Created 9/18/17
// Takes a string parameter and prints an integer telling how long the string is.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;


void PrintStringLength(string str)
{
    cout << str.length() << endl;
}


int main()
{
    cout << "Enter \\ to exit!" << endl << endl;
    string userString;
    while(true)
    {
        cout << "Enter string to be counted: ";
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
        PrintStringLength(userString);
    }
    return 0;
}
