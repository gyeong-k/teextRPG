#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "../include/battle.h"
#include "../include/character.h"
#include "../include/enemy.h"
#include "../include/player.h"
#include "../include/inventory.h"

std::vector<Enemy> makeEnemies();
bool processBattleRound(Enemy& enemy, int num , Player& player, Inventory& item) ;
void processLevelUp (Player& player, Enemy& enemy, Inventory& item);



int main() {
    int level = 1;
    bool result;

    //플레이어 생성
    Player player("Hero", 100, 20, level);
    player.displayStatus();
    
    //아이템 생성
    Inventory item(player.health*0.1, player.attackPower*0.07); 

    //적의 vector 생성
    std::vector<Enemy> enemies = makeEnemies();

    // player.increase_player();
    // item.increase_item(player.health*0.1, player.attackPower*0.07);
    // player.health += item.health_item;
    // player.attackPower += item.attackPower_item;
    // player.increase_player();
    // player.health += item.health_item;
    // player.attackPower += item.attackPower_item;
    // item.increase_item(player.health*0.1, player.attackPower*0.07);


    //플레이어가 죽을 떄까지 반복
    //한 판에 적이 다 죽으면 레벨 올려 -> 레벨은 50까지
    //매 레밴 inventory 안에 있는 함수를 이용해서 아이템을 받아와
    //플레이어는 선택해서 능력치 올려
    //적은 매 레벨마다 수 또는 능력이 올라가 -> 이건 적 헤더 파일에 구현홰   
    //50은 기니까 중간에 게임을 저장하고 불러올 수 있어야 돼
    //이건 한 레벨이 끝나면 선택하게 해줘.
    //여러 적 생성 및 초기화

    std::cout << "Enemies:\n";

    for (size_t i = 0; i < enemies.size(); ++i) {
        std::cout << i + 1 << ". " << enemies[i].name << " (HP: " << enemies[i].health << ", Attack: " << enemies[i].attackPower << ")\n";
    }


    for (size_t i = 1; i <= 50 ; i++) {
        Enemy enemy = enemies[i-1];
        enemy.print();

        switch ((i-1) / 5)
        {
            case 0: //1~5
                result = processBattleRound(enemies[0], 1 , player, item) ;    
                if (result)  processLevelUp(player, enemies[0], item);
                break;

            case 1: //6~10
                //enemy = enemies[1];
                if(player.level < 8)   {
                    result = processBattleRound(enemies[1], 1 , player, item);
                    if (result)  processLevelUp(player, enemies[0], item);    
                }
                else {
                    result = processBattleRound(enemies[1], 2 , player, item);
                };
                break;

            case 2: //11~15
                //enemy = enemies[2];
                result = processBattleRound(enemies[2], 2 , player, item) ;                
                break;

            case 3: //16~20
                //enemy = enemies[3];
                result = processBattleRound(enemies[3], 3 , player, item) ;
                break;

            case 4: //21~15
                //enemy = enemies[4];
                if(player.level < 24)  result = processBattleRound(enemies[4], 3 , player, item) ;
                else    result = processBattleRound(enemies[4], 4 , player, item) ;
                break;

            case 5: //26~30
                //enemy = enemies[5];
                result = processBattleRound(enemies[5], 4 , player, item) ;
                break;

            case 6: //31~35
                //enemy = enemies[6];
                result = processBattleRound(enemies[6], 4 , player, item) ;
                break;

            case 7: //36~40
                //enemy = enemies[7];
                result = processBattleRound(enemies[7], 4 , player, item) ;
                break;

            case 8: //41~45
                //enemy = enemies[8];
                result = processBattleRound(enemies[8], 5 , player, item) ;
                break;

            case 9: //46~50
                //enemy = enemies[9];
                if (player.level == 50) result = processBattleRound(enemies[10], 5 , player, item) ;
                else    result = processBattleRound(enemies[9], 5 , player, item) ;
                break;
            
            default:
                std::cout << "적이 존재하지 않습니다." << "\n";
                break;
        }
        // if (result) {
        //     processLevelUp(player, enemy, item);
        // }
        if (!player.isAlive()) {
            std::cout << "============================================" << "\n" << "\n";

            std::cout << "사망 - 최종 레벨: "<< player.level << "\n";
            break;
        }     
    }
    
    return 0;
}

std::vector<Enemy> makeEnemies () {
    std::vector<Enemy> enemies;
    enemies.push_back(Enemy("Goblin", 50, 10));
    enemies.push_back(Enemy("Wolf", 88, 16));
    enemies.push_back(Enemy("Orc", 155, 25));
    enemies.push_back(Enemy("Troll", 270, 40));
    enemies.push_back(Enemy("Skeleton Warrior", 477, 67));
    enemies.push_back(Enemy("Lightning Spirit", 1313, 160));
    enemies.push_back(Enemy("Dark Knight", 2300, 260));
    enemies.push_back(Enemy("Flame Sorcerer", 4055, 418));
    enemies.push_back(Enemy("Corrupted Dragon", 7121	, 672));
    enemies.push_back(Enemy("Shadow Lord", 12510, 1080));
    return enemies;
}
bool processBattleRound(Enemy& enemy, int num , Player& player, Inventory& item) {
    
    //플레이어 죽었는지 판단하는 변수
    bool alive = true;
    //죽은 적의 수
    int deadNum = 0;
    //아이템 고르기
    int choose;
    

    //적의 수만큼 반복
    for (size_t i =1 ; i < num +1 ; i++){
        //먼저 배틀
        bool result = battle(player, enemy);
        
        //적 한마리 죽을 때마다 아이템 선택해 보충
        //적이 죽어고 배틀할 적이 남으면 보충 아이템 선택
        if (result &&  i < num) {    
            //죽은 적의 수 +1
            deadNum ++;    
            std::cout << "적을 처지했습니다 " << "\n";
            std::cout << "남은 적의 수 : " << num - i << "\n";

            //아이템 선택
            while (1)
            {
                std::cout << "아이템을 선택하세요. " << "\n";
                std::cout << "1 : 생명력 "<< "+" << item.health_item<< "\n";
                std::cout << "2 : 공격력 " <<"+" << item.attackPower_item <<"\n";
                std::cin >> choose;
                if(choose == 1) {
                    player.health += item.health_item;
                    std::cout << "플레이어의 체력 : " << player.health <<"\n";
                    break;
                }
                else if (choose == 2){
                    player.attackPower += item.attackPower_item;
                    std::cout << "플레이어의 공격력 : " << player.attackPower <<"\n";
                    break;
                } else {
                    std::cout << "다시 입력해 주세요." << "\n";
                }
            }
        } else {
            //플레이어 죽음
            return false; //   배틀함수 boolean으로 바꾸기고 false  반환 (이럼 반복문도 알아서 끝나겠지 모)
        }
    }
    //반복 끝
    if ( num == deadNum )   return true;
    else return false;
}

void processLevelUp (Player& player,Enemy& enemy, Inventory& item) {
    int choose;

    //플레이어 레벨 업
    player.level ++;
    std::cout << "레벨 UP!!!! "<< player.level << "\n";
    player.increase_player();
    std::cout << "플레이어의 능력치가 올라갔습니다." << "\n";
    std::cout << "체력 : "<< player.health << "     공격력 : "<< player.attackPower  << "\n";

    //적의 능력치 올리기
    enemy.increaseEnemySkill();

    while(1) {
        //아이템 선택 해서 플레이어 능력치 변경
        std::cout << "레벨업 보상 - 아이템을 선택하세요. " << "\n";
        std::cout << "1 : 생명력 아이템이 40~50% 확률로 성능이 증가합니다."<< "\n";
        std::cout << "2 : 공격력 아이템이 50~60% 확률로 성능이 증가합니다." <<"\n";
        std::cin >> choose;
        if (choose != 1 && choose != 2) std::cout << "다시 선택해주세요."<< "\n";
        else    break;
    }
    

    //인벤토리 안 increase 함수 사용, 
    if (choose == 1) {
        item.increaseHealthItem(player.health*0.1);
        std::cout << "체력이 아이템 성능 : " << item.health_item <<"\n";
        player.health += item.health_item;
        std::cout << "플레이어의 체력 : " << player.health  <<"\n";

    } else if (choose == 2) {
        item.increaseAttackPowerItem(player.attackPower*0.07);
        std::cout << "체력이 아이템 성능 : " << item.attackPower_item <<"\n";
        player.attackPower += item.attackPower_item;
        std::cout << "플레이어의 공격력 : " << player.attackPower  <<"\n";
    }
}


