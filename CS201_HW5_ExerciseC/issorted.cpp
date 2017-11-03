// collatzfile.cpp
// CS201_HW5_ExerciseB
// Dillon Mills
// Created on 11/2/17
//
// Function isSorted takes a vector<int> and a bool.
// If the given bool is true, then the function checks whether the given vector is sorted in ascending order;
// otherwise, it checks whether the vector is sorted in descending order.
// The function returns true if the given vector is sorted as required;
// otherwise it returns false.

#include <iostream>
using std::cout;
using std::endl;
#include <sstream>
using std::ostringstream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "issorted.hpp"

bool isSorted(const vector<int> & data, bool ascending)
{
    if(data.size() <= 1){ return true;}
    bool isAscending = true;
    bool isDescending = true;
    for (unsigned int i = 0; i < data.size() - 1; i++)
    {
        if(data[i] > data[i+1]){ isAscending = false; }
        if(data[i] < data[i+1]){ isDescending = false; }
    }
    if(ascending && isAscending){ return true; }
    else if(!ascending && isDescending){ return true; }
    else{ return false; }
}
