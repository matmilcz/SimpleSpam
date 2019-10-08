#include "KeyboardController.h"

KeyboardController::KeyboardController()
{
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
}

void KeyboardController::pressKey(WORD key)
{
	ip.ki.wVk = key;
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));
}

void KeyboardController::releaseKey(WORD key)
{
	ip.ki.wVk = key;
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}

void KeyboardController::ctrlC()
{
	// TODO: output to change
	const char* output = "Test! ¹œ¿æŸó³ê";
	const size_t len = strlen(output) + 1;
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), output, len);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
}

void KeyboardController::ctrlV()
{
	pressKey(VK_CONTROL);
	pressKey('V');
	releaseKey('V');
	releaseKey(VK_CONTROL);
}

void KeyboardController::enter()
{
	keybd_event(VK_RETURN, 0, 0, 0);
}
