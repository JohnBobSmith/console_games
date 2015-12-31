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
		std::cout << "Please enter how many players you would like. 1 or 2.\n";
		std::cout << "Also enter which piece player one is. NO spaces\n";
		std::cout << "Example: ./tictactoe 20 for two player game, random piece.\n";
		std::cout << "Additional help will come when I'm closer to releasing game fully...\n";
		return 0;
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
			std::cout << "Player one, your piece is O\n";
			std::cout << "Player two, your piece is X\n";
			player.playerPiece = 'O';
			player2.playerPiece = 'X';
			player.isTwoHumanPlayer = true;
		}
	}
	
	if (strtol(argv[1], NULL, 10) == 21) {
		std::cout << "Starting 2 player game, player on is X.\n";
		player.playerPiece = 'X';
		player2.playerPiece = 'O';
		player.isTwoHumanPlayer = true;
	}
	
	if (strtol(argv[1], NULL, 10) == 22) {
		std::cout << "Starting 2 player game, player one is O.\n";
		player.playerPiece = 'O';
		player2.playerPiece = 'X';
		player.isTwoHumanPlayer = true;
	}

	while (game.isRunning) {
		//Time to play the game!
		int userInput = 0;
		if (player.isTwoHumanPlayer) {
			if (player.isPlayerTurn) {
				piece = player.playerPiece;
				std::cout << "Player one, enter the number of the square you want.\n";
				userInput = player.get_input();
				game.make_move(userInput, player.playerPiece);
				player.isPlayerTurn = false;
			} else {
				piece = player2.playerPiece;
				std::cout << "Player two, enter the number of the square you want.\n";
				userInput = player.get_input();
				game.make_move(userInput, player2.playerPiece);
				player.isPlayerTurn = true;
			}
		}
		
		if (userInput == -1) {
			return -1;
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
		
		if (game.is_board_full()) {
			std::cout << "That sucks. No one wins :(\n";
			std::cout << "Exiting on grounds of stalemate.\n\n";
			return 0;
		}
	}
}


