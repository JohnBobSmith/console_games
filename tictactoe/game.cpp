#include "game.h"
#include <iostream>

Game::Game()
{
	//Constructor used for automatic initial board creation.
	for (int row = 0; row < MAX_ROWS; row++) { 
		for (int col = 0; col < MAX_COLS; col++) { 
			board[row][col] = pieceNeutral;
		}
	}
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

bool Game::is_valid_space(int xPosition, int yPosition, char piece)
{
	if (board[xPosition][yPosition] == piece) {
		return false; //Invalid location
	} else {
		return true;
	}
}

bool Game::is_victory(char piece)
{
	if (is_win_horizontal(piece) || is_win_vertical(piece) || is_win_diagonal(piece)) {
		return true; //"piece" won in some way
	} else {
		return false;
	}
}

bool Game::place_new_piece(int xPosition, int yPosition, char piece)
{
	if (is_valid_space(xPosition, yPosition, piece)) {
		board[xPosition][yPosition] = piece; //All clear, place piece
	} else {
		std::cout << "Error: Overlap on " << xPosition << " " << yPosition << ". No piece placed.";
		return false; //Cannot place the piece
	}
	return true; //To avoid false returns (no pun intended)
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







