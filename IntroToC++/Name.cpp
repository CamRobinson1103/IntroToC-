#include <iostream>



int main() 
{
	std::string help;

	int max = 100;
	int min = 0;
	int tries = 0;

	std::cout << "Think of a number between 1 and 100." << std::endl;

	do 
	{
		int guess = 20 % (max - (min + 1)) + (min + 1);
		std::cout << "I guess " << guess << std::endl;
		std::cout << "Am I guess high, low, or correct?: ";	
		std::cin >> help;

		if (help == "high") 
		{ 
			std::cout << "I was too high." << std::endl;
			max = guess;
			tries++;
		}

		if (help == "low")
		{ 
			std::cout << "I was too low." << std::endl;
			min = guess;
			tries++;
		}
		if (tries == 5)
		{ 
			std::cout << "Hey.... did you change your number?" << std::endl;
		}
	}


	while (help != "correct");
	std::cout << "The computer's guess was correct after " << tries << " tries!" << std::endl;

	return(0);

	//int guess = 2 % (max - (min + 1)) + (min + 1);
} 