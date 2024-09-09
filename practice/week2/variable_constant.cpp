#include <iostream>
#define PI 3.14159265359
using namespace std;

int main()
{
    int income = 1000;
    const double TAX_RATE = 0.25; // const를 사용해 상수 취급
    income = income - TAX_RATE * income;

    double x = 100;
    x = x * PI;

    cout << x << endl;
    return 0;
}