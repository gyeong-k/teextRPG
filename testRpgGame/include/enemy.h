#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "character.h"

class Enemy : public Character {
    public:
        Enemy(std::string name, int health, int attackPower);
        //적으; 공격, 생명 올리는 메소드
        void increaseEnemySkill(); 
        void print() ;
};

#endif