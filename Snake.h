#pragma once
#include <string>
#include <iostream>



struct Snake {
	int i;
	int j;
};

struct Board {
	int i;
	int j;
};

char snakeSplash[6][50]
{
	{"           /^\\\/^\\\ \n"},
	{"         _|__|  O|\\ \n"},
	{"\\\/     /~     \\\_/ \\\ \n"},
	{" \\\____|__________/  \\\ \n"},
	{"        \\\_______      \\\ \n"},
	{"                `\\\     \\\ \n"}

};