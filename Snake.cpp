#include <iostream>
#include <string>
#include "Snake.h"
#include <conio.h>
#include "ConsoleHelp.h"
#include <Windows.h>
#include <chrono>
#include <thread>
#include <time.h>


int main() 
{
	Snake snake{ 5, 5 };
	Board board{ 20, 40 };
	char input{ '0' };
	COORD cur{ 0, 0 };

	bool debug = false;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			std::cout << ch::colorText(snakeSplash[i][j], 32);
		}
	}
	std::cout << "Press w, a, s or d to play\n";

	// Getting starting direction
	do {
		input = _getch();
	} while (input != 'w' && input != 'a' && input != 's' && input != 'd');

	while (true)
	{

		// Waits for keypress to move the snake if debug is true
		if (debug)
		{
			do {
				input = _getch();
			} while (input != 'w' && input != 'a' && input != 's' && input != 'd');
		}

		// Free movement
		//if (GetAsyncKeyState(0x57)) snake.i -= 1; //W
		//if (GetAsyncKeyState(0x53)) snake.i += 1; //S
		//if (GetAsyncKeyState(0x41)) snake.j -= 1; //A
		//if (GetAsyncKeyState(0x44)) snake.j += 1; //D



		// Snake style movement
		if (_kbhit())
		{
			input = _getch();
		}
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
		default:
			break;
		}

		//loop around board
		if (snake.i < 1) snake.i = board.i - 2;
		if (snake.i > board.i - 2) snake.i = 1;
		if (snake.j < 1) snake.j = board.j - 2;
		if (snake.j > board.j - 2) snake.j = 1;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		for (int i = 0; i < board.i; i++)
		{
			for (int j = 0; j < board.j; j++)
			{
				if (j == board.j - 1)
				{
					std::cout << "#\n";
				}
				else if (j == 0)
				{
					std::cout << '#';
				}
				else if (i == 0 || i == board.i -1)
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

		if (debug)
		{
			std::cout << "Snake.i=" << snake.i << " Snake.j=" << snake.j;
		}



		std::this_thread::sleep_for(std::chrono::milliseconds(66));
		//gameloop ends here
	}



}

