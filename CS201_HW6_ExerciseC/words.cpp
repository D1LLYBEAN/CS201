// words.cpp
// CS201_HW6_ExerciseC
// Dillon Mills
// Created on 11/12/17
//
// Accepts as input a sentence in which all of the
// words are run together, but the first character of each word is
// uppercase. Convert the sentence to a string in which the words are
// separated by spaces and only the first word starts with an
// uppercase letter.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::stringstream;
#include <map>
using std::map;
#include <vector>
using std::vector;


int main()
{
    while (true)
    {
        cout << "Type: ";

        string userLine;
        getline(cin, userLine);
        if(userLine == ""){ break; }

        string outputString;
        bool sentenceStart = true;
        bool quoteStart = false;
        for(char c : userLine)
        {
            if (sentenceStart)
            {
                outputString += c;
                sentenceStart = false;
            }
            else if(c == '!' || c == '.' || c == '?')
            {
                outputString += string(1,c) + " ";
                sentenceStart = true;
            }
            else if(c == ',' || c == ':' || c == ';' || c == '(' || c == '[' || c == '{' || c == '%')  // Unneeded?
            {
                outputString += c;
            }
            else if(c == '#' || c == '$' || c == '(' || c == '[' || c == '{' || c == '@')
            {
                outputString += " " + string(1,c);
            }
            else if(c == '&')
            {
                outputString += " " + string(1,c) + " ";
            }
            else if(c >= 'A' && c <= 'Z')
            {
                c += 'a' - 'A';
                outputString += " " + string(1,c);
            }
            else
            {
                outputString += c;
            }
            // All other symbols are too ambiguous to space properly...
            // A lot of these will already fail in some circumstances (especially for math or code).
        }

        cout << outputString << "\n\n";
    }

    return 0;
}
