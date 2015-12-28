#include "player.h"
#include "game.h"
#include <iostream>
#include <limits>

Player::Player()
{

}

Player::~Player()
{
	//dtor
}

int Player::get_input()
{
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
			std::cout << "\nCan you not screw up the input?\n";
			std::cout << "At least you've confirmed the input validator works.\n";
			std::cout << "So thats good. Now exiting program on grounds of user error.\n";
			return -1; //User error.
		}
	}
}

bool Player::sanitize_input(int input)
{
	Game game; //For checking if input is within bounds of board.
	
	if (input == 9) {
		return true; //9 is valid input for an exit.
	}
	
	if (std::cin.fail() || input < 0 || input > game.get_max_rows()) {
		return false; //Failed input
	} 
	return true; //No failure detected, so input is valid.
}

		
		
		
		
		
		
		
