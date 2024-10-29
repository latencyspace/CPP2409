#include <iostream>
#include <string>
using namespace std;

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수

	while (1) {		
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		string toStringNum = to_string(randomNum); // 랜덤으로 추출한 randomNum의 3자리 숫자를 각각 추출하기 위해 to_string을 사용해 문자열로 변경하였습니다.

		firstNum = toStringNum[0]; // firstNum은 랜덤으로 추출된 세 자리 숫자 중 0번 인덱스에 있는 숫자를 추출합니다.
		secondNum = toStringNum[1]; // secondNum은 랜덤으로 추출된 세 자리 숫자 중 1번 인덱스에 있는 숫자를 추출합니다.
		thirdNum = toStringNum[2]; // thirdNum은 랜덤으로 추출된 세 자리 숫자 중 2번 인덱스에 있는 숫자를 추출합니다.

		if (firstNum == secondNum || secondNum == thirdNum || thirdNum == firstNum) {
			return same;
		} // 각 자리마다 추출된 숫자들이 같은지 다른지 확인하여, 만약 같다면 same, 즉 false를 반환합니다.

		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
			string toStringUserNum = to_string(userNumber); // 사용자가 입력한 userNumber의 3자리 숫자를 각각 추출하기 위해 to_string을 사용해 문자열로 변경하였습니다.

			guessFirst = toStringUserNum[0]; // guessFirs은 사용자가 입력한 세 자리의 숫자 중 0번 인덱스에 있는 숫자를 추출합니다.
			guessSecond = toStringUserNum[1]; // guessSecond은 사용자가 입력한 세 자리의 숫자 중 1번 인덱스에 있는 숫자를 추출합니다.
			guessThird = toStringUserNum[2]; // guessThird은 사용자가 입력한 세 자리의 숫자 중 2번 인덱스에 있는 숫자를 추출합니다.

			if (firstNum == secondNum || secondNum == thirdNum || thirdNum == firstNum) {
				return same;
			} // 각 자리마다 추출된 숫자들이 같은지 다른지 확인하여, 만약 같다면 same, 즉 false를 반환합니다.			

			if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

			if (same == true) {
				break;
			}
		}


		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
		if (firstNum == guessFirst) {
			strike += 1;
		} // 정답의 첫 번째 자리수와 추측한 숫자 첫 번째 자릿수가 일치할 때 strike를 +1 합니다.

		if (secondNum == guessSecond) {
			strike += 1;
		} // 정답의 두 번째 자리수와 추측한 숫자 두 번째 자릿수가 일치할 때 strike를 +1 합니다.

		if (thirdNum == guessThird) {
			strike += 1;
		} // 정답의 세 번째 자리수와 추측한 숫자 세 번째 자릿수가 일치할 때 strike를 +1 합니다.

		if (firstNum == guessSecond) {
			ball += 1;
		}  // 정답의 첫 번째 자리수와 추측한 숫자 두 번째 자릿수가 일치할 때 ball을 +1 합니다.

		if (firstNum == guessThird) {
			ball += 1;
		} // 정답의 첫 번째 자리수와 추측한 숫자 세 번째 자릿수가 일치할 때 ball을 +1 합니다.
		
		if (secondNum == guessThird) {
			ball += 1;
		} // 정답의 두 번째 자리수와 추측한 숫자 세 번째 자릿수가 일치할 때 ball을 +1 합니다.


		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
		
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}

	return 0;
}
