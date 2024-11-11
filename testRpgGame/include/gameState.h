#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <string>
#include "player.h"
#include "inventory.h"


//클래스에서 다른 클래스의 멤버함수를 가져올 경우 문법 알아보기
class GameState {
    public:
        GameState(Player& player, Inventory& item);
        //상태 저장
        void save(const std::string& filename);
        //데이터 가져오기
        void load(const std::string& filename);

    private:
        Player& player; // 플레이어의 현재 상태를 참조 (멤버 변수임)
        Inventory& item;
};

#endif 