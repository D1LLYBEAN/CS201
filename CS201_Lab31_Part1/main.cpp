#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class myClass{
public:
    void printData()
    {
        cout << "Data:\n" << _data << "\n\n";
    }
    void setData(string newData)
    {
        _data = newData;
    }
private:
    string _data;
};

int main()
{
    myClass testClass_1;
    myClass testClass_2;

    testClass_1.setData("Hello World!");
    testClass_2.setData("The quick brown fox jumped over the lazy dog.");

    testClass_1.printData();
    testClass_2.printData();

    myClass testClass_3 = testClass_1;

    testClass_3.printData();

    return 0;
}
