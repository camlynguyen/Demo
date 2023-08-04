#pragma a
#ifndef Job_h
#define Job_h
#include"In4Store.h"
struct JOB {
	int PhoneNumber, Salary, DayWork,Age,ID,Day,Month,Year,TR;
	char Name[30], Address[30];
};
class JOB_s {
private:
	JOB Dulieu;
	static int size;
	char FileName[30],FileNameS[30];
	int NumberOfJob;
public:
	JOB_s(char* Fn,char*FnS);
	~JOB_s();
	void In();
	void Change();
	void Delete();
	void Out();
	void find(char*s);
	void OutF();
	void TraLuong();
	void ChamCong();
	int Check(int M, int Y);
};
#endif // !Job_h

