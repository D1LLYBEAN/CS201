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
#include <tuple>
using std::tuple;
using std::get;
using std::make_tuple;
#include "truncstruct.hpp"


int main()
{
    while(true)
    {
        cout << "Enter a string (empty line to end): ";
        string userLine;
        getline(cin,userLine);
        if(userLine == ""){break;}

        int userInt;
        while(true)
        {
            cout << "Enter an integer: ";
            string userLine2;
            getline(cin,userLine2);
            istringstream iss(userLine2);
            iss >> userInt;
            if(!iss)
            {
                cout << "! Error: not an integer !\n";
                continue;
            }
            break;
        }

        SI userStruct = {userLine, userInt};

        SI returnStruct = trunc8(userStruct.str);

        cout << "trunc8:\t" << returnStruct.str << "\t|\t" << returnStruct.len << endl;

        returnStruct = trunc(userStruct);

        cout << "trunc:\t" << returnStruct.str << "\t|\t" << returnStruct.len << endl;

        cout << endl;
    }

    return 0;
}
