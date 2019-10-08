#pragma comment(lib, "user32.lib")

#include "UI.h"
#include "Spammer.h"

int main()
{
	/*HWND currentWindow = GetForegroundWindow();
	HWND spamWindow = currentWindow;*/

	//while (spamWindow == currentWindow)
	//{
	//	Sleep(100); // otherwise GetForegroundWindow() returns 0
	//	spamWindow = GetForegroundWindow();
	//}

	UI ui;
	ui.showInstructions();

	POINT cursorDestinationPos = ui.askForCursorDestinationPos();
	Spammer spammer(cursorDestinationPos);
	spammer.startSpam();

	return 0;
}