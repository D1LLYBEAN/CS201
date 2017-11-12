// reverse.cpp
// CS201_HW6_ExerciseD
// Dillon Mills
// Created on 11/12/17
//
// Demonstrates the function of reverseArray().
//
// reverseArray() accepts an int array and the array’s size as
// arguments, creates a copy of the array (except
// that the element values will be reversed in the copy), and then
// returns a pointer to the new array.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::stringstream;
#include <map>
using std::map;
#include <vector>
using std::vector;


int * reverseArray(const int arr[], int arrSize)
{
    int * newArr = new int[arrSize];
    for(int i = 0; i < arrSize; i++)
    {
        newArr[i] = arr[arrSize - i - 1];
    }

    return newArr;
}

int main()
{
    int oldArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // I didn't feel like doing anything clever here, like user input...

    cout << "Old Array:";
    for (int i = 0; i < 10; i++)
    {
        cout << " " << oldArr[i];
    }
    cout << endl;

    int * newArr = reverseArray(oldArr,10);

    cout << "New Array:";
    for (int i = 0; i < 10; i++)
    {
        cout << " " << newArr[i];
    }
    cout << endl;

    delete [] newArr;

    return 0;
}
