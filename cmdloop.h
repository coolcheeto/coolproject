#include <iostream>
#include <sstream>
#include <string>

#ifndef CMDLOOP_H
#define CMDLOOP_H

using namespace std;

string splitter(string playerInput, int wordReturnNum) // I sniffed a lot of paint before writing this function. I'm not sure what it does.
{
	string line = playerInput;
	string arr[4];
	int i = 0;
	stringstream ssin(line);
	while (ssin.good() && i < 4)
	{
		ssin >> arr[i];
		++i;
	}

	return arr[wordReturnNum];
}

void cmdloop() // This function serves as an interpreter for player commands. It reads the player command and runs the appropriate function.
{
	string playerInput; // Pre-split player input.
	string pi[3]; // Short for player input. Each place in the variable contains one of the words in the input. i.e. '0' contains the first word, '1' contains the second etc.
	while (true)
	{
		cout<<"player@playercomputer> ";
		getline(std::cin, playerInput); // Get player input and put it in the string variable 'playerInput'
		
		pi[0] = splitter(playerInput, 0); // Splits the string we get from playerInput and splits it into multiple strings. For example, 'hello world' turns into 'hello' and 'world'
		pi[1] = splitter(playerInput, 1);
		pi[2] = splitter(playerInput, 2);
		pi[3] = splitter(playerInput, 3);
	
		if (pi[0] == "printhelloisabel") // Simple example command.
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
