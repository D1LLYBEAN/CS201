// printprimes.cpp
// CS201_HW3_ExerciseB
// Dillon Mills
// Created on 9/25/17
// Stores a list of all the prime numbers from 1 through 100 in a file.

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;
#include <fstream>
using std::ofstream;

// Takes an integer as an argument and returns true if the argument is a prime number and false otherwise.
int isPrime(int intToTest)
{
    for (int i = 2; i < intToTest / 2 + 1; i++)
    {
        if (intToTest % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    cout << "Also saved to primes.txt" << endl << endl;
    string outputString;
    for (int i = 1; i <= 100; i++)
    {
        if (isPrime(i))
        {
            ostringstream ss;
            ss << i;
            outputString += ss.str() + ", ";
        }
    }
    outputString.replace(outputString.length() - 2, 2, ".");
    cout << "Primes: " << outputString << endl;

    ofstream myFile("primes.txt");
    if (!myFile)
    {
        cout << endl << "! Error: failed to open file !" << endl;
        return 1;
    }
    myFile << "Primes: " << outputString << endl;
    if (!myFile)
    {
        cout << endl << "! Error: failed to write to file !" << endl;
        return 1;
    }
    return 0;
}
