#include <iostream>
using namespace std;

int main()
{
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100): ";
    cin >> floor;

    // for (int i = floor; i > 0; i--)
    // {
    //     for (int j = 0; j < floor - i; j++)
    //     {
    //         cout << "S";
    //     }
    //     for (int k = 0; k < i * 2 - 1; k++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    int i = floor;
    while (i > 0)
    {
        int j = 0;
        while (j < floor - i)
        {
            cout << "S";
            j++;
        }

        int k = 0;
        while (k < i * 2 - 1)
        {
            cout << "*";
            k++;
        }

        cout << endl;
        i--;
    }
    return 0;
}