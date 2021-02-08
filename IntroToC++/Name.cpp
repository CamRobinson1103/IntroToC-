#include <iostream>
#include <fstream>
#include "Character.h"
#include "Enemy.h"
#include <string>

int main()
{

    
    //Loads player
    Character player = Character();
    player.health = 50;
    player.swordDamage = 10;
    player.gunDamage = 20;
    player.bombDamage = 50;

    //Loads enemy
    Enemy enemy = Enemy();
    enemy.health = 50;
    enemy.swordDamage = 10;
    enemy.gunDamage = 20;
    enemy.bombDamage = 50;

    //Sets up enemy attack round
    int enemyAttack;
    //Sets up Payer attack round
    int playerAttack;
    //Sets up turns
    int Round = 1;

    //Create an instance of a file stream
    std::fstream file;

    //Search for the file with the name given in the first
    //argument. If no file with this name exists, one with
    //the name is created. Then "std::ios::out" is used to
    //say that we want to output data to the binary file.
    file.open("save.txt", std::ios::out|std::ios::binary||std::ios::app);
    file.write((char*)&player, sizeof(Character));

    //Check is the file isn't opened. If so, return from main.
    if (!file.is_open())
    {
        return 1;
    }

    file.seekg(sizeof(Character) * 2, std::ios::beg);

    //Writes player's stats to the text file.
    file << player.health << std::endl;
    file << player.swordDamage;
    file << player.gunDamage;
    file << player.bombDamage;

    //Writes enemy's stats to the text file.
    file << enemy.health << std::endl;
    file << enemy.swordDamage;
    file << enemy.gunDamage;
    file << enemy.bombDamage;

    //Close the file when we're done.
    file.close();

    


    //Loads from the binary file
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

    //Closes file once we're done
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
        //Starts Round 1
        if (Round == 1)
        {
            //Selects a number for a weapon
            std::cout << "\n Pick a weapon (1), (2), or (3):"<< std::endl;
            std::cout << "(1) Sword" << std::endl;
            std::cout << "(2) Gun" << std::endl;
            std::cout << "(3) Bomb" << std::endl;
            std::cin >> playerAttack;

            switch (playerAttack)
            {
                //Shows results for the corresponding number a player chooses
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
           //Enemy's turn
        switch (enemy.health)
        {
            ////Shows results for the corresponding choice of the enemy
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
    //Results from the battle
    while (player.health > 0 && enemy.health > 0);
    {
        //If player wins, this is displayed
        if (enemy.health <= 0)
            std::cout << "Player win!!" << std::endl;
        //If player wins, this is displayed
        if(player.health <= 0)
            std::cout << "Player lose!!" << std::endl;
        return 0;
    }
    return 0;

}




