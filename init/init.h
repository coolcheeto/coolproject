#include <vector>
#include "init/filesys.h"

#ifndef INIT_H
#define INIT_H

void placeInsideFolder(int parentdir, int childdir)
{
	folders[parentdir].children.push_back(childdir);
	folders[childdir].parent = parentdir;
	return;
}

void init()
{
	/* FOLDERS */
	folders.push_back(Folder()); // ID 0
	folders[0].name = "/";

	folders.push_back(Folder()); // ID 1
	folders[1].name = "Documents";

	folders.push_back(Folder()); // ID 2
	folders[2].name = "Videos";

	folders.push_back(Folder()); // ID 3
	folders[3].name = "Pictures";
	
	placeInsideFolder(0, 1);
	placeInsideFolder(0, 2);
	placeInsideFolder(0, 3);
}

#endif
