#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include "KeyboardController.h"
#include "CursorController.h"

class Spammer
{
public:
	Spammer(const POINT& _cursorDestinationPos);
	void startSpam();
	void stopSpam();

private:
	KeyboardController keyboardController;
	CursorController cursorController;
	HWND currentWindow = { 0 };
	bool isRunning = false;
	unsigned int spamInterval = 1000; // ms

	void waitTillNextSpam();
};

