# 🧑🏻‍💻 C++프로그래밍및실습 (2024학년도 2학기, 김미수 교수님)

**#include <include>**

> *헤더파일은 미리 작성된 코드를 다른 코드 파일에서 재사용하거나 참조하기 위해 사용되는 파일을 의미합니다.*
> 

**using namespace std;**

> *std는 namespace를 사용하기 위해 선언하는 코드입니다.*
> 
- namespace: 특정 이름과 다른 이름이 충돌하지 않도록 구분하기 위해 사용합니다.
- std: 표준 C++ 라이브러리의 네임스페이스입니다.

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World!" << std::endl; 
    return 0;                       
}
```

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;                      
}
```

**int main()**

> *C++에서 프로그램의 시작점을 정의하는 것으로, 프로그램 실행 시 가장 먼저 실행되는 함수입니다.*
> 

**cout << “Hello World!” << endl;**

> *Hello World!를 출력하기 위한 코드입니다.*
> 
- cout: Character output의 약자로, 텍스트 출력 시 사용합니다.
- <<: 출력할 문자를 cout으로 전송하는 출력 연산자입니다.
- endl: 표준 줄바꿈 문자로, \n과 같은 역할입니다.

**return 0;**

> *main() 함수의 작업을 끝내고 외부로 0을 반환하는 코드입니다.*
> 

---

### Variable & Constant

**변수 Variable**

> *데이터(값)을 저장하는 상자로 메모리에 어떤 값을 저장할 때 사용하고, 변수를 선언한 후 사용할 때는 자료형을 명시하지 않아도 됩니다.*
> 
- 변수명 작성 규칙
    - 알파벳, 숫자, 밑줄을 사용할 수 있고, 알파벳은 대소문자를 구분합니다.
        - hello_1, HELLO_1
        - hello_1 ≠ HELLO_1
    - 첫 글자는 숫자로 시작 불가하며, 변수명 내 공백 포함이 불가합니다.
        - ❌ 123_abc
    - C++ 언어 내 키워드(예약어)로 지정된 단어는 사용이 불가합니다.
        - ❌ int

```cpp
int i; // 변수 i를 선언합니다.
i = 100 // 변수 i에 100을 저장합니다.

int i = 100; // 변수 i를 선언하고 100으로 초기화합니다.

int i { 100 }; // int i = 100;과 동일합니다.
string s { "Hello" }; // string s = "Hello"와 동일합니다.
```

**상수 Constant**

> *프로그램 내에서 값을 변경할 수 없는 값 또는 변수를 의미합니다.*
> 
- literal: 값으로 저장하는 숫자 또는 문자열 등을 의미하며, 프로그램 실행 동안 변경이 되지 않기 때문에 상수로 취급합니다.
- symbolic: 의미 있는 이름을 갖는 상수를 의미합니다.
    - #define: 세미콜론을 사용하지 않으며, #include 바로 밑에 작성됩니다.
        - #define PI 3.141592
    - const: 세미콜론을 붙여 사용합니다.
        - const double TAX_RATE = 0.25;

---

### Data Type

**논리형 Boolean**

> *참(True, 1 또는 0 이외의 모든 수) 또는 거짓(False, 0)만을 가질 수 있습니다.*
> 

**문자형 Char**

> *알파벳 문자 1개만 가질 수 있습니다.*
> 

**문자열형 String**

> 문자열을 가질 수 있으며, string 헤더파일을 추가하여 사용할 수 있습니다.
> 

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
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

> *auto 키워드는 변수나 표현식의 데이터 형식을 컴파일러가 자동으로 추론할 수 있도록 합니다.*
> 

```cpp
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

> *덧셈, 뺄셈, 곱셈은 생략하였습니다.*
> 

| 연산자 | 의미 |
| --- | --- |
| x / y | x를 y로 나눈다. |
| x & y | x를 y로 나눈 나머지를 의미합니다. |

**축약식**

> *뺄셈, 곱셈, 나눗셈은 생략하였습니다.*
> 

| 식 | 축약식 |
| --- | --- |
| a = a + b | a += b |

**증감연산자**

> *뺄셈은 생략하였습니다.*
> 

| 식 | 증감연산자 | 설명 |
| --- | --- | --- |
| a = a + 1 | a++ | a를 먼저 사용한 후 1을 더합니다. |
|  | ++a | a에 1을 먼저 더한 후 사용합니다. |

---

## Challenge

### 최대한의 사탕 사기

> *철수가 가지고 있는 돈과 캔디의 가격을 입력 받아, 철수가 최대한 살 수 있는 사탕 개수와 나머지 돈을 계산하라.*
> 
- 입력: 가지고 있는 돈, 사탕 가격
- 출력: 최대로 살 수 있는 캔디(몫), 캔디 구입 후 남은 돈(나머지)
- 테스트케이스: 철수가 가지고 있는 돈은 1000이며, 캔디의 가격은 300이다.

```cpp
#include <iostream>
using namespace std;

int main()
{
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

### 온도 변환

> *미국에서는 화씨 온도를 사용한다. 화씨 온도를 섭씨 온도로 바꾸는 프로그램을 작성하라.*
> 
- 입력: 화씨온도
- 출력: 섭씨온도
- 테스트케이스: 섭씨온도의 계산식은 (5.0 / 9.0) * (화씨온도 - 32)이며, 화씨온도는 60이다.

```cpp
#include <iostream>
using namespace std;

int main()
{
    double f_temp;
    double c_temp;
    
    cout << "화씨온도: "
    cin >> f_temp;
    
    c_temp = (5.0 / 9.0) * (f_temp - 32);
    
    cout << "섭씨온도: " << c_temp << endl;
    
    return 0;
}
```
