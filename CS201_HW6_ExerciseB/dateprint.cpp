// dateprint.cpp
// CS201_HW6_ExerciseB
// Dillon Mills
// Created on 11/12/17
//
// Reads a string from the user containing a date in the form "mm/dd/yyyy", then the date in the form "Month dd, yyyy".

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::stringstream;
#include <map>
using std::map;
#include <vector>
using std::vector;


int main()
{
    map<int,string> months =
    {
        {1, "January"},
        {2, "February"},
        {3, "March"},
        {4, "April"},
        {5, "May"},
        {6, "June"},
        {7, "July"},
        {8, "August"},
        {9, "September"},
        {10, "October"},
        {11, "November"},
        {12, "December"},
    };

    while (true)
    {
        cout << "Enter date (m/d/y): ";

        string userLine;
        getline(cin, userLine);
        if(userLine == ""){ break; }

        stringstream ss;
        ss << userLine;

        string tempStr;
        vector<int> userDate(3);
        int i = 0;
        bool badInput = false;

        while(getline(ss, tempStr, '/'))
        {
            if(!(stringstream(tempStr) >> userDate[i])){ badInput = true; }
            i++;
        }

        if(badInput)
        {
            cout << "\n! Error: input type !\n\n";
            continue;
        }
        if(i < 3)
        {
            cout << "\n! Error: too few inputs !\n\n";
            continue;
        }
        if(i > 3)
        {
            cout << "\n! Error: too many inputs !\n\n";
            continue;
        }
        if(userDate[0] < 1 || userDate[0] > 12)
        {
            cout << "\n! Error: month range !\n\n";
            continue;
        }
        if(userDate[1] < 1 || userDate[1] > 31)
        {
            cout << "\n! Error: day range !\n\n";
            continue;
        }
        else if(((userDate[0] == 4 || userDate[0] == 6 || userDate[0] == 9 || userDate[0] == 11) && userDate[1] > 30) || (userDate[0] == 2 && userDate[1] > 29)) // this is trash!
        {
            cout << "\n! Error: day range (month specific) !\n\n";
            continue;
        }
        if(userDate[2] == 0)
        {
            cout <<"\n! Error: year 0 does not exist in the Anno Domini system !\n\n";
            continue;
        }

        string BCAC = "";
        if (userDate[2] < 0)
        {
            userDate[2] *= -1;
            BCAC = " BC";
        }

        cout << "\nDate: " << months[userDate[0]] << " " << userDate[1] << ", " << userDate[2] << BCAC << "\n\n";
    }

    return 0;
}
