#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <string>
#include "player.h"

//클래스에서 다른 클래스의 멤버함수를 가져올 경우 문법 알아보기
class GameState {
    public:
        GameState(Player& player);

        void save(const std::string& filename);

        void load(const std::string& filename);
};

#endif 