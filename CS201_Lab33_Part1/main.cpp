// student_main.cpp
// Glenn G. Chappell
// 22 Nov 2016
//
// For CS 201 Fall 2016
//
// Modified by Chris Hartman
// 11/22/17
//
// Simple Main Program for Class Student
// Requires student.hpp, student.cpp (not written yet?)

// *********************************************************************
// DO NOT MODIFY THIS FILE!
// *********************************************************************

#include "student.hpp"  // For class Student
#include "student.hpp"  // Oops! Twice. Hope this isn't a problem ...
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// Main program
// Create some Student objects and call their printInfo function.
int main()
{
    // Create student objects
    const Student s1("Iggy Abadaba");  // Name; id chosen automatically
    const Student s2("Frederica Figwig", 1234);      // Name & id
    const Student s3("Clifford Clumbergump", 2345);  // Name & id

    // Print info
    cout << "Info on first student:" << endl;
    s1.printInfo();
    cout << endl;

    cout << "Info on second student:" << endl;
    s2.printInfo();
    cout << endl;

    cout << "Info on third student:" << endl;
    s3.printInfo();
    cout << endl;

    // Quit when user hits Enter
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
}
