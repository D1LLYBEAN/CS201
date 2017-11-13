// main.cpp
// CS201_Lab29_Part1
// Dillon Mills
// Created on 11/13/17


#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
using std::normal_distribution;
#include <algorithm>
using std::sort;
#include <iomanip>
using std::setprecision;


int main()
{
    vector<double> rands(10);
    random_device rd;
    mt19937 gen(rd());
    int maxChars = 80;

    uniform_real_distribution<double> distrib_unif(0,1);

    for (int i = 0; i < 10; i++)
    {
        rands[i] = distrib_unif(gen);
    }

    sort(rands.begin(),rands.end());

    cout << "Uniform Distribution:" << endl;
    for (double n : rands)
    {
        cout << std::fixed << setprecision(3) << n << "\t" << string((int)(n * 80),'#') << endl;
    }

    normal_distribution<double> distrib_norm(0,1);

    for (int i = 0; i < 10; i++)
    {
        rands[i] = distrib_norm(gen);
    }

    sort(rands.begin(),rands.end());

    cout << "Normal Distribution:" << endl;
    for (double n : rands)
    {
        cout << std::fixed << setprecision(3) << n << "\t" << string((int)(80 / (std::abs(n)+1)),'#') << endl;
    }

    return 0;
}
