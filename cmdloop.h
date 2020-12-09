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

void cmdloop() // This function serves as an interpreter for player commands. It reads the player command and runs the appropriate function.
{
	int i = 0;
	string playerInput; // Pre-split player input.
	string pi[9];
	while (true)
	{
		cout<<"player@playercomputer:"<<folders[workingdir].name<<"> ";
	
		getline(std::cin, playerInput); // Get player input and put it in the string variable 'playerInput'
		
		i = 0;	
		stringstream ssin(playerInput);
		while (ssin.good() && i < 9)
		{
			ssin >> pi[i];
			++i;
		}
		
		if (pi[0] == "cd" && pi[1] != "") 
		{
			cd(pi[1]);
		}
		else if (playerInput == "ls")
		{
			ls();
		} else if (playerInput == "pwd")
		{
			cout<<workingdir;
		} else
		{
			cout<<"Command not found.\n"; // If the player input doesn't corrospond to any registered commands.
		}
	
	for (int i = 0; i <= 8; i++)
	{
		pi[i] = "";
	}
	}
	return;
}

#endif
