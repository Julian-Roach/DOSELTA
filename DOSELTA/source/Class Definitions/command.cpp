#include "../DOSELTA.h"

namespace DOS
{
	Command::Command(std::string name, std::string description, simple_action function)
	{
		this->name        = name;
		this->description = description;
		this->function    = function;
	}
}