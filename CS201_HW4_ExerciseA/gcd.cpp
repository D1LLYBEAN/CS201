// main.cpp
// CS201_Lab12_Part3
// Dillon Mills
// Created on 9/27/17
// Inputs an arbitrary number of lines of text from the user. After all the input is done, the program prints out every line (containing "x") that was typed.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;
#include <sstream>
using std::istringstream;

int GCD(int a, int b)
{
    while (a > 0)
    {
        cout << "a =\t" << a << ";\tb =\t" << b << endl;
        int temp = a;
        a = b % a;
        b = temp;
    }
    return b;
}


int main()
{
    cout << "Enter \\ to exit." << endl << endl;
    while (true)
    {
        cout << "Type two positive integers (a b): ";
        string userInput;
        getline(cin, userInput);
        if (!cin)
        {
            cout << endl << "! Error: cin failure!" << endl;
            return 1;
        }
        if (userInput == "\\")
        {
            cout << endl << "Exiting..." << endl << endl;
            break;
        }
        istringstream iss(userInput);
        int a, b;
        iss >> a >> b;
        if (!iss || a < 0 || b < 0)
        {
            cout << "! Error: iss, bad format or negative integer !" << endl << endl;
            continue;
        }
        cout << "a =\t0;\tb =\t" << GCD(a,b) << endl;
    }

    return 0;
}
