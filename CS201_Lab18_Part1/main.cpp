// main.cpp
// CS201_Lab18_Part1
// Dillon Mills
// Created on 10/11/17
// Converts numbers to strings using specified formatting

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <cmath>
#include <ios>
using std::fixed;
#include <iomanip>
using std::setprecision;
using std::setw;

int main()
{
    cout << fixed;
    for(int i = 0; i <= 20; i++)
    {
        cout << setprecision(2);
        cout << setw(4) << i * 0.05;
        cout << setprecision(8);
        cout << setw(12) << cos(i * 0.05);
        cout << setprecision(2);
        cout << setw(10) << exp(10.0 * i * 0.05) << endl;
    }
    return 0;
}
