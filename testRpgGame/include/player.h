#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "character.h"

class Player : public Character {
    public:
        Player(std::string name, int health, int attackPower);

        void displayStatus();

};

#endif