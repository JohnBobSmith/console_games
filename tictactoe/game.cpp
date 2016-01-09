#include "game.h"
#include "player.h"
#include <iostream>
#include <cstdlib>

Game::Game()
{
	//Constructor used for automatic initial board creation.
	for (int row = 0; row < MAX_ROWS; row++) { 
		for (int col = 0; col < MAX_COLS; col++) { 
			board[row][col] = pieceNeutral;
		}
	}
	
	//Also create our help board.
	helpBoard[0][0] = 0;
	helpBoard[0][1] = 1;
	helpBoard[0][2] = 2;
	helpBoard[1][0] = 3;
	helpBoard[1][1] = 4;
	helpBoard[1][2] = 5;
	helpBoard[2][0] = 6;
	helpBoard[2][1] = 7;
	helpBoard[2][2] = 8;
}

Game::~Game()
{
	//dtor in case I need it
}

void Game::print_board()
{
	for (int row = 0; row < MAX_ROWS; row++) { 
		std::cout << "\n"; //Proper spacing
		for (int col = 0; col < MAX_COLS; col++) { 
			std::cout << board[row][col];
		}
	}
	std::cout << "\n\n"; //To avoid odd formatting. 
									//Call it vertical padding I guess.
}

void Game::print_help_board()
{
	for (int row = 0; row < MAX_ROWS; row++) { 
		std::cout << "\n"; //Proper spacing
		for (int col = 0; col < MAX_COLS; col++) { 
			std::cout << helpBoard[row][col];
		}
	}
	std::cout << "\n\n"; //To avoid odd formatting. 
}

bool Game::is_valid_space(int xPosition, int yPosition)
{
	if (board[xPosition][yPosition] != pieceNeutral) {
		return false; //Piece is not neutral therefore occupied.
	}
	return true; //All clear. Neutral piece is a green light.
}

bool Game::add_new_piece(int xPosition, int yPosition, char piece)
{
	//Finally proper stalemate detection if this goes well.
	//Keep track of our open tiles
	static int openTiles = 9;
	
	if (is_valid_space(xPosition, yPosition)) {
		board[xPosition][yPosition] = piece; //All clear, place piece
		//We placed a piece, therefore we have 1 less spot open.
		openTiles -= 1;
		if (openTiles <= 0) { //If we have no spots open...
			isStalemate = true; //...the board is full.
		}
	} else {
		//Piece failed to place, therefore an overlap.
		std::cout << "\n\n...OVERLAP DETECTED...\n\n";
		return false;
	}
	return true; //Function did its job.
}

void Game::reset()
{
	//Add neutral piece's to the board, overwriting anything thats there already.
	for (int row = 0; row < MAX_ROWS; row++) {
		for (int col = 0; col < MAX_COLS; col++) {
			board[row][col] = pieceNeutral;
		}
	}
}

int Game::get_random_num(int bound)
{
	int randomNum = rand() % bound;
	return randomNum;
}

int Game::make_move(int input, char piece)
{
	if (input == -1) {
		return -1; //Generic exit
	}

	if (input == 0) {
		if (!add_new_piece(0, 0, piece)) {
			return 1;
		}
	}

	if (input == 1) {
		if (!add_new_piece(0, 1, piece)) {
			return 1;
		}
	}

	if (input == 2) {
		if (!add_new_piece(0, 2, piece)) {
			return 1;
		}
	}

	if (input == 3) {
		if (!add_new_piece(1, 0, piece)){
			return 1;
		}
	}
	
	if (input == 4) {
		if (!add_new_piece(1, 1, piece)) {
			return 1;
		}
	}

	if (input == 5) {
		if (!add_new_piece(1, 2, piece)) {
			return 1;
		}
	}

	if (input == 6) {
		if (!add_new_piece(2, 0, piece)) {
			return 1;
		}
	}

	if (input == 7) {
		if (!add_new_piece(2, 1, piece)) {
			return 1;
		}
	}

	if (input == 8) {
		if (!add_new_piece(2, 2, piece)) {
			return 1;
		}
	}
	
	if (input == 9) {
		return -1; //Generic exit
	}
}

bool Game::is_victory(char piece)
{
	if (is_win_horizontal(piece) || is_win_vertical(piece) || is_win_diagonal(piece)) {
		return true; //"piece" won in some way
	}
	return false;
}

//Our three private win-checking functions. I hope thats self explanatory.
//Return true on success (a win), false otherwise.
bool Game::is_win_vertical(char piece)
{
	if (board[0][0] == piece && board[0][1] == piece && board[0][2] == piece) {
		return true;
	}
	if (board[1][0] == piece && board[1][1] == piece && board[1][2] == piece) {
		return true;
	}
	if (board[2][0] == piece && board[2][1] == piece && board[2][2] == piece) {
		return true;
	}
	return false; //No win if none of these return true.
}

bool Game::is_win_horizontal(char piece)
{
	if (board[0][0] == piece && board[1][0] == piece && board[2][0] == piece) {
		return true;
	}
	if (board[0][1] == piece && board[1][1] == piece && board[2][1] == piece) {
		return true;
	}
	if (board[0][2] == piece && board[1][2] == piece && board[2][2] == piece) {
		return true;
	}
	return false; //No win if none of these return true.	
}

bool Game::is_win_diagonal(char piece)
{
	if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece) {
		return true;
	}
	if (board[2][0] == piece && board[1][1] == piece && board[0][2] == piece) { 
		return true;
	}
	return false; //No win if none of these return true.
}







