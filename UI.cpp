#include "UI.h"

void UI::showInstructions()
{
	std::string instr = 
		"Step 1: Make sure the chat window you will to spam is visible and not covered by any other window. \n"
		"Step 2: ...";

	std::cout << instr << std::endl;
}

POINT UI::askForCursorDestinationPos()
{
	std::cout << "Please, set proper cursor position and press a key to continue..." << std::endl;
	std::cin.get();

	POINT p;
	GetCursorPos(&p);
	std::cout << "Position set: " << std::endl << "x: " << p.x << "  y : " << p.y << std::endl;

	return p;
}
