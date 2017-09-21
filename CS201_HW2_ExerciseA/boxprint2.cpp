// boxprint2.cpp
// CS201_HW2_ExerciseA
// Dillon Mills
// Created on 9/21/17
// Inputs a line of text from the user - using line-oriented input with proper error handling - and then prints the text inside a box of asterisks.
// In addition to a string, it inputs a positive integer from the user, indicating the number of layers of asterisks to print.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;

int main()
{
    cout << "Enter \\ at any time to exit!" << endl;
    string userString;
    string userInput;
    while(true)
    {
        cout << endl << "Enter text to be printed inside a box of asterisks: ";
        getline(cin, userString);
        if (!cin)
        {
            cout << "! Error: cin failure !" << endl;
            return 1;
        }
        if (userString == "\\")
        {
            cout << endl << "Exiting..." << endl;
            break;
        }

        cout << "Enter box thickness: ";
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
        int userInt;
        iss >> userInt;
        if (!iss)
        {
            cout << endl << "! Error: iss not an integer !" << endl;
            return 1;
        }
        if (userInt <= 0)
        {
            cout << endl << "! Error: input length " << userInt << " less than one!" << endl;
            return 1;
        }

        int boxHeight = (userInt * 2) + 3;
        int boxWidth = (userInt * 2) + 2 + userString.size();
        string outputString = "\n";
        for (int row = 0; row <= boxHeight; row++)
        {
            for (int col = 0; col < boxWidth; col ++)
            {
                if (row < userInt || row > boxHeight - userInt || col < userInt || col >= boxWidth - userInt)
                {
                    outputString += "*";
                }
                else if (row < userInt + 1 || row > boxHeight - userInt - 1 || col < userInt + 1 || col >= boxWidth - userInt - 1)
                {
                    outputString += " ";
                }
                else
                {
                    outputString += userString[col - userInt - 1];
                }
            }
            outputString += "\n";
        }
        cout << outputString;
    }
    return 0;
}
