#include "../DOSELTA.h"

#include <Windows.h> // BAD PRACTICE; ONLY FOR WINDOWS

bool dirExists(const std::string& dirName_in)
{
	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());

	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;

	return false;
}


namespace DOS
{
	// The function that needs to be run on the beginning of the program.
	void Prepare()
	{
		// Check if the DOSELTA directory exists, create if it doesn't.
		if (!dirExists(DOSELTA_DIRECTORYNAME))
		{
			LOG_NOPFX("The direcotry did not exist but it does now.");
			std::filesystem::create_directory(DOSELTA_DIRECTORYNAME);
		}
		else
			LOG_NOPFX("The directory exists.");
	}
}