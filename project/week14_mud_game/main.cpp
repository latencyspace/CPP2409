// 1. int map[mapY][mapX] 대신 vector<vector<int>> map을 선언해 2차원 벡터를 사용함
// 2. 2차원 배열 int map[mapY][mapX]을 const vector<vector<int>>& map 및 vector<vector<int>>& map으로 수정하였음
// 3. const 키워드를 활용해 함수에서 map이 수정되지 않는 경우 상수 참조 ( const ) 로 전달함

// "빌드가 완료되었지만, 오류가 발생했습니다." 에 대한 해결법
// -> 새로운 터미널에서 아래 코드를 작성해서 직접 빌드하기
// /usr/bin/g++ -std=c++14 -fdiagnostics-color=always -g /Users/latency/Desktop/Dev/C++/CPP2409/project/week14_mud_game/main.cpp /Users/latency/Desktop/Dev/C++/CPP2409/project/week14_mud_game/user.cpp -o /Users/latency/Desktop/Dev/C++/CPP2409/project/week14_mud_game/main
// 먼저 오류는 링커가 user.cpp 파일에서 User 클래스의 구현을 찾지 못했기 때문에 발생한 것
// 그렇기 때문에 user.cpp 파일을 빌드에 포함시켜야 해서 빌드 명령에 user.cpp를 추가함
// main.cpp와 user.cpp를 함께 컴파일하고 링크해 User 클래스의 정의를 찾을 수 있게 함

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(const vector<vector<int>> &map, User &user, int user_x, int user_y);
bool checkGoal(const vector<vector<int>> &map, int user_x, int user_y);
void checkState(vector<vector<int>> &map, User &user, int user_x, int user_y);
bool CheckUser(const User &user);

// 예외 처리 - 파일 읽기 실패 및 데이터 검증
vector<vector<int>> loadMapFromFile(const string &filename)
{
    ifstream file(filename);
    vector<vector<int>> map;

    if (!file.is_open())
    {
        cout << "map.txt 파일이 없습니다. 기본 맵을 생성합니다." << endl;
        ofstream outfile(filename);
        outfile << "0,1,2,0,4\n1,0,0,2,0\n0,0,0,0,0\n0,2,3,0,0\n3,0,0,0,2\n";
        outfile.close();
        file.open(filename); // 다시 열기
    }

    string line;
    try
    {
        while (getline(file, line))
        {
            vector<int> row;
            stringstream ss(line);
            string cell;
            while (getline(ss, cell, ','))
            {
                if (!isdigit(cell[0]) && cell[0] != '-')
                    throw runtime_error("유효하지 않은 데이터: " + cell);

                row.push_back(stoi(cell));
            }
            map.push_back(row);
        }
    }
    catch (const exception &e)
    {
        cerr << "맵 데이터 읽기 중 예외 발생: " << e.what() << endl;
        cout << "기본 맵으로 대체합니다." << endl;

        return vector<vector<int>>{
            {0, 1, 2, 0, 4},
            {1, 0, 0, 2, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 3, 0, 0},
            {3, 0, 0, 0, 2}};
    }

    file.close();
    return map;
}

// 예외 처리 - 직업 선택 및 명령어
int main()
{
    const string filename = "map.txt";
    vector<vector<int>> map;

    try
    {
        map = loadMapFromFile(filename);
    }
    catch (const exception &e)
    {
        cerr << "맵 로드 중 예외 발생: " << e.what() << endl;
        return 1;
    }

    User *currentUser = nullptr;
    string job_choice;

    try
    {
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
            throw invalid_argument("잘못된 직업 선택: " + job_choice);
        }
    }
    catch (const exception &e)
    {
        cerr << "예외 발생: " << e.what() << endl;
        return 1;
    }

    // 게임 루프 유지
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

// 예외 처리: 이동 범위 초과 처리
bool checkXY(int user_x, int mapX, int user_y, int mapY)
{
    try
    {
        if (user_x < 0 || user_x >= mapX || user_y < 0 || user_y >= mapY)
            throw out_of_range("맵 범위를 벗어남: (" + to_string(user_x) + ", " + to_string(user_y) + ")");
    }
    catch (const out_of_range &e)
    {
        cerr << "예외 발생: " << e.what() << endl;
        return false;
    }
    return true;
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
