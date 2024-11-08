#include <random>
#include <ctime>
#include <iostream>
#include "../include/inventory.h"
#include "../include/player.h"


Inventory::Inventory (double health_item, double attackPower_item) 
    : health_item(health_item),attackPower_item(attackPower_item)  {} 

    //item 성능 올리기 => 매 레벨 시작 시 호출
void Inventory::increase_item(double health_default_increase, double attackPower_default_increase) {
    //난수 생성기 초기화
    std::mt19937 generator(static_cast<unsigned int>(std::time(0)));    //현재 시간 시드 설정 => int로 변환

    //정수 범위 난수 생성
    std::uniform_int_distribution<int> distribution_h(20,30); 
    std::uniform_int_distribution<int> distribution_a(30,40);    

    int randomHealth = distribution_h(generator);       //생명 증가 비율
    int randomAttackPower = distribution_a(generator);  //공격력 증가 비율

    //std::cout<<"인벤토리 1 : "<<health_item<<","<< attackPower_item<<"\n";

    //호출 될 때마다 아이템 성능 올리기
    health_item += health_default_increase*randomHealth*0.01;
    attackPower_item += attackPower_default_increase*randomAttackPower*0.01;
    std::cout<<"아이템 증가값"<< health_default_increase*randomHealth*0.01<<",   "<< attackPower_default_increase*randomAttackPower*0.01<<"\n";
    std::cout<<"증가 결과"<<health_item<<",    "<< attackPower_item<<"\n";


}

void Inventory::increaseHealthItem(double healthDefaulIncrease) {
    //난수 생성기 초기화
    std::mt19937 generator(static_cast<unsigned int>(std::time(0)));    //현재 시간 시드 설정 => int로 변환
    //정수 범위 난수 생성
    std::uniform_int_distribution<int> distribution_h(20,25); 

    int randomHealth = distribution_h(generator);       //생명 증가 비율
    //생명 아이템 값
    health_item += healthDefaulIncrease*randomHealth*0.01;


};
void Inventory::increaseAttackPowerItem(double healthDefaultIncrease) {
    //난수 생성기 초기화
    std::mt19937 generator(static_cast<unsigned int>(std::time(0)));    //현재 시간 시드 설정 => int로 변환
    //정수 범위 난수 생성
    std::uniform_int_distribution<int> distribution_a(30,35); 
    int randomAttackPower = distribution_a(generator);  //공격력 증가 비율

    //공격력 아이템 값
    attackPower_item += healthDefaultIncrease*randomAttackPower*0.01;

};