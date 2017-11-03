// issorted_test.cpp
// Glenn G. Chappell
// 20 Oct 2016
//
// For CS 201, Fall 2016
// Test program for function isSorted
// Used in Assignment 5, Exercise C

#include "issorted.hpp"
// For function isSorted
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cstddef>
using std::size_t;


// b2s
// Return string form of given bool: "true" or "false".
string b2s(bool b)
{
    return b ? "true" : "false";
}


// doTest
// Do a single test of function isSorted. Given are the parameters for
// isSorted, the expected return value, and a bool indicating whether
// all tests have passed so far. The test is done. Results are printed
// to cout. If the test failed, then allPassed is set to false.
void doTest(const vector<int> & data,  // Test data
            bool ascending,            // bool argument for isSorted
            bool expected,             // Expected return value
            bool & allpassed)          // Set to false if test fails
{
    static int testnum = 0;
    ++testnum;
    bool result = isSorted(data, ascending);
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
    cout << "  Test data: ";
    if (data.empty())
    {
        cout << "{ }  [empty vector]" << endl;
    }
    else if (data.size() <= 12)
    {
        cout << "{ ";
        for (size_t i = 0; i+1 < data.size(); ++i)
        {
            cout << data[i] << ", ";
        }
        cout << data.back() << " }" << endl;
    }
    else
    {
        cout << "[too long to print]" << endl;
    }
    cout << "  Ascending: " << b2s(ascending) << endl;
    cout << "  Expected return value: " << b2s(expected) << endl;
    cout << "  Actual return value: " << b2s(result) << endl;
    cout << endl;
}


// Main program
// Do tests of function isSorted. Print results to cout.
int main()
{
    bool allpassed = true;  // Have all tests so far passed?
    cout << "Test Suite for function isSorted" << endl;
    cout << endl;

    // Tests from assignment description

    vector<int> v1 { 1, 4, 7, 7, 7, 10, 20 };
    doTest(v1, true, true, allpassed);    // Test #1
    doTest(v1, false, false, allpassed);  // Test #2

    vector<int> v2 { 3, 2, 1, 0, 0, -100 };
    doTest(v2, true, false, allpassed);   // Test #3
    doTest(v2, false, true, allpassed);   // Test #4

    vector<int> v3 { 1, 0, 1 };
    doTest(v3, true, false, allpassed);   // Test #5
    doTest(v3, false, false, allpassed);  // Test #6

    vector<int> v4 { 42 };
    doTest(v4, true, true, allpassed);    // Test #7
    doTest(v4, false, true, allpassed);   // Test #8

    // Other tests

    vector<int> v5 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    doTest(v5, true, true, allpassed);    // Test #9
    doTest(v5, false, true, allpassed);   // Test #10

    vector<int> v6 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 };
    doTest(v6, true, true, allpassed);    // Test #11
    doTest(v6, false, false, allpassed);  // Test #12

    vector<int> v7;
    doTest(v7, true, true, allpassed);    // Test #13
    doTest(v7, false, true, allpassed);   // Test #14

    vector<int> v8(1000000, -3);
    doTest(v8, true, true, allpassed);    // Test #15
    doTest(v8, false, true, allpassed);   // Test #16

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
