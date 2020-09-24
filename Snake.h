#pragma once
#include <string>
#include <iostream>
#include <vector>

struct v2int {
	int x;
	int y;
};

//// functions to use with std::sort()
//// example sorting a std::vector<v2int>: 
//// std::sort(someVector.begin(), someVector.end(), sortv2x());
//bool sortv2intx(const v2int& l, const v2int r);
//
//bool sortv2inty(const v2int& l, const v2int r);


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