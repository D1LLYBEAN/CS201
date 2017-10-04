// gcd.cpp
// CS201_HW4_ExerciseA
// Dillon Mills
// Created on 10/2/17
// inputs two nonnegative integers from the user, prints the GCD of the two integers, and then repeats.

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
            cout << endl << "Exiting..." << endl;
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
