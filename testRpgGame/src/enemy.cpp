#include "../include/enemy.h"
#include <string>
#include <ctime>
#include <random>
#include <iostream>

//생성자 함수
Enemy::Enemy (std::string name, int health, int attackPower) : Character (name, health, attackPower) {};
void Enemy::increaseEnemySkill(){
    //난수 생성기 초기화
    std::mt19937 generator(static_cast<unsigned int>(std::time(0)));   

    //정수 범위 난수 생성
    std::uniform_int_distribution<int> distribution_h(10,18); 
    std::uniform_int_distribution<int> distribution_a(15,23);    

    int randomHealth = distribution_h(generator);       //생명 증가 랜덤 비율
    int randomPower = distribution_a(generator);       //공격 증가 랜덤 비율

    health += health * 0.01 * randomHealth;
    attackPower += attackPower * 0.01 * randomPower;
} 

void Enemy::print() {
    std::cout << name << ", "<< health<< ", " << attackPower <<"\n";
}



