#include "game.h"
#include "player.h"
#include <iostream>

int main()
{
	Game game;
	Player player;

	int userInput[2]; //Generalized user input.
	int gameInput[2]; //for when playing.

	//One time welcome message.
	std::cout << "\n\nW E L C O M E  T O  T I C  T A C  T O E\n\n";
	std::cout << "You may begin playing: Now! Here's a blank board.\n";
	
	while (game.isRunning) {
		game.print_board();
		
		std::cout << "enter the X value then the Y value of your move.\n";
		userInput[0] = player.get_input();
		userInput[1] = player.get_input();
		
		if (userInput[0] == -1 || userInput[1] == -1) {
			game.isRunning = false;
			return -1; //My input validtaor had only one job...
			//And he still has it. You, user, you're fired!
		}
		
		if (userInput[0] == 9 || userInput[1] == 9) {
			//Valid user exit.
			std::cout << "\n\nUser exit requested. Goodbye!";
			game.isRunning = false;
			return 0;
		} else {
			gameInput[0] = userInput[0];
			gameInput[1] = userInput[1];
			std::cout << "You entered: " << userInput[0] << ":" << userInput[1];
			std::cout << "\nMaking move...";
			game.add_new_piece(gameInput[0], gameInput[1], 'X');
			game.print_board();
		}
		
		if (game.is_victory('X')) {
			std::cout << "\n\nY O U  W I N ! ! !\n\n";
			std::cout << "Now exiting on grounds of happy victory ;)";
			return 0;
		}
	}
}


