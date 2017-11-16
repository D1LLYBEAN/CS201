// main.cpp
// RealTimeInput
// Dillon Mills
// Created 9/13/17
// Reads key presses in real time, and exits when ESC is pressed.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <conio.h>
#include <stdlib.h>
#include <vector>
using std::vector;
#include <string>
using std::string;

// mechanical constants
const int MAP_SIZE = 16;
//const int CLS_SIZE = 20;
// graphical constants
const char PATH = 0xB0;     // ░
const char WALL = 0xDB;     // █
const char PLAYER_W = 0x8C; // î
const char PLAYER_A = 0x8D; // ì
const char PLAYER_S = 0x8B; // ï
const char PLAYER_D = 0xA1; // í

void printMap(int pPosX, int pPosY, char avatar)
{
    string outputString;// = string(CLS_SIZE,'\n');
    outputString += string(MAP_SIZE + 2,WALL) + "\n" + string(1,WALL);
    for(int i = MAP_SIZE-1; i >= 0; i--)
    {
        for(int j = 0; j <= MAP_SIZE-1; j++)
        {
            if (pPosX == i && pPosY == j)
            {
                outputString += avatar;
            }
            else
            {
                outputString += PATH;
            }
        }
        string tempString = string(1,WALL) + "\n" + string(1,WALL);
        outputString += tempString;
    }
    outputString += string(MAP_SIZE + 1,WALL) + "\n";

    system("CLS");
    cout << outputString;
}

void helpText()
{
    cout << "\n" << (char)0x8B << " is the hero.\n";
    cout << "wasd or arrow keys to move.\n";
    cout << "ctrl + wasd to rotate without moving.\n";
    cout << "\nPress ESC at any point to exit.\n";
    cout << "I'll understand...\n";
}

void inventory()
{
    cout << "\nThis is a placeholder for an inventory screen.\n";
}

int main()
{
    vector<int> pPos(2);
    char pAvat = PLAYER_S;

    printMap(pPos[0],pPos[1],pAvat);
    cout << "\nWelcome to my game!\n";
    cout << "There's not much to it yet, but it's getting better.\n";
    cout << "Please pardon the flicker.\n";
    helpText();
    int key;
    bool loop = true;
    while (loop)
    {
        key = getch();
        if (key == 0x00 || key == 0xE0)
        {
            key *= 0x0100; // shift left by 8 bits to get extended code
            key += getch(); // retrieve second byte of extended code
        }

//        if (key >= 'a' && key <= 'z')
//        {
//            key -= 'a' - 'A';
//        }

        switch (key)
        {
            case 'W': // no such luck for arrow keys...
                if(pAvat == PLAYER_W){ pPos[0] += (pPos[0] < 15)? 1 : 0; }
            case 'w':
            case 0xE048: //[UP ARROW]
                pPos[0] += (pPos[0] < 15)? 1 : 0;
            case 0x0017: // ctrl + w
            case 0xE08D: // ctrl + [UP ARROW]
                pAvat = PLAYER_W;
                break;

            case 'A':
                if(pAvat == PLAYER_A){ pPos[1] -= (pPos[1] < 15)? 1 : 0; }
            case 'a':
            case 0xE04b: // [LEFT ARROW]
                pPos[1] -= (pPos[1] > 0)? 1 : 0;
            case 0x0001: // ctrl + a
            case 0xE073: // ctrl + [LEFT ARROW]
                pAvat = PLAYER_A;
                break;

            case 'S':
                if(pAvat == PLAYER_S){ pPos[0] -= (pPos[0] < 15)? 1 : 0; }
            case 's':
            case 0xE050: // [DOWN ARROW]
                pPos[0] -= (pPos[0] > 0)? 1 : 0;
            case 0x0013: // ctrl + s
            case 0xE091: // ctrl + [DOWN ARROW]
                pAvat = PLAYER_S;
                break;

            case 'D':
                if(pAvat == PLAYER_D){ pPos[1] += (pPos[1] < 15)? 1 : 0; }
            case 'd':
            case 0xE04d: // [RIGHT ARROW]
                pPos[1] += (pPos[1] < 15)? 1 : 0;
            case 0x0004: // ctrl + d
            case 0xE074: // ctrl + [RIGHT ARROW]
                pAvat = PLAYER_D;
                break;
            case 0x1B: // ESC key
                cout << endl << "Exiting..." << endl;
                loop = false;
                break;
            case '/':
            case '?':
                printMap(pPos[0],pPos[1],pAvat);
                helpText();
                continue;
            case 'i':
                printMap(pPos[0],pPos[1],pAvat);
                inventory();
                continue;
            default:
                break;
        }
        printMap(pPos[0],pPos[1],pAvat);
        cout << "0x" << std::hex << key;
    }

    system("CLS");
    cout << endl << "Goodbye!" << endl;

    return 0;
}
