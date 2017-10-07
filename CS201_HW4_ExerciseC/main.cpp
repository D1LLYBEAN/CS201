// order.cpp
// CS201_HW4_ExerciseC
// Dillon Mills
// Created on 10/7/17
// Reads lines from the file "lines.txt" and prints the lines in alphabetical (by ASCII) order.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream;


int main()
{
    vector<string> lines {};
    ifstream infile("lines.txt");
    string line;
    while (getline(infile, line))
    {
        if (line[0] > 0)
        {
            lines.push_back(line);
        }
    }
    cout << "lines.txt out of order (excluding NULLs):\n";
    for(auto n : lines)
    {
        cout << n << endl;
    }

    // bubble sort, hell yeah.
    for(int k = 1; k < lines.size(); k++)
    {
        for(int i = 0; i < lines.size() - k; i++)
        {
            string lineA = lines[i];
            string lineB = lines[i + 1];
            for(int j = 0; j < lineA.length(); j++)
            {
                if (lineA[j] > lineB[j])
                {
                    lines[i] = lineB;
                    lines[i + 1] = lineA;
                    break;
                }
                else if (lineA[j] < lineB[j])
                {
                    break;
                }
            }
        }
    }

    cout << "\nlines.txt in order (excluding NULLs):\n";
    for(auto n : lines)
    {
        cout << n << endl;
    }
}
