#include "../include/battle.h"
#include <iostream>

void battle(Player& player, Enemy& enemy) {
    std::cout<< "Battle starts between " <<player.name << " and " << enemy.name << "!\n";

    while(player.isAlive() && enemy.isAlive()) {
        //플레이어 공격
        enemy.takeDamge(player.attackPower);
        std::cout << player.name << " attacks " << enemy.name << " for " << player.attackPower << " damage.\n";
        if (!enemy.isAlive()) {
            std:: cout << enemy.name << "is defeated\n" ;
            break;
        }

        //적의 공격
        player.takeDamge(enemy.attackPower);
        std::cout << enemy.name << " attacks " << player.name << " for " << enemy.attackPower << " damage.\n";
        if (!player.isAlive()) {
            std:: cout << player.name << "is defeated\n" ;
            break;
        }
    }   
}
