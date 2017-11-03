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
using std::ostringstream;
using std::istringstream;
#include <iomanip>
using std::setprecision;
using std::fixed;
#include <vector>
using std::vector;
#include <math.h>


int main()
{
    while(true)
    {
        // take user input...
        cout << "Type a nonnegative number (empty line to end): ";
        string userLine;
        getline(cin,userLine);
        if(userLine == ""){break;}

        // convert to double...
        double userDouble;
        istringstream iss(userLine);
        iss >> userDouble;

        // do error checking...
        if(!iss)
        {
            cout << "\n! Error: iss not a float !\n";
            continue;
        }
        if(userDouble < 0)
        {
            cout << "\n! Error: negative number !\n";
            continue;
        }

        // convert sqrt(double) to string with 8 digits past the decimal...
        ostringstream ss;
        ss << fixed << setprecision(8) << sqrt(userDouble);
        string outputDouble = ss.str();

        // format the spaces into a new string...
        string outputString(1,ss.str()[0]);
        for(unsigned int i = 1; i < outputDouble.length(); i++)
        {
            outputString += " ";
            outputString += outputDouble[i];
        }

        // output...
        cout << endl << outputString << endl << endl;
    }

    return 0;
}
