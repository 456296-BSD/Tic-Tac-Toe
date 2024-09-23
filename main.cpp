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
//	9/23/2024

//  _  _             _           ___ _ _        
// | || |___ __ _ __| |___ _ _  | __(_) |___ ___
// | __ / -_) _` / _` / -_) '_| | _|| | / -_|_-<
// |_||_\___\__,_\__,_\___|_|   |_| |_|_\___/__/
//

#include "../Arch-Linux-BTW.h"

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

void TakeTurn(char playerRef) {
	return; // PLACE HOLDER
}

char GetOtherPlayer(char playerRef) {
	if(playerRef == 'x'){
		return 'o'; 
	} else {
		return 'x';
	}
}

bool CheckWin(char** boardPtr){
	return false; // PLACE HOLDER
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
	
	// Both of these take in a 3x3 char array pointer.
	ResetBoard(board); // Init board. (Base value for each board space is '-')
	PrintBoard(board); // You're smart I will let you figure out what this one does.
	
	std::cout << "Welcome to Tic-Tac-Toe. When prompted enter first an x value 1-3 then a y value 1-3." << std::endl;
	
	// Start game loop.	
	bool isRunning = true;
	while(isRunning) {
		if(!CheckWin(board)) {
			player = GetOtherPlayer(player);
			TakeTurn(player); // Allows the current player, x or o, to make a move.
			PrintBoard(board); 
		}
		// NEEDED: PLAY AGAIN
	}
}
