#ifndef USER_H
#define USER_H

#include <iostream>

class User
{
private:
    int hp;
    int itemCnt; // 아이템 개수 변수 추가

public:
    User(); // 생성자: HP를 20으로 설정
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP() const;
    void IncreaseItemCnt();
    int GetItemCnt() const;
    friend std::ostream &operator<<(std::ostream &os, const User &user); // 출력 연산자 오버로드 선언
};

#endif
