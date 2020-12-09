#include <string>
#include <vector>

#ifndef FOLDER_H
#define FOLDER_H

struct Folder {
	std::string name;
	std::vector<int> children; // Subdirectories
	int parent; // Directory in which this directory is located
};

extern std::vector<Folder> folders; // Vector containing all directories
extern int workingdir = 0; // Directory in which the player resides
#endif
