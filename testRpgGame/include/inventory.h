#ifndef INVENTORY_H
#define INVENTORY_H
#include "../include/player.h"
//생명 아이템
//
class Inventory {
    public:
        double health_item;
        double attackPower_item;

        // Inventory() = default;  // 기본 생성자 추가
        Inventory (double health_item, double attackPower_item);

        void increase_item(double health_default_increase, double attackPower_default_increase);
        void increaseHealthItem(double healthDefaulIncrease);
        void increaseAttackPowerItem(double healthDefaultIncrease);

};

#endif