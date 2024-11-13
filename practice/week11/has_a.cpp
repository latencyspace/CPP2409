#include <iostream>
#include <string>
using namespace std;

class Date
{
    int year, month, day;

public:
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void Print()
    {
        cout << year << "." << month << "." << day << endl;
    }
};

class Person
{
    string name;
    Date birth;

    // Person 클래스 생성자에서 Date 타입의 birth 멤버 변수가 기본 생성자가 없기 때문에 해당 멤버를 초기화해야 함
    // 해결하기 위해 Person 클래스의 생성자에서 초기화 리스트를 사용해 birth를 초기화하였음
public:
    Person(string n, Date d) : name(n), birth(d)
    {
        // name = n;
        // birth = d;
    }
    void Print()
    {
        cout << name << ":";
        birth.Print();
        cout << endl;
    }
};

int main()
{
    Date d{1998, 3, 1};
    Person p{"김철수", d};
    p.Print();
    return 0;
}