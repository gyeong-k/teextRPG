#include "./include/character.h"
//#include <string>

Character::Character (std::string n, int h, int a) : name(n), health(h), attackPower(a) {};

void Character :: takeDamge(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

bool Character :: isAlive() const {
    return health > 0;
}
