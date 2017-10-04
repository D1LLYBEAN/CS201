// assoc.cpp
// CS201_HW4_ExerciseBS
// Dillon Mills
// Created on 10/4/17
// Allows the user to create, modify, and query an associative dataset.

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

// linear search
int linearSearch(vector<int> keys, vector<int> values, int thekey)
{
    for(int i = 0; i < keys.size(); i++)
    {
        if(keys[i] == thekey)
        {
            return i;
        }
    }
    return -1;
}


// Main program
// Create a dataset, and do searches in it.
int main()
{
    // Make associative (KEY-VALUE) dataset
    vector<int> keys {};
    vector<int> values {};

    cout << "Associative Dataset\n";

    // Input & search loop
    while (true)
    {
        // Print menu
        cout << "\n1 Set the value associated with a key\n2 View the value associated with a key\n3 Quit\n\nChoice: ";

        // Get a line
        string userInput;
        getline(cin, userInput);
        if (!cin){ cout << "! Error: cin failure !" << endl; return 1; }
        istringstream in(userInput);
        int choice;
        in >> choice;
        if (!in || choice < 1 || choice > 3) { cout << "! Error: invalid input !" << endl; continue; }

        // Execute chosen menu action
        if (choice == 1) // SET
        {
            cout << "Enter key and value [key value]: ";
            getline(cin, userInput);
            if (!cin){ cout << "! Error: cin failure !" << endl; return 1; }
            istringstream in(userInput);
            int userKey, userValue;
            in >> userKey >> userValue;
            if (!in || userKey < 1) { cout << "! Error: invalid input !" << endl; continue; }

            int foundIndex = linearSearch(keys, values, userKey);
            if (foundIndex > -1)
            {
                values[foundIndex] = userValue;
            }
            else
            {
                keys.push_back(userKey);
                values.push_back(userValue);
                foundIndex = keys.size() - 1;
            }
            cout << "VALUE = " << values[foundIndex] << "; stored at KEY = " << keys[foundIndex] << "." << endl;
        }
        else if (choice == 2) // VIEW
        {
            cout << "Enter key: ";
            getline(cin, userInput);
            if (!cin){ cout << "! Error: cin failure !" << endl; return 1; }
            istringstream in(userInput);
            int userKey;
            in >> userKey;
            if (!in || userKey < 1) { cout << "! Error: invalid input !" << endl; continue; }

            int foundIndex = linearSearch(keys, values, userKey);
            if (foundIndex > -1)
            {
                cout << "KEY found; VALUE = " << values[foundIndex] << endl;
            }
            else
            {
                cout << "KEY not found" << endl;
            }
        }
        else // QUIT
        {
            break;
        }
    }
}
