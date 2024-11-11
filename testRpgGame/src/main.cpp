#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>
#include "../include/battle.h"
#include "../include/character.h"
#include "../include/enemy.h"
#include "../include/player.h"
#include "../include/inventory.h"
#include "../include/gameState.h"


std::vector<Enemy> makeEnemies();
bool processBattleRound(Enemy& enemy, int num , Player& player, Inventory& item) ;
void processLevelUp (Player& player, Enemy& enemy, Inventory& item);
bool isFileEmpty(const std::string& filename) ;



int main() {
    //세이브 기능은 매 case 시작할때만 5 레벨씩 가능하게 해주기
    //세이브 파일 이름
    std::string filename = "gameState.txt";
    
    int level = 1;
    bool result;

    //플레이어 생성
    Player player("Hero", 100, 20, level);
    player.displayStatus();

    //아이템 생성
    Inventory item(player.health*0.1, player.attackPower*0.07); 


    //세이브 파일에 데이터가 있으면 위 초기화 변수에 데이터 넣어주기
    if (!isFileEmpty(filename)) {
        GameState gameState(player, item);
        gameState.load(filename);
    }


    //적의 vector 생성
    std::vector<Enemy> enemies = makeEnemies();

    for (size_t i = 1; i <= 50 ; i++) {
        Enemy& enemy = enemies[(i-1) / 5];
        
        switch ((i-1) / 5)
        {
            case 0: //1~5
                //std::cout << "case 0 " << "\n";
                result = processBattleRound(enemy, 1 , player, item) ;    
                break;

            case 1: //6~10
                //enemy = enemies[1];
                if(player.level < 8)   {
                    result = processBattleRound(enemies[1], 2 , player, item);
                }
                else {
                    result = processBattleRound(enemies[1], 4 , player, item);
                };
                break;

            case 2: //11~15
                //enemy = enemies[2];
                result = processBattleRound(enemies[2], 4 , player, item) ;                
                break;

            case 3: //16~20
                //enemy = enemies[3];
                result = processBattleRound(enemies[3], 5 , player, item) ;
                break;

            case 4: //21~15
                //enemy = enemies[4];
                if(player.level < 24)  result = processBattleRound(enemies[4], 5 , player, item) ;
                else    result = processBattleRound(enemies[4], 6 , player, item) ;
                break;

            case 5: //26~30
                //enemy = enemies[5];
                result = processBattleRound(enemies[5], 7 , player, item) ;
                break;

            case 6: //31~35
                //enemy = enemies[6];
                result = processBattleRound(enemies[6], 7 , player, item) ;
                break;

            case 7: //36~40
                //enemy = enemies[7];
                result = processBattleRound(enemies[7], 8 , player, item) ;
                break;

            case 8: //41~45
                //enemy = enemies[8];
                result = processBattleRound(enemies[8], 9 , player, item) ;
                break;

            case 9: //46~50
                //enemy = enemies[9];
                if (player.level == 50) result = processBattleRound(enemies[10], 11 , player, item) ;
                else    result = processBattleRound(enemies[9], 10 , player, item) ;
                break;
            
            default:
                std::cout << "적이 존재하지 않습니다." << "\n";
                break;
        }
        if (result) { 
            processLevelUp(player, enemy, item);
        }
        if (!player.isAlive()) {
            std::cout << "============================================" << "\n" << "\n";

            std::cout << "사망 - 최종 레벨: "<< player.level << "\n";
            //세이브 파일 초기화하기
            std::ofstream file(filename, std::ios::trunc);
            if(file.is_open()) {
                file.close();
                std::cout << "File has been emptied successfully.\n";
            } else {
                std::cerr << "Failed to open file.\n";
            }

            break;
        }     
        if(i%5 == 0) {
            int choose;
            std::cout << "세이브하시겠습니까?" << "\n";
            std::cout << "1 : 세이브" << "\n";
            std::cin >> choose;
            if (choose == 1) {
                GameState gameState(player, item);
                gameState.save(filename);
                std::cout << "게임이 저장되었습니다." << "\n";
            } else {
                std::cout << "게임을 저장 없이 진행합니다." << "\n";
            }
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
    // 해결해야 되는 부분
    // 배틀과 생존에 적과 플레이터 모두 자체를 참조하게 함 -> 다음 단계에서 부족한 체력 그대로 배틀을 하게되는 문제 발생
    //플레이어 죽었는지 판단하는 변수
    bool alive = true;
    //죽은 적의 수
    int deadNum = 0;
    //아이템 고르기
    int choose;
    //플레이어의 체력 , 공격력 보관 변수
    double storePlayer[2] = {player.health, player.attackPower};

    //적의 정보 보관
    double storeEnemy[2] = {enemy.health, enemy.attackPower};

    //적의 수만큼 반복
    for (size_t i =1 ; i < num +1 ; i++){
        std::cout << "\n"<< "\n"<< "\n"<< " 레벨 " << player.level << " - 배틀 시작" << "\n";
        std::cout << " 레벨 " << player.level << "\n";
        std::cout << " 적 정보 :  " << enemy.health << ", "<< enemy.attackPower  << "\n";
        //먼저 배틀
        bool result = battle(player, enemy);

        deadNum++;

        //적 한마리 죽을 때마다 아이템 선택해 보충
        //적이 죽어고 배틀할 적이 남으면 보충 아이템 선택 -> 랜덤
        if (result &&  i < num) {    
            std::cout << "적을 처지했습니다 " << "\n";
            std::cout << "남은 적의 수 : " << num - i << "\n";
            enemy.health = storeEnemy[0];
            enemy.attackPower = storeEnemy[1];
            
            //난수 생성기 초기화
            std::mt19937 generator(static_cast<unsigned int>(std::time(0)));    //현재 시간 시드 설정 => int로 변환
            //정수 범위 난수 생성
            std::uniform_int_distribution<int> distribution(0,1); 

            int randomHealth = distribution(generator);       //생명 증가 비율

            //아이템 선택
            if (randomHealth == 1) {
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
            }
            
        } else if (result && num == deadNum ) {
            player.health = storePlayer[0];
            player.attackPower = storePlayer[1];
            enemy.health = storeEnemy[0];
            enemy.attackPower = storeEnemy[1];
            return true;
        }
        else {
            //플레이어 죽음
            return false; //   배틀함수 boolean으로 바꾸기고 false  반환 (이럼 반복문도 알아서 끝나겠지 모)
        }
    }

}

void processLevelUp (Player& player,Enemy& enemy, Inventory& item) {
    int choose;

    //플레이어 레벨 업
    player.level ++;
    std::cout << "==================레벨 UP!!!! "<< player.level<<"================" << "\n";
    player.increase_player();
    std::cout << "플레이어의 능력치가 올라갔습니다." << "\n";
    //적의 능력치 올리기
    enemy.increaseEnemySkill();
    std::cout << "체력 : "<< player.health << "     공격력 : "<< player.attackPower  << "\n";

    std::cout << "============================================================" << "\n";

    while(1) {
        //아이템 선택 해서 플레이어 능력치 변경
        std::cout << "레벨업 보상 - 아이템을 선택하세요. " << "\n";
        std::cout << "1 : 생명력 아이템이 20~30% 확률로 성능이 증가합니다."<< "\n";
        std::cout << "2 : 공격력 아이템이 30~40% 확률로 성능이 증가합니다." <<"\n";
        std::cin >> choose;
        //여기서 무한 반복 일어남 => 아닌가?
        if (choose != 1 && choose != 2) std::cout << "다시 선택해주세요."<< "\n";
        else    break;
    }

    //인벤토리 안 increase 함수 사용, 
    if (choose == 1) {
        item.increaseHealthItem(player.health*0.1);
        //std::cout << "체력 아이템 성능 : " << item.health_item <<"\n";
        player.health += item.health_item;
        //std::cout << "플레이어의 체력 : " << player.health  <<"\n";

    } else if (choose == 2) {
        item.increaseAttackPowerItem(player.attackPower*0.07);
        //std::cout << "공격력 아이템 성능 : " << item.attackPower_item <<"\n";
        player.attackPower += item.attackPower_item;
        std::cout << "플레이어의 공격력 : " << player.attackPower  <<"\n";
    }
}


bool isFileEmpty(const std::string& filename) {
    try {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);  // 파일을 끝 위치에서 열기
        if (!file.is_open()) {
            std::cerr << "Failed to open file." << std::endl;
            return false;
        }

        // 파일의 크기를 확인
        std::streamsize fileSize = file.tellg();  // 파일 크기
        file.close();
        return fileSize == 0;  // 파일 크기가 0이면 빈 파일
    } catch (const std::ios_base::failure& e) {
        std::cerr << "파일 예외 발생: " << e.what() << std::endl;
        return true;  // 파일이 비어 있다고 가정하고 처리
    }
}