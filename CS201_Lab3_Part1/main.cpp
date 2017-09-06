// main.cpp
// CS201_Lab3_Part1
// Dillon Mills
// Created on 9/6/17
// Asks the user to type their full name, then prints “Your name is: ”, followed by the user’s name on the same line.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;

int main()
{
    cout << "Enter your full name: ";
    string userName;
    getline(cin, userName);
    cout << "Your name is " << userName << "." << endl;

    return 0;
}
