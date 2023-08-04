#include"ThucDon.h"
int _ThucDon::size = sizeof(ThucDon_s);
_ThucDon::_ThucDon(char* Filename) {
	strcpy_s(FileName, Filename);
	fstream f; f.open(FileName, ios::ate | ios::binary|ios::in);
	if (!f.good()) { NumberOfFF = 0; }
	NumberOfFF = (f.tellg() / size);
	f.close();
}
int _ThucDon::getNumber() {
	return NumberOfFF;
}
void _ThucDon::In() {
	char a; string TD;
	int ai,check;
	fstream f; f.open(FileName, ios::binary | ios::out | ios::app);
	while (1) {
		system("cls");
		cout << "Nhap ten mon an:";cin.ignore();
		cin.get( Dulieu.Name,30);
		do {
			check = 0;
			ai = Check_::TranCharToIn("Ma cua mon: ");
			for (int i = 0; i < NumberOfFF; i++) {
				if (ai == Dulieu.ID)check++;
			}
		} while (check == 1);
		Dulieu.ID = ai;
		Dulieu.prices = Check_::TranCharToIn("Gia :");
		f.write((char*)(&Dulieu), size); NumberOfFF++;
		cout << "Ban co muon nhap mon khac khong (Nhan ESC de thoat hoac nhan phim bat ki de tiep tuc):"; a = _getch();
		if (a == 27) break;
	}
	f.close();
}
void _ThucDon::Out() {
	fstream f; f.open(FileName, ios::in | ios::binary);
	cout << "_________________________________________________\n";
	cout << "| ID" << "\t\tTEN MON\t\t" << "GIA\t\t|" << endl;
	cout << "-------------------------------------------------\n";
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfFF; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		cout <<"| " <<setw(16) << Dulieu.ID   << setw(15) << Dulieu.Name << setw(15) << Dulieu.prices <<"|"<< endl;
	}
	cout << "-------------------------------------------------\n";
	f.close();
}
void _ThucDon::Change() {
	fstream f; f.open(FileName, ios::in | ios::out | ios::binary | ios::app);
	char check[10]; int a,checks,n;
	string TD;
	a=Check_::TranCharToIn("Nhap ID muon thay doi:");
	for (int i = 0; i < NumberOfFF; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		if(a==Dulieu.ID){
			n = i;
			}
		}
	f.seekg(n+1 * size, ios::beg);
	f.read((char*)(&Dulieu), size);
	f.seekg(-size, ios::cur);
	cin.ignore();
	cout << "Nhap ten mon an:"; cin.get(Dulieu.Name,30);
	Dulieu.prices = Check_::TranCharToIn("Gia :");
	f.write((char*)(&Dulieu), size);
	f.close();
}
void _ThucDon::Delete() {
	fstream f; f.open(FileName, ios::in | ios::out | ios::binary);
	int a,j=0;
	ThucDon_s DS[100];
	a=Check_::TranCharToIn("Nhap ID muon sua:");
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfFF; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		if (a != Dulieu.ID) { DS[j] = Dulieu; j++; }
	}NumberOfFF--;
	f.close();
	int re = remove(FileName);
	fstream fe; fe.open(FileName, ios::binary | ios::out | ios::app);
	for (int i = 0; i < NumberOfFF; i++) {
		f.write((char*)(&DS[i]), size);
	}
	fe.close();
}
void _ThucDon::Find(char* s) {
	fstream f; char*sl=new char[30];
	f.open(FileName, ios::binary | ios::in | ios::out);
	if (NumberOfFF == 0) {
		cout << "Tep khong co du lieu:";
		cin.get(); return;
	}
	cout << "  ID" << "\tTen mon\t" << "Gia\t" << "Nguyen Lieu\t\t" << endl;
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfFF; i++) {
		sl == NULL;
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		sl = strstr(Dulieu.Name,s);
		if (sl!=NULL) {
			cout << setw(9) << Dulieu.ID << setw(12) << Dulieu.Name << setw(8) << Dulieu.prices << endl;
		}
	}
	f.close();
}
void _ThucDon::OutF() {
	string Name;
	char Key,*ch=new char [30];
	int x = 10;
	cout << "\tESC: THOAT" << "\t SHIFT+2 THAY DOI THONG TIN\t\t" << "SHIFT+3: XOA THONG TIN" << endl;
	cout << "\nTIM KIEM: \n"; Out(); Check_::gotoxy(10, 2);
	while (1) {
		Key = _getch(); system("cls");
		if (Key != 27 && Key != 8) { Name += Key; }
		if (Key == 8) {
			if (Name.length() > 0) {
				Name.pop_back();
			}
			else {}
		}
		switch (Key)
		{
		case 64:
			Out(); Change(); Out(); _getch(); break;
		case 35:
			Out(); Delete(); system("cls");  Out(); _getch(); break;
		default:
			break;
		}
		if (Key == 27) break;
		ch = (char*)Name.c_str();
		system("cls");
		cout << "\tESC: THOAT" << "\t\t SHIFT+2: THAY DOI THONG TIN\t\t" << "SHIFT+3: XOA THONG TIN" << endl;
		cout << "\nTIM KIEM: " << Name; Check_::gotoxy(x +Name.length(), 2);
		cout << endl;
		Find(ch);
	}
}
char* _ThucDon::getFileName() {
	return FileName;
}
