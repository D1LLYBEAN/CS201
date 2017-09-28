// rps.cpp
// CS201_HW3_ExerciseC
// Dillon Mills
// Created on 9/28/17
// Lets the user play the game of Rock, Paper, Scissors against the computer.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
using std::tolower;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include <fstream>
using std::ofstream;


// random_int
// returns a random integer in the range [a, b].
// NOT VERY RANDOM, SHOULD BE SEEDED WITH TIME.
int random_int(int rMin, int rMax)
{
    // Construct a random-number generator object -- static, so it stays
    // around -- and seed it nondeterministically.
    static random_device rd;
    static mt19937 rng(rd());

    // Generate a random number in the given range, using our
    // random-number generator. Then return the number.
    return uniform_int_distribution<int>(rMin, rMax)(rng);
}


// IntToRPS
// converts int to rock, paper, or scissors string.
string IntToRPS (int intToConvert)
{
    switch (intToConvert)
    {
        case 1:
            return "rock";
            break;
        case 2:
            return "paper";
            break;
        case 3:
            return "scissors";
            break;
        default:
            return "! ERROR: invalid input !";
            break;
    }
}


// ToLowerCase
// convert string to lowercase.
string ToLowerCase (string stringToConvert)
{
    for (int i = 0; i < stringToConvert.length(); i++)
    {
        stringToConvert[i] = tolower(stringToConvert[i]);
    }
    return stringToConvert;
}


// OutputCompareRPS
// compares user and computer inputs and prints result to console.
void OutputCompareRPS (string userInput, string computerInput)
{
    // output choices and determine winner.
    cout << endl;
    cout << "Your choice: " << userInput << endl;
    cout << "Computer choice: " << computerInput << endl;
    if (userInput == computerInput)
    {
        cout << "TIE" << endl;
    }
    else if ((userInput == "rock" && computerInput == "paper") || (userInput == "paper" && computerInput == "scissors") || (userInput == "scissors" && computerInput == "rock"))
    {
        cout << "YOU LOSE" << endl;
    }
    else
    {
        cout << "YOU WIN" << endl;
    }
    cout << endl;
}


int main()
{
    cout << "Computer choices written to \"rps.txt\" every round, before user chooses, for integrity." << endl;
    cout << "Enter \\ at any time to exit!" << endl << endl;

    while (true)
    {
        // computer choses rock (1), paper (2), or scissors (3).
        int computerInt = random_int(1,3);
        string computerInput = IntToRPS(computerInt);
        ofstream myFile("rps.txt");
        if (!myFile)
        {
            cout << endl << "! Error: failed to open file !" << endl;
            return 1;
        }
        myFile << computerInput << endl;
        if (!myFile)
        {
            cout << endl << "! Error: failed to write to file !" << endl;
            return 1;
        }

        // take user input.
        cout << "Enter rock, paper, or scissors: ";
        string userInput;
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

        userInput = ToLowerCase(userInput);

        // test for invalid user input.
        if (userInput != "rock" && userInput != "paper" && userInput != "scissors")
        {
            cout << endl << "! Error: " << userInput << " is an invalid input !" << endl << endl;
            continue;
        }

        OutputCompareRPS(userInput, computerInput);
    }

    return 0;
}
