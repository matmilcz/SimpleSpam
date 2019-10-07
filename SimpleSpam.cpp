#pragma comment(lib, "user32.lib")

#include "UI.h"
#include "KeyboardController.h"
#include "CursorController.h"

void printHWND(HWND hWnd)
{
	std::cout << hWnd << std::endl;
}

int main()
{
	/*
	GUITHREADINFO guiThreadInfoObject = { 0 };

	printHWND(GetForegroundWindow());
	std::cout << GetWindowThreadProcessId(GetForegroundWindow(), 0) << std::endl;


	Sleep(5000);
	printHWND(GetForegroundWindow());
	std::cout << GetWindowThreadProcessId(GetForegroundWindow(), 0) << std::endl;
	DWORD tid = GetWindowThreadProcessId(GetForegroundWindow(), 0);
	GetGUIThreadInfo(tid, &guiThreadInfoObject);
	std::cout << guiThreadInfoObject.hwndCapture << std::endl;
	HWND focus = guiThreadInfoObject.hwndFocus;
	printHWND(focus);

	Sleep(5000);
	printHWND(GetForegroundWindow());
	std::cout << GetWindowThreadProcessId(GetForegroundWindow(), 0) << std::endl;
	*/

	UI ui;
	KeyboardController keyboardController;
	CursorController cursorController;

	auto cursorDestinationPos = ui.askForCursorDestinationPos();
	cursorController.setCursorDestinationPos(cursorDestinationPos);

	while (true)
	{
		cursorController.updateCursorReturnPos();
		cursorController.moveCursorToDestinationPos();

		keyboardController.ctrlC();
		cursorController.leftClick();
		keyboardController.ctrlV();
		keyboardController.enter();

		cursorController.moveCursorToReturnPos();
		Sleep(1000);
	}

	return 0;
}