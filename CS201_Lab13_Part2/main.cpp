// main.cpp
// CS201_Lab12_Part3
// Dillon Mills
// Created on 9/27/17
// Inputs an arbitrary number of lines of text from the user. After all the input is done, the program prints out every line (containing "x") that was typed.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;


int main()
{
    vector<string> stringVector {"Hello", "", "Goodbye", "", "NULLs in lines 2 and 4 above."};

    cout << "Enter \\ to stop inputting lines." << endl << endl;
    while(true)
    {
        string userInput;
        getline(cin, userInput);
        if (!cin)
        {
            cout << endl << "! Error: cin failure!" << endl;
            return 1;
        }
        if (userInput == "\\")
        {
            cout << endl << "Exiting..." << endl << endl;
            break;
        }

        stringVector.push_back(userInput);
    }

    for (auto &nStr : stringVector)
    {
        if(nStr[0] != 0)
        {
            nStr[0] = 'x';
        }
    }

    string outputString;
    for (auto nStr : stringVector)
    {
        outputString += nStr + '\n';
    }

    cout << "Strings:" << endl << outputString << endl;
    return 0;
}
