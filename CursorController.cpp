#include "CursorController.h"

void CursorController::setCursorDestinationPos(const POINT& p)
{
	cursorDestinationPos = p;
}

void CursorController::updateCursorReturnPos()
{
	GetCursorPos(&cursorReturnPos);
}

void CursorController::leftClick()
{
	leftDown();
	leftUp();
}

void CursorController::moveCursorToDestinationPos()
{
	moveCursorToPos(cursorDestinationPos.x, cursorDestinationPos.y);
}

void CursorController::moveCursorToReturnPos()
{
	moveCursorToPos(cursorReturnPos.x, cursorReturnPos.y);
}

void CursorController::leftDown()
{
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));
}

void CursorController::leftUp()
{
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}

void CursorController::moveCursorToPos(int x, int y)
{
	double fScreenWidth = static_cast<double>(GetSystemMetrics(SM_CXSCREEN)) - 1;
	double fScreenHeight = static_cast<double>(GetSystemMetrics(SM_CYSCREEN)) - 1;
	double fx = x * (65535.0f / fScreenWidth);
	double fy = y * (65535.0f / fScreenHeight);

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = fx;
	Input.mi.dy = fy;
	::SendInput(1, &Input, sizeof(INPUT));
}
