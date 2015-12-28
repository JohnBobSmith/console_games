#include "game.h"
#include "player.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(0)); //Random numbers.
	Game game;
	Player player;

	int userInput[2]; //Generalized user input.
	int gameInput[2]; //for when playing.
		
	//Welcome message/banner
	std::cout << "\n\nW E L C O M E  T O  T I C  T A C  T O E\n\n";	
	
	while (game.isRunning) {
		if (player.playerPiece == '-') {
			//One time welcome and setup stuff.
			std::cout << "Welcome! Which piece would you like. X or O?\n";
			std::cout << "Enter 1 for X, 2 for O, A zero for random.\n";
			userInput[0] = player.get_input();
	
			if (userInput[0] == -1) {
				//Delibrately create a bug here to allow
				//the bug-to-feature introduced in my input
				//validator to work.
				/*
					Basically I need to make 2 input requests,
					one for X and one for the Y positions on the grid,
					but I was having serious trouble with it. So now
					I use the extra input requset to inform the user this
					is his very last chance and to tell him he blew it 
					otherwise. A sort of joke from a bug I haven't yet
					figured out, hence the bug-to-feature code in player.cpp.
				*/
				userInput[0] = player.get_input(); //No harm in programmer humor.
				return -1; //Silly users, making me convert bugs into features haha. 
			}
			
			if (userInput[0] == 0) {
				int randomNum = rand() % 100;
				if (randomNum % 2 == 0) {
					std::cout << "\nYour random piece is X";
					player.playerPiece = 'X';
				} else {
					std::cout << "\nYour random piece is O";
					player.playerPiece = 'O';
				}
			}
	
			if (userInput[0] == 1) {
				std::cout << "\nYour piece is X";
				player.playerPiece = 'X';
			}
			if (userInput[0] == 2) {
				std::cout << "\nYour piece is O";
				player.playerPiece = 'O';
			}
			std::cout << "\nSetup complete! You may begin playing... NOW!";
		}
		
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
			//Deliberate input-swap to avoid chaning 3+ lines of code.
			//X is first, Y is second. Now our board array thinks so too.
			game.add_new_piece(gameInput[1], gameInput[0], player.playerPiece);
			game.print_board();
		}
		
		if (game.is_victory('X') && player.playerPiece == 'X') {
			std::cout << "\n\nY O U  W I N ! ! !\n\n";
			std::cout << "Now exiting on grounds of happy victory ;)\n\n";
			return 0;
		}
		
		if (game.is_victory('O') && player.playerPiece == 'O') {
			std::cout << "\n\nY O U  W I N ! ! !\n\n";
			std::cout << "Now exiting on grounds of happy victory ;)\n\n";
			return 0;
		}
	}
}


