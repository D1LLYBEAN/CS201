// main.cpp
// CS201_Lab5_Part2
// Dillon Mills
// Created on 9/11/17
// Write a program that includes a loop that uses a continue statement in some meaningful way. This can be a modification of your program from part 1.

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
        if(userInput.size() < maxStringLength){continue;}
        cout << userInput << " TOO LONG!" << endl;
        break;
    }

    return 0;
}
