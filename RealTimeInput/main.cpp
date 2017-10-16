// main.cpp
// RealTimeInput
// Dillon Mills
// Created 9/13/17
// Reads key presses in real time, and exits when ESC is pressed.

#include <iostream>
using std::cout;
using std::endl;
#include <conio.h>


int main()
{
    cout << "Press ESC at any point to exit!" << endl;
    int key;
    bool loop = true;
    while (loop)
    {
        key = _getch();
        if (key == 0)
        {
            key = getch(); // retrieve second byte of extended code
            key *= 256; // shift left by 8 bits to get extended code
        }
        switch (key)
        {
            case 27: // ESC
                cout << endl << "Exiting..." << endl;
                loop = false;
                break;
            default:
                break;
        }
    }
    cout << endl << "End of Program!" << endl;
}
