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

void User::doAttack()
{
    std::cout << "공격합니다" << std::endl; // 기본 공격 메시지
}

// Magician 클래스 구현
void Magician::doAttack()
{
    std::cout << "마법 사용" << std::endl; // 마법사 공격 메시지
}

// Warrior 클래스 구현
void Warrior::doAttack()
{
    std::cout << "베기 사용" << std::endl; // 전사 공격 메시지
}

// 출력 연산자 중복 정의
std::ostream &operator<<(std::ostream &os, const User &user)
{
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다.";
    return os;
}
