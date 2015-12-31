#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
	public:
		//Always have ctor and dtor. You never know.
		Player();
		~Player();
		
		//The following boolean decides which player goes.
		//For example, player one moves, player two move.
		//A value of true means it is player ones turn.
		bool isPlayerTurn = true; 
		
		//Used to determine who the game is played against.
		//If this is true, 2 humans players are playing.
		//Two humans are assumed becuse you need a minimum
		//of one, and second player comes into play via this
		//variable.
		bool isTwoHumanPlayer = false;
		
		//The previous player piece system was a bit of a fail.
		//Now opting for a public player piece, which gets assigned
		//The non-neutral value from main and the users input.
		char playerPiece = '-';
		
		//Get user input, no sanitation/validation.
		//This function does call a sanitation function,
		//but there is still no 100% guaruntee that the result
		//is 100% safe to use. But it should help.
		//
		//Mischievous users anyways... Argh!
		int get_input();
		
		//And this is the dishwasher function full of soap and
		//sanitization chemicals... Returns true if good input,
		//false otherwise. 
		bool sanitize_input(int input);
};

#endif
