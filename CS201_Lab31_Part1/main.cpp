#include <iostream>
using std::cout;
using std::endl;
#include "adder.hpp"


int main()
{
    Adder adder1, adder2, adder3;

    adder1.add(1);
    adder2.add(2);
    adder3.add(3);

    cout << "Adder 1: " << Adder::total() << endl;

    return 0;
}
