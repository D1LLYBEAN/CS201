// main.cpp
// RealTimeInput
// Dillon Mills
// Created 9/13/17
// Reads key presses in real time, and exits when ESC is pressed.

#include <iostream>
using std::cout;
using std::endl;
#include <conio.h>
#include <stdlib.h>
#include <vector>
using std::vector;
#include <string>
using std::string;


int main()
{
    vector<int> pPos(2);

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
        if (key >= 'a' && key <= 'z')
        {
            key -= 'a' - 'A';
        }
        switch (key)
        {
            case 'W':
                pPos[0] += (pPos[0] < 15)? 1 : 0;
                break;
            case 'A':
                pPos[1] -= (pPos[1] > 0)? 1 : 0;
                break;
            case 'S':
                pPos[0] -= (pPos[0] > 0)? 1 : 0;
                break;
            case 'D':
                pPos[1] += (pPos[1] < 15)? 1 : 0;
                break;
            case 27: // ESC
                cout << endl << "Exiting..." << endl;
                loop = false;
                break;
            default:
                cout << key;
                break;
        }

        string outputString = "#" + string(16,'#') + "#\n#";
        for(int i = 15; i >= 0; i--)
        {
            for(int j = 0; j <= 15; j++)
            {
                if (pPos[0] == i && pPos[1] == j)
                {
                    outputString += "i";
                }
                else
                {
                    outputString += " ";
                }
            }
            outputString += "#\n#";
        }
        outputString += string(16,'#') + "#\n";

        system("CLS");
        cout << outputString;
    }

    system("CLS");
    cout << endl << "End of Program!" << endl;
}
