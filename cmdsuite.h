#include <iostream>
#include <string>
#include "init/init.h" // Includes the full folder of init
#include "init/filesys.h"

#ifndef CMDSUITE_H
#define CMDSUITE_H

using namespace std;

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

int isChild(int toSearch, string toFind) // Searches a directory's children to see if their names corrospond to a name given to the function. If true, it returns the directories id. If false, it returns zero.
{
	for (int i = 0; i < folders[toSearch].children.size(); i++)
	{
		if (folders[folders[toSearch].children[i]].name == toFind)
		{
			return folders[toSearch].children[i];  // Returns folder given
		}
	}

	return 0;
}

void ls() // Lists directories
{
	if (folders[workingdir].children.size() == 0)
	{
		return;
	}
	for (int x = 0; x <= folders[workingdir].children.size() - 1; x++)
	{
		cout << folders[folders[workingdir].children[x]].name<<"   ";
	}
	cout<<"\n";
	return;
}

void mkdir(string foldername) // Creates directory
{
	folders.push_back(Folder());
	folders[folders.size() - 1].name = foldername;
	placeInsideFolder(workingdir, folders.size() - 1);
}


void cd(string toChange) // Changes directory
{	
	if (toChange == "..")
	{
		workingdir = folders[workingdir].parent;
		return;
	}

	if (toChange.find("/") != string::npos)
	{
		int currentdir = workingdir;
		vector<string> splitdir = split(toChange, '/');
		for (int i = 0; i < splitdir.size(); i++)
		{
			if (splitdir[i] == "..")
			{
				currentdir = folders[currentdir].parent;
			}else 
			{
				currentdir = isChild(currentdir, splitdir[i]);
				if (currentdir == 0) { break; }  // Breaking to avoid any fuckery with shit
			}
		}
		if (currentdir == 0)
		{
			cout << "Invalid directory.\n";
			return;
		}else 
		{
			workingdir = currentdir;
			return;
		}
	}

	int functionResult = isChild(workingdir, toChange);
	
	if (functionResult == 0)
	{
		cout << "Invalid directory.\n";
	} else
	{
		workingdir = functionResult;
	}
	return;
}

#endif
