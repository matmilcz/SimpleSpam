#include "UI.h"

POINT UI::askForCursorDestinationPos()
{
	std::cout << "Please, set proper cursor position and press a key to continue..." << std::endl;
	std::cin.get();

	POINT p;
	GetCursorPos(&p);
	std::cout << "Position set: " << std::endl << "x: " << p.x << "  y : " << p.y << std::endl;

	return p;
}
