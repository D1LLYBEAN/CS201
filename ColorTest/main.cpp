#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <bitset>
using std::bitset;
#include <vector>
using std::vector;
#include <windows.h>


struct Avatar{
    int ascii;
    int color;
};

Avatar PLAYER = {'i',0x8F};
Avatar WALL = {'#',0x8F};
Avatar PATH = {' ',0x8F};

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPosition = {0,0};

    cout << "##### WORLD!";

    cin.get(); // wait

    SetConsoleCursorPosition(hConsole,cursorPosition); // set cursor to cursorPosition

    cin.get(); // wait

    SetConsoleCursorPosition(hConsole,cursorPosition); // when you hit enter, it moves the cursor...

    cout << "HELLO"; // replace "#####" with "HELLO"

    cin.get();

    vector<vector<Avatar>> grid {
            {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
            {WALL,PATH,PATH,PATH,PATH,PATH,PATH,WALL},
            {WALL,PATH,PATH,PATH,PATH,PATH,PATH,WALL},
            {WALL,PATH,PATH,PATH,PATH,PATH,PATH,WALL},
            {WALL,PATH,PATH,PATH,PATH,PATH,PATH,WALL},
            {WALL,PATH,PATH,PATH,PATH,PATH,PATH,WALL},
            {WALL,PATH,PATH,PATH,PATH,PATH,PATH,WALL},
            {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
    };

    SetConsoleCursorPosition(hConsole,cursorPosition);

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            SetConsoleTextAttribute(hConsole,grid[i][j].color);
            cout << (char)grid[i][j].ascii;
        }
        cout << endl;
    }

    cin.get();

    grid[5][5] = PLAYER;

    SetConsoleCursorPosition(hConsole,cursorPosition);

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            SetConsoleTextAttribute(hConsole,grid[i][j].color);
            cout << (char)grid[i][j].ascii;
        }
        cout << endl;
    }

    SetConsoleCursorPosition(hConsole,{5,5});

    cin.get();

    for(int i=0x00; i<=0xFF; i++)
    {
        SetConsoleTextAttribute(hConsole,i);
        cout << std::hex << i << "\tCOLOR\n";
    }
    SetConsoleTextAttribute(hConsole,0x0F);

    return 0;
}
