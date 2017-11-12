// verify.cpp
// CS201_HW6_ExerciseA
// Dillon Mills
// Created on 11/12/17
//
// Asks for a password and then verifies that it meets the stated criteria.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;


bool containsChars(string str, int checkChars)
{
    char startChar, endChar;
    switch (checkChars)
    {
    case 0:
        startChar = 'A';
        endChar = 'Z';
        break;
    case 1:
        startChar = 'a';
        endChar = 'z';
        break;
    case 2:
        startChar = '0';
        endChar = '9';
        break;
    default:
        break;
    }
    for(char n : str)
    {
        if(n >= startChar && n <= endChar)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    cout << "Password must:\n";
    cout << "be at least six characters long,\n";
    cout << "contain at least one uppercase letter,\n";
    cout << "contain at least one lowercase letter,\n";
    cout << "have at least one digit.\n";

    string userLine;

    while (true)
    {
        cout << "\nEnter password: ";

        getline(cin, userLine);

        bool error = false;

        if(userLine.size() < 6)
        {
            error = true;
            cout << "! Error: Password must be at least six characters long !\n";
        }
        if (!containsChars(userLine,0))
        {
            error = true;
            cout << "! Error: Password must contain at least one uppercase letter !\n";
        }
        if (!containsChars(userLine,1))
        {
            error = true;
            cout << "! Error: Password must contain at least one lowercase letter !\n";
        }
        if (!containsChars(userLine,2))
        {
            error = true;
            cout << "! Error: Password must have at least one digit !\n";
        }

        if(error == false){ break; }
    }

    cout << "\nYour new password is: " << userLine << endl;

    return 0;
}
