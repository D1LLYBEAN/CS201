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
    vector<string> stringVector {"Hello", "", "Goodbye", ""};

    string outputString;
    for (auto nVec : stringVector)
    {
        outputString += nVec + '\n';
    }

    cout << "Strings:" << endl << outputString << endl;
    return 0;
}
