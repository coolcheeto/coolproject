#include <iostream>
#include <sstream>
#include <string>

#ifndef CMDLOOP_H
#define CMDLOOP_H

using namespace std;

void cmdloop() // This function serves as an interpreter for player commands. It reads the player command and runs the appropriate function.
{
	int i = 0;
	string playerInput; // Pre-split player input.
	string pi[9];
	while (true)
	{
		cout<<"player@playercomputer> ";
		getline(std::cin, playerInput); // Get player input and put it in the string variable 'playerInput'
		
		i = 0;	
		stringstream ssin(playerInput);
		while (ssin.good() && i < 9)
		{
			ssin >> pi[i];
			++i;
		}
		
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
