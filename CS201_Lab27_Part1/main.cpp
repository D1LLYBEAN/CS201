// main.cpp
// CS201_Lab27_Part1
// Dillon Mills
// Created on 11/08/17


#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <map>
using std::map;

int main()
{
    map<int, string> assocMap;

    while(true)
    {
        cout << "Enter a key-value pair (int string): ";
        string userLine;
        getline(cin,userLine);
        if(userLine == ""){break;}
        int userInt;
        string userString;
        istringstream iss(userLine);
        iss >> userInt;
        getline(iss,userString);
        if(!iss)
        {
            cout << "! Error: iss !\n";
            continue;
        }
        assocMap[userInt] = userString;
    }

    cout << "\nSorted associated key-value pairs:\n";
    for(auto p : assocMap)
    {
        cout << "Key: " << p.first << ", ";
        cout << "Value : " << p.second << endl;
    }

    while(true)
    {
        cout << "\nEnter a key (int): ";
        string userLine;
        getline(cin,userLine);
        if(userLine == ""){break;}
        int userInt;
        istringstream iss(userLine);
        iss >> userInt;
        if(!iss)
        {
            cout << "! Error: iss !\n";
            continue;
        }

        if (assocMap.count(userInt))
        {
            cout << "Key: " << userInt << ", ";
            cout << "Value : " << assocMap[userInt] << endl;
        }
        else
        {
            cout << "Nothing stored at key: " << userInt << endl;
        }
    }

    return 0;
}
