#pragma once
#include <string>
#include <iostream>

namespace ch { //consoleHelp.cpp

	std::string capitalizeString(std::string);

	std::string capitalizeSentence(std::string);

	int getInt();

	long getLong();

	std::string getString();

	std::string colorText(std::string text, int textColor);

	std::string colorText(char text, int textColor);



}

