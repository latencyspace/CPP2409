#include "user.h"
#include <iostream>

// 생성자: HP를 20으로 설정, 아이템 개수를 0으로 초기화
User::User() : hp(20), itemCnt(0) {}

void User::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;
    if (hp < 0)
        hp = 0; // HP가 음수가 되지 않도록 조정
}

void User::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

int User::GetHP() const
{
    return hp;
}

void User::IncreaseItemCnt()
{
    itemCnt++;
}

int User::GetItemCnt() const
{
    return itemCnt;
}

// 출력 연산자 중복 정의
std::ostream &operator<<(std::ostream &os, const User &user)
{
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다.";
    return os;
}
