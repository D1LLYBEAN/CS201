// student.cpp
// CS201_Lab33_Part1
//
// Dillon Mills
// Nov 22 2017


#include "student.hpp"


Student::Student()
{
    _name = "NEW STUDENT";
    _ident = 0;
}


Student::Student(std::string n)
{
    _name = n;
    _ident = 0;
}


Student::Student(std::string n, int id)
{
    _name = n;
    _ident = id;
}


void Student::printInfo() const
{
    std::cout << "Name: " << _name << "\n";
    std::cout << "Ident: " << _ident << "\n";
}
