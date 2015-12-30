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
		
		//Fully parse the entire input, including errors, user
		//and/or program exits, from a single function with other
		//mini-function as needed. This way, we can avoid repeating
		//literally 30+ lines of code. if userinput == 0 here, do this.
		//Same check but elsewhere, do this instead... etc. This also
		//allows for a message to be displayed. This is useful for 
		//those repeat message, mostly in setup. "player one's/two's piece is..".
		int parse_input(int input, std::string message);
};

#endif
