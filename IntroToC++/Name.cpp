#include <iostream>
#include <fstream>
#include "Character.h"
#include "Enemy.h"
#include <string>

int main()
{
    using namespace std;
    struct Player {
        int item_no;
        string name;
    };
    

    Character player = Character();
    player.health = 50;
    player.swordDamage = 10;
    player.gunDamage = 20;
    player.bombDamage = 50;

    Enemy enemy = Enemy();
    enemy.health = 50;
    enemy.swordDamage = 10;
    enemy.gunDamage = 20;
    enemy.bombDamage = 50;


    int enemyAttack;
    int playerAttack;
    int Round = 1;

    std::fstream file;
    file.open("save.txt", std::ios::out|std::ios::binary||std::ios::app);
    file.write((char*)&player, sizeof(Character));
    if (!file.is_open())
    {
        return 1;
    }

    file.seekg(sizeof(Character) * 2, std::ios::beg);

    file << player.health << std::endl;
    file << player.swordDamage;
    file << player.gunDamage;
    file << player.bombDamage;

    file << enemy.health << std::endl;
    file << enemy.swordDamage;
    file << enemy.gunDamage;
    file << enemy.bombDamage;
    file.close();

    



    file.open("save.txt", std::ios::in | std::ios::binary||std::ios::app);
    file.write((char*)&player, sizeof(Character));
    file >> player.health;
    file >> player.swordDamage;
    file << player.gunDamage;
    file << player.bombDamage;

    file >> enemy.health;
    file >> enemy.swordDamage;
    file << enemy.gunDamage;
    file << enemy.bombDamage;
    file.close();


    


    std::cout << player.health << std::endl;
    std::cout << player.swordDamage << std::endl;
    std::cout << player.gunDamage << std::endl;
    std::cout << player.bombDamage << std::endl;

    std::cout << enemy.health << std::endl;
    std::cout << enemy.swordDamage << std::endl;
    std::cout << enemy.gunDamage << std::endl;
    std::cout << enemy.bombDamage << std::endl;

    do
    {
        if (Round == 1)
        {
            std::cout << "\n Pick a weapon (1), (2), or (3):"<< std::endl;
            std::cout << "(1) Sword" << std::endl;
            std::cout << "(2) Gun" << std::endl;
            std::cout << "(3) Bomb" << std::endl;
            std::cin >> playerAttack;

            switch (playerAttack)
            {

            case 1: 
                std::cout << "\nPlayer chose a sword" << std::endl;
                enemy.health = enemy.health - player.swordDamage;
                std::cout << "Player inflicted " << player.swordDamage << " points on their enemy." << std::endl;
                std::cout << "Player health is " << player.health << std::endl;
                std::cout << "The enemy's health is " << enemy.health << std::endl;
                break;

            case 2:
                std::cout << "\nYou chose a gun" << std::endl;
                enemy.health = enemy.health - player.gunDamage;
                std::cout << "Player inflicted " << player.gunDamage << " points on their enemy." << std::endl;
                std::cout << "Player health is " << player.health << std::endl;
                std::cout << "The enemy's health is " << enemy.health << std::endl;
                break;

            case 3:
                std::cout << "\nYou chose a bomb" << std::endl;
                enemy.health = enemy.health - player.bombDamage;
                std::cout << "Player inflicted " << player.bombDamage << " points on their enemy." << std::endl;
                std::cout << "Player health is " << player.health << std::endl;
                std::cout << "The computer's health is " << enemy.health << std::endl;
                break;
            }
        }

       if (Round == 2)
        switch (enemy.health)
        {
        case 1:
            std::cout << "The enemy inflicted " << enemy.gunDamage << " points on player." << std::endl;
            player.health = player.health - enemy.gunDamage;
            std::cout << "Player health is " << player.health << std::endl;
            std::cout << "Enemy's health is " << enemy.health << std::endl;
            break;

        case 2:
            std::cout << "The enemy inflicted " << enemy.swordDamage << " points on player." << std::endl;
            player.health = player.health - enemy.swordDamage;
            std::cout << "Player health is " << player.health << std::endl;
            std::cout << "Enemy's health is " << enemy.health << std::endl;
            break;

        case 3:
            std::cout << "The enemy inflicted " << enemy.bombDamage << " points on player." << std::endl;
            player.health = player.health - enemy.bombDamage;
            std::cout << "Player health is " << player.health << std::endl;
            std::cout << "Enemy's health is " << enemy.health << std::endl;
            break;
        }


    }

    while (player.health > 0 && enemy.health > 0);
    {
        if (enemy.health <= 0)
            std::cout << "Player win!!" << std::endl;
        if(player.health <= 0)
            std::cout << "Player lose!!" << std::endl;
        return 0;
    }



    return 0;

}

//#include<iostream>
//#include<fstream>
//using namespace std;
//struct Player {
//    int item_no;
//    string name;
//};
//int main() {
//    ofstream wf("save.txt", ios::out | ios::binary);
//    if (!wf) {
//        cout << "Cannot open file!" << endl;
//        return 1;
//    }
//    Player items[3];
//    items[0].item_no = 1;
//    items[0].name = "Potion";
//    items[1].item_no = 2;
//    items[1].name = "Sword";
//    items[2].item_no = 3;
//    items[2].name = "Shield";
//    for (int i = 0; i < 3; i++)
//        wf.write((char*)&items[i], sizeof(Player));
//    wf.close();
//
//    if (!wf.good()) {
//        cout << "Error occurred at writing time!" << endl;
//        return 1;
//    }
//
//    ifstream rf("save.txt", ios::out | ios::binary);
//    if (!rf) {
//        cout << "Cannot open file!" << endl;
//        return 1;
//    }
//    Player rstu[3];
//    for (int i = 0; i < 3; i++)
//        rf.read((char*)&rstu[i], sizeof(Player));
//    rf.close();
//    if (!rf.good()) {
//        cout << "Error occurred at reading time!" << endl;
//        return 1;
//    }
//    cout << "Player's Items:" << endl;
//    for (int i = 0; i < 3; i++) {
//        cout << "Item No: " << items[i].item_no << endl;
//        cout << "Name: " << items[i].name << endl;
//        cout << endl;
//    }
//    return 0;
//}


