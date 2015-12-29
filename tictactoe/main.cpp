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
	Player player2; //Unused if we dont have isTwoHumanPlayer set.

	int userInput[2]; //Generalized user input.
	int gameInput[2]; //for when playing.
		
	//Welcome message/banner
	std::cout << "\n\nW E L C O M E  T O  T I C  T A C  T O E\n\n";	
	
	while (game.isRunning) {
		//One time welcome and setup stuff next ~50 lines...
		if (!game.isSetupComplete) {
			std::cout << "How many human players are there? 1 or 2?\n";
			std::cout << "A value of zero will also start a single player\n";
			std::cout << "game in the same way a value of 1 would.\n";
			userInput[0] = player.get_input();
			if (userInput[0] == 9) {
				//valid exit.
				std::cout << "Exit requested. Goodbye!";
				game.isRunning = false;
				return 0;
			}
	
			if (userInput[0] == -1) {
				//error-based exit.
				game.isRunning = false;
				return -1;
			}

			if (userInput[0] == 1 || userInput[0] == 0) {
				std::cout << "A single player game will begin shortly.\n";
			} 
			if (userInput[0] == 2) {
				std::cout << "A two player game will begin shortly.\n";
				player.isTwoHumanPlayer = true;
			}
			if (player.playerPiece == '-') {
				std::cout << "Which piece would you like. X or O?\n";
				std::cout << "Enter 1 for X, 2 for O, A zero for random.\n";
				userInput[0] = player.get_input();

				if (userInput[0] == 9) {
					//valid exit.
					std::cout << "Exit requested. Goodbye!";
					game.isRunning = false;
					return 0;
				}

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
						if(player.isTwoHumanPlayer) {
							std::cout << "Player two's random piece is X. Player one will be O";
							player2.playerPiece ='X';
							player.playerPiece = 'O';
						} else {
							std::cout << "\nYour random piece is X";
							player.playerPiece = 'X'; 
						}
					} else {
						if (player.isTwoHumanPlayer) {
							std::cout << "Player two's random piece is O. Player one will be X";
							player2.playerPiece = 'O';
							player.playerPiece = 'X';
						} else {
							std::cout << "\nYour random piece is O";
							player.playerPiece = 'O';
						}
					}
				}

				if (userInput[0] == 1) {
					if(player.isTwoHumanPlayer) {
						std::cout << "Player two's piece is X. Player one will be O";
						player2.playerPiece ='X';
						player.playerPiece = 'O';
					} else {
						std::cout << "\nYour piece is X";
						player.playerPiece = 'X'; 
					}
				}
				if (userInput[0] == 2) {
					if (player.isTwoHumanPlayer) {
						std::cout << "Player two's piece is O. Player one will be X.";
						player2.playerPiece = 'O';
						player.playerPiece = 'X';
					} else {
						std::cout << "\nYour piece is O";
						player.playerPiece = 'O';
					}
				}
				std::cout << "\nSetup complete! You may begin playing... NOW!";
				game.isSetupComplete = true; //Prevent infinite if statement.
			}
		}
		
		//The following boolean decides which player does what at any given time.		
		static bool isPlayerTurn = true; //Player one goes. 
		
		if (player.isTwoHumanPlayer) {
			if (isPlayerTurn) {
				std::cout << "Player one, enter the X position then Y position of your move.\n";
				userInput[0] = player.get_input();
				userInput[1] = player.get_input();
			} else {
				std::cout << "Player two, enter the X position then Y position of your move.\n";
				userInput[0] = player.get_input();
				userInput[1] = player.get_input();			
			}
		} else {
			std::cout << "Enter the X position then the Y position of your move.\n";
			userInput[0] = player.get_input();
			userInput[0] = player.get_input();
		}

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
			std::cout << "You entered: " << userInput[0] << ":" << userInput[1];
			std::cout << "\nMaking move...";
			//Deliberate input-swap to avoid chaning 3+ lines of code.
			//X is first, Y is second. Now our board array thinks so too.
			if (player.isTwoHumanPlayer) {
				if (isPlayerTurn) {
					game.add_new_piece(userInput[0], userInput[1], player.playerPiece);
					isPlayerTurn = false;
				} else {
					game.add_new_piece(userInput[0], userInput[1], player2.playerPiece);
					isPlayerTurn = true;				
				}
			}
			game.print_board();
		}
		
		
		//Whoever wins first wins first, there is no other option.
		//You cannot tie for win in tic tac toe, but you can draw.
		if (game.is_victory(player.playerPiece)) {
			std::cout << "\n\nPlayer one wins!\n\n";
			std::cout << "Now exiting on grounds of happy victory ;)\n\n";
			return 0;
		}
		
		if (game.is_victory(player2.playerPiece)) {
			std::cout << "\n\nPlayer two wins!\n\n";
			std::cout << "Now exiting on grounds of happy victory ;)\n\n";
			return 0;
		}
	}
}


