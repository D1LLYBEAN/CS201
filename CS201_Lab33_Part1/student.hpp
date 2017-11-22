// student.hpp
// CS201_Lab33_Part1
//
// Dillon Mills
// Nov 22 2017

#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <string>


class Student
{
public:
    Student();
    Student(std::string n);
    Student(std::string n, int id);
    void printInfo() const;
private:
    std::string _name;
    int _ident;
};


#endif // STUDENT_H
