// dynamic.cpp  INCOMPLETE
// Glenn G. Chappell
// 27 Oct 2016
//
// For CS 201 Fall 2016
// Dynamic Allocation
//
// Completed By:
// Dillon Mills
// 27 Oct 2017


#include <iostream>
using std::cout;
using std::endl;
using std::cin;


// printThree
// Takes a pointer to an int array, which must have size at least 3 --
// or a null pointer. Prints the first three items in the array, or
// "NULL POINTER", if the passed pointer is null.
void printThree(int const * p)
{
    if (p == nullptr)
    {
        cout << "NULL POINTER" << endl;
    }
    else
    {
        cout << p[0] << " " << p[1] << " " << p[2] << endl;
    }
    delete p;
}


// Main Program
// Do some dynamic allocation. Call printThree multiple times.
int main()
{
    cout << "PART 1:\n";
    // Make a dynamic array of int. Put at least three values in it.
    int * array3 = new int[3];
    for(int i=0; i<3; i++)
    {
        array3[i] = i * i;
    }
    // Then call printThree with it.
    cout << "\nprintThree(dynamic_array) twice:\n";
    printThree(array3);
    printThree(array3);
    cout << "\nprintThree(nullptr):\n";
    // Call printThree with a null pointer.
    printThree(nullptr);
    // Deallocate the dynamic array.
    cout << "\nDeallocating dynamic_array...\n";
    delete array3;
    cout << "Complete.\n";

    cout << "\n\n\nPART 2:\n";
    cout << "\na.\nThe 'const' in the parameter list of function printThree() IS NOT a problem here. I am still able to deallocate, despite 'const' being in the parameter list.\n";
    cout << "\nb.\nI think it SHOULD be a problem. It would be safer if 'const' would protect the original array.\n";
    cout << "\nc.\nIf I deallocate both in printThree() and in main(), nothing seems to happen.\n";

    // Quit when user hits Enter
    cout << "\n\n\nPress ENTER to quit.";
    while (cin.get() != '\n') ;
    cout << endl;
}
