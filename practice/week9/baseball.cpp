#include <iostream>
#include <string>
#include <set>
#include <cstdlib> // rand()를 사용하기 위해 추가
using namespace std;

// 숫자의 자릿수가 모두 다른지 체크하는 함수
bool checkNumber(int number)
{
    string strNum = to_string(number);
    set<char> digits; // 중복된 숫자를 저장하지 않기 위해 set 사용

    // 각 자리수를 확인
    for (char digit : strNum)
    {
        // 이미 존재하는 숫자가 있다면 false 반환
        if (digits.find(digit) != digits.end())
        {
            return false;
        }
        digits.insert(digit); // 숫자를 set에 삽입
    }
    return true; // 모든 숫자가 다르면 true 반환
}

int main()
{
    int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수

    while (true)
    {
        randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

        // 3자리 숫자의 자릿수가 모두 다른지 체크
        if (!checkNumber(randomNum))
        {
            continue; // 숫자가 같으면 다시 랜덤 숫자 생성
        }

        break; // 자릿수가 모두 다르면 루프 종료
    }

    int turn = 0;
    while (true)
    {
        cout << turn + 1 << "번째 시도입니다." << endl;

        int userNumber; // 사용자가 입력한 세자리수 저장 변수
        while (true)
        {
            cout << "세자리 수를 입력해주세요: ";
            cin >> userNumber;

            // 입력된 숫자가 3자리인지 체크
            if (to_string(userNumber).length() != 3 || !checkNumber(userNumber))
            {
                cout << "입력된 숫자가 3자리 수가 아니거나 자릿수가 동일합니다. 다시 입력하세요." << endl;
                continue;
            }
            break; // 올바른 입력이면 루프 종료
        }

        int strike = 0; // 스트라이크 갯수를 저장하는 변수
        int ball = 0;   // 볼 갯수를 저장하는 변수

        // 정답과 추측한 숫자의 자릿수와 숫자를 비교
        string toStringNum = to_string(randomNum);
        string toStringUserNum = to_string(userNumber);

        if (toStringNum[0] == toStringUserNum[0])
            strike++;
        if (toStringNum[1] == toStringUserNum[1])
            strike++;
        if (toStringNum[2] == toStringUserNum[2])
            strike++;

        if (toStringNum[0] == toStringUserNum[1] || toStringNum[0] == toStringUserNum[2])
            ball++;
        if (toStringNum[1] == toStringUserNum[0] || toStringNum[1] == toStringUserNum[2])
            ball++;
        if (toStringNum[2] == toStringUserNum[0] || toStringNum[2] == toStringUserNum[1])
            ball++;

        cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << " 볼 입니다." << endl;

        if (strike == 3)
        {
            cout << "정답을 맞췄습니다. 축하합니다!" << endl;
            break;
        }

        turn++;
    }

    return 0;
}
