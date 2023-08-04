#pragma once
#ifndef NguyenLieu_
#define NguyenLieu_
#include"Job.h"
#include"Check.h"
using namespace std;
struct Mate {
	char NameMaterial[30];
	int PricePerQuantity, Price, NumberMa, Day, Month, Year, IdHistoryTran;
};
class material {
private:
	Mate DulieuMa;
	char FileNameMa[30];
	static int sizeMa;
	int NumberOfMa;
public:
	material(char* filenameMa);
	void Input();
	void Ouput();
	void ChangeMa();
	void DeteleMa();
	int SapXep();
	void Find(char* Name);
	void OutF();
	int Check(int M, int Y);
};
#endif

