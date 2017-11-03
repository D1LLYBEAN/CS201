#include <iostream>

using namespace std;

int main()
{
    cout << "Dec Hex Chr\n";
    for(int i = 0; i <= 255; i++)
    {
        cout << std::dec << i << " ";
        cout << std::hex << i << " ";
        cout << (char)i << "\n\n";
    }
    return 0;
}
