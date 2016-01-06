#include "game.h"
#include "player.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(int argc, char **argv)
{
	srand(time(0)); //Random numbers.
	Game game;
	Player player;
	Player player2; //Unused if we dont have isTwoHumanPlayer set.

	char piece = '-';	//current players player piece.
	
	if (argc < 2) {
		std::cout << "Please enter a valid CLI argument, with NO hypens. \n";
		std::cout << "Example: ./tictactoe 20 for two player game, random piece.\n";
		std::cout << "Additional help will come when I'm closer to releasing game fully...\n";
		return -2; //Bad CLI arg or lack of one.
	}
	
	//Welcome message/banner
	std::cout << "\n\nW E L C O M E  T O  T I C  T A C  T O E\n\n";	
	
	if (strtol(argv[1], NULL, 10) == 20) {
		std::cout << "Starting 2 player game, random pieces.\n";
		std::cout << "Chosing random piece...\n";
		if (game.get_random_num(100) % 2 == 0) {
			player.playerPiece = 'X';
			player2.playerPiece = 'O';
			std::cout << "Player one, your piece is " << player.playerPiece << "\n";
			std::cout << "Player two, your piece is " << player2.playerPiece << "\n";
			player.isTwoHumanPlayer = true;
		} else {
			player.playerPiece = 'O';
			player2.playerPiece = 'X';
			std::cout << "Player one, your piece is " << player.playerPiece << "\n";
			std::cout << "Player two, your piece is " << player2.playerPiece << "\n";
			player.isTwoHumanPlayer = true;
		}
	} else if (strtol(argv[1], NULL, 10) == 21) {
		player.playerPiece = 'X';
		player2.playerPiece = 'O';
		std::cout << "Starting 2 player game, fixed peices.\n";
		std::cout << "Player one, your piece is " << player.playerPiece << "\n";
		std::cout << "Player two, your piece is " << player2.playerPiece << "\n";
		player.isTwoHumanPlayer = true;
	} else if (strtol(argv[1], NULL, 10) == 22) {
		player.playerPiece = 'O';
		player2.playerPiece = 'X';
		std::cout << "Starting 2 player game, fixed peices.\n";
		std::cout << "Player one, your piece is " << player.playerPiece << "\n";
		std::cout << "Player two, your piece is " << player2.playerPiece << "\n";
		player.isTwoHumanPlayer = true;
	} else {
		std::cout << "Error. Invalid CLI argument. Arguments are: 20 | 21 | 22\n";
		std::cout << "Please use one of the above when running the program.\n";
		std::cout << "For example, ./tictactoe 20\n";
		std::cout << "Now exiting so you can retry.\n";
		return -2; //bad CLI arg or lack of one.
	}

	while (game.isRunning) {
		//Time to play the game!
		int userInput = 0;

		if (player.isTwoHumanPlayer) {
			if (player.isPlayerTurn) {
				piece = player.playerPiece;
				std::cout << "Player one, enter the number of the square you want.\n";
				userInput = player.get_input();
				if (userInput == -1) {
					std::cout << "\nExit requested. Bye!\n";
					return -1; //Error or user exit.
				}
				if  (game.make_move(userInput, player.playerPiece) == 1) {
					std::cout << "Overlap detected... \n";
					std::cout << "Player 1, try again.\n";
					player.isPlayerTurn = true;
				} else {
					player.isPlayerTurn = false;
				}
			} else {
				piece = player2.playerPiece;
				std::cout << "Player two, enter the number of the square you want.\n";
				userInput = player.get_input();
				if (userInput == -1) {
					std::cout << "\nExit requested. Bye!\n";
					return -1; //Error or user exit.
				}
				if  (game.make_move(userInput, player2.playerPiece) == 1) {
					std::cout << "Overlap detected... \n";
					std::cout << "Player 2, try again.\n";
					player.isPlayerTurn = false;
				} else {
					player.isPlayerTurn = true;
				}
			}
		}
		game.print_board();
		
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
		
		if (game.isStalemate) {
			std::cout << "\n\nNobody wins!\n\n";
			std::cout << "Now exiting on grounds of an angry stalemate. ARgh!\n\n";
			return 0;
		}
	}
}


