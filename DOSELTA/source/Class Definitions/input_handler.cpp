#include "../DOSELTA.h"

namespace DOS
{
	InputHandler::InputHandler(CommandManager* commandManager_ptr)
	{
		this->_commandManager_ptr = commandManager_ptr;
	}

	void InputHandler::getInput()
	{
		// Reset.
		std::string unprocessed = "";
		_input = "";

		// Get input.
		LOG_INPUTARROWS;
		std::getline(std::cin, unprocessed);
		unprocessed.push_back(_inputSeparator);

		// Process the input now; check if there are any arguments appended.

		// Get the command.
		unsigned int i = 0;
		while(i < unprocessed.size() && unprocessed[i] != _inputSeparator)
		{
			_input.push_back(unprocessed[i]);
			i++;
		}
		unprocessed.erase(unprocessed.begin(), unprocessed.begin() + i);

		// Get the arguments.
		std::string product = "";
		int argIndex = 0;
		for (unsigned int i = 0; i < unprocessed.size() && _arguments.size() > argIndex; i++)
		{
			if (unprocessed[i] != _inputSeparator)
				product.push_back(unprocessed[i]);

			else if (!product.empty())
			{
				*_arguments[argIndex] = product;
				product = "";
				argIndex++;
			}
		}
	}

	void InputHandler::handleInput()
	{
		_commandManager_ptr->execute(_input);
	}

	void InputHandler::addArgument(std::string* argument_ptr)
	{
		_arguments.push_back(argument_ptr);
	}
}
