#include <iostream>

int main()
{
    int playerHealth = 50;
    int enemyHealth = 50;
    int enemyWeapon;
    int playerWeapon;
    int Round = 0;
    int swordDamage = 10;
    int gunDamage = 20;
    int bombDamage = 50;

    do
    {
        if (Round == 0)
        {
            std::cout << "\n Pick a weapon (1), (2), or (3):"<< std::endl;
            std::cout << "(1) Sword" << std::endl;
            std::cout << "(2) Gun" << std::endl;
            std::cout << "(3) Bomb" << std::endl;
            std::cin >> playerWeapon;

            switch (playerWeapon)
            {

            case 1: 
                std::cout << "\nPlayer chose a sword" << std::endl;
                enemyHealth = enemyHealth - swordDamage;
                std::cout << "Player inflicted " << swordDamage << " points on their enemy." << std::endl;
                std::cout << "Player health is " << playerHealth << std::endl;
                std::cout << "The enemy's health is " << enemyHealth << std::endl;
                break;

            case 2:
                std::cout << "\nYou chose a gun" << std::endl;
                enemyHealth = enemyHealth - gunDamage;
                std::cout << "Player inflicted " << gunDamage << " points on their enemy." << std::endl;
                std::cout << "Player health is " << playerHealth << std::endl;
                std::cout << "The enemy's health is " << enemyHealth << std::endl;
                break;

            case 3:
                std::cout << "\nYou chose a bomb" << std::endl;
                enemyHealth = enemyHealth - bombDamage;
                std::cout << "Player inflicted " << bombDamage << " points on their enemy." << std::endl;
                std::cout << "Player health is " << playerHealth << std::endl;
                std::cout << "The computer's health is " << enemyHealth << std::endl;
                break;
            }
        }
        Round == 1;


        switch (enemyHealth)
        {
        case 1:
            std::cout << "The enemy inflicted " << gunDamage << " points on player." << std::endl;
            playerHealth = playerHealth - gunDamage;
            std::cout << "Player health is " << playerHealth << std::endl;
            std::cout << "Enemy's health is " << enemyHealth << std::endl;
            break;

        case 2:
            std::cout << "The enemy inflicted " << swordDamage << " points on player." << std::endl;
            playerHealth = playerHealth - swordDamage;
            std::cout << "Player health is " << playerHealth << std::endl;
            std::cout << "Enemy's health is " << enemyHealth << std::endl;
            break;

        case 3:
            std::cout << "The enemy inflicted " << bombDamage << " points on player." << std::endl;
            playerHealth = playerHealth - bombDamage;
            std::cout << "Player health is " << playerHealth << std::endl;
            std::cout << "Enemy's health is " << enemyHealth << std::endl;
            break;
        }


    }

    while (playerHealth > 0 && enemyHealth > 0);
    {
        if (enemyHealth <= 0)
            std::cout << "Player win!!" << std::endl;
        if(playerHealth <= 0)
            std::cout << "Player lose!!" << std::endl;
        return 0;
    }



}

