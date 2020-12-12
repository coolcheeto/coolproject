#include <string>
#include "init/init.h" // Includes the full folder of init
#include "init/filesys.h"

#ifndef CMDSUITE_H
#define CMDSUITE_H

int isChild(int toSearch, std::string toFind) // Searches a directory's children to see if their names corrospond to a name given to the function. If true, it returns the directories id. If false, it returns zero.
{
	for (int i = 0; i < folders[toSearch].children.size(); i++)
	{
		if (folders[folders[toSearch].children[i]].name == toFind)
		{
			return folders[toSearch].children[i];
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
		std::cout << folders[folders[workingdir].children[x]].name<<"   ";
	}
	std::cout<<"\n";
	return;
}

void mkdir(std::string foldername) // Creates directory
{
	folders.push_back(Folder());
	folders[folders.size() - 1].name = foldername;
	placeInsideFolder(workingdir, folders.size() - 1);
}


void cd(std::string toChange) // Changes directory
{	
	if (toChange == "..")
	{
		workingdir = folders[workingdir].parent;
		return;
	}
	int functionResult = isChild(workingdir, toChange);
	
	if (functionResult == 0)
	{
		return;
	} else
	{
		workingdir = functionResult;
	}
	return;
}

#endif
