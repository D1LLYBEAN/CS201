// truncstruct.cpp
// Glenn G. Chappell
// 2 Nov 2016
//
// For CS 201 Fall 2016
// Source for functions trunc8, trunc
// struct version
//
// Modified 11/3/2017
// Chris Hartman
// For CS 201 Fall 2017

#include "truncstruct.hpp"
// For struct SI definition
#include <string>
using std::string;
#include <cctype>
using std::toupper;


// trunc
// (See header for description.)
SI trunc(const SI & t)
{
    // Get input string & maxlen
    string s = t.str;
    int maxlen = t.len;
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
    return SI { s, len };
}


// trunc8
// (See header for description.)
SI trunc8(const string & s)
{
    return trunc(SI { s, 8 });
}
