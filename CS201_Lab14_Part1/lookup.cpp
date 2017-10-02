// lookup.cpp  INCOMPLETE
// Glenn G. Chappell
// 3 Oct 2016
//
// For CS 201 Fall 2016
// Look-up by Key
//
// Modified slightly by
// Chris Hartman
// 2 Oct 2017
// For CS 201 Fall 2017
//
// Modified again by
// Dillon Mills
// 2 Oct 2017
// For CS 201 Lab 14

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;

// linearSearch
// Given a vector<int> holding keys, and a vector<string> holding the
// associated values, and a key to search for (thekey). Does Linear
// Search in an attempt to find the given key. If it is not found,
// returns false. If it is found, sets thevalue to the associated value
// and returns true.
bool linearSearch(vector<int> keys,
                  vector<string> values,
                  int thekey,
                  string & thevalue)
{
    for(int i = 0; i < keys.size(); i++)
    {
        if(keys[i] == thekey)
        {
            thevalue = values[i];
            return true;
        }
    }

    return false;
}


// Main program
// Create a dataset, and do searches in it.
int main()
{
    // Make associative (KEY-VALUE) dataset
    vector<int> keys {21,  22, 23, 25, 27, 31, 32, 33, 36, 38};
    vector<string> values {
        "Alice Smith",
        "Bill Jones",
        "Charles Johnson",
        "Daphne Robertson",
        "Egbert Williams",
        "Fifi Phillips",
        "George Watson",
        "Harriet Baker",
        "Iris Gump",
        "Jake Hawkins"
    };

    // Print opening message
    cout << "Linear Search in a key-value dataset" << endl;
    cout << endl;

    // Input & search loop
    while (true)
    {
        // Get a line
        cout << "Type a positive integer KEY (empty line to end): ";
        string line;
        getline(cin, line);
        if (!cin)
            return 1;
        if (line == "")
            break;

        // Get an int from the above line
        istringstream in(line);
        int thekey;
        in >> thekey;
        if (!in) {
            cout << "Please type a positive integer" << endl;
            cout << endl;
            continue;
        }
        if (thekey < 1) {
            cout << "Please type a positive integer" << endl;
            cout << endl;
            continue;
        }

        string thevalue;
        bool found = linearSearch(keys, values, thekey, thevalue);
        if (found)
            cout << "KEY found; VALUE = " << thevalue << endl;
        else
            cout << "KEY not found" << endl;
        cout << endl;
    }
    cout << endl;

    // Quit when user hits Enter
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
}
