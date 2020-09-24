#include <iostream>
#include <string>
#include "Snake.h"
#include <conio.h>
#include "ConsoleHelp.h"
#include <Windows.h>
#include <chrono>
#include <thread>
#include <time.h>
#include <vector>

v2int snake{ 5, 5 };
v2int board{ 20, 40 };
char input{ '0' };
char lastInput{ 'd' };
COORD cur{ 0, 0 };
std::vector<v2int> snakeBody;
std::vector<v2int> apples;
int numberOfApples{ 2 };

bool debug = false;

int main() 
{
	std::srand(time(NULL));
	while (true) 
	{
		snake = { 5,5 };
		snakeBody.clear();
		apples.clear();
		system("cls");
		for (int x = 0; x < 6; x++)
		{
			for (int y = 0; y < 27; y++)
			{
				std::cout << ch::colorText(snakeSplash[x][y], 32);
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
			// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

			//if (GetAsyncKeyState(0x57)) snake.x -= 1; //W
			//if (GetAsyncKeyState(0x53)) snake.x += 1; //S
			//if (GetAsyncKeyState(0x41)) snake.y -= 1; //A
			//if (GetAsyncKeyState(0x44)) snake.y += 1; //D

			// push old snake pos in to snake body
			snakeBody.push_back(snake);

			// remove first element in snakebody if the body is larger than 2
			if (snakeBody.size() > 2)
			{
				snakeBody.erase(snakeBody.begin());
			}


			// Snake style movement

			lastInput = input;

			// Check if a character is in the stream
			if (_kbhit())
			{
				//input that character to input
				input = _getch();
			}

			// If the input is not valid, input is changed to the last valid input
			if (input != 'w' && input != 's' && input != 'a' && input != 'd')
			{
				input = lastInput;
			}

			switch (input)
			{
			case 'w':
				snake.x -= 1;
				break;
			case 'a':
				snake.y -= 1;
				break;
			case 's':
				snake.x += 1;
				break;
			case 'd':
				snake.y += 1;
				break;
			default:
				break;
			}

			// check for collision with body
			if (v2intVectorMatch(snake.x, snake.y, snakeBody))
			{
				system("cls");
				std::cout << "Score: " << snakeBody.size();
				_getch();
				break;

			}
			// lose game screen

			// debug extend body
			// press x to push current pos into snakeBody
			if (GetAsyncKeyState(0x58)) snakeBody.push_back(snake);

			// eat and extend if the head hits an apple
			if (v2intVectorMatch(snake.x, snake.y, apples))
			{
				snakeBody.push_back(snake);
				for (int i = 0; i < apples.size(); i++)
				{
					if (apples[i].x == snake.x && apples[i].y == snake.y)
					{
						apples.erase(apples.begin() + i);
						break;
					}
				}
			}

			// Create apples
			setApples();

			//loop around board
			if (snake.x < 1) snake.x = board.x - 2;
			if (snake.x > board.x - 2) snake.x = 1;
			if (snake.y < 1) snake.y = board.y - 2;
			if (snake.y > board.y - 2) snake.y = 1;

			// faster than system("cls")
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

			for (int x = 0; x < board.x; x++)
			{
				for (int y = 0; y < board.y; y++)
				{
					if (y == board.y - 1)
					{
						std::cout << "#\n";
					}
					else if (y == 0)
					{
						std::cout << '#';
					}
					else if (x == 0 || x == board.x - 1)
					{
						std::cout << '#';
					}
					else if (snake.x == x && snake.y == y)
					{
						//print snake head
						std::cout << ch::colorText('@', 31);
					}
					else if (v2intVectorMatch(x, y, snakeBody))
					{
						//print snake body
						std::cout << "#";
					}
					else if (v2intVectorMatch(x, y, apples))
					{
						//print apple
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
				std::cout << "Snake.x=" << snake.x << " Snake.y=" << snake.y;
			}
			std::cout << numberOfApples << " " << apples.size();

			// slowing down the game
			std::this_thread::sleep_for(std::chrono::milliseconds(66));
		}
	}


}

bool v2intVectorMatch(int _x, int _y, std::vector<v2int> _v2Vector)
{

	for (int i = 0; i < _v2Vector.size(); i++)
	{
		if (_v2Vector[i].x == _x && _v2Vector[i].y == _y)
		{
			return true;
		}
	}
	return false;
}

void setApples()
{
	if (apples.size() >= numberOfApples)
	{
		return;
	}

	v2int _vrand;

	if (apples.size() < numberOfApples)
	{
		int _xrand = rand() % (board.x - 2) + 1;
		int _yrand = rand() % (board.y - 2) + 1;
		_vrand = { _xrand, _yrand };
		apples.push_back(_vrand);
	}
}

