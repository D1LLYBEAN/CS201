// main.cpp
// CS201_Lab3_Part2
// Dillon Mills
// Created on 9/6/17
// Asks the user to type three integers on the same line, separated by space. It then prints the sum of these integers.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;

int main()
{
    cout << "Enter three integers, separated by spaces (i1 i2 i3): ";
    int userInts[3];
    cin >> userInts[0] >> userInts[1] >> userInts [2];
    cout << "The sum of the three integers is " << userInts [0] + userInts[1] + userInts[2] << endl;

    return 0;
}
