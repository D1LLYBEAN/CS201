// main.cpp
// CS201_Lab12_Part2
// Dillon Mills
// Created on 9/27/17
// Inputs an arbitrary number of lines of text from the user. After all the input is done, the program prints out every line (longer than 9 characters) that was typed.

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
    cout << "Enter as many lines of text as you'd like." << endl;
    cout << "Enter only '\\' to exit!" << endl << endl;
    vector<string> sVec(1);
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

        sVec.push_back(userInput);

    }

    string outputString;
    for (int i = 0; i < sVec.size(); i++)
    {
        if (sVec[i].length() >= 10)
        {
            outputString += sVec[i] + '\n';
        }
    }
    cout << "Inputs of length greater than 10:" << endl << outputString;

    return 0;
}
