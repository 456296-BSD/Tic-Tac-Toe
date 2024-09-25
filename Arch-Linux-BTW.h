//	 _______  ______    _______  __   __    ___      ___   __    _  __   __  __   __   
//	|   _   ||    _ |  |       ||  | |  |  |   |    |   | |  |  | ||  | |  ||  |_|  |  
//	|  |_|  ||   | ||  |       ||  |_|  |  |   |    |   | |   |_| ||  | |  ||       |  
//	|       ||   |_||_ |       ||       |  |   |    |   | |       ||  |_|  ||       |  
//	|       ||    __  ||      _||       |  |   |___ |   | |  _    ||       | |     |   
//	|   _   ||   |  | ||     |_ |   _   |  |       ||   | | | |   ||       ||   _   |  
//	|__| |__||___|  |_||_______||__| |__|  |_______||___| |_|  |__||_______||__| |__|  
//	                             _______  _______  _     _                             
//	                            |  _    ||       || | _ | |                            
//	                            | |_|   ||_     _|| || || |                            
//	                            |       |  |   |  |       |                            
//	                            |  _   |   |   |  |       |                            
//	                            | |_|   |  |   |  |   _   |                            
//	                            |_______|  |___|  |__| |__|
//
//	A general C++ tools header file
//
//	Author: Sawyer Scheve
//	9/25/2024

//  _  _             _           ___ _ _        
// | || |___ __ _ __| |___ _ _  | __(_) |___ ___
// | __ / -_) _` / _` / -_) '_| | _|| | / -_|_-<
// |_||_\___\__,_\__,_\___|_|   |_| |_|_\___/__/
//                                              

#include <iostream>
#include <cstring>

//  ___                       
// | _ \___ _ __  _____ _____ 
// |   / -_) '  \/ _ \ V / -_)
// |_|_\___|_|_|_\___/\_/\___|
//                            

char* Remove(char* input, char charToRemove) {
	char* output = new char[81];
	int counter = 0;
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] != charToRemove) {
			output[counter] = input[i];
			counter++;
		}
	}
	output[counter] = '\0';
	return output;	
}

//  ___                         
// | _ \_____ _____ _ _ ___ ___ 
// |   / -_) V / -_) '_(_-</ -_)
// |_|_\___|\_/\___|_| /__/\___|
//

char* Reverse(char* input) {
	char* output = new char[81];
	int counter = strlen(input);
	output[counter] = '\0';
	counter--;
	for (int i = 0; i < strlen(input); i++) {
		output[counter] = input[i];
		counter--;
	}
	return output;
}

//  _                                       
// | |   _____ __ _____ _ _ __ __ _ ___ ___ 
// | |__/ _ \ V  V / -_) '_/ _/ _` (_-</ -_)
// |____\___/\_/\_/\___|_| \__\__,_/__/\___|
//

char* Lowercase(char* input) {
	for (int i = 0; i < strlen(input); i++) {
		if (65 <= int(input[i]) && int(input[i]) <= 90) {
			input[i] = char(int(input[i]) + 32);
		}
	}
	return input;
}
