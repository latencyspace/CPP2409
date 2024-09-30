#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++)
    {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    int choice;
    cout << "1. 가장 나이가 많은 사람\n";
    cout << "2. 가장 나이가 적은 사람\n";
    cout << "위 항목 중 하나를 선택하세요: ";
    cin >> choice;

    if (choice == 1)
    {
        int maxAgePeople = 0;
        for (int i = 1; i < maxPeople; i++)
        {
            if (ages[i] > ages[maxAgePeople])
            {
                maxAgePeople = i;
            }
        }
        cout << "가장 나이가 많은 사람의 이름은 " << names[maxAgePeople] << "이고, 나이는 " << ages[maxAgePeople] << "살 입니다." << endl;
    }
    else if (choice == 2)
    {
        int minAgePeople = 0;
        for (int i = 1; i < maxPeople; i++)
        {
            if (ages[i] < ages[minAgePeople])
            {
                minAgePeople = i;
            }
        }
        cout << "가장 나이가 적은 사람의 이름은 " << names[minAgePeople] << "이고, 나이는 " << ages[minAgePeople] << "살 입니다." << endl;
    }
    else
    {
        cout << "잘못된 입력입니다. 프로그램을 종료합니다." << endl;
    }
    return 0;
}

// 동점일 때, 해당하는 모든 사람을 모두 출력하는 코드 작성