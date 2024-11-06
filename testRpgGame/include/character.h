#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
class Character{
    public:
        std::string name;
        int health;
        int attackPower;

        Character (std::string n, int h, int a);

        //캐릭터마다 데미지에 따라 감소 하는 health를 다르게 처리
        //그대로 사용한 자식은 재정의 필요 없음
        virtual void takeDamge (int damage);
        bool isAlive() const ;
};

#endif