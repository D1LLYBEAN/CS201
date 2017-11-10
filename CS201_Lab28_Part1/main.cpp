// main.cpp
// CS201_Lab28_Part1
// Dillon Mills
// Created on 11/10/17


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
#include <utility>
using std::pair;
#include <algorithm>
using std::stable_sort;
#include <tuple>
using std::tuple;

int main()
{
    vector<tuple<string,string>> vt = {{"Hello", "World"}};

    vector<pair<string,string>> vectorPairs = {
        {"Alpha",   "zulu"},
        {"Bravo",   "yankee"},
        {"Charlie", "xray"},
        {"Delta",   "whiskey"},
        {"Echo",    "victor"},
        {"Foxtrot", "uniform"},
        {"Golf",    "tango"},
        {"Hotel",   "sierra"},
        {"Indigo",  "romeo"},
        {"Juliett", "quebec"},
        {"Kilo",    "papa"},
        {"Lima",    "oscar"},
        {"Mike",    "novemb"},
        {"Novemb",  "mike"},
        {"Oscar",   "lima"},
        {"Papa",    "kilo"},
        {"Quebec",  "juliett"},
        {"Romeo",   "indigo"},
        {"Sierra",  "hotel"},
        {"Tango",   "golf"},
        {"Uniform", "foxtrot"},
        {"Victor",  "echo"},
        {"Whiskey", "delta"},
        {"Xray",    "charlie"},
        {"Yankee",  "bravo"},
        {"Zulu",    "alpha"},
    };

    cout << "Original Vector:\n";
    for(auto n : vectorPairs)
    {
        cout << n.first << "\t" << n.second << endl;
    }

    while(true)
    {
        cout << "\nEnter sorting preference (asc/desc): ";
        string userLine;
        getline(cin,userLine);
        if(userLine == ""){break;}
        if (userLine == "asc"){
            stable_sort(vectorPairs.begin(),vectorPairs.end(),
                [](const pair<string,string> &a, const pair<string,string> &b){return a.second < b.second;} // second field, ascending
            );
        }
        else if (userLine == "desc"){
            stable_sort(vectorPairs.begin(),vectorPairs.end(),
                [](const pair<string,string> &a, const pair<string,string> &b){return a.second > b.second;} // second field, ascending
            );
        }
        else {cout << "\n! Error: invalid input !\n"; continue;}
        cout << "\nSorted Vector:\n";
        for(auto n : vectorPairs)
        {
            cout << n.first << "\t" << n.second << endl;
        }
    }

    return 0;
}
