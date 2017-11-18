// threesmall.cpp
// CS201_HW7_ExerciseA
//
// Dillon Mills
// November 17 2017
//
// Input integers from the user, continuing until the user types an empty
// line. If the first line typed by the user is empty, then quit the program.
// If the user typed three or fewer numbers, then print them all.
// If the user typed more than three values, then print the three smallest
// values.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;


const int MAX_INTVEC_SIZE = 3;


int main()
{
    vector<int> userInts;
    while(true)
    {
        cout << "Enter an integer (blank line to continue): ";
        string line;
        getline(cin,line);
        istringstream iss(line);
        if(line == "") { break; }
        int testInt;
        iss >> testInt;
        if(!iss)
        {
            cout << "\n! ERROR: not an integer !\n\n";
            continue;
        }
        if (userInts.size() < MAX_INTVEC_SIZE)
        {
            userInts.push_back(testInt);
            sort(userInts.begin(),userInts.end());
        }
        else
        {
            if(testInt < userInts[MAX_INTVEC_SIZE-1])
            {
                userInts[MAX_INTVEC_SIZE-1] = testInt;
                sort(userInts.begin(),userInts.end());
            }
        }
    }

    cout << "\nSmallest Three Values Entered: ";
    for (int n : userInts)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
