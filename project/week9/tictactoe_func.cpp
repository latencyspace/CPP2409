#include <iostream>
using namespace std;

// 좌표의 유효성을 체크하는 함수
bool isValid(char **board, int numCell, int x, int y)
{
    if (x < 0 || x >= numCell || y < 0 || y >= numCell)
    { // 좌표 범위를 벗어날 때
        cout << x << "," << y << ": x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
        return false;
    }
    if (board[x][y] != ' ')
    { // 좌표 범위의 입력값이 중복될 때
        cout << x << "," << y << ": 이미 돌이 차있습니다." << endl;
        return false;
    }
    return true; // 유효한 경우
}

// 승리자를 체크하는 함수
bool checkWin(char **board, int numCell, char currentUser)
{
    // 가로/세로 체크
    for (int i = 0; i < numCell; i++)
    {
        if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser)
        {
            cout << "가로에 모두 돌이 놓였습니다!!" << endl;
            return true;
        }
        if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser)
        {
            cout << "세로에 모두 돌이 놓였습니다!!" << endl;
            return true;
        }
    }

    // 대각선 체크
    if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser)
    {
        cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        return true;
    }
    if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser)
    {
        cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        return true;
    }

    return false; // 승리자가 없는 경우
}

// 보드판을 출력하는 함수
// 보드판을 출력하는 함수
void printBoard(char **board, int numCell)
{
    for (int i = 0; i < numCell; i++)
    {
        for (int k = 0; k < numCell; k++)
        {
            cout << "---";
            if (k < numCell - 1)
            {
                cout << "|"; // 마지막 열이 아닐 때만 구분선 추가
            }
        }
        cout << endl;

        for (int j = 0; j < numCell; j++)
        {
            cout << " " << board[i][j] << " "; // 각 칸의 내용 출력
            if (j < numCell - 1)
            {
                cout << "|"; // 마지막 열이 아닐 때만 구분선 추가
            }
        }
        cout << endl;
    }

    // 마지막 구분선 출력
    for (int k = 0; k < numCell; k++)
    {
        cout << "---";
        if (k < numCell - 1)
        {
            cout << "|"; // 마지막 열이 아닐 때만 구분선 추가
        }
    }
    cout << endl; // 마지막 줄 바꿈
}

int main()
{
    int numCell;

    // 사용자로부터 보드 크기 입력받기
    cout << "보드의 크기를 입력하세요 (3 이상의 정수): ";
    cin >> numCell;

    // 보드 크기가 3보다 작으면 종료
    if (numCell < 3)
    {
        cout << "보드의 크기는 3 이상이어야 합니다." << endl;
        return 0;
    }

    // 동적 할당으로 보드판 생성
    char **board = new char *[numCell];
    for (int i = 0; i < numCell; i++)
    {
        board[i] = new char[numCell];
        for (int j = 0; j < numCell; j++)
        {
            board[i][j] = ' ';
        }
    }

    int k = 0;                              // 누구 차례인지 체크하기 위한 변수
    char currentUser;                       // 현재 유저의 돌을 저장하기 위한 변수
    const char players[] = {'X', 'O', 'H'}; // 3인 게임

    // 게임을 무한 반복
    while (true)
    {
        // 현재 유저 결정
        currentUser = players[k % 3];
        cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";

        // 좌표 입력 받기
        int x, y;
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 입력받은 좌표의 유효성 체크
        if (!isValid(board, numCell, x, y))
        {
            continue; // 유효하지 않으면 다시 입력
        }

        // 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 현재 보드 판 출력
        printBoard(board, numCell);

        // 승리 체크
        if (checkWin(board, numCell, currentUser))
        {
            cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            break;
        }

        // 모든 칸 다 찼는지 체크하기
        int checked = 0;
        for (int i = 0; i < numCell; i++)
        {
            for (int j = 0; j < numCell; j++)
            {
                if (board[i][j] == ' ')
                {
                    checked++;
                }
            }
        }
        if (checked == 0)
        {
            cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
            break;
        }

        k++;
    }

    // 동적으로 할당한 메모리 해제
    for (int i = 0; i < numCell; i++)
    {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
