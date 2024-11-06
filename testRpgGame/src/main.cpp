#include <iostream>
#include <string>
#include <vector>
#include "../include/battle.h"
#include "../include/character.h"
#include "../include/enemy.h"
#include "../include/player.h"

int main() {
    int level = 1;
    //플레이어 생성
    Player player("Hero", 100, 20);

    //플레이어가 죽을 떄까지 반복
    //한 판에 적이 다 죽으면 레벨 올려 -> 레벨은 50까지
    //매 레밴 inventory 안에 있는 함수를 이용해서 아이템을 받아와
    //플레이어는 선택해서 능력치 올려
    //적은 매 레벨마다 수 또는 능력이 올라가 -> 이건 적 헤더 파일에 구현홰
    
    //50은 기니까 중간에 게임을 저장하고 불러올 수 있어야 돼
    //이건 한 레벨이 끝나면 선택하게 해줘.
    
    

    //여러 적 생성
    std::vector<Enemy> enemies;
    enemies.push_back(Enemy("Goblin", 50, 10));
    enemies.push_back(Enemy("Orc", 80, 15));
    enemies.push_back(Enemy("Troll", 100, 20));

    std::cout << "Enemies:\n";

    for (size_t i = 0; i < enemies.size(); ++i) {
        std::cout << i + 1 << ". " << enemies[i].name << " (HP: " << enemies[i].health << ", Attack: " << enemies[i].attackPower << ")\n";
    }
    battle(player, enemies[0]);
    return 0;
}


