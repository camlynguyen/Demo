#pragma once
#ifndef store
#define store_h
#include<iostream>
#include<string.h>
#include<conio.h>
#include<cstring>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
struct Store {
	char NameOfStore[30];
	int Luong, BanGhe,CaLam;
};
class Store_s {
public:
	char FileName[30];static int size;
	int Num;
    Store Dulieu;
	Store_s(char *fn);
	void In();
	void Out();
	int getCalam();
	int GetLuong();
	char* GetNameStore();

};
#endif // !store

