#include "Spammer.h"

Spammer::Spammer(const POINT& _cursorDestinationPos)
{
	cursorController.setCursorDestinationPos(_cursorDestinationPos);
}

void Spammer::startSpam()
{
	isRunning = true;

	while (isRunning)
	{
		cursorController.updateCursorReturnPos();
		cursorController.moveCursorToDestinationPos();

		keyboardController.ctrlC();
		/*currentWindow = GetForegroundWindow();
		if (not IsIconic(spamWindow))
		{
			SetForegroundWindow(spamWindow);
		}*/

		cursorController.leftClick();
		keyboardController.ctrlV();
		keyboardController.enter();

		//SetForegroundWindow(currentWindow);
		cursorController.moveCursorToReturnPos();

		Sleep(spamInterval);

		checkIfShouldStop();
	}
}

bool Spammer::checkIfShouldStop()
{
	//std::streambuf* pbuf = std::cin.rdbuf();
	return false;
}
