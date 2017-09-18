// main.cpp
// CS201_Lab8_Part3
// Dillon Mills
// Created 9/18/17
// Takes a string parameter and prints its parameter backwards.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;


void PrintStringLength(string str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;
}


int main()
{
    cout << "Enter \\ to exit!" << endl << endl;
    string userString;
    while(true)
    {
        cout << "Enter string to be reversed: ";
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
