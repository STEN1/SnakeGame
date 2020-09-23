#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Snake.h"
#include <conio.h>
#include "ConsoleHelp.h"




int main() 
{
	Snake snake{ 5, 5 };
	Board board{ 10, 30 };
	char input{ '0' };

	std::cout << "WASD to play";

	while (true)
	{
		do {
			input = _getch();
		} while (input != 'w' && input != 'a' && input != 's' && input != 'd');

		switch (input)
		{
		case 'w':
			snake.i -= 1;
			break;
		case 'a':
			snake.j -= 1;
			break;
		case 's':
			snake.i += 1;
			break;
		case 'd':
			snake.j += 1;
			break;
		}

		//loop around board
		if (snake.i < 0) snake.i = board.i;
		if (snake.i > board.i) snake.i = 0;
		if (snake.j < 0) snake.j = board.j;
		if (snake.j > board.j) snake.j = 0;

		system("cls");
		for (int i = 0; i < board.i; i++)
		{
			for (int j = 0; j < board.j; j++)
			{
				if (j == 29)
				{
					std::cout << "#\n";
				}
				else if (j == 0)
				{
					std::cout << '#';
				}
				else if (i == 0 || i == 9)
				{
					std::cout << '#';
				}
				else if (snake.i == i && snake.j == j)
				{
					std::cout << ch::colorText('@', 31);
				}
				else
				{
					std::cout << ' ';
				}
			}
		}
	}



}

