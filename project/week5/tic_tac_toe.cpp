#include <iostream>
using namespace std;

int main()
{
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받은 X, Y 좌표를 저장할 변수

    // 보드판 초기화
    for (x = 0; x < numCell; x++)
    {
        for (y = 0; y < numCell; y++)
        {
            board[x][y] = ' ';
        }
    }

    // 게임 코드
    int k = 0;              // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 문자 변수
    while (true)
    {
        // 1. 누구 차례인지 출력
        // switch (k & 2)
        // {
        // case 0:
        //     cout << "첫 번째 유저(X)의 차례입니다 -> ";
        //     currentUser = 'X';
        //     break;
        // case 1:
        //     cout << "두 번째 유저(X)의 차례입니다 -> ";
        //     currentUser = 'O';
        //     break;
        // }
        currentUser = (k % 2 == 0) ? 'X' : 'O';
        cout << (currentUser == 'X' ? "첫 번째 유저(X)" : "두 번째 유저(O)") << "의 차례입니다 -> ";

        // 2. 좌표 입력 받기
        cout << "(X, Y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (x >= numCell || y >= numCell)
        {
            cout << x << ", " << y << ": ";
            cout << "X와 Y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] != ' ')
        {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드판 출력
        for (int i = 0; i < numCell; i++)
        {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++)
            {
                cout << board[i][j];
                if (j == numCell - 1)
                {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

        // 6. 게임 승자 확인
        bool Winner = false;

        // 6-1. 가로 체크
        for (int i = 0; i < numCell; i++)
        {
            if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser)
            {
                Winner = true;
                break;
            }
        }
        // 6-2. 세로 체크
        for (int i = 0; i < numCell; i++)
        {
            if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser)
            {
                Winner = true;
                break;
            }
        }
        // 6-3. 대각선 체크
        if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser)
        {
            Winner = true;
        }
        if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser)
        {
            Winner = true;
        }

        // 6-4. 승자가 결정된 경우
        if (Winner)
        {
            cout << "승자: " << currentUser << "!" << endl;
            break;
        }

        // 7. 모든 칸이 찼는지 확인
        bool isFull = true;
        for (int i = 0; i < numCell; i++)
        {
            for (int j = 0; j < numCell; j++)
            {
                if (board[i][j] == ' ')
                {
                    isFull = false;
                    break;
                }
            }
        }

        // 7-1. 모든 칸이 찼다면
        if (isFull)
        {
            cout << "모든 칸이 찼습니다. 게임 종료!" << endl;
            break;
        }

        k++;
    }
    return 0;
}