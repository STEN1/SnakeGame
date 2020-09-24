#pragma once
#include <string>
#include <iostream>
#include <vector>

struct v2int {
	int x;
	int y;
};


bool v2intVectorMatch(int x, int y, std::vector<v2int>);


void setApples();

char snakeSplash[6][27]
{
	{"           /^\\\/^\\\        \n"},
	{"         _|__|  O|\\      \n"},
	{"\\\/     /~     \\\_/ \\\      \n"},
	{" \\\____|__________/  \\\    \n"},
	{"        \\\_______      \\\  \n"},
	{"                `\\\     \\\ \n"}

};