#include <iostream>
using namespace std;

int main()
{
    bool b;
    b = (1 == 2);
    cout << "1==2 = " << b << endl; // false = 0

    b = (1 == 1);
    cout << "1==1 = " << b << endl; // true = 1

    return 0;
}