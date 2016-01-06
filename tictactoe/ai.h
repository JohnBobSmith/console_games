#ifndef AI_H
#define AI_H
#include "game.h"
class AI : public Game
{
	public:
		AI(); //Initiate internal data
		~AI();
		
		//Used strictly for debuggin and/or testing.
		void print_aiboard();
		
		void update_board(int xPosition, int yPosition, char piece);
		
		std::array<std::array<char, MAX_ROWS>, MAX_COLS> aiboard = board;
};

#endif //AI_H
