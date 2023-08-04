#include"In4Store.h"
int Store_s::size = sizeof(Store);
Store_s::Store_s(char* Fn) {
	strcpy_s(FileName, Fn);
	fstream f; f.open(FileName, ios::binary | ios::in | ios::ate);
	if (!f.good()) Num = 0;
	Num = f.tellg() / size;
}

void Store_s::In() {
	char a[10],b[10],c[10],d[10],k[5],ch[5];
	int as, bs, cs, C; Store D;
	if (Num == 0) {
		fstream f; f.open(FileName, ios::binary | ios::out | ios::app);
		cin.ignore();
		cout << "Ten cua hang:"; cin.get(D.NameOfStore, 30);
		do {
			cout << "Luong/h: "; cin >> a;
			as = atoi(a);
		} while (as == 0);
		do {
			cout << "Thoi gian 1 ca: "; cin >> b;
			bs = atoi(b);
		} while (bs == 0);
		do {
			cout << "So luong ban ghe cua cua hang:"; cin >> c;
			cs = atoi(c);
		} while (cs == 0);
		D.CaLam = bs;
		D.BanGhe = cs;
		D.Luong = as;
		f.write((char*)(&D), size); Num=1;
		f.close();
	}
	else {
		do { cout << "Thong tin cua hang da ton tai ban co muon thay doi no khong (Y/N):"; cin >> ch; } while (strcmp(ch, "Y") != 0 && strcmp(ch, "N") != 0);
		if (strcmp(ch, "Y") == 0) {
			fstream f; f.open(FileName, ios::binary | ios::out | ios::in);
			f.seekg(0, ios::beg);
			f.read((char*)(&Dulieu), size);
			f.seekg(-size, ios::cur);
			cin.ignore();
			cout << "Ten cua hang:"; cin.get(D.NameOfStore, 30);
			do {
				cout << "Luong/h: "; cin >> a;
				as = atoi(a);
			} while (as == 0);
			do {
				cout << "Thoi gian 1 ca: "; cin >> b;
				bs = atoi(b);
			} while (bs == 0);
			do {
				cout << "So luong ban ghe cua cua hang:"; cin >> c;
				cs = atoi(c);
			} while (cs == 0);
			D.CaLam = bs;
			D.BanGhe = cs;
			D.Luong = as;
			f.write((char*)(&D), size);
			f.close();
		}
		if (strcmp(ch, "N") == 0) return;
	}
	
}
void Store_s::Out() {
	fstream f; f.open(FileName, ios::binary |ios::in);
	cout << "______________________________________________________________________________________________\n";
	cout << "| TEN CUA HANG\t\t" << "LUONG/h" << "\t\tSO h LAM VIEC/CA" << "\t\tSO LUONG BAN GHE      |\n";
	cout << "______________________________________________________________________________________________\n";
	f.seekg(0,ios::beg);
	f.read((char*)(&Dulieu), size);
	cout << "| " << setw(15) << Dulieu.NameOfStore << setw(15) << Dulieu.Luong << setw(12) << Dulieu.CaLam << setw(32) << Dulieu.BanGhe << setw(20)<<"|\n";
	cout << "______________________________________________________________________________________________\n";
	_getch();
	f.close();
}
int Store_s::GetLuong() {
	fstream f; f.open(FileName, ios::binary | ios::in);
	f.seekg(0, ios::beg);
	f.read((char*)(&Dulieu), size);
	f.close();
	return Dulieu.Luong;
}
int Store_s::getCalam() {
	fstream f; f.open(FileName, ios::binary | ios::in);
	f.seekg(0, ios::beg);
	f.read((char*)(&Dulieu), size);
	f.close();
	return Dulieu.CaLam;
}
char*Store_s::GetNameStore() {
	fstream f; f.open(FileName, ios::binary | ios::in);
	f.seekg(0, ios::beg);
	f.read((char*)(&Dulieu), size);
	f.close();
	return Dulieu.NameOfStore;
}