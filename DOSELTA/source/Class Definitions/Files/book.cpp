#include "../../DOSELTA.h"

namespace DOS
{
	// Load in data for book files.
	void BookFile::read()
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
			_pages.push_back(data);
		}

		file.close();
	}

	// Write in data for book files.
	void BookFile::write()
	{
		std::ofstream file;

		file.open(DOSELTA_DIRECTORYNAME "/" + name + DOSELTA_FILEEXTENSION);

		// Write the first value without an endline.
		file << _pages[0];
		for (size_t i = 1; i < this->size(); i++)
			file << std::endl << _pages[i];

		file.close();
	}

	// Add pages to the Book class.
	void BookFile::addPage(std::string newPage)
	{
		_pages.push_back(newPage);
	}

	void BookFile::setPage(size_t pageIndex, std::string newPage)
	{
		if (pageIndex >= _pages.size()) { LOG_FATAL(FATAL_PAGEINDEXBAD); } // Fatal error

		else
			_pages[pageIndex] = newPage;
	}

	std::string BookFile::getPage(size_t pageIndex)
	{
		if (pageIndex >= _pages.size()) { LOG_FATAL(FATAL_PAGEINDEXBAD); return std::string(); } // Fatal error

		else
			return _pages[pageIndex];
	}

	void BookFile::removePage(size_t pageIndex)
	{
		if (pageIndex > _pages.size() - 1 || pageIndex < 0)
			return;

		for (size_t i = 1; i <= _pages.size() - 1 - pageIndex; i++)
		{
			_pages[pageIndex + i - 1] = _pages[pageIndex + i];
		}
		_pages.pop_back();
	}

	size_t BookFile::size() { return _pages.size(); }
}