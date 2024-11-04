#include "user.h"

// 생성자: HP를 20으로 설정
User::User() : hp(20) {}

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
