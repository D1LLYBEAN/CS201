// boxprint.cpp
// CS201_HW1_ExerciseA
// Dillon Mills
// Created on 9/8/17
// Inputs a line of text from the user - using line-oriented input with proper error handling - and then prints the text inside a box of asterisks.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;

int main()
{
    cout << "Enter text to be printed inside a box of asterisks: ";

    string userInput;
    getline(cin, userInput);
    if (!cin)
    {
        cout << "! Error: cin failure !" << endl;
        return 1;
    }

    int userInputSize = userInput.size();
    if (!userInputSize)
    {
        cout << "! Error: string input length 0 !" << endl;
        return 1;
    }

    string outputString;
    for(int i = 0; i < userInputSize + 4; i++)      // *************
    {
        outputString += "*";
    }
    outputString += "\n*";
    for(int i = 0; i < userInputSize + 2; i++)      // *           *
    {
        outputString += " ";
    }
    outputString += "*\n* " + userInput + " *\n*";  // * userInput *
    for(int i = 0; i < userInputSize + 2; i++)      // *           *
    {
        outputString += " ";
    }
    outputString += "*\n";
    for(int i = 0; i < userInputSize + 4; i++)      // *************
    {
        outputString += "*";
    }
    cout << endl << outputString << endl;

    // OUTPUT:
    //
    // *************
    // *           *
    // * userInput *
    // *           *
    // *************
    //

    return 0;
}
