// 1. int map[mapY][mapX] 대신 vector<vector<int>> map을 선언해 2차원 벡터를 사용함
// 2. 2차원 배열 int map[mapY][mapX]을 const vector<vector<int>>& map 및 vector<vector<int>>& map으로 수정하였음
// 3. const 키워드를 활용해 함수에서 map이 수정되지 않는 경우 상수 참조 ( const ) 로 전달함

// "빌드가 완료되었지만, 오류가 발생했습니다." 에 대한 해결법
// -> 새로운 터미널에서 아래 코드를 작성해서 직접 빌드하기
// /usr/bin/g++ -std=c++14 -fdiagnostics-color=always -g /Users/latency/Desktop/Dev/C++/CPP2409/project/week10_mud/main.cpp /Users/latency/Desktop/Dev/C++/CPP2409/project/week10_mud/user.cpp -o /Users/latency/Desktop/Dev/C++/CPP2409/project/week10_mud/main
// 먼저 오류는 링커가 user.cpp 파일에서 User 클래스의 구현을 찾지 못했기 때문에 발생한 것
// 그렇기 때문에 user.cpp 파일을 빌드에 포함시켜야 해서 빌드 명령에 user.cpp를 추가함
// main.cpp와 user.cpp를 함께 컴파일하고 링크해 User 클래스의 정의를 찾을 수 있게 함

#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(const vector<vector<int>> &map, User &user, int user_x, int user_y);
bool checkGoal(const vector<vector<int>> &map, int user_x, int user_y);
void checkState(vector<vector<int>> &map, User &user, int user_x, int user_y);
bool CheckUser(const User &user);

int main()
{
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}};

    int magician_x = 0;
    int magician_y = 0;
    int warrior_x = 0;
    int warrior_y = 0;

    User *currentUser = nullptr;
    string job_choice;

    cout << "직업을 선택하세요 (마법사 또는 전사): ";
    cin >> job_choice;

    if (job_choice == "마법사")
    {
        currentUser = new Magician();
    }
    else if (job_choice == "전사")
    {
        currentUser = new Warrior();
    }
    else
    {
        cout << "잘못된 선택입니다. 게임을 종료합니다." << endl;
        return 0;
    }

    while (true)
    {
        cout << "현재 HP: " << currentUser->GetHP() << endl;
        string user_input;

        cout << "명령어를 입력하세요 (상,하,좌,우,지도,정보,공격,종료): ";
        cin >> user_input;

        if (user_input == "공격")
        {
            currentUser->doAttack();
            continue;
        }
        else if (user_input == "지도")
        {
            displayMap(map, *currentUser, magician_x, magician_y);
            continue;
        }
        else if (user_input == "정보")
        {
            cout << *currentUser << endl;
            continue;
        }
        else if (user_input == "종료")
        {
            break;
        }

        // 이동 처리
        if (user_input == "상")
            magician_y--;
        else if (user_input == "하")
            magician_y++;
        else if (user_input == "좌")
            magician_x--;
        else if (user_input == "우")
            magician_x++;

        // 이동 범위 체크
        if (!checkXY(magician_x, mapX, magician_y, mapY))
        {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
            // 이동 취소
            if (user_input == "상")
                magician_y++;
            else if (user_input == "하")
                magician_y--;
            else if (user_input == "좌")
                magician_x++;
            else if (user_input == "우")
                magician_x--;
            continue;
        }

        // HP 감소 처리
        currentUser->DecreaseHP(1);
        if (!CheckUser(*currentUser))
        {
            cout << "HP가 0이 되어 실패했습니다!" << endl;
            break;
        }

        displayMap(map, *currentUser, magician_x, magician_y);
        checkState(map, *currentUser, magician_x, magician_y);

        if (checkGoal(map, magician_x, magician_y))
        {
            cout << "축하합니다!" << endl;
            break;
        }
    }

    delete currentUser; // 메모리 해제
    return 0;
}

void displayMap(const vector<vector<int>> &map, User &user, int user_x, int user_y)
{
    cout << "\n ----------------------------------------------------- " << endl;
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            if (i == user_y && j == user_x)
            {
                cout << (dynamic_cast<Magician *>(&user) ? "  마법사  |" : "   전사   |");
            }
            else
            {
                switch (map[i][j])
                {
                case 0:
                    cout << "          |";
                    break;
                case 1:
                    cout << "  아이템  |";
                    break;
                case 2:
                    cout << "    적    |";
                    break;
                case 3:
                    cout << "   포션   |";
                    break;
                case 4:
                    cout << "  목적지  |";
                    break;
                }
            }
        }
        cout << "\n ----------------------------------------------------- " << endl;
    }
}

bool checkXY(int user_x, int mapX, int user_y, int mapY)
{
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

bool checkGoal(const vector<vector<int>> &map, int user_x, int user_y)
{
    return map[user_y][user_x] == 4;
}

void checkState(vector<vector<int>> &map, User &user, int user_x, int user_y)
{
    switch (map[user_y][user_x])
    {
    case 1:
        cout << "아이템이 있습니다." << endl;
        user.IncreaseItemCnt();
        map[user_y][user_x] = 0;
        break;
    case 2:
        cout << "적이 있습니다. HP가 2 감소합니다." << endl;
        user.DecreaseHP(2);
        if (!CheckUser(user))
        {
            cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
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

bool CheckUser(const User &user)
{
    return user.GetHP() > 0;
}
