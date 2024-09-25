//	 _______  ___   _______         _______  _______  _______         _______  _______  _______ 
//	|       ||   | |       |       |       ||   _   ||       |       |       ||       ||       |
//	|_     _||   | |       | ____  |_     _||  |_|  ||       | ____  |_     _||   _   ||    ___|
//	  |   |  |   | |       ||____|   |   |  |       ||       ||____|   |   |  |  | |  ||   |___ 
//	  |   |  |   | |      _|         |   |  |       ||      _|         |   |  |  |_|  ||    ___|
//	  |   |  |   | |     |_          |   |  |   _   ||     |_          |   |  |       ||   |___ 
//	  |___|  |___| |_______|         |___|  |__| |__||_______|         |___|  |_______||_______|
//
//	Play Tic-Tac-Toe! Guys I swear it's fun!
//
//	Sawyer Scheve
//	9/25/2024

//  _  _             _           ___ _ _        
// | || |___ __ _ __| |___ _ _  | __(_) |___ ___
// | __ / -_) _` / _` / -_) '_| | _|| | / -_|_-<
// |_||_\___\__,_\__,_\___|_|   |_| |_|_\___/__/
//

#include "Arch-Linux-BTW.h"

//  ___             _   _
// | __|  _ _ _  __| |_(_)___ _ _  ___
// | _| || | ' \/ _|  _| / _ \ ' \(_-<
// |_| \_,_|_||_\__|\__|_\___/_||_/__/
//

void PrintBoard(char** boardPtr) {
	// Print title.
	std::cout << "\t  _______  ___   _______             _______  _______  _______             _______  _______  _______  \n"
		     "\t |       ||   | |       |           |       ||   _   ||       |           |       ||       ||       | \n"
		     "\t |_     _||   | |       |   ____    |_     _||  |_|  ||       |   ____    |_     _||   _   ||    ___| \n"
  		     "\t   |   |  |   | |       |  |____|     |   |  |       ||       |  |____|     |   |  |  | |  ||   |___  \n"
  		     "\t   |   |  |   | |      _|             |   |  |       ||      _|             |   |  |  |_|  ||    ___| \n"
  		     "\t   |   |  |   | |     |_              |   |  |   _   ||     |_              |   |  |       ||   |___  \n"
		     "\t   |___|  |___| |_______|             |___|  |__| |__||_______|             |___|  |_______||_______| \n" << std::endl;
	// Print board.
	std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << boardPtr[0][0] <<  '\t' << boardPtr[0][1] <<  '\t' << boardPtr[0][2] << '\n' << '\n' <<
		     '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << boardPtr[1][0] <<  '\t' << boardPtr[1][1] <<  '\t' << boardPtr[1][2] << '\n' << '\n' <<
		     '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << boardPtr[2][0] <<  '\t' << boardPtr[2][1] <<  '\t' << boardPtr[2][2] << std::endl;
}

void ResetBoard(char** boardPtr) {
	for(int x = 0; x < 3; x++) {
		for(int y = 0; y < 3; y++) {
			boardPtr[x][y] = '-';
		}
	}
}

void TakeTurn(char** boardPtr, char playerRef, int x, int y) {
	x = x - 1;
	y = y - 1;
	boardPtr[x][y] = playerRef;
}

bool IsValidMove(char** boardPtr, int x, int y) {
	x = x - 1;
	y = y - 1;
	if(boardPtr[x][y] == '-') {
		return true;
	} else {
		return false;
	}
}

char GetOtherPlayer(char playerRef) {
	if(playerRef == 'x'){
		return 'o'; 
	} else {
		return 'x';
	}
}

bool CheckWin(char** boardPtr, char playerRef){
	if((boardPtr[0][0] == playerRef && boardPtr[0][1] == playerRef && boardPtr[0][2] == playerRef) ||
			(boardPtr[1][0] == playerRef && boardPtr[1][1] == playerRef && boardPtr[1][2] == playerRef) ||
			(boardPtr[2][0] == playerRef && boardPtr[2][1] == playerRef && boardPtr[2][2] == playerRef) ||
			(boardPtr[0][0] == playerRef && boardPtr[1][0] == playerRef && boardPtr[2][0] == playerRef) ||
			(boardPtr[0][1] == playerRef && boardPtr[1][1] == playerRef && boardPtr[2][1] == playerRef) ||
			(boardPtr[0][2] == playerRef && boardPtr[1][2] == playerRef && boardPtr[2][2] == playerRef) ||
			(boardPtr[0][0] == playerRef && boardPtr[1][1] == playerRef && boardPtr[2][2] == playerRef) ||
			(boardPtr[0][2] == playerRef && boardPtr[1][1] == playerRef && boardPtr[2][0] == playerRef)) {
		return true;
	} else {
		int counter = 0;
		for(int x = 0; x < 3; x++) {
			for(int y = 0; y < 3; y++) {
				if(boardPtr[x][y] != '-') {
					counter++;
				}
			}
		}
		if(counter == 9) {
			return true;
		} else {
			return false;
		}
	}
}

bool CheckTie(char** boardPtr) {
	int counter = 0;
	for(int x = 0; x < 3; x++) {
		for(int y = 0; y < 3; y++) {
			if(boardPtr[x][y] != '-') {
				counter++;
			}
		}
	}
	if(counter == 9) {
		return true;
	} else {
		return false;
	}
}

//  ___          _        _   
// | _ \_ _ ___ (_)___ __| |_ 
// |  _/ '_/ _ \| / -_) _|  _|
// |_| |_| \___// \___\__|\__|
//            |__/            

int main() {
	// Create board as a 2D char array pointer. Why specifically that? I don't know mind your business!
	char** board = new char*[3];
	for(int i = 0; i <= 2; i++) {
		board[i] = new char[3];	
	}

	char player = 'o'; // Set starting player to o because its going to be switched to x when the game starts anyways.
	
	// Board space coordinates.
	int x;
	int y;
	
	// Both of these take in a 3x3 char array pointer.
	ResetBoard(board); // Init board. (Base value for each board space is '-')
	PrintBoard(board); // You're smart I will let you figure out what this one does.
	
	std::cout << "Welcome to Tic-Tac-Toe. When prompted enter first a row number 1-3 then a column number 1-3." << std::endl;
	
	// Start game loop.
	bool isRunning = true;
	while(isRunning) {
		if(!CheckWin(board, player)) { // If the game has not been won yet continue gameplay loop.
			player = GetOtherPlayer(player); // Set the current player.
			
			// Get player inputs.
			std::cout << "Enter row number. [1-3]:";
			std::cin >> x;

			std::cout << "Enter column number. [1-3]:";
			std::cin >> y;

			if(IsValidMove(board, x, y)) { // If the entered move is valid allow the player to make their move.
				TakeTurn(board, player, x, y); // Allows the current player, x or o, to make a move.
			} else {
				std::cout << "Invalid move. Try again." << std::endl;
				player = GetOtherPlayer(player); // This is just a dumb way of making it so the player doesn't switch on an invalid move.
			}
			PrintBoard(board);
		} else { // If the game is over do this.
			if(!CheckTie(board)) { // If someone won say who.
				if(player == 'x') {
					std::cout << "X is the winner!" << std::endl;
				}
				if(player == 'o') {
					std::cout << "O is the winner!" << std::endl;
				}	
			} else { // If it was a tie say that instead.
				std::cout << "Game tied!" << std::endl;
			}
			
			// Check if the player would like to play again.
			char again;

			std::cout << "Would you like to play again? [y/N]:";
			std::cin >> again;

			if(again == 'y' || again == 'Y') { // If so reset the board.
				isRunning = true;
				ResetBoard(board);
				player = 'o';
				PrintBoard(board);
			} else { // If not kill game.
				isRunning = false;
			}
		}
	}
}
