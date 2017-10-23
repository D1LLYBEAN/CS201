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

void printMap(int pPosX, int pPosY, char avatar)
{
    string outputString = "#" + string(16,'#') + "#\n#";
    for(int i = 15; i >= 0; i--)
    {
        for(int j = 0; j <= 15; j++)
        {
            if (pPosX == i && pPosY == j)
            {
                outputString += avatar;
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


int main()
{
    vector<int> pPos(2);
    char pAvat = '\x18';

    printMap(pPos[0],pPos[1],pAvat);
    cout << "\nWelcome to my game!\n";
    cout << "There's not much to it yet, but it's getting better.\n";
    cout << "\nYour character is the \"i\" symbol.\n";
    cout << "Move around with WASD.\n";
    cout << "\nPress ESC at any point to exit.\n";
    cout << "I'll understand...\n";
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
                pAvat = '\x18';
                break;
            case 'A':
                pPos[1] -= (pPos[1] > 0)? 1 : 0;
                pAvat = '\x1a'; // can't get it to print left arrow!!!
                break;
            case 'S':
                pPos[0] -= (pPos[0] > 0)? 1 : 0;
                pAvat = '\x19';
                break;
            case 'D':
                pPos[1] += (pPos[1] < 15)? 1 : 0;
                pAvat = '\x1a';
                break;
            case 27: // ESC
                cout << endl << "Exiting..." << endl;
                loop = false;
                break;
            default:
                cout << key;
                break;
        }

        printMap(pPos[0],pPos[1],pAvat);
    }

    system("CLS");
    cout << endl << "Goodbye!" << endl;

    return 0;
}
