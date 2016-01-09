#ifndef GAME_H
#define GAME_H

#include <array>

class Game
{
	public:
		//Standard Con/Destructors
		Game(); //Initialize the board.
		~Game(); //Not sure if I need this, but it's here in case
	
		//Are we playing the game?
		bool isRunning = true;
		
		//The easiest way I could implement stalemate 
		//detection with my limited knowledge.
		//Is the board completely full, thereby causing a stalemate?
		bool isStalemate = false;
		
		//Board specific variables. 
		static const int MAX_ROWS = 3; //Bounds for our board array
		static const int MAX_COLS = 3;
		
		//Return the bounds of our board.
		//Useful for, say, only allowing the player
		//to make a move within board boundaries
		//when player data is in a different class.
		int get_max_rows() { return MAX_ROWS; }
		int get_max_cols() { return MAX_COLS; }
	
		//Return our private piece variables for public use.
		char get_piece_x() { return pieceX; }
		char get_piece_o() { return pieceO; } 

		//Print the board in its current state
		void print_board();
		
		//Print our help board. This board does not change.
		void print_help_board();
	
		//Check for an overlap, IE placing an X on top of an O.
		//Returns false if there is an overlap. The space is invalid.
		//Does NOT check for input sanity or bounds!!! This is done
		//in some other class, likely going to be the player class.
		bool is_valid_space(int xPosition, int yPosition);
	
		//Check for every possible win using piece as the winning piece.
		//For example, check if O is the winning piece.
		//Returns true on a win, false otherwise.
		bool is_victory(char piece);
	
		//Allow a different function/class/file/whatever to acces the board.
		//This is done to allow placement of pieces to the board without
		//the risk of accidently trashing it. is_valid_space() should always
		//be called first, and it likely will be called in this function.
		//Returns false if it cannot place the piece.
		bool add_new_piece(int xPosition, int yPosition, char piece);
	
		//Removes all pieces from the board, re-sets the score (if I chose to 
		//implement scoring) to zero. This is used in preperation for a new game.
		void reset();
		
		//Simple random number generator, with bounds.
		int get_random_num(int bound = 0);
		
		//Place a piece on the board based on user input.
		int make_move(int input, char piece);
	
	private:
		//Three win calcualtion functions to make my job easier.
		//Check for vertical, horizontal, or diagonal wins independently.
		//Used by is_victory() to simplify win checking even more.
		bool is_win_vertical(char piece);
		bool is_win_horizontal(char piece);
		bool is_win_diagonal(char piece);
	
		//char board[MAX_ROWS][MAX_COLS]; //The board itself
		std::array<std::array<char, MAX_ROWS>, MAX_COLS> board; //The board itself
		
		//These make setting up the board/player(s)/etc MUCH easier.
		char pieceX = 'X'; //The player class assigns these variables to a local var.
		char pieceO = 'O'; //for example, something like: player.set_piece(game.pieceX);
		char pieceNeutral = '-'; //The blank or empty piece.
		
		//Settings for making a help board. Shows the player which number corresponds
		//to the tile he/she wants. Below are variables for that.
		int helpBoard[MAX_ROWS][MAX_COLS];
};

#endif


