#include <iostream>
#include <string>

namespace ch {

	std::string capitalizeString(std::string text) {

		//capitalize first letter
		text[0] = toupper(text[0]);

		for (int i = 0; i < text.size(); i++) {
			if ((i + 1) <= text.size()) {
				if (text[i] == ' ') {
					text[i + 1] = toupper(text[i + 1]);
				}
			}

		}

		return text;
	}

	std::string capitalizeSentence(std::string text) {

		//capitalize first letter
		text[0] = toupper(text[0]);

		for (int i = 0; i < text.size(); i++) {
			if ((i + 2) <= text.size()) {
				if (text[i] == '.') {
					text[i + 2] = toupper(text[i + 2]);
				}
			}
			if ((i + 1) <= text.size()) {
				if (text[i] == 'i' && text[i + 1] == ' ') {
					text[i] = toupper(text[i]);
				}
			}
		}

		return text;
	}

	std::string getString() {
		std::string s;
		if (std::cin.peek() == static_cast<int>('\n')) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		std::getline(std::cin, s);
		return s;
	}

	int getInt() {
		int i;
		std::cin >> i;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cin >> i;
		}
		return i;
	}

	long getLong() {
		long l;
		std::cin >> l;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cin >> l;
		}
		return l;
	}

	std::string colorText(std::string text, int textColor) {

		// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors

		return "\033[" + std::to_string(textColor) + 'm' + text + "\033[0m";
	}

	std::string colorText(char text, int textColor) {

		// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors

		return "\033[" + std::to_string(textColor) + 'm' + text + "\033[0m";
	}
}