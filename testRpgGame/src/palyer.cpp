#include "../include/player.h"
#include <iostream>
#include <random>
#include <ctime>

Player::Player (std::string name, double health, double attackPower, int level) : Character (name, health, attackPower), level(level) {}

//플레이어 상태 출력
void Player::displayStatus() {
    std::cout<<"player" <<name<< "- HP: " << health << "level : " << level<<"\n";
}

//플레이어의 능력치 올리기 / 매 레밸마다 기본적으로 올리는 것
void Player::increase_player() {
//난수 생성기 초기화
    std::mt19937 generator(static_cast<unsigned int>(std::time(0)));    //현재 시간 시드 설정 => int로 변환

    //정수 범위 난수 생성
    std::uniform_int_distribution<int> distribution_h(8,10);
    std::uniform_int_distribution<int> distribution_a(5,7); 

    
    int randomHealth = distribution_h(generator);       //생명 증가 비율
    int randomAttackPower = distribution_a(generator);  //공격력 증가 비율
    
    std::cout<< "기본 증가 전 : " << health <<","<<attackPower <<"\n";
    health += health * randomHealth * 0.01;
    attackPower += attackPower * randomAttackPower * 0.01;
    std::cout<< "기본 증가 후 : " << health <<","<<attackPower <<"\n";
}




