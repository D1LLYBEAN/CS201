// main.cpp
// CS201_Lab2_Part3
// Dillon Mills
// Created on 9/8/17
// Prints an [row] x [col] box (given by the user) made of some single character, using nested loops with error handling.

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
    cout << "Enter desired positive integer box size (row col): ";

    string userInput;
    getline(cin, userInput);
    if (!cin)
    {
        cout << "!Error: cin!" << endl;
        return 1;
    }

    istringstream iss(userInput);
    int userRow, userCol;
    iss >> userRow >> userCol;
    if (!iss)
    {
        cout << "!Error: iss!" << endl;
        return 1;
    }

    if (userRow == 0 || userCol == 0)
    {
        cout << "Error: row and col cannot be 0!" << endl;
        return 1;
    }

    for (int row = 0; row < userRow; row++)
    {
        for (int col = 0; col < userCol; col++)
        {
            cout << "#";
        }
        cout << endl;
    }

    return 0;
}
