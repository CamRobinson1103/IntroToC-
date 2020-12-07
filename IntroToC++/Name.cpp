#include <iostream>



int main() 
{
	int min = 0;
	int max = 100;
	int tries = 0;
	std::string help;

	std::cout << "Think of a number between 1 and 100." << std::endl;

	do 
	{
		int guess = 50 % (max - (min + 1)) + (min + 1);
		std::cout << "I guess " << guess << std::endl;
		std::cout << "Am I guessing too high, too low, or am I right? " << std::endl;
		std::cin >> help;

		if (help == "high") 
		{ 
			std::cout << "I was too high." << std::endl;
			max = guess;
			tries++;
		}

		else if (help == "low")
		{ 
			std::cout << "I was too low." << std::endl;
			min = guess;
			tries++;
		}
		else if (tries == 100)
		{ 
			std::cout << "Hey.... did you change your number?" << std::endl;
		}
	}


	while (help != "correct");
	std::cout << "The computer's guess was correct after " << tries << " tries!" << std::endl;

	return(0);

} 