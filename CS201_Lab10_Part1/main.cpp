// collatz.cpp
// CS201_Lab10_Part1
// Dillon Mills
// Created on 9/22/17
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
using std::ostringstream;

bool IsDiv3(int intToDiv)
{
    return intToDiv % 3 == 0;
}

string FindDiv3(int low, int high)
{
    string outputString;
    for(int i = low; i < high; i++)
    {
        if (IsDiv3(i))
        {
            ostringstream ss;
            ss << i;
            outputString += ss.str() + ", ";
        }
    }
    if(outputString.length() >= 2)
    {
        outputString.replace(outputString.length() - 2, 2, ".");
    }
    else
    {
        outputString = "NULL";
    }
    return outputString;
}

int main()
{
    cout << "Enter \\ at any time to exit!" << endl;
    string userString;
    string userInput;
    while(true)
    {
        cout << "Enter two integers (low high): ";
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
        int userIntLow, userIntHigh;
        iss >> userIntLow >> userIntHigh;
        if (!iss)
        {
            cout << endl << "! Error: iss !" << endl;
            return 2;
        }
        iss.ignore(iss.str().length(),'\n');
        if (userIntLow > userIntHigh)
        {
            cout << endl << "! Error: low > high !" << endl << "Swapping low/high values..." << endl << endl;
            int tempint = userIntLow;
            userIntLow = userIntHigh;
            userIntHigh = tempint;
        }

        cout << FindDiv3(userIntLow, userIntHigh) << endl;
    }
    return 0;
}
