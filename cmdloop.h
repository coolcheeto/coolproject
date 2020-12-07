#include <iostream>
#include <sstream>
#include <string>

#ifndef CMDLOOP_H
#define CMDLOOP_H

using namespace std;

struct playerInputContainer {
	string pi[9]; // maximum of 10 words. if you want more for some reason, just increase the magic number.
};

playerInputContainer splitter(string playerInput) // I sniffed a lot of paint before writing this function. I'm not sure what it does.
{
	playerInputContainer pic;
	string line = playerInput;
	int i = 0;
	stringstream ssin(line);
	while (ssin.good() && i < 9)
	{
		ssin >> pic.pi[i];
		++i;
	}

	return pic;
}

void cmdloop() // This function serves as an interpreter for player commands. It reads the player command and runs the appropriate function.
{
	string playerInput; // Pre-split player input.
	playerInputContainer pic;
	while (true)
	{
		cout<<"player@playercomputer> ";
		getline(std::cin, playerInput); // Get player input and put it in the string variable 'playerInput'
	
		pic = splitter(playerInput);
		
		if (pic.pi[0] == "printhelloisabel") // Simple example command.
		{
			cout<< "Hello, Isabel!\n";
		} else
		{
			cout<<"Command not found.\n"; // If the player input doesn't corrospond to any registered commands.
		}
	}
	return;
}

#endif
