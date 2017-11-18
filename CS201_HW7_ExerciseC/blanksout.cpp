// vectormax.cpp
// CS201_HW7_ExerciseCS
//
// Dillon Mills
// November 17 2017
//
// Demonstrates the use of
// function vectorMax, calling it several times, with both empty and
// nonempty vectors.
//
// vectorMax that takes a vector<int>, and prints
// information about it in a neat, understandable manner. If the vector is
// empty, then a message to this effect is printed. Otherwise, the function
// should print all the items in the vector, and then the item with the
// greatest value. Determined using std::max_element.


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
using std::max_element;
#include <map>
using std::map;
#include <utility>
using std::pair;


void blanksOut(map<int,string> & m)
{
    for(pair<int,string> p : m)
    {
        while(true)
        {
            if(p.second[0] == ' ')
            {
                p.second.erase(0,1);
            }
            else
            {
                break;
            }
        }
        while(true)
        {
            if(p.second[p.second.length()-1] == ' ')
            {
                p.second.erase(p.second.length()-1,1);
            }
            else
            {
                break;
            }
        }
        m[p.first] = p.second;
        cout << p.first << ":\t|" << p.second << "|" << endl;
    }
}
