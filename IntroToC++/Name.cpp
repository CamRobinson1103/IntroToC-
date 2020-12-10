#include <iostream>

char space[10] = { 'o','1','2','3','4','5','6','7','8','9' };

int checkWin();
void grid();

int main()
{
    int player = 1, i, choice;

    char mark;
    do
    {
        grid();
        player = (player % 2) ? 1 : 2;

        std::cout << "Player " << player << ", enter a number:  ";
        std::cin >> choice;

        mark = (player == 1) ? 'x' : 'o';

        if (choice == 1 && space[1] == '1')
        {
            space[1] = mark;
        }

        else if (choice == 2 && space[2] == '2')
        {
            space[2] = mark;
        }

        else if (choice == 3 && space[3] == '3')
        {
            space[3] = mark;
        }

        else if (choice == 4 && space[4] == '4')
        {
            space[4] = mark;
        }

        else if (choice == 5 && space[5] == '5')
        {
            space[5] = mark;
        }

        else if (choice == 6 && space[6] == '6')
        {
            space[6] = mark;
        }

        else if (choice == 7 && space[7] == '7')
        {
            space[7] = mark;
        }

        else if (choice == 8 && space[8] == '8')
        {
            space[8] = mark;
        }

        else if (choice == 9 && space[9] == '9')
        {
            space[9] = mark;
        }

        else
        {
            std::cout << "Movement Unavailable ";
        }
        i = checkWin();

        player++;
    } while (i == -1);
    grid();
    if (i == 1)

        std::cout << "==>\aPlayer " << --player << " win ";
    else
        std::cout << "==>\aTie";

    std::cin.ignore();
    std::cin.get();
    return 0;
}

int checkWin()
{
    if (space[1] == space[2] && space[2] == space[3])
    {
        return 1;
    }
    else if (space[4] == space[5] && space[5] == space[6])
    {
        return 1;
    }
    else if (space[7] == space[8] && space[8] == space[9])
    {
        return 1;
    }
    else if (space[1] == space[4] && space[4] == space[7])
    {
        return 1;
    }
    else if (space[2] == space[5] && space[5] == space[8])
    {
        return 1;
    }
    else if (space[3] == space[6] && space[6] == space[9])
    {
        return 1;
    }
    else if (space[1] == space[5] && space[5] == space[9])
    {
        return 1;
    }
    else if (space[3] == space[5] && space[5] == space[7])
    {
        return 1;
    }

    else if (space[1] != '1' && space[2] != '2' && space[3] != '3'
        && space[4] != '4' && space[5] != '5' && space[6] != '6'
        && space[7] != '7' && space[8] != '8' && space[9] != '9')
    {
        return 0;
    }



    else
    {
        return -1;
    }

}

void grid()
{
    system("cls");

    std::cout << "Player 1 = x    Player 2 = o   Press Enter after x or o" << std::endl;


    std::cout << "  " << space[1] << "  ,  " << space[2] << "  ,  " << space[3] << std::endl;
    std::cout << "  " << space[4] << "  ,  " << space[5] << "  ,  " << space[6] << std::endl;
    std::cout << "  " << space[7] << "  ,  " << space[8] << "  ,  " << space[9] << std::endl;

}