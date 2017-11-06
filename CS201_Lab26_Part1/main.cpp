// main.cpp
// CS201_Lab24_Part1
// Dillon Mills
// Created on 11/01/17


#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;
#include <algorithm>
using std::reverse;


int main()
{
    cout << "Enter starting and ending indices to reverse (start end): ";
    string userLine;
    getline(cin,userLine);
    if(userLine == ""){return 1;}
    int userIntStart, userIntEnd;
    istringstream iss(userLine);
    iss >> userIntStart >> userIntEnd;
    if(!iss)
    {
        cout << "! Error: iss !\n";
        return 1;
    }

    vector<int> data {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto dataBegin = data.begin() + userIntStart;
    auto dataEnd = data.begin() + userIntEnd;

    auto iter = data.begin();
    while(iter < data.end())
    {
        cout << *iter << endl;
        iter++;
    }
    cout << endl;

    reverse(dataBegin, dataEnd);

    iter = data.begin();
    while(iter < data.end())
    {
        cout << *iter << endl;
        iter++;
    }
    cout << endl;

    return 0;
}
