#include "game.h"
#include "player.h"
#include <iostream>

int main()
{
	Game game;
	Player player;

	int userInput; //Generalized user input.
	int inputX; //Store the value of the players input here
	int inputY; //to be passed along to the apropriate functions

	while (game.isRunning) {
		//One time setup message.
		std::cout << "\n\nWelcome to tic tacin toe!";
		std::cout << "\nWhich piece would you like? X or O";
		std::cout << "\n1 is for X, 2 is for O.";
		userInput = player.get_input();

		switch (userInput) 
		{
		case -1:
			game.isRunning = false;
			return -1;
			break;

		case 9:
			std::cout << "\n\nUser exit requested. Goodbye!\n\n";
			game.isRunning = false;
			break;

		case 1:
			if (player.get_player_piece() == '-') {
				//One time setup of player piece
				player.set_player_piece(game.get_piece_x());
				std::cout << "\nYour piece is now set to: " << player.get_player_piece();
			} else {
				std::cout << "It works! DISGTUNGISHING THIGNYU";
			}
			break;

		case 2:
			if (player.get_player_piece() == '-') {
				//One time setup of player piece
				player.set_player_piece(game.get_piece_o());
				std::cout << "\nYour piece is now set to: " << player.get_player_piece();
			} else {
				std::cout << "It works!";
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


