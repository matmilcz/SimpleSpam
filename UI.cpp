#include "UI.h"

void UI::showInstructions()
{
	std::string instr = 
		"Step 1: Make sure the chat window you wish to spam is visible and not covered by any other window. \n"
		"Step 2: ... \n";

	std::cout << instr << std::endl;
}

void UI::showMenu()
{
	unsigned int i = 0;
	for (auto menuPos : menu)
	{
		++i;
		std::cout << i << ". " << menuPos.first << std::endl;
	}
	//menu[0].second(this);
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

void UI::waitForUserInputToStopThread()
{
	constexpr char awaitedStr[] = "stop";

	std::cout << "Type '"<< awaitedStr << "' to stop spamming..." << std::endl;
	std::string str;

	while (str != awaitedStr)
	{
		str = "";
		std::cin >> str;
	}
}
