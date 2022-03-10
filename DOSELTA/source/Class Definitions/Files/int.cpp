#include "../../DOSELTA.h"

namespace DOS
{
	// Load in data for int files.
	void IntFile::read()
	{
		std::ifstream file;

		file.open(DOSELTA_DIRECTORYNAME "/" + name + DOSELTA_FILEEXTENSION);
		if (!file.is_open())
		{
			LOG_PROBLEM(HARMLESS_FILENOTFOUND(name));
			return;
		}

		file >> _number;

		file.close();
	}

	// Write in data for int files.
	void IntFile::write()
	{
		std::ofstream file;

		file.open(DOSELTA_DIRECTORYNAME "/" + name + DOSELTA_FILEEXTENSION);

		file << _number << std::endl;

		file.close();
	}

	// Get and set functions for int files.
	int IntFile::getData() { return _number; }
	void IntFile::setData(int data) { _number = data; }
}
