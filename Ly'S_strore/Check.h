#pragma once
#ifndef  Check_s
#define Check_s
#include<string>
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include<string.h>
#include<cstring>
#include<fstream>
using namespace std;
namespace Check_ {
	int TranCharToIn(string c);
	int CheckDate(int a, int b,int c);
	void gotoxy(int x, int y);
	void SET_COLOR(int color);
}
#endif // ! Check_s

