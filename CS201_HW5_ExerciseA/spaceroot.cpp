// spaceroot.cpp
// CS201_HW5_ExerciseA
// Dillon Mills
// Created on 10/30/17
//
// Input a line from the user. If the line is empty, then quit.
// Read a (possibly fractional) number from the line. If the number is negative, then print an error message.
// If the number is not negative, then print the square root of the number, with exactly eight digits to the right of the decimal point, and a blank between each pair of consecutive characters.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;
#include <math.h>


int main()
{
    while(true)
    {
        cout << "Type a nonnegative number (empty line to end): ";
        string userLine;
        getline(cin,userLine);
        if(userLine == ""){break;}

        float userFloat;
        istringstream iss(userLine);
        iss >> userFloat;
        if(!iss)
        {
            cout << "\n! Error: iss not a float !\n";
            continue;
        }
        if(userFloat < 0)
        {
            cout << "\n! Error: negative number !\n";
            continue;
        }

        int sqrtDouble = (int)(sqrt(userFloat) * 100000000);

        cout << "Spaced-out square root: ";

        vector<int> digits;
        while (true)
        {
            digits.push_back(sqrtDouble % 10);
            sqrtDouble = sqrtDouble / 10;
            if(sqrtDouble < 1){break;}
        }

        for(int i = digits.size(); i >= 0; i++)
        {
            cout << digits[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
