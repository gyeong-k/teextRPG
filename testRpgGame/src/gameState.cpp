#include "../include/gameState.h"
#include <iostream>
#include <fstream>

GameState::GameState(Player& p, Inventory& i) : player(p), item(i) {}

void GameState::save(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << player.level << "\n";
        file << player.health << "\n";
        file << player.attackPower << "\n";
        file << item.health_item << "\n";
        file << item.attackPower_item << "\n";


        file.close();
        std::cout<< "Game saved successfully.\n" ;
    } else {
        std::cout << "Unable to open file for saving.\n";
    }
}

void GameState::load(const std::string& filename) {
    std::ifstream file(filename);
    if(file.is_open()) {
        int level;
        double health;
        double attackPower;
        double health_item;
        double attackPower_item;

        file >> level >> health >> attackPower >>health_item>> attackPower_item;
        player.level = level;
        player.health = health;
        player.attackPower = attackPower;
        item.health_item = health_item;
        item.attackPower_item = attackPower_item;

        file.close();
        std::cout << "Game loaded successfully.\n";
    } else {
        std::cerr << "Unable to open file for loading.\n";
    }
}