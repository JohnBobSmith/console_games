#include "game.h"
#include "player.h"
#include <iostream>

int main()
{
	Game game;
	Player player;

	char playerPiece = player.get_player_piece();
	std::cout << "Player piece is: " << playerPiece;
	int userInput; //Generalized user input.
	int inputX; //Store the value of the players input here
	int inputO; //to be passed along to the apropriate functions

	while (game.isRunning) {
		//One time setup message.
		if (playerPiece == '-') {
			std::cout << "\n\nWelcome to tic tacin toe!";
			std::cout << "\nWhich piece would you like? X or O";
			std::cout << "\n1 is for X, 2 is for O.";
			userInput = player.get_input();
		} else {
			//The piece is set, we can begin playing!
			std::cout << "\n\nYou may begin playing: Now! Here's a blank board.\n";
			game.print_board();
			std::cout << "Enter the X position of your move.";
			userInput = player.get_input();
			if (userInput) { //If we have no errors
				inputX = userInput;
			}
			std::cout << "Enter the Y position of your move.";
			userInput = player.get_input();
			if (userInput) { //No errors detected
				inputO = userInput;
			}
			std::cout << "You entered: " << inputX << ":" << inputO;
			std::cout << "Making move...";
			//Should help with making moves correctly...
			game.add_new_piece(inputX, inputO, playerPiece);
			game.print_board();
		}

		switch (userInput) 
		{
		case -1:
			//Any generic exit
			game.isRunning = false;
			return -1;
			break;

		case 9:
			//Deliberate user exit
			std::cout << "\n\nUser exit requested. Goodbye!\n\n";
			game.isRunning = false;
			break;

		case 0:
			break; //Valid input.

		case 1:
			if (player.get_player_piece() == '-') {
				//One time setup of player piece
				playerPiece = game.get_piece_x();
				std::cout << playerPiece;
				break;
			} else {
				break;
			}
			break;

		case 2:
			if (player.get_player_piece() == '-') {
				//One time setup of player piece
				playerPiece = game.get_piece_o();
				std::cout << playerPiece;
				break;
			} else {
				break;
			}
			break;

		default:
			if (player.get_player_piece() == '-') {
				std::cout << "\nError. Invalid input. Defaulting to O as player piece...";
				player.set_player_piece(game.get_piece_o());
				std::cout << "\nYour piece is now set to: " << player.get_player_piece();
				break;
			} else {
				std::cout << "Error of some sort. I have no idea what you are doing...\n";
				std::cout << "Now exiting on grounds of a user and/or unkown error...\n";
				return -1;
				break;
			}
			break;
		}
	}
}


