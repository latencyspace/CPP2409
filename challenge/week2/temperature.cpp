#include <iostream>
using namespace std;

int main()
{
    int c_temperature;

    cout << "화씨온도: ";
    cin >> c_temperature;
    cout << "섭씨온도: " << (5.0 / 9.0) * (c_temperature - 32) << endl;

    return 0;
}