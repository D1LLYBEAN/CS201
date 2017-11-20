// printtime.cpp  INCOMPLETE
// Glenn G. Chappell
// 20 Nov 2016
//
// Modified 11/20/17
// Chris Hartman
//
// For CS 201 Fall 2017
// Time of Day Class & Program

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>
using std::setw;
using std::setfill;


class Time {

// ***** Time: constructors *****
public:

    Time()
    {
        _hr = 0;
        _min = 0;
        _sec = 0;
    }
    Time(int i_hr, int i_min, int i_sec)
    {
        _hr = i_hr;
        _min = i_min;
        _sec = i_sec;
    }

// ***** Time: general public member functions *****
public:

    void print() const
    {
        cout << setfill('0') << setw(2) << _hr << ":";
        cout << setfill('0') << setw(2) << _min << ":";
        cout << setfill('0') << setw(2) << _sec;
    }

private:

    int _hr;   // Hours past midnight
    int _min;  // Minutes past the hour
    int _sec;  // Seconds past the minute

};


int main()
{
    // Print header
    cout << "Here are some times:" << endl;
    cout << endl;

    // Make a Time object; print it
    Time t1;
    cout << "Time #1: [";
    t1.print();
    cout << "]" << endl;
    cout << endl;

    // Make a Time object; print it
    Time t2(1,2,3);
    cout << "Time #1: [";
    t2.print();
    cout << "]" << endl;
    cout << endl;

    // Quit when user hits Enter
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
}
