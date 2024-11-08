#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "character.h"

class Player : public Character {
    public:
        int level;
        Player(std::string name, double health, double attackPower, int level);

        void displayStatus();
        void increase_player();

};

#endif