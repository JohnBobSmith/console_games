#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:
		//Always have ctor and dtor. You never know.
		Player();
		~Player();
		
		//Make a move as the player.
		int make_move(int xPosition, int yPosition, char piece); 
		
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
		
		//Assign an X or an O to playerPiece. Avoid completely
		//hardcoding which piece the player is.
		int set_player_piece(char piece) { playerPiece = piece; }
		char get_player_piece() { return playerPiece; }
				
		private:
			char playerPiece = '-'; //The piece unique to the player
			//this ^ starts with a neutral piece.
};

#endif
