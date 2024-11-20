# 🧑🏻‍💻 C++프로그래밍및실습 (2024학년도 2학기, 김미수 교수님)

### CPP Style Guide

> Based on Google Coding Style

- 클래스 및 함수명: PascalCase
- 파일이름 및 변수명: snake_case
- 상수명: SNAKE_CASE

**#include <include>**

> _헤더파일은 미리 작성된 코드를 다른 코드 파일에서 재사용하거나 참조하기 위해 사용되는 파일을 의미합니다._

**using namespace std;**

> _std는 namespace를 사용하기 위해 선언하는 코드입니다._

- namespace: 특정 이름과 다른 이름이 충돌하지 않도록 구분하기 위해 사용합니다.
- std: 표준 C++ 라이브러리의 네임스페이스입니다.

```cpp
// ❌ using namespace std;

#include <iostream>

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

```cpp
// ⭕️ using namespace std;

#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
```

**int main()**

> _C++에서 프로그램의 시작점을 정의하는 것으로, 프로그램 실행 시 가장 먼저 실행되는 함수입니다._

**cout << “Hello World!” << endl;**

> _Hello World!를 출력하기 위한 코드입니다._

- cout: Character output의 약자로, 텍스트 출력 시 사용합니다.
- <<: 출력할 문자를 cout으로 전송하는 출력 연산자입니다.
- endl: 표준 줄바꿈 문자로, \n과 같은 역할입니다.

**return 0;**

> _main() 함수의 작업을 끝내고 외부로 0을 반환하는 코드입니다._

---

### Variable & Constant

**변수 Variable**

> _데이터(값)을 저장하는 상자로 메모리에 어떤 값을 저장할 때 사용하고, 변수를 선언한 후 사용할 때는 자료형을 명시하지 않아도 됩니다._

- 변수명 작성 규칙
  - 알파벳, 숫자, 밑줄을 사용할 수 있고, 알파벳은 대소문자를 구분합니다.
    - hello_1, HELLO_1
    - hello_1 ≠ HELLO_1
  - 첫 글자는 숫자로 시작 불가하며, 변수명 내 공백 포함이 불가합니다.
    - ❌ 123_abc
  - C++ 언어 내 키워드(예약어)로 지정된 단어는 사용이 불가합니다.
    - ❌ int

```cpp
// 변수 선언 예시

int i; // 변수 i를 선언합니다.
i = 100 // 변수 i에 100을 저장합니다.

int i = 100; // 변수 i를 선언하고 100으로 초기화합니다.

int i { 100 }; // int i = 100;과 동일합니다.
string s { "Hello" }; // string s = "Hello"와 동일합니다.
```

**상수 Constant**

> _프로그램 내에서 값을 변경할 수 없는 값 또는 변수를 의미합니다._

- literal: 값으로 저장하는 숫자 또는 문자열 등을 의미하며, 프로그램 실행 동안 변경이 되지 않기 때문에 상수로 취급합니다.
- symbolic: 의미 있는 이름을 갖는 상수를 의미합니다.
  - #define: 세미콜론을 사용하지 않으며, #include 바로 밑에 작성됩니다.
    - #define PI 3.141592
  - const: 세미콜론을 붙여 사용합니다.
    - const double TAX_RATE = 0.25;

---

### Data Type

**논리형 Boolean**

> _참(True, 1 또는 0 이외의 모든 수) 또는 거짓(False, 0)만을 가질 수 있습니다._

**문자형 Char**

> _알파벳 문자 1개만 가질 수 있습니다._

**문자열형 String**

> 문자열을 가질 수 있으며, string 헤더파일을 추가하여 사용할 수 있습니다.

```cpp
// C++에서 + 연산자는 문자열끼리 더할 수 있지만, 문자열과 정수는 직접 더할 수 없음

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "사과";
    string s2;

    s2 = s1 + " " + to_string(10) + "개";
    // s2 = s1 + " " + 10 + "개";

    cout << s2 << endl;
}
```

---

### Automatic Type Deduction

**자동 타입 추론**

> _auto 키워드는 변수나 표현식의 데이터 형식을 컴파일러가 자동으로 추론할 수 있도록 합니다._

```cpp
// auto d = 1.0;

#include <iostream>
using namespace std;

auto add(int x, int y)
{
    return x + y;
}

int main()
{
    auto sum = add(5, 6);
    cout << sum;
    return 0;
}
```

---

### Input & Output Function

```cpp
int i;
cin >> i; // 정수를 읽어서 i에 저장합니다.

double f;
cin >> f; // 실수를 읽어서 f에 저장합니다.

cout << i; // 정수 형식으로 i의 값이 출력됩니다.
cout << f; // 실수 형식으로 f의 값이 출력됩니다.
```

---

### Expression & Operators

**산술연산자**

> _덧셈, 뺄셈, 곱셈은 생략하였습니다._

| 연산자 | 의미                              |
| ------ | --------------------------------- |
| x / y  | x를 y로 나눈다.                   |
| x & y  | x를 y로 나눈 나머지를 의미합니다. |

**축약식**

> _뺄셈, 곱셈, 나눗셈은 생략하였습니다._

| 식        | 축약식 |
| --------- | ------ |
| a = a + b | a += b |

**증감연산자**

> _뺄셈은 생략하였습니다._

| 식        | 증감연산자 | 설명                             |
| --------- | ---------- | -------------------------------- |
| a = a + 1 | a++        | a를 먼저 사용한 후 1을 더합니다. |
|           | ++a        | a에 1을 먼저 더한 후 사용합니다. |

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    iny y = ++x; // x를 먼저 증가시키고 증가시킨 값을 y에 대입합니다.
    // x+1이 된 6이 y에 저장되고, x 값이 6이 됩니다.
    int z = x--; // x가 z에 대입되고 x 값이 감소합니다.
    // x 값인 6이 z에 저장되고, x 값이 감소되어 5가 됩니다.

    return 0;
}
```

---

### Challenge

**최대한의 사탕 사기**

> _철수가 가지고 있는 돈과 캔디의 가격을 입력 받아, 철수가 최대한 살 수 있는 사탕 개수와 나머지 돈을 계산하라._

- 입력: 가지고 있는 돈, 사탕 가격
- 출력: 최대로 살 수 있는 캔디(몫), 캔디 구입 후 남은 돈(나머지)
- 테스트케이스: 철수가 가지고 있는 돈은 1000이며, 캔디의 가격은 300이다.

```cpp
#include <iostream>
using namespace std;

int main() {
    int money;
    int candy_price;

    cout << "현재 가지고 있는 돈: ";
    cint >> money;

    cout << "캔디의 가격: ";
    cin >> candy_price;

    int n_candies = money / candy_price;
    cout << "최대로 살 수 있는 캔디의 개수: " << n_candies << endl;

    int change = money % candy_price;
    cout << "캔디 구입 후 남은 돈: " << change << endl;

    return 0;
}
```

**온도 변환**

> _미국에서는 화씨 온도를 사용한다. 화씨 온도를 섭씨 온도로 바꾸는 프로그램을 작성하라._

- 입력: 화씨온도
- 출력: 섭씨온도
- 테스트케이스: 섭씨온도의 계산식은 (5.0 / 9.0) \* (화씨온도 - 32)이며, 화씨온도는 60이다.

```cpp
#include <iostream>
using namespace std;

int main() {
    double f_temp;
    double c_temp;

    cout << "화씨온도: "
    cin >> f_temp;

    c_temp = (5.0 / 9.0) * (f_temp - 32);

    cout << "섭씨온도: " << c_temp << endl;

    return 0;
}
```

---

### **제어문 Control Statement**

> _프로그램의 실행 흐름을 조절하는 문장으로, 꼭 세미콜론으로 구분되진 않습니다._

**관계 연산자 Relational Operators**

> _두 변수 사이에 관계를 나타내기 위한 연산자로, 참이면 1 거짓이면 0을 반환하며 >, ≥, <, ≤은 생략하였습니다._

| 비교 표현식 | 의미            |
| ----------- | --------------- |
| x == y      | x와 y가 같은가? |
| x != y      | x와 y가 다른가? |

**논리 연산자 Logical Operators**

> _논리적인 조건을 판단하고 논리값을 조합하거나 변환하는 연산자입니다._

| 논리 표현식 |          | 의미                                                  |
| ----------- | -------- | ----------------------------------------------------- | ------- | -------------------------------------------------------- |
| x && y      | AND 연산 | x와 y가 모두 참이면 참이며, 그렇지 않으면 거짓입니다. |
| x           |          | y                                                     | OR 연산 | x나 y 중 하나만 참이면 참이며, 모두 거짓이면 거짓입니다. |
| !x          | NOT 연산 | x가 참이면 거짓, 거짓이면 참입니다.                   |

---

### **조건문 Control Statement**

> _프로그램이 특정 조건에 따라 다른 동작을 수행하도록 하는 구조의 문장입니다._

**if-else**

> _주어진 조건이 참일 경우, 중괄호 안에 있는 문장을 실행합니다._

```cpp
if (조건식 1) {
		문장 1
}

else if (조건식 2) {
		문장 2
}

else {
		문장 3
}
```

- if: 가장 첫 번째로 확인할 블록입니다.
- else if: 상위 조건을 만족하지 않을 경우 확인할 블록입니다.
- else: 조건을 모두 만족하지 않을 때 수행되는 블록입니다.

```cpp
// 3개의 정수를 입력 받고, 가장 큰 수를 출력하는 프로그램

#include <iostream>
using namespace std;

int main() {
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    if (a >= b && a >= c)
        largest = a;
    else if (b >= a && b >= c)
        largest = b;
    else
        largest = c;

    cout << "가장 큰 정수는 " << largest << endl;
    return 0;
}
```

**switch**

> _케이스에 따라 다른 동작을 수행할 때 사용되는 제어구조입니다._

```cpp
// break가 없으면, 참인 케이스 이후에 모든 케이스 블록이 실행됨

switch (표현식) {
		case 값 1:
			문장 1;
			break;
		case 값 2:
			문장 2;
			break;
		default;
			문장 3;
}
```

```cpp
// 사용자에게 메뉴를 입력받아 실행 결과를 출력하는 프로그램

#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "1. 파일 저장" << endl;
    cout << "2. 저장 없이 닫기" << endl;
    cout << "3. 종료" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "파일 저장을 선택했습니다." << endl;
        break;
    case 2:
        cout << "파일 닫기를 선택했습니다." << endl;
        break;
    case 3:
        cout << "프로그램을 종료합니다." << endl;
        break;
    default:
        cout << "잘못된 선택입니다." << endl;
        break;
    }

    return 0;
}
```

**Comparison**

|        | if-else                                                                               | switch                                                                               |
| ------ | ------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| 구조   | 상단에서 확인 가능합니다.                                                             | 상단에서 확인 가능합니다.                                                            |
| 장점   | 더 복잡한 조건식 표현이 가능하며, 조건 범위나 자료형에 제약이 없습니다.               | 조건 설정이 쉬워 코드 가독성이 높고, 조건식이 단순해 프로그램이 효율적입니다.        |
| 단점   | 조건식에 따라 프로그램 성능(속도)에 악영향을 미치며, switch 대비 가독성이 떨어집니다. | 제한된 데이터 유형으로 인해 조건식이 제한되어있고, break문의 실수 가능성이 높습니다. |
| 사용처 | switch 문으로 처리가 어려운 경우 사용합니다.                                          | 선택지에 대한 처리가 필요할 때 사용합니다.                                           |

---

### Challenge

**switch → if-else**

```cpp
// Problem

#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "1. 파일 저장" << endl;
    cout << "2. 저장 없이 닫기" << endl;
    cout << "3. 종료" << endl;
    cin >> choice;

    switch (choice) {
		    case 1:
	        cout << "파일 저장을 선택했습니다." << endl;
					break;
				case 2:
					cout << "파일 닫기를 선택했습니다." << endl;
					break;
				case 3:
					cout << "프로그램을 종료합니다." << endl;
					break;
				default:
					cout << "잘못된 선택입니다." << endl;
					break;
		}

    return 0;
}

```

```cpp
// Answer

#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "1. 파일 저장" << endl;
    cout << "2. 저장 없이 닫기" << endl;
    cout << "3. 종료" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "파일 저장을 선택했습니다." << endl;
    }
    else if (choice == 2) {
        cout << "파일 닫기를 선택했습니다." << endl;
    }
    else if (choice == 3) {
        cout << "프로그램을 종료합니다." << endl;
    }
    else {
        cout << "잘못된 선택입니다." << endl;
    }

    return 0;
}

```

**if-else → switch**

```cpp
// Problem

#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "숫자를 입력하시오: ";
    cin >> number;

    if (number == 0) {
		    cout << "zero" << endl;
		}
    else if (number == 1) {
        cout << "one" << endl;
    }
    else {
        cout << "many" << endl;
    }

    return 0;
}
```

```cpp
// Answer

#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "숫자를 입력하시오: ";
    cin >> number;

    switch (number) {
    case 0:
        cout << "zero" << endl;
        break;
    case 1:
        cout << "one" << endl;
        break;
    default:
        cout << "many" << endl;
    }

    return 0;
}
```

---

### Loop Statement

**for 문**

```cpp
for (초기식; 조건식; 증감식) {
	문장
}
```

```cpp
// i가 0부터 시작해 1씩 증가시키면서 5 미만일 때 까지 아래 문장을 반복하는 예시

for (i = 0; i < 5; i++) {
	cout << "Hello";
}
```

1. 변수를 선언하고 초기화 합니다. 이는 한 번만 수행됩니다.
2. 변수의 조건을 확인합니다.
3. 조건에 해당하면 중괄호 내에 있는 문장을 수행합니다.
4. 변수의 값을 증감한 후 다시 조건을 확인합니다.

```cpp
// 1부터 10까지의 정수를 더하여 합을 구하는 프로그램

#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 1; i <= 10; i++)
	    sum += 1;
	   cout << "1부터 10까지의 정수의 합: " << sum << endl;

    return 0;
}
```

```cpp
// 팩토리얼 값을 계산하는 프로그램

#include <iostream>
using namespace std;

int main() {
    long fact = 1;
    int n;

    cout << "정수를 입력하시오: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
        fact = fact * i;

    cout << n << "!은 " << fact << "입니다." << endl;

    return 0;
}
```

**while 문**

```cpp
while (조건식) {
	문장
}
```

1. 조건식을 확인합니다.
2. 조건식이 참이면 문장을 수행합니다.

```cpp
// 구구단

#include <iostream>
using namespace std;

int main() {
    int n;
    int i = 1;

    cout << "구구단 중에서 출력하고 싶은 단을 입력하시오: ";
    cin >> n;

    while (i <= 9) {
	    cout << n << " * " << i << " = " << n * i << endl;
	    i++;
	   }
		return 0;
}
```

**do-while 문**

```cpp
do {
	문장
}
while (조건식);
```

1. 문장을 먼저 한 번 수행합니다.
2. 조건식을 확인합니다.
3. 조건식이 참이면 문장을 수행합니다.

```cpp
// 종료를 입력하기 전까지 입력을 그대로 출력하는 프로그램

#include <iostream>
using namespace std;

int main() {
    string str;
    do {
	    cout << "문자열을 입력하시오: ";
	    cin >> str;
	    cout << "사용자의 입력: " << str << endl;
	  }
	  while (str != "종료");

		return 0;
}
```

**break**

```cpp
// 4까지 출력하고 반복문을 즉각 종료하는 프로그램

#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i < 10; i++)
    {
	    cout << i << " ";
	    if (i == 4)
		    break;
		}
		return 0;
}
```

**continue**

```cpp
// 다음 반복을 즉각 진행하여 continue를 출력하는 프로그램

#include <iostream>
using namespace std;

int main() {
    int i = 0;
    do {
	    i++;
	    cout << "continue 문장 전에 있는 문장" << endl;
	    continue;
	    cout << "continue 문장 후에 있는 문장" << endl;
	  }
	  while (i < 3);
	  return 0;
}
```

**Comparison**

|        | for                                                    |
| ------ | ------------------------------------------------------ |
| 구조   | 상단에서 확인 가능합니다.                              |
| 장점   | 초기화, 조건 검사, 증감코드 명확 등의 장점이 있습니다. |
| 단점   | 반복 횟수를 알아야만 합니다.                           |
| 사용처 | 반복 횟수를 알고 있을 때 사용할 수 있습니다.           |
| 예     | 리스트 순회                                            |

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};

    cout << "for문을 사용하여 리스트 순회: " << endl;

    for (int i = 0; i < 5; i++) {
	    cout << numbers[i] << " ";
	  }
	  cout << endl;

	  return 0;
}
```

|        | while                                                |
| ------ | ---------------------------------------------------- |
| 구조   | 상단에서 확인 가능합니다.                            |
| 장점   | 초기화나 증감 코드가 필수가 아닙니다.                |
| 단점   | 조건 검사를 명확히 설정해야 합니다.                  |
| 사용처 | 종료 조건이 불명확하거나, 무한 루프일 때 사용합니다. |
| 예     | 사용자 입력 처리                                     |

```cpp
#include <iostream>
using namespace std;

int main() {
    int userInput;
    cout << "while문을 사용하여 사용자의 입력 처리: " << endl;

    cout << "정수를 입력하세요 (0을 입력하면 종료): ";
    while (true) {
	    cin >> userInput;

	    if (userInput == 0) {
		    break;
		  }

		  cout << "입력값: " << userInput << endl;
		}
		return 0;
}
```

|        | do-while                                        |
| ------ | ----------------------------------------------- |
| 구조   | 상단에서 확인 가능합니다.                       |
| 장점   | 최소 한 번의 실행을 보장합니다.                 |
| 단점   | 불필요한 실행이 발생할 수 있습니다.             |
| 사용처 | 최소 한 번 실행 후 조건을 검사할 때 사용합니다. |
| 예     | 메뉴 선택                                       |

```cpp
#include <iostream>
using namespace std;

int main() {
	int choice;
  cout << "do-while문을 사용하여 메뉴 선택: " << endl;

  do {
		cout << "메뉴를 선택하세요 (1. 옵션 1, 2. 옵션 2, 3. 종료): ";
	  cin >> choice;

	  switch (choice) {
		  case 1:
			  cout << "옵션 1 선택" << endl;
			  break;
			case 2:
				cout << "옵션 2 선택" << endl;
				break;
			case 3:
				cout << "프로그램 종료" << endl;
				break;
			case 4:
				cout << "잘못된 선택" << endl;
				break;
		}
	} while (choice != 3);
	return 0;
}
```

**중첩문 Nested Statement**

> _조건문 안에 조건문을 n번 겹치게 작성하는 문장입니다._

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "구구단 출력: " << endl;

    for (int i = 2; i <= 9; ++i)
    {
        cout << i << "단: " << endl;

        for (int j = 1; j <= 9; ++j)
        {
            cout << i << " x " << j << " = " << (i + j) << endl;
        }
        cout << endl;
    }
    return 0;
}
```

---

### Challenge

**[while → for] while로 구현된 아래 코드를 for문을 사용해 구현하세요.**

```cpp
// Problem

#include <iostream>
using namespace std;

int main() {
    int userInput;

    cout << "정수를 10번 입력하세요 (0을 입력하면 종료): ";

    while (true) {
			  cin >> userInput;
			  if (userInput == 0) {
				  break;
		}
    cout << "입력값: " << userInput << " 횟수: " << i << endl;

    if (i == 10) {
			break;
		}

			}
    cout << "종료되었습니다." << endl;

    return 0;
}
```

```cpp
// Answer

#include <iostream>
using namespace std;

int main() {
    int userInput;

    cout << "정수를 10번 입력하세요 (0을 입력하면 종료): ";

    for (int i = 0; i < 10; i++) {
        cin >> userInput;
        if (userInput == 0) {
            break;
        }

        cout << "입력값: " << userInput << " 횟수: " << i << endl;
    }
    cout << "종료되었습니다." << endl;

    return 0;
}
```

**[자음과 모음 개수 세기] 영문자를 입력받고, 영문자들의 자음과 모음의 개수를 세는 프로그램을 구현하세요.**

```cpp
#include <iostream>
using namespace std;

int main()
{
    int vowel = 0;
    int consonant = 0;
    cout << "영문자를 입력하고 ctrl + z를 치세요" << endl;

    char ch;

    while (cin >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vowel++;
            break;
        default:
            consonant++;
        }
    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;

    return 0;
}
```

**[숫자 맞추기 프로그램] 프로그램이 저장한 0부터 99사이의 정수를 사용자가 맞추는 프로그램을 구현하세요.**

```cpp
#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));

    int answer = rand() % 100;
    int tries = 0;

    int guess;

    do {
        cout << "정답을 추측하여 보시오: ";
        cin >> guess;
        tries++;

        if(guess > answer)
        cout << "제시한 정수가 높습니다." <<endl;
        if(guess < answer)
        cout << "제시한 정수가 낮습니다." <<endl;
    } while (guess != answer);

    cout << "축하합니다. 시도 횟수= " <<tries << endl;
    return 0;
}
```

**[산수 문제 자동 출제] 프로그램이 보여주는 산수 문제를 푸는 프로그램을 구현하세요.**

```cpp
// 종료조건: 사용자가 정답을 맞출 때

#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int i;
    int ans;
    cout << "산수 문제를 자동으로 출제합니다. " << endl;

    while (true) {
        int firstNum = rand() % 100;
        int secondNum = rand() % 100;

        cout << firstNum << " + " << secondNum << " = ";
        cin >> ans;

        if (firstNum + secondNum == ans) {
            cout << "맞았습니다." << endl;
            break;
        }
        else {
            cout << "틀렸습니다." << endl;
        }

    }
    return 0;
}
```
