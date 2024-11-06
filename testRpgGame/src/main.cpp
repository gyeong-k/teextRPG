#include <iostream>
#include <string>
#include <vector>
#include "../include/battle.h"
#include "../include/character.h"
#include "../include/enemy.h"
#include "../include/player.h"

int main() {
    //플레이어 생성
    Player player("Hero", 100, 20);

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


