#pragma once

#include <windows.h>

class KeyboardController
{
public:
	KeyboardController();

	void ctrlC();
	void ctrlV();
	void enter();

private:
	INPUT ip;

	void pressKey(WORD key);
	void releaseKey(WORD key);
};

