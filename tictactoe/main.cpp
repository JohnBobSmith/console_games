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
			if (userInput[0] == -1) {
				//Generic exit code error.
				std::cout << "\n\nExit requested and/or enforced by an error.\n\n";
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
/*
				----------------------------------
				PRESERVING THIS MOMENT IN HISTORY
				----------------------------------
				if (userInput[0] == -1) {
					//Delibrately create a bug here to allow
					//the bug-to-feature introduced in my input
					//validator to work.
					//
					//	Basically I need to make 2 input requests,
					//	one for X and one for the Y positions on the grid,
					//	but I was having serious trouble with it. So now
					//	I use the extra input requset to inform the user this
					//	is his very last chance and to tell him he blew it 
					//	otherwise. A sort of joke from a bug I haven't yet
					//	figured out, hence the bug-to-feature code in player.cpp.
					//
					userInput[0] = player.get_input(); //No harm in programmer humor.
					return -1; //Silly users, making me convert bugs into features haha. 
				}
*/
				if (userInput[0] == -1) {
					//Generic exit code error.
					std::cout << "\n\nExit requested and/or enforced by an error.\n\n";
					game.isRunning = false;
					return -1;
				}
				if (userInput[0] == 0) {
					int randomNum = rand() % 100;
					if (randomNum % 2 == 0) { //Number is even.
						if(player.isTwoHumanPlayer) {
							std::cout << "Player one's random piece is O. Player two will be X";
							player.playerPiece = 'O';
							player2.playerPiece ='X';
						} else {
							//Single player game.
							std::cout << "\nYour random piece is X";
							player.playerPiece = 'X'; 
						}
					} else { //Number is odd.
						if (player.isTwoHumanPlayer) {
							std::cout << "Player one's random piece is X. Player two will be O";
							player.playerPiece = 'X';
							player2.playerPiece = 'O';
						} else {
							//Single player.
							std::cout << "\nYour random piece is O";
							player.playerPiece = 'O';
						}
					}
				}

				if (userInput[0] == 1) {
					if(player.isTwoHumanPlayer) {
						std::cout << "Player ones's piece is X. Player two will be O";
						player.playerPiece = 'X';						
						player2.playerPiece ='O';
					} else {
						//Single player.
						std::cout << "\nYour piece is X";
						player.playerPiece = 'X'; 
					}
				}
				if (userInput[0] == 2) {
					if (player.isTwoHumanPlayer) {
						std::cout << "Player one's piece is O. Player two will be X.";
						player.playerPiece = 'O';
						player2.playerPiece = 'X';
					} else {
						std::cout << "\nYour piece is O";
						player.playerPiece = 'O';
					}
				}
				std::cout << "\nSetup complete! You may begin playing... NOW!\n\n";
				game.isSetupComplete = true; //Prevent infinite if statement.
			}
		}
		

		
		if (player.isTwoHumanPlayer) {
			if (player.isPlayerTurn) {
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
			//Generic exit code error.
			std::cout << "\n\nExit requested and/or enforced by an error.\n\n";
			game.isRunning = false;
			return -1;
		} else {
			std::cout << "You entered: " << userInput[0] << ":" << userInput[1];
			std::cout << "\nMaking move...";
			if (player.isTwoHumanPlayer) {
				if (player.isPlayerTurn) {
					game.add_new_piece(userInput[0], userInput[1], player.playerPiece);
					player.isPlayerTurn = false; //Player one just finished, queue player two.
				} else {
					game.add_new_piece(userInput[0], userInput[1], player2.playerPiece);
					player.isPlayerTurn = true; //Player two just finished, queue player one.				
				}
			} else {
				//Single human player.
				game.add_new_piece(userInput[0], userInput[1], player.playerPiece);
			}
			game.print_board();
		}
		
		
		//Whoever wins first wins first, there is no other option.
		//You cannot tie for win in tic tac toe, but you can draw
		//and/or stalemate the game. <--- happens regularly... stalemates :Z
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
		
		if (game.is_board_full()) {
			//stalemate...
			std::cout << "Aw shucks. No one wins :(.\nNow Exiting.";
			return 0;
		}
	}
}


