#include "Spammer.h"
#include "Quoter.h"

Spammer::Spammer(const POINT& _cursorDestinationPos)
{
	cursorController.setCursorDestinationPos(_cursorDestinationPos);
}

void Spammer::startSpam()
{
	Quoter quoter;

	isRunning = true;
	while (isRunning)
	{
		currentWindow = GetForegroundWindow();
		cursorController.updateCursorReturnPos();
		cursorController.moveCursorToDestinationPos();
		
		keyboardController.ctrlC(quoter.getRandomQuote());
		/*
		if (not IsIconic(spamWindow))
		{
			SetForegroundWindow(spamWindow);
		}
		*/

		cursorController.leftClick();
		keyboardController.ctrlV();
		keyboardController.enter();

		SetForegroundWindow(currentWindow);
		cursorController.moveCursorToReturnPos();

		waitTillNextSpam();
	}
}

void Spammer::stopSpam()
{
	isRunning = false;
}

void Spammer::waitTillNextSpam()
{
	unsigned int sleepCounter = spamInterval;
	while (sleepCounter > 0)
	{
		if (isRunning)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			--sleepCounter;
		}
		else
		{
			break;
		}
	}
}
