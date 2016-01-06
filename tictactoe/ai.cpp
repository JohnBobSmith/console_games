#include "ai.h"
#include <iostream>

AI::AI()
{
	aiboard = board;
}

AI::~AI()
{
	//dtor
}

void AI::print_aiboard()
{
	//Print the AI's board.
	for (int row = 0; row < 3; row++) {
		std::cout << std::endl;
		for (int col = 0; col < 3; col++) {
			std::cout << aiboard[row][col];	
		}
	}
	std::cout << std::endl;
}

void AI::update_board(int xPosition, int yPosition, char piece)
{
	aiboard[xPosition][yPosition] = piece;
}


