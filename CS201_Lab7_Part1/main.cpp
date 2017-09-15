// main.cpp
// CS201_Lab7_Part1
// Dillon Mills
// Created 9/15/17
// Open a text file, with proper error checking. Print the word “Hello” to the text file 40 times, each on a separate line. Do the printing inside a for-loop.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ofstream;

int main()
{
    // get text to print
    cout << "Enter text to print: " << endl;
    string userInput;
    getline(cin, userInput);
    if (!cin)
    {
        cout << "! Error: cin failure !" << endl;
        return 1;
    }
    istringstream iss1(userInput);
    string fileText = userInput;

    // get number of times to print
    cout << "Enter positive integer times to print: " << endl;
    getline(cin, userInput);
    if (!cin)
    {
        cout << "! Error: cin failure !" << endl;
        return 1;
    }
    istringstream iss(userInput);
    int printCount;
    iss >> printCount;
    if (!iss)
    {
        cout << endl << "! Error: iss not an integer !" << endl;
        return 1;
    }

    // get file name
    cout << "Enter file name: " << endl;
    getline(cin, userInput);
    if (!cin)
    {
        cout << "! Error: cin failure !" << endl;
        return 1;
    }
    string fileName = userInput;

    // Print text to file
    fileName += ".txt";
    ofstream myFile(fileName);
    if (!myFile)
    {
        cout << endl << "! Error: failed to open file !" << endl;
        return 0;
    }
    for (int i = 0; i < printCount; i++)
    {
        myFile << fileText << endl;
        if (!myFile)
        {
            cout << endl << "! Error: failed to write to file !" << endl;
            return 0;
        }
    }

    return 0;
}
