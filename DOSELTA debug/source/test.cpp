#include <iostream>

#include "DOSELTA.h"

#include "macros.h"

void displayNumbersetfile(DOS::BookFile* numberset)
{
	for (size_t i = 0; i < numberset->size(); i++)
	{
		LOG("Value: " << numberset->getPage(i));
	}
}
void testquit(DOS::BookFile* settosave)
{
	settosave->write();
}

int main()
{
	DOS::Prepare();

	typedef std::string str;
	// TODO: do the same exception stuff for book.

	bool running = true;

	DOS::CommandManager cm;
	DOS::InputHandler ih(&cm);

	std::string argument1 = "";
	ih.addArgument(&argument1);


	str age = "hello";
	str height = "world!";
	DOS::BookFile nsf("two");

	nsf.read();

	DOS::Command showset("$syf", "stands for \"show your file\"", [&nsf]() { displayNumbersetfile(&nsf); });
	DOS::Command commands("$dispcommands", "displays commands", [&cm]() {cm.displayCommands(); });
	DOS::Command quit("$end", "ends the program run", [&nsf, &running]() { testquit(&nsf); running = false; });
	DOS::Command write("$write", "push backs a string you write as argument", [&nsf, &argument1] { str newstr = argument1; nsf.addPage(newstr); });

	cm.add(showset); cm.add(commands); cm.add(quit); cm.add(write);

	cm.execute("$dispcommands");

	while (running)
	{
		ih.getInput();

		DOS::ClearScreen();

		ih.handleInput();
	}

	return 0;
}