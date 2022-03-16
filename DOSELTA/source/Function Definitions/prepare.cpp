#include "../DOSELTA.h"


namespace DOS
{
	// The function that needs to be run on the beginning of the program.
	void Prepare()
	{
		// Create the DOSELTA_DATA directory. It won't do anything if the directory does not exist.
		system("mkdir " DOSELTA_DIRECTORYNAME); // BAD PRACTICE; ONLY FOR WINDOWS

		DOS::ClearScreen(); // Clear, in case it notifies about the directory already existing.
	}
}