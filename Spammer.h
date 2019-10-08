#pragma once

#include <iostream>
#include "KeyboardController.h"
#include "CursorController.h"

class Spammer
{
public:
	Spammer(const POINT& _cursorDestinationPos);
	void startSpam();
	//void stopSpam();

private:
	KeyboardController keyboardController;
	CursorController cursorController;

	bool isRunning = false;
	unsigned int spamInterval = 1000; // ms

	bool checkIfShouldStop();
};

