#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
protected:
    int hp;
    int itemCnt;

public:
    User() : hp(20), itemCnt(0) {}
    virtual ~User() {}
    virtual void DecreaseHP(int dec_hp) = 0;
    virtual void IncreaseHP(int inc_hp) = 0;
    virtual int GetHP() const = 0;
    void IncreaseItemCnt()
    {
        itemCnt++;
    }
    int GetItemCnt() const
    {
        return itemCnt;
    }
    virtual void doAttack() = 0;
    friend ostream &operator<<(ostream &os, const User &user);
};

class Magician : public User
{
public:
    void DecreaseHP(int dec_hp) override
    {
        hp -= dec_hp;
        if (hp < 0)
            hp = 0;
    }
    void IncreaseHP(int inc_hp) override
    {
        hp += inc_hp;
    }
    int GetHP() const override
    {
        return hp;
    }
    void doAttack() override
    {
        cout << "마법 사용" << endl;
    }
};

class Warrior : public User
{
public:
    void DecreaseHP(int dec_hp) override
    {
        hp -= dec_hp;
        if (hp < 0)
            hp = 0;
    }
    void IncreaseHP(int inc_hp) override
    {
        hp += inc_hp;
    }
    int GetHP() const override
    {
        return hp;
    }
    void doAttack() override
    {
        cout << "베기 사용" << endl;
    }
};

ostream &operator<<(ostream &os, const User &user)
{
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다." << endl;
    return os;
}

#endif
