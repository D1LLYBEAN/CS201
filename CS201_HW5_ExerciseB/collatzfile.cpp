// collatzfile.cpp
// CS201_HW5_ExerciseB
// Dillon Mills
// Created on 11/2/17
//
// Inputs two positive integers from the user.
// Calling the two integers a and b, the program then opens file cseqs.txt
// and writes to it the Collatz sequences starting at a, starting at a+1, at a+2, etc.
// ending with the Collatz sequence starting at b.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
using std::ostringstream;
#include <vector>
using std::vector;
#include <math.h>
#include <fstream>
using std::ofstream;


int main()
{
    // take user input, repeat if error detected...
    int userInt_a, userInt_b;
    while (true)
    {
        // take user input...
        cout << "Enter two positive integers (a b): ";
        string userLine;
        getline(cin, userLine);
        if(!cin || userLine == ""){ return 1; }

        // convert to int_a and int_b...
        istringstream iss(userLine);
        iss >> userInt_a >> userInt_b;

        // do error checking...
        if (!iss)
        {
            cout << "! Error: iss not an integer !\n";
            continue;
        }
        if (userInt_a <= 0 || userInt_b <= 0)
        {
            cout << "! Error: non-positive integer(s) !\n";
            continue;
        }
        if (userInt_a > userInt_b)
        {
            cout << "a > b, swapping...\n";
            int save_userInt_a = userInt_a;
            userInt_a = userInt_b;
            userInt_b = save_userInt_a;
        }
        break;
    }

    // prepare to output collatz to file and notify user...
    cout << "\nWriting Collatz to cseqs.txt...\n";
    ofstream myfile;
    myfile.open("cseqs.txt");

    // calculate Collatz multiple times and output to file...
    while (userInt_a <= userInt_b)
    {
        // calculate Collatz once, storing the line into ostringstream...
        ostringstream ss;
        int userInt = userInt_a;
        while(userInt > 1)
        {
            ss << userInt << ", ";
            if (userInt % 2)
            {
                userInt = (3 * userInt) + 1;
            }
            else
            {
                userInt = userInt / 2;
            }
        }
        ss << userInt;

        // output ostringstream line to file...
        myfile << ss.str() << endl;

        // increment to next Collatz starting value...
        userInt_a++;
    }

    // close file and notify user of program success...
    myfile.close();
    cout << "\nCollatz successfully written to cseqs.txt\n";

    return 0;
}
