#include "../../DOSELTA.h"

namespace DOS
{
	// Load in data for numberset files.
	void NumbersetFile::read()
	{
		std::ifstream file;

		file.open(DOSELTA_DIRECTORYNAME "/" + name + DOSELTA_FILEEXTENSION);
		if (!file.is_open())
		{
			LOG_PROBLEM(HARMLESS_FILENOTFOUND(name));
			return;
		}

		std::string data;
		while (!file.eof())
		{
			getline(file, data);
			_numbers.push_back(std::stoi(data));
		}

		file.close();
	}

	// Write in data for numberset files.
	void NumbersetFile::write()
	{
		std::ofstream file;

		file.open(DOSELTA_DIRECTORYNAME "/" + name + DOSELTA_FILEEXTENSION);

		// Write the first value without an endline.
		file << _numbers[0];
		for (size_t i = 1; i < this->size(); i++)
			file << std::endl << _numbers[i];

		file.close();
	}

	// Add numbers to the Numberset class.
	void NumbersetFile::addNumber(int newNumber)
	{
		_numbers.push_back(newNumber);
	}

	void NumbersetFile::setNumber(size_t numberIndex, int newNumber)
	{
		if (numberIndex >= _numbers.size()) { LOG_FATAL(FATAL_NUMBERINDEXBAD); } // Fatal error

		else
			_numbers[numberIndex] = newNumber;
	}

	int NumbersetFile::getNumber(size_t numberIndex)
	{
		if (numberIndex >= _numbers.size()) { LOG_FATAL(FATAL_NUMBERINDEXBAD); return NULL; } // Fatal error

		else
			return _numbers[numberIndex];
	}

	size_t NumbersetFile::size() { return _numbers.size(); }
}