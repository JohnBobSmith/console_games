#include "player.h"
#include "game.h"
#include <iostream>
#include <limits>

Player::Player()
{
	//ctor
}

Player::~Player()
{
	//dtor
}

int Player::get_input()
{
	//For convserion of a bug into a feature...
	static bool isTheUserToast = false; //Static ensurese my bug-to-feature will work!
	static int failCount = 3;//Retry but not indefinitely.
	int input; //Players input.
	
	std::cout << "\nEnter your choice:\n";
	std::cin >> input;
	
	if (sanitize_input(input)) {
		return input;
		//parse_input();
	} else {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		failCount -= 1;
		if (failCount > 0) {
			std::cout << "\nBad input... try again\n";
			get_input();
		} else {
			if (!isTheUserToast) {
				std::cout << "You have one more chance. Don't blow it...";
				isTheUserToast = true;
				return -1; //User error.
			} else {
				std::cout << "You blew it. BYE!";
				return -1; //I TOTALLY JUST TURNED A BUG INTO A FEATURE!!!
			}
		}
	}
}

bool Player::sanitize_input(int input)
{
	Game game; //For checking if input is within bounds of board.
	
	if (input == 9) {
		return true; //9 is valid input for an exit.
	}
	
	if (std::cin.fail() || input < 0 || input >= game.get_max_rows()) {
		return false; //Failed input
	} 
	return true; //No failure detected, so input is valid.
}

		
		
		
		
		
		
		
