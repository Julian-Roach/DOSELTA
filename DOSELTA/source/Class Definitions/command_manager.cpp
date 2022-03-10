#include "../DOSELTA.h"

namespace DOS
{
	void CommandManager::add(Command newCommand) { _commands.push_back(newCommand); }

	void CommandManager::execute(std::string commandName)
	{
		for (unsigned int i = 0; i < _commands.size(); i++)
			if (_commands[i].name == commandName)
			{
				_commands[i].function();
				return;
			}
		LOG_PROBLEM(HARMLESS_COMMANDNOTFOUND(commandName));
		return;
	}

	void CommandManager::displayCommands()
	{
		LOG_NOPFX("The command list:");
		
		for (unsigned int i = 0; i < _commands.size(); i++)
		{
			LOG_COMMAND(_commands[i].name, _commands[i].description);
		}
	}
}
