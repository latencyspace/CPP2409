// "빌드가 완료되었지만, 오류가 발생했습니다." 에 대한 해결법
// -> 새로운 터미널에서 아래 코드를 작성해서 직접 빌드하기
// /usr/bin/g++ -std=c++14 -fdiagnostics-color=always -g /Users/latency/Desktop/Dev/C++/CPP2409/project/week10_mud/main.cpp /Users/latency/Desktop/Dev/C++/CPP2409/project/week10_mud/user.cpp -o /Users/latency/Desktop/Dev/C++/CPP2409/project/week10_mud/main
// 먼저 오류는 링커가 user.cpp 파일에서 User 클래스의 구현을 찾지 못했기 때문에 발생한 것
// 그렇기 때문에 user.cpp 파일을 빌드에 포함시켜야 해서 빌드 명령에 user.cpp를 추가함
// main.cpp와 user.cpp를 함께 컴파일하고 링크해 User 클래스의 정의를 찾을 수 있게 함

#include <iostream>
#include <string>
#include "user.h" // User 클래스 선언부 포함

using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], User &user, int user_x, int user_y);
bool CheckUser(User user); // HP가 0인지 확인하는 함수

int main()
{
    int map[mapY][mapX] = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}};

    int user_x = 0;
    int user_y = 0;
    User user; // User 객체 생성

    while (true)
    {
        cout << "현재 HP: " << user.GetHP() << endl;
        string user_input;

        cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
        cin >> user_input;

        if (user_input == "상")
        {
            user_y--;
            cout << "위로 한 칸 올라갑니다." << endl;
        }
        else if (user_input == "하")
        {
            user_y++;
            cout << "아래로 한 칸 내려갑니다." << endl;
        }
        else if (user_input == "좌")
        {
            user_x--;
            cout << "왼쪽으로 이동합니다." << endl;
        }
        else if (user_input == "우")
        {
            user_x++;
            cout << "오른쪽으로 이동합니다." << endl;
        }
        else if (user_input == "지도")
        {
            displayMap(map, user_x, user_y);
            continue;
        }
        else if (user_input == "종료")
        {
            break;
        }
        else
        {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        if (!checkXY(user_x, mapX, user_y, mapY))
        {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
            if (user_input == "상")
                user_y++;
            else if (user_input == "하")
                user_y--;
            else if (user_input == "좌")
                user_x++;
            else if (user_input == "우")
                user_x--;
            continue;
        }

        user.DecreaseHP(1);
        if (!CheckUser(user))
        {
            cout << "HP가 0이 되어 실패했습니다!" << endl;
            break;
        }

        displayMap(map, user_x, user_y);
        checkState(map, user, user_x, user_y);

        if (checkGoal(map, user_x, user_y))
        {
            cout << "축하합니다!" << endl;
            break;
        }
    }

    return 0;
}

void displayMap(int map[][mapX], int user_x, int user_y)
{
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            if (i == user_y && j == user_x)
                cout << " USER |";
            else
            {
                switch (map[i][j])
                {
                case 0:
                    cout << "      |";
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |";
                    break;
                case 3:
                    cout << " 포션 |";
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }
        cout << "\n -------------------------------- " << endl;
    }
}

bool checkXY(int user_x, int mapX, int user_y, int mapY)
{
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

bool checkGoal(int map[][mapX], int user_x, int user_y)
{
    return map[user_y][user_x] == 4;
}

void checkState(int map[][mapX], User &user, int user_x, int user_y)
{
    switch (map[user_y][user_x])
    {
    case 1:
        cout << "아이템이 있습니다." << endl;
        break;
    case 2:
        cout << "적이 있습니다. HP가 2 감소합니다." << endl;
        user.DecreaseHP(2);
        if (!CheckUser(user))
        {
            cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
            cout << "게임을 종료합니다." << endl;
            exit(0);
        }
        break;
    case 3:
        cout << "포션을 발견했습니다. HP가 2 회복됩니다." << endl;
        user.IncreaseHP(2);
        break;
    case 4:
        cout << "목적지에 도착했습니다!" << endl;
        break;
    }
}

bool CheckUser(User user)
{
    return user.GetHP() > 0;
}
