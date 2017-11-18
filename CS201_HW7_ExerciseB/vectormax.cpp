// vectormax.cpp
// CS201_HW7_ExerciseB
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


void vectorMax(vector<int> intVec)
{
    static int vecCount = 0;
    ++vecCount;
    cout  << "Vector #" << vecCount << endl;
    if(intVec.size() == 0)
    {
        cout << "! ERROR: empty vector !\n";
    }
    else
    {
        cout << "All Items: ";
        for(int i : intVec)
        {
            cout << i << " ";
        }
        cout << "\nGreatest Value: " << *max_element(intVec.begin(),intVec.end()) << endl;
    }
    cout << endl;
}


int main()
{
    vector<int> v1 {5, 2, 7, 3, 8, 4, 1, 6, 1};
    vector<int> v2 {};
    vector<int> v3 {6, 6, 6, 6, 6, 6, 6};
    vector<int> v4 {4, 3, 2, 1};

    vectorMax(v1);
    vectorMax(v2);
    vectorMax(v3);
    vectorMax(v4);

    return 0;
}
