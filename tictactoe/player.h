#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:
		//Always have ctor and dtor. You never know.
		Player();
		~Player();
		
		//The previous player piece system was a bit of a fail.
		//Now opting for a public player piece, which gets assigned
		//The non-neutral value from main and the users input.
		char playerPiece;
		
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
