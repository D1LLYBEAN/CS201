// main.cpp
// CS201_Lab15_Part1
// Dillon Mills
// Created on 10/6/17

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include "bubblesort.hpp"

int main()
{
    vector<int> values {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    cout << "Original:\n";
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << ", ";
    }
    cout << endl;

    bubblesort(values);

    cout << "\nResult:\n";
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << ", ";
    }
    cout << endl;
}
