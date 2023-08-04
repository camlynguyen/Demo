#include "Job.h"
#include"Check.h"
int JOB_s::size = sizeof(JOB);
JOB_s::JOB_s(char* Fn,char*Fns) {
	strcpy_s(FileNameS, Fns);
	strcpy_s(FileName, Fn);
	fstream f; f.open(FileName, ios::binary | ios::ate | ios::in);
	NumberOfJob = f.tellg() / size;
	if (!f.good()) { NumberOfJob = 0; }
}
JOB_s::~JOB_s() {
	cout << "Hoan Thanh";
}
void JOB_s::In() {
	char check;
	int as, bs, cs, ds,es;
	Store_s* St = new Store_s(FileNameS);
	fstream f; f.open(FileName, ios::binary | ios::out | ios::app);
	while (1) {
		system("cls");
		cin.ignore();
		cout << "Nhap ten: "; cin.get(Dulieu.Name, 30);
		as=Check_::TranCharToIn("Nhap ID: ");
		cin.ignore();
		cout << "Nhap dia chi: "; cin.get(Dulieu.Address, 30);
		ds = Check_::TranCharToIn("Nhap Tuoi:");
		bs = Check_::TranCharToIn("Nhap SDT:");
		es = Check_::TranCharToIn("Nhap so ca lam viec:");
		Dulieu.ID = as; Dulieu.Age = ds; Dulieu.DayWork = es; Dulieu.PhoneNumber = bs;
		Dulieu.Salary = St->Dulieu.Luong * Dulieu.DayWork;
		Dulieu.Day = Dulieu.Month = Dulieu.Year = 0;
		Dulieu.TR = 0;
		f.write((char*)(&Dulieu), size); NumberOfJob++;
		cout << "Nhan ESC de thoat hoac nhan phim bat ki de tiep tuc:";
		check = _getch();
		if (check == 27) break;
	}
	f.close();
}
void JOB_s::Change() {
	int a,as,bs,ds,es,ch=0;
	Store_s* St = new Store_s(FileNameS);
	fstream f; f.open(FileName, ios::binary | ios::in | ios::out);
	a=Check_::TranCharToIn("Nhap ID muon thay doi:");
	for (int i = 0; i < NumberOfJob; i++) {
		f.seekg(size * i, ios::beg);
		f.read((char*)(&Dulieu), size);
		if (Dulieu.ID == a) {
			ch++;
			f.seekg(-size, ios::cur);
			cin.ignore();
			cout << "Nhap ten: "; cin.get(Dulieu.Name, 30);
			as = Check_::TranCharToIn("Nhap ID");
			cin.ignore();
			cout << "Nhap dia chi: "; cin.get(Dulieu.Address, 30);
			ds = Check_::TranCharToIn("Nhap Tuoi:");
			bs = Check_::TranCharToIn("Nhap SDT:");
			es = Check_::TranCharToIn("Nhap so ca lam viec:");
			Dulieu.ID = as; Dulieu.Age = ds; Dulieu.DayWork = es; Dulieu.PhoneNumber = bs;
			Dulieu.Salary = St->Dulieu.Luong * Dulieu.DayWork;
			Dulieu.Day = Dulieu.Month = Dulieu.Year = 0;
			f.write((char*)(&Dulieu), size);
		}
	}
	if (ch == 0) { cout << "Nothing\n"; }
	f.close();
}
void JOB_s::Delete() {
	int check, a;
	fstream f;
	cout << "Nhap ID phan tu muon xoa:"; cin >> check;
	f.open(FileName, ios::binary | ios::in | ios::out);
	if (NumberOfJob == 0) {
		cout << "Tep khong co du lieu:";
		cin.get(); return;
	}JOB DS[100];
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfJob; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		DS[i] = Dulieu;
		if (DS[i].ID == check) a = i;
	}
	f.close();


	int ret = remove(FileName);
	if (ret == 0) {
		for (int i = a + 1; i < NumberOfJob; i++) {
			DS[i - 1] = DS[i];
		}NumberOfJob--;
		fstream fe;
		fe.open(FileName, ios::binary | ios::in | ios::app);
		for (int j = 0; j < NumberOfJob; j++) {
			fe.write((char*)(&DS[j]), size);
		}
		fe.close();
	}
}
void JOB_s::Out() {
	Store_s* St = new Store_s(FileNameS);
	fstream f;
	f.open(FileName, ios::binary | ios::in|ios::out);
	cout << "________________________________________________________________________________________________________________\n";
	cout << "| ID\t\t" <<"NAME\t\t"<<"\tADDRESS\t\t"<<"NUMBER\t\t"<<"SALARY\t\t"<<"SHIFT\t\t"<<"AGE\t|"<< endl;
	cout << "________________________________________________________________________________________________________________\n";
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfJob; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		f.seekg(-size, ios::cur);
		Dulieu.Salary = St->GetLuong() * Dulieu.DayWork;
		f.write((char*)(&Dulieu), size);
		if (Dulieu.TR == 0) {
			cout <<"| "<< setw(16) << Dulieu.ID << setw(23) << Dulieu.Name << setw(16) << Dulieu.Address << setw(16) << Dulieu.PhoneNumber << setw(19) << Dulieu.Salary << setw(13) << Dulieu.DayWork <<setw(7)<<Dulieu.Age <<"|" << endl;
		}
		else { cout << ""; };
	}
	cout << "________________________________________________________________________________________________________________\n";
	f.close();
}
void JOB_s::find(char*s) {
	fstream f;
	f.open(FileName, ios::binary | ios::in | ios::out);
	if (NumberOfJob == 0) {
		cout << "Tep khong co du lieu:";
		cin.get(); return;
	}
	cout << "________________________________________________________________________________________________________________\n";
	cout << "| ID\t\t" << "NAME\t\t" << "\tADDRESS\t\t" << "NUMBER\t\t" << "SALARY\t\t" << "SHIFT\t\t" << "AGE\t|" << endl;
	cout << "________________________________________________________________________________________________________________\n";
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfJob; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		
		if ( Dulieu.TR == 0&& strstr( Dulieu.Name,s)!= NULL) {
			cout << "| " << setw(16) << Dulieu.ID << setw(23) << Dulieu.Name << setw(16) << Dulieu.Address << setw(16) << Dulieu.PhoneNumber << setw(19) << Dulieu.Salary << setw(13) << Dulieu.DayWork << setw(7) << Dulieu.Age << "|" << endl;
		}
	}
	cout << "________________________________________________________________________________________________________________\n";
	f.close();
}
void JOB_s::OutF() {
	char* ch=new char[30];
	string Name;
	char Key;
	int x = 10;
	cout << "\tESC: THOAT" << "\t SHIFT+2 THAY DOI THONG TIN\t\t" << "SHIFT+3: XOA THONG TIN" << endl;
	cout << "\nTIM KIEM: \n"; Out(); Check_::gotoxy(10, 2);
	while (1) {
		Key = _getch(); system("cls");
		if (Key != 27 ) { Name += Key; }
		if (Key == 8) {
			if (Name.length() > 1) {
				Name.pop_back(); Name.pop_back();
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
		cout << "\tESC: THOAT" << "\t SHIFT+2: THAY DOI THONG TIN\t\t" << "SHIFT+3: XOA THONG TIN" << endl;
		cout << "\nTIM KIEM: " << ch; Check_::gotoxy(x + strlen(ch), 2);
		cout << endl;
		find(ch);
	}
}
void JOB_s::TraLuong() {
	int check,a,D,M,Y;
	Out();
	check = Check_::TranCharToIn("Nhap ID nhan vien muon tra luong:");
	do {
		Check_::gotoxy(0, 20); D = Check_::TranCharToIn("Tra luong ngay:"); Check_::gotoxy(16, 20);  cout << "/"; Check_::gotoxy(18, 20); M = Check_::TranCharToIn(""); Check_::gotoxy(21,20); cout << "/"; Check_::gotoxy(23, 20);   Y = Check_::TranCharToIn("");
	} while (Check_::CheckDate(D, M, Y) == 0);
	JOB DS;
	fstream f; f.open(FileName, ios::binary | ios::out | ios::in);
	for (int i = 0; i < NumberOfJob; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		if (check == Dulieu.ID&&Dulieu.TR==0) { 
			a = i;
			DS.Address == Dulieu.Address; DS.TR = 1;
			DS.Age = Dulieu.Age; DS.Day = D; DS.Month = M; DS.Year = Y; DS.DayWork = Dulieu.DayWork; DS.ID = Dulieu.ID; DS.PhoneNumber = Dulieu.PhoneNumber; DS.Salary = Dulieu.Salary;;
		}
	}
	f.write((char*)(&DS), size); NumberOfJob++;
	f.seekg(a * size, ios::beg);
	f.read((char*)(&Dulieu), size);
	f.seekg(-size, ios::cur);
	Dulieu.DayWork = 0;
	f.write((char*)(&Dulieu), size);
	f.close();
}
void JOB_s::ChamCong() {
	Out();
	Store_s* St = new Store_s(FileNameS);
	int a, ch = 0;
	fstream f; f.open(FileName, ios::binary | ios::in | ios::out);
	int c; cout << "Nhap ID cua nguoi muon diem danh:"; cin >> c;
	for (int i = 0; i < NumberOfJob; i++) {
		f.seekg((i * size), ios::beg);
		f.read((char*)(&Dulieu), size);
		if (c == Dulieu.ID ) { ch++; a = i; }
	}
	if (ch == 0) return;
	f.seekg((a)*size, ios::beg);
	f.read((char*)(&Dulieu), size);
	f.seekg(-size, ios::cur);
	Dulieu.DayWork = Dulieu.DayWork + St->getCalam();
	Dulieu.Salary = St->GetLuong() * Dulieu.DayWork;
	f.write((char*)(&Dulieu), size);
	f.close();
	Out(); _getch();
}
int JOB_s::Check(int M, int Y) {
	int a = 0;
	fstream f; f.open(FileName, ios::binary | ios::in|ios::out);
	for (int i = 0; i < NumberOfJob; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		if (Dulieu.Month == M && Dulieu.Year == Y&&Dulieu.TR==1) {
	
			a +=Dulieu.Salary;
		}
	}
	f.close();return a;
}