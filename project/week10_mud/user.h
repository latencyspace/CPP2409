#ifndef USER_H
#define USER_H

class User
{
private:
    int hp;

public:
    User(); // 생성자: HP를 20으로 설정
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP() const;
};

#endif
