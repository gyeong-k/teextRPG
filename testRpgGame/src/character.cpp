#include "../include/character.h"
#include <string>

Character::Character (std::string name, double health, double attackPower) : name(name), health(health), attackPower(attackPower) {};

void Character :: takeDamge(double damage) {
    health -= damage;
    if (health < 0) health = 0;
}

bool Character :: isAlive() const {
    return health > 0;
}
