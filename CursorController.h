#pragma once

#include <windows.h>

class CursorController
{
public:
	void setCursorDestinationPos(const POINT& p);
	void updateCursorReturnPos();
	void leftClick();
	void moveCursorToDestinationPos();
	void moveCursorToReturnPos();

private:
	INPUT Input = { 0 };
	POINT cursorReturnPos;
	POINT cursorDestinationPos;

	void leftDown();
	void leftUp();
	void moveCursorToPos(int x, int y);
};

