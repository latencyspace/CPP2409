#include <iostream>
using namespace std;

int main()
{
    int x, y;

    cout << "x값을 입력하시오: ";
    cin >> x;

    cout << "y값을 입력하시오: ";
    cin >> y;

    if (x > y) // 2개 이상의 출력문 작성 시 중괄호 사용
        cout << "x가 y보다 큽니다. " << endl;
    else if (x == y) // 1가지의 출력문 작성 시에도 사용해도 됨
    {
        cout << "x와 y는 같습니다. " << endl;
    }
    else
        cout << "y가 x보다 큽니다. " << endl;

    return 0;
}