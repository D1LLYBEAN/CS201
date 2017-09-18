// main.cpp
// CS201_Lab8_Part2
// Dillon Mills
// Created 9/18/17
// Takes a string parameter and prints a line of “#” characters, where the number of characters is equal to the length of the string.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;


void PrintStringLength(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        cout << "#";
    }
    cout << endl;
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
