// trunc.h
// Glenn G. Chappell
// 30 Oct 2016
//
// For CS 201 Fall 2016
// Header for functions trunc8, trunc
//
// Modified 11/1/2017
// Chris Hartman
// For CS 201 Fall 2017

#ifndef FILE_TRUNC_HPP_INCLUDED
#define FILE_TRUNC_HPP_INCLUDED

#include <tuple>
using std::tuple;
#include <string>
using std::string;


// trunc
// Given tuple holding a string and an int ("maxlen"), truncates given
// string to length at most maxlen (or 0 if maxlen is negative) and
// converted to upper-case. Returns tuple of resulting string and its
// length.
tuple<string, int> trunc(const tuple<string, int> & t);


// trunc8
// Given a string, truncates input string to length at most 8 and
// converted to upper-case. Returns tuple of resulting string and its
// length.
tuple<string, int> trunc8(const string & s);


#endif //#ifndef FILE_TRUNC_HPP_INCLUDED

