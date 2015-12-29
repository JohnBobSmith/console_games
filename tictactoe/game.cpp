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

bool Game::is_valid_space(int xPosition, int yPosition)
{
	if (board[xPosition][yPosition] != pieceNeutral) {
		return false; //Piece is not neutral therefore occupied.
	}
	return true; //All clear. Neutral piece is a green light.
}

bool Game::is_board_full()
{
	//Static int because only this function shall use it,
	//and static so that I can call the function without
	//re-setting the value.
	static int blankTilesRemaining = 9;
	for (int row = 0; row < MAX_ROWS; row++) {
		for (int col = 0; col < MAX_COLS; col++) {
			if (board[row][col] != pieceNeutral) {
				blankTilesRemaining -= 1;
			}
		}
	}
	if (blankTilesRemaining == 0) {
		//Board is full.
		return true;	
	} else {
		return false; //The board is empty.
	}
	return false;
}

bool Game::add_new_piece(int xPosition, int yPosition, char piece)
{
	if (is_valid_space(xPosition, yPosition)) {
		board[xPosition][yPosition] = piece; //All clear, place piece
		return true;
	} else {
		std::cout << "Error: Overlap on " << xPosition << ":" << yPosition << "...\n";
		return false; //For sure exit, a possible logic error fix.
	}
	return false; //Cannot place the piece
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







