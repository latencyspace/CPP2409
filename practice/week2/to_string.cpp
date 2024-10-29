#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "사과";
    string s2;
    // " "은 문자열이고 10은 정수인데, C++에서 + 연산자는 문자열끼리는 더할 수 있으나 문자열과 정수는 직접 더할 수 없기 때문임
    // s2 = s1 + " " + 10 + "개";
    s2 = s1 + " " + to_string(10) + "개";
    cout << s2 << endl;
}