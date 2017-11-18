// blanksout_test.cpp
// Glenn G. Chappell
// 9 Nov 2016
//
// For CS 201, Fall 2016
// Test program for function blanksOut
// Used in Assignment 7, Exercise C
//
// Modified 11/15/17
// Chris Hartman
// For CS 201, Fall 2017

#include "blanksout.hpp"
// For function blanksOut
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <map>
using std::map;
#include <string>
using std::string;


// doTest
// Do a single test of function blanksOut. Given are the parameter for
// blanksOut, the expected return value, and a bool indicating whether
// all tests have passed so far. The test is done. Results are printed
// to cout. If the test failed, then allPassed is set to false.
void doTest(const map<int, string> & data,      // Test data
            const map<int, string> & expected,  // Expected return value
            bool & allpassed)              // Set to false if test fails
{
    static int testnum = 0;
    ++testnum;
    auto result = data;
    blanksOut(result);
    cout << "Test #" << testnum << ": ";

    // Did test pass?
    if (result == expected)
    {
        cout << "passed" << endl;
        return;
    }

    // Test failed
    allpassed = false;
    cout << "FAILED **********" << endl;
}


// Main program
// Do tests of function blanksOut. Print results to cout.
int main()
{
    bool allpassed = true;  // Have all tests so far passed?
    cout << "Test Suite for function blanksOut" << endl;
    cout << endl;

    // Tests from assignment description

    {
    map<int, string> m {
        { 33, "  x  y   " },
        { 51, "zzz" },
        { 40, "    aaa" }
    };
    map<int, string> mr {
        { 33, "x  y" },
        { 51, "zzz" },
        { 40, "aaa" }
    };
    doTest(m, mr, allpassed);  // Test #1
    }

    // Other tests

    {
    map<int, string> m;
    map<int, string> mr;
    doTest(m, mr, allpassed);  // Test #2
    }

    {
    map<int, string> m {
        { 1, "Z" }
    };
    map<int, string> mr {
        { 1, "Z" }
    };
    doTest(m, mr, allpassed);  // Test #3
    }

    {
    map<int, string> m {
        { 1, "Z            " }
    };
    map<int, string> mr {
        { 1, "Z" }
    };
    doTest(m, mr, allpassed);  // Test #4
    }

    {
    map<int, string> m {
        { 1, "                                 " }
    };
    map<int, string> mr {
        { 1, "" }
    };
    doTest(m, mr, allpassed);  // Test #5
    }

    {
    map<int, string> m {
        { -17000, "" }
    };
    map<int, string> mr {
        { -17000, "" }
    };
    doTest(m, mr, allpassed);  // Test #6
    }

    // Print results
    cout << endl;
    if (allpassed)
    {
        cout << "All tests passed" << endl;
    }
    else
    {
        cout << "NOT ALL TESTS PASSED ************************" << endl;
    }
    cout << endl;

    // Quit when user hits Enter
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
}
