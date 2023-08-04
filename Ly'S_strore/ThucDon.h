#pragma once
#ifndef ThucDon_
#define ThucDon_
#include"Check.h"
#include<vector>
struct ThucDon_s {
	char Name[30];
	int prices,ID;
};
class _ThucDon {
protected:
	static int size;
	char FileName[30];
	int NumberOfFF;
public:
	int getNumber();
	_ThucDon(char*FileName);
    ThucDon_s Dulieu;
	void In();
	void Out();
	void Change();
	void Delete();
	void Find(char *a);
	void OutF();
	char* getFileName();
};
#endif // !ThucDon_

