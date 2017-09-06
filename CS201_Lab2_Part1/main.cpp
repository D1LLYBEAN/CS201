// main.cpp
// CS201_Lab2_Part1
// Dillon Mills
// Created on 9/1/17
// Takes an integer user input, adds one to it, squares it, then outputs it to console.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Enter an integer: ";
    int userInt = 0;
    cin >> userInt;
    cout << "The square of (" << userInt << " + 1) is " << (userInt + 1) * (userInt + 1) << endl;
    return 0;
}
