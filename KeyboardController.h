#pragma once

#include <windows.h>
#include <string>

class KeyboardController
{
public:
	KeyboardController();

	void ctrlC(const std::string& stringToCopy);
	void ctrlV();
	void enter();

private:
	INPUT ip;

	void pressKey(WORD key);
	void releaseKey(WORD key);
};

