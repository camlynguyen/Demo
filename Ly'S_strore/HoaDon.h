#pragma once
#ifndef HoaDon_
#define HoaDon_
#include"Check.h"
#include"ThucDon.h"
#include"In4Store.h"
struct Mon {
	int Gia;
	string Mon;
};
struct HoaDon_s {
	Mon M[20];
	char Nameclient[30];
	int SumPrices, ID, Day, Mont, Year,PhoneNumber;
	char Adress[30];
	char HinhThucNhanHang[30];
};
class _HoaDon {
protected:
	HoaDon_s Dulieu;
	char FileName[30];
	static int size;
	int NumberOfClient;
public:
	virtual void Create()=0;
	virtual void Out()=0;
	virtual void Delete()=0;
	virtual void find(char* Name)=0;
	virtual void OutF()=0;
	virtual int Check(int a,int b)=0;
	virtual void ChiTietHoaDon()=0;
};
class Bill:public _HoaDon {
public:
	Bill(char* Filename);
	void Create();
	void Out();
	void Delete();
	void find(char* Name);
	void OutF();
	int Check(int a, int b);
	void ChiTietHoaDon() ;
};
class BillShip:public _HoaDon{
public:
	BillShip(char* filename);
	void Create();
	void Out();
	void Delete();
	void find(char* Name);
	void OutF();
	int Check(int a, int b);
	void ChiTietHoaDon() ;
};
#endif // !HoaDon_

