#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
class Character{
    public:
        std::string name;
        double health;
        double attackPower;

        Character (std::string name, double health, double attackPower);

        //캐릭터마다 데미지에 따라 감소 하는 health를 다르게 처리
        //그대로 사용한 자식은 재정의 필요 없음
        virtual void takeDamge (double damage);
        bool isAlive() const ;
};

#endif