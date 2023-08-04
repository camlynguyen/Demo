#include"Check.h"
void Check_::gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
int Check_::CheckDate(int a, int b, int c) {
	if (a > 31 | a < 0) return 0;
	if (b > 12 | b < 0)  return 0;
	if (c > 2021 | c < 2000) return 0;
	switch (b)
	{
	case 4:case 6:case 9:case 11:
		if (a > 30) return 0; break;
	case 2:
		if (c % 4 == 0) {
			if (a > 29) return 0; break;
		}
		if (c % 4 != 0) {
			if (a > 28)return 0; break;
		}
	default:
		break;
	}
	return 1;
}
int Check_::TranCharToIn(string v) {
	char a[12]; int b;
	do {
		cout << v;
		cin >> a;
		b = atoi(a);
	} while (b == 0);
	return b;
}
void Check_::SET_COLOR(int color)
{
	WORD wColor;


	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}