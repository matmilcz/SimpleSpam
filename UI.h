#pragma once

#include <iostream>
#include <sstream>
#include <Windows.h>

class UI
{
public:
	void showInstructions();
	POINT askForCursorDestinationPos();
	void waitForUserInputToStopThread();
};

