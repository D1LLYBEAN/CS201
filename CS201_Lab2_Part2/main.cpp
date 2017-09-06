// main.cpp
// CS201_Lab2_Part1
// Dillon Mills
// Created on 9/1/17
// Takes the user's birthday as three separate integers and returns it formatted to console.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Enter your birthday (MM DD YYYY): ";
    int userMonth, userDay, userYear;
    cin >> userMonth >> userDay >> userYear;
    cout << "The date you entered was " << userMonth << "/" << userDay << "/" << userYear << endl;
    return 0;
}
