#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "character.h"

class Enemy : public Character {
    public:
        Enemy(std::string n, int h, int a);
};

#endif