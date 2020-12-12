#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "cmdsuite.h"
#include "init/filesys.h"

#ifndef CMDLOOP_H
#define CMDLOOP_H

using namespace std;

vector<Folder> folders;

vector<string> split(const string& s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

void cmdloop() // This function serves as an interpreter for player commands. It reads the player command and runs the appropriate function.
{
	int i = 0;
	string playerInput; // Unsplit player input.
	vector<string> pi;
	while (true)
	{
		cout<<"player@playercomputer:"<<folders[workingdir].name<<"> ";
		
		// Player Input Processing
		getline(cin, playerInput); // Get player input and put it in the string variable 'playerInput'
		
		pi = split(playerInput, ' ');
		
		// Commands
		if (playerInput != "")
		{
			if (pi[0] == "cd" && pi.size() > 1)
			{
				cd(pi[1]);
			}
			else if (playerInput == "ls")
			{
				ls();
			}
			else
			{
				cout << "Command not found.\n"; // If the player input doesn't corrospond to any registered commands.
			}
		}
		
		// Resetting the player input
		pi.clear();
	}
	return;
}

#endif
