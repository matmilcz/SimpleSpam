#pragma comment(lib, "user32.lib")

#include <thread>
#include "UI.h"
#include "Spammer.h"

int main()
{
	//while (spamWindow == currentWindow)
	//{
	//	Sleep(100); // otherwise GetForegroundWindow() returns 0
	//	spamWindow = GetForegroundWindow();
	//}

	UI ui;
	ui.showInstructions();

	POINT cursorDestinationPos = ui.askForCursorDestinationPos();
	Spammer spammer(cursorDestinationPos);
	std::thread spammerThread(&Spammer::startSpam, &spammer);

	ui.waitForUserInputToStopThread();

	spammer.stopSpam();
	spammerThread.join();

	return 0;
}