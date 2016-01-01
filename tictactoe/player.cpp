#include "player.h"
#include "game.h"
#include <iostream>
#include <limits>
#include <string>

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
	static int failCount = 3;//Retry but not indefinitely.
	int input; //Players input.
	
	std::cout << "\nEnter your choice:\n";
	std::cin >> input;
	
	if (sanitize_input(input)) {
		if (input == 9) {
			return -1; 
		} else {
			return input;
		}
	} else {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		failCount -= 1;
		if (failCount > 0) {
			std::cout << "\nBad input... try again\n";
			get_input();
		} else {
			if (failCount <= 0) {
				std::cout << "Three strikes and your out!\n";
				std::cout << "Now exitng program. Bye!\n";
				return -1;
			}
		}
	}
}

bool Player::sanitize_input(int input)
{	
	if (input == 9) {
		return true; //9 is valid input for an exit.
	}
	
	if (std::cin.fail() || input < 0 || input >= 9) {
		return false; //Failed input
	} 
	return true; //No failure detected, so input is valid.
}

		
		
		
		
		
