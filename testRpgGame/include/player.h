#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "character.h"

class Player : public Character {
    public:
        Player(std::string n, int h, int a);

        void displayStatus();

};

#endif