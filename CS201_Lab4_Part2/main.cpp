// main.cpp
// CS201_Lab2_Part2
// Dillon Mills
// Created on 9/8/17
// Prints a 60 × 10 box made of some single character, using nested loops.

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 60; col++)
        {
            cout << "#";
        }
        cout << endl;
    }

    return 0;
}
