// main.cpp
// CS201_Lab6_Part1
// Dillon Mills
// Created 9/13/17
// Starting point: line-oriented integer input

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;


// Main program
// Input an integer with error checking.
int main()
{
    int pX = 0; // player position X
    int pY = 0; // player position Y

    cout << "Enter \\ at any point to exit!" << endl;

    while (true)
    {
        cout << endl << "Your coordinates are: (" << pX << "," << pY << ")" << endl;
        // Input a line, with error checking
        string line;
        cout << "Enter a direction to move (WASD): ";
        getline(cin, line);
        if (!cin)
        {
            cout << "! Error: cin failure !" << endl;
            break;
        }

        // Input an integer from the above line
        istringstream iss(line);
        char userChar;  // Integer to input from line
        iss >> userChar;
        if (!iss)
        {
            cout << endl << "! Error: iss not a char !" << endl;
            continue; // skips printing process, returns to asking for input.
        }

        if (userChar == '\\'){break;} // exits if the user enters \

        if (userChar >= 'a' || userChar <= 'z')
        {
            userChar -= 'a' - 'A'; // convert to uppercase
        }

        switch (userChar)
        {
            case 'W': // move North
                pY++;
                cout << "You moved North" << endl;
                break;
            case 'A': // move West
                pX--;
                cout << "You moved North" << endl;
                break;
            case 'S': // move South
                pY--;
                cout << "You moved North" << endl;
                break;
            case 'D': // move East
                pX++;
                cout << "You moved North" << endl;
                break;
            default:
                for (int i = 0; i < 3; i++)
                {
                    cout << "! Error: invalid input !" << endl;
                }
                break;
        }
    }
    cout << endl << "Goodbye, I'll miss you!" << endl << endl;

    // Quit when user hits Enter
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
}
