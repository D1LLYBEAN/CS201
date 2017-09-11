// main.cpp
// CS201_Lab5_Part1
// Dillon Mills
// Created on 9/11/17
// Repeatedly inputs a line from the user and exits if the line is at least 10 characters long.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;

#define maxStringLength 10

int main()
{
    string userInput;
    while (true)
    {
        cout << "Enter a string: ";
        getline(cin, userInput);
        if (!cin)
        {
            cout << "! Error: cin failure !" << endl;
            return 1;
        }
        if(userInput.size() >= maxStringLength){break;}
        // this "While-True-Break" format allows DO_SOMETHING_WTIH_INPUT here.
    }
    cout << userInput << " TOO LONG!" << endl;

    return 0;
}
