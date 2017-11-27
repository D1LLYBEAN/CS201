#include "adder.hpp"


int Adder::_sum = 0;


Adder::Adder()
{
    _sum = 0;
}


void Adder::add(int i)
{
    _sum += i;
}


Adder::total()
{
    return _sum;
}
