#pragma once

#include <iostream>
#include <sstream>
#include <Windows.h>
#include <vector>
#include <utility>
#include <functional>

class UI
{
public:
	void showInstructions();
	void showMenu();
	POINT askForCursorDestinationPos();
	void waitForUserInputToStopThread();

	void dummy() { std::cout << "dummy" << std::endl; } // temp

private:
	typedef std::pair<std::string, std::function<void(UI*)>> string_function_pair;
	std::vector<string_function_pair> menu = { std::make_pair("Start spamming", &UI::dummy),
											   std::make_pair("Choose file with quotes to spam", &UI::dummy),
											   std::make_pair("Set spamming interval", &UI::dummy),
											   std::make_pair("Show instructions", &UI::showInstructions) };

};

