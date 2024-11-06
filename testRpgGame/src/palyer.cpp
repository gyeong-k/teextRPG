#include "../include/player.h"
#include <iostream>

Player::Player (std::string name, int health, int attackPower) : Character (name, health, attackPower) {};

//플레이어 상태 출력
void Player::displayStatus() {
    std::cout<<"player" <<name<< "- HP: " << health << "\n";
};


