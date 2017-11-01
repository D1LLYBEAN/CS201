// trunc.cpp
// Glenn G. Chappell
// 30 Oct 2016
//
// For CS 201 Fall 2016
// Source for functions trunc8, trunc
//
// Modified 11/1/2017
// Chris Hartman
// For CS 201 Fall 2017
//
// Completed By:
// Dillon Mills
// 1 November 2017


#include "trunc.hpp"
#include <tuple>
using std::tuple;
using std::make_tuple;
using std::get;
#include <string>
using std::string;
#include <cctype>
using std::toupper;


// trunc
// (See header for description.)
tuple<string, int> trunc(const tuple<string, int> & t)
{
    // Get input string & maxlen
    string s = get<0>(t);
    int maxlen = get<1>(t);
    if (maxlen < 0)
        maxlen = 0;

    // Truncate string & get its new length
    if (int(s.size()) > maxlen)
        s = s.substr(0, maxlen);
    int len = int(s.size());

    // Convert string to upper-case
    for (int i = 0; i < len; ++i)
        s[i] = char(toupper(s[i]));

    // Create return value
    return make_tuple(s, len);
}


// trunc8
// (See header for description.)
tuple<string, int> trunc8(const string & s)
{
    return trunc(make_tuple(s, 8));
}
