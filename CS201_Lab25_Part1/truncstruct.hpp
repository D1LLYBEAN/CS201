// truncstruct.h
// Glenn G. Chappell
// 2 Nov 2016
//
// For CS 201 Fall 2016
// Header for functions trunc8, trunc
// struct version

#ifndef FILE_TRUNCSTRUCT_H_INCLUDED
#define FILE_TRUNCSTRUCT_H_INCLUDED

#include <string>
using std::string;


// struct SI
// Holds string and info about its length.
struct SI {
    string str;
    int    len;
};


// trunc
// Given struct SI, truncates given string to length at most given
// length (or 0 if this is negative) and converted to upper-case.
// Returns struct SI of resulting string and its length.
SI trunc(const SI & t);


// trunc8
// Given a string, truncates input string to length at most 8 and
// converted to upper-case. Returns struct SI holding resulting string
// and its/ length.
SI trunc8(const string & s);


#endif //#ifndef FILE_TRUNCSTRUCT_H_INCLUDED

