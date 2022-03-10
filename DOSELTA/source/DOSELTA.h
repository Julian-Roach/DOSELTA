/******************************************************************************
DOSELTA - Data Oriented, Small and Efficient c++ Library for Task Automation.

The Description:
DOSELTA is a library helping you to write applications for your simple tasks.
You can quickly write an app that will go through some data, process it, and
give you some output, if you wish. DOSELTA is great for creating little
projects requiring data storage, such as diaries, or lists of ideas.

Be careful though - don't delete the .doselta files! Otherwise you will lose
all of that data permamently.

Actual Purpose:
Basically, I created this library just for myself; I just needed to make simple
little applications, (such as diaries, TODO lists, password storages, etc. ) so
I created this "shortcut" for them. This project isn't meant to be used by
anyone, but if you like it, and you would like to "upgrade" it a little, feel
free to pull request your changes!
*******************************************************************************/

#pragma once





// INCLUDES

// Common, required includes.
#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <fstream>
#include <filesystem>





// MACROS

// Fatal error messages.
#define FATAL_PAGEINDEXBAD "The page on a given index in a Book class does not exist."
#define FATAL_NUMBERINDEXBAD "The number on a given index in a Numberset class does not exist."

// Harmless error messages.
#define HARMLESS_COMMANDNOTFOUND(commandName) "The command \"" + commandName + "\" was not found."
#define HARMLESS_FILENOTFOUND(fileName) "The file \"" + fileName + "\" was not found; no data received."

// The prefix space must be 12 characters long, for convienent reading.
#define LOG_NOPFX(content)\
	std::cout << "          | " << content << std::endl

#define LOG_PROBLEM(problem)\
	std::cout << "[PROBLEM] | " << problem << std::endl

#define LOG_FATAL(fatal)\
	std::cout << "[FATAL]   |" << fatal << std::endl;

#define LOG_COMMAND(commandName, commandDescription)\
	std::cout << "[COMMAND] | " << commandName << " - " << commandDescription << std::endl

#define LOG_INPUTARROWS\
	std::cout << "[INPUT]   | >>> ";

// DOSELTA macros.
#define DOSELTA_DIRECTORYNAME "DOSELTA_DATA"
#define DOSELTA_FILEEXTENSION ".doselta"

// DOS NAMESPACE
namespace DOS
{





	// TYPEDEFS
	typedef std::function<void()> simple_action;





	// FILE RELATED

	// The File classes. For each type, a class is needed.
	class File
	{
	public:
		File(std::string name);

		virtual void read() {};
		virtual void write() {};

		std::string name = "";
	};

	class IntFile  : public File
	{
	public:
		using File::File;

		void read();
		void write();

		void setData(int data);
		int getData();
	private:
		int _number = NULL;
	};

	class StrFile  : public File
	{
	public:
		using File::File;

		void read();
		void write();

		void setData(std::string data);
		std::string getData();
	private:
		std::string _string = "";
	};

	// BookFile is like a vector of strings. It reads/writes to one file.
	class BookFile : public File
	{
	public:
		using File::File;

		void read();
		void write();

		void addPage(std::string newPage);
		void setPage(size_t pageIndex, std::string newPage);
		std::string getPage(size_t pageIndex);

		size_t size();
	private:
		std::vector<std::string> _pages;
	};

	// NumbersetFile is like a vector of integers. It reads/writes to one file.
	class NumbersetFile : public File
	{
	public:
		using File::File;

		void read();
		void write();

		void addNumber(int newNumber);
		void setNumber(size_t numberIndex, int newNumber);
		int getNumber(size_t numberIndex);

		size_t size();
	private:
		std::vector<int> _numbers;
	};





	// COMMAND RELATED
	
	// The Command class.
	class Command
	{
	public:
		Command(std::string name, std::string description, simple_action function);

		std::string name        = "";
		std::string description = "";
		simple_action function  = nullptr;
	};

	// The CommandManager class. It manages all commands.
	class CommandManager
	{
	public:
		void add(Command newCommand);
		void displayCommands();
		void execute(std::string commandName);

		std::string* _commandArgument_ptr = nullptr;
	private:
		std::vector<Command> _commands;
	};





	// INPUT RELATED

	// The input handler gets the input, and runs the execute()
	// function of the CommandManager class with it.
	class InputHandler
	{
	public:
		InputHandler(CommandManager* commandManager_ptr);
		void getInput();
		void handleInput();
		void addArgument(std::string* argument_ptr);

	private:
		CommandManager* _commandManager_ptr = nullptr;
		std::string _input = "";
		std::vector<std::string*> _arguments;
		
		const char _inputSeparator = ':';
	};





	// DOSELTA FUNCTIONS

	void ClearScreen();
	void Prepare();
}
