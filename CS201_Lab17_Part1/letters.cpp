// letters.cpp  INCOMPLETE
// Glenn G. Chappell
// 9 Oct 2016
//
// For CS 201 Fall 2016
// Count Letters in a String
//
// Modified slightly
// 9 Oct 2017
// Chris Hartman
//
// For CS 201 Fall 2017
//
// Completed
// 9 Oct 2017
// Dillon Mills

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;

// countLetters
// Given a string, return the number of letters it contains.
int countLetters(const string & s, int & lowercaseCount, int & uppercaseCount, int & digitCount, int & otherCount)
{
    int letterCount = 0;
    lowercaseCount = 0;
    uppercaseCount = 0;
    digitCount = 0;
    otherCount = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == 0)
            break;
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            lowercaseCount++;
            letterCount++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            uppercaseCount++;
            letterCount++;
        }
        else if (s[i] >= '0' && s[i] <= '9')
            digitCount++;
        else
            otherCount++;
    }
    return letterCount;
}


// Main program
// Repeat: input a line and count the letters in it.
int main()
{
    // Print opening message
    cout << "Counting letters in a line" << endl;
    cout << endl;

    while (true)
    {
        // Input a line, with error checking
        string line;
        cout << "Type some text (empty line to end): ";
        getline(cin, line);
        if (!cin)
            return 0;
        if (line == "")
            break;

        // Echo typing and count letters
        cout << endl;
        cout << "You typed: \"" << line << "\"" << endl;

        int numlowers, numuppers, numdigits, numothers;
        int numletters = countLetters(line, numlowers, numuppers, numdigits, numothers);

        cout << "This line contains ";
        if (numletters == 0)
            cout << "no letters\n";
        else if (numletters == 1)
            cout << "1 letter\n";
        else
            cout << numletters << " letters\n";

        cout << "Lowercase:\t" << numlowers << endl;
        cout << "Uppercase:\t" << numuppers << endl;
        cout << "Digits:\t\t" << numdigits << endl;
        cout << "Others:\t\t" << numothers << endl;
        cout << endl;
    }
    cout << endl;

    // Quit when user hits Enter
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
}
