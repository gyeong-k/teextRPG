#ifndef ENERMY_H
#define ENERMY_H

#include <string>
#include "character.h"

class Enermy : public Character {
    public:
        Enermy(std::string n, int h, int a);
};

#endif