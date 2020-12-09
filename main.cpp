#include <iostream> // Basic I/O processing.
#include <string>
#include "cmdloop.h" // Contains looped function used for reading commands.
#include "init/init.h"

using namespace std;

int main() // Initialization of the main function. This function will be used to call other functions that will initialize variables, and call the function that starts the game.
{
	init(); // Variable initialization.
	cmdloop(); // Command loop.
	return 1;
}
