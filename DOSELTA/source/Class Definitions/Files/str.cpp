#include "../../DOSELTA.h"

namespace DOS
{
	// Load in data for str files.
	void StrFile::read()
	{
		std::ifstream file;

		file.open(DOSELTA_DIRECTORYNAME "/" + name + DOSELTA_FILEEXTENSION);
		if (!file.is_open())
		{
			LOG_PROBLEM(HARMLESS_FILENOTFOUND(name));
			return;
		}

		getline(file, _string);

		file.close();
	}

	// Write in data for str files.
	void StrFile::write()
	{
		std::ofstream file;

		file.open(DOSELTA_DIRECTORYNAME "/" + name + DOSELTA_FILEEXTENSION);

		file << _string << std::endl;

		file.close();
	}


	// Get and set functions for str files.
	std::string StrFile::getData() { return _string; }
	void StrFile::setData(std::string data) { _string = data; }
}
