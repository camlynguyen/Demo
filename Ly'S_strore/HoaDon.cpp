#include"HoaDon.h"
int _HoaDon::size= sizeof(HoaDon_s);
Bill::Bill(char* Filename) {
	strcpy_s(FileName, Filename);
	fstream f; f.open(FileName, ios::binary | ios::ate|ios::in);
	if (!f.good()) {NumberOfClient = 0; }
	NumberOfClient = f.tellg() / size;
}
void Bill::Create() {
	string as;
	char b[30] = "ThucDon",check;
	int IDFood,D,M,Y,sum=0,ch=0,o=0;
	_ThucDon* TD= new _ThucDon(b);
	fstream f; f.open(FileName, ios::binary | ios::out | ios::app);
	Dulieu.ID = 1010000 + NumberOfClient;
	Dulieu.HinhThucNhanHang == "0";
	Dulieu.PhoneNumber = 0;
	Dulieu.Adress == "0";
	cout << "\nNhap ten khach hang: ";cin.ignore(); cin.get(Dulieu.Nameclient,30);
	cout << "\n";
	TD->Out();
	fstream fe; fe.open(TD->getFileName(), ios::binary | ios::in);
	while (1) {
		IDFood = Check_::TranCharToIn("Nhap ma cua mon an ban muon chon:");
		for (int i = 0; i < TD->getNumber(); i++) {
			fe.seekg(i * sizeof(ThucDon_s), ios::beg);
			fe.read((char*)(&TD->Dulieu), sizeof(ThucDon_s));
			if (IDFood == TD->Dulieu.ID) {
				Dulieu.M[o].Mon = TD->Dulieu.Name;
				Dulieu.M[o].Gia = TD->Dulieu.prices;
				sum += TD->Dulieu.prices; ch++;o++;
			}
			
		}
		if (ch == 0)cout << "Khong co mon nay:";
		cout << "\nNhan ECS de thoat hoc an phim bat ki de tiep tuc:\n"; check = _getch();
		if (check == 27) { break; }
	}
	fe.close();
	do {
		Check_::gotoxy(40, 0); D = Check_::TranCharToIn("Hoa don ngay:"); Check_::gotoxy(55, 0);  cout << "/"; Check_::gotoxy(57, 0); M = Check_::TranCharToIn(""); Check_::gotoxy(60, 0); cout << "/"; Check_::gotoxy(62, 0);   Y = Check_::TranCharToIn("");
	} while (Check_::CheckDate(D, M, Y) == 0);
	Dulieu.Day = D; Dulieu.Mont = M; Dulieu.Year = Y;
	Dulieu.SumPrices = sum;
	f.write((char*)(&Dulieu), size); NumberOfClient++;
	f.close();
}
void Bill::Out() {
	fstream f; f.open(FileName, ios::binary | ios::in );
	cout << "_______________________________________________________________________________\n";
	cout << "|ID KHACH\t" << "TEN KHACH HANG\t" << "\tTONG HOA DON" << "\t\tNGAY HOA DON  |" << endl;
	cout << "-------------------------------------------------------------------------------\n";
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfClient; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		cout << "|" << setw(17) << Dulieu.ID << setw(24) << Dulieu.Nameclient << setw(23) << Dulieu.SumPrices << Dulieu.Day << "/" << Dulieu.Mont << "/" << setw(9) << Dulieu.Year << "|" << endl;
	}
	cout << "-------------------------------------------------------------------------------\n";
	f.close();
}
void Bill::Delete() {
	int check;
	fstream f;
	f.open(FileName, ios::binary | ios::in | ios::out);
	if (!f.good()) {
		cout << "Tep khong co du lieu:";
		cin.get(); return;
	}HoaDon_s DS[100];
	cout.setf(ios::left);
	for (int i = 0; i <NumberOfClient; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		DS[i] = Dulieu;
	}
	f.close();
	do { cout << "Nhap phan tu muon xoa:"; cin >> check; } while (check > NumberOfClient || check < 0);
	int ret = remove(FileName);
	if (ret == 0) {
		cout << "Xoa thanh cong\n";
		fstream fe;
		fe.open(FileName, ios::binary | ios::in | ios::app);
		for (int i = check; i < NumberOfClient; i++) {
			DS[i - 1] = DS[i];
		}NumberOfClient--;
		int j = 0; while (1) {
			fe.write((char*)(&DS[j]), size);  j++;
			if (j >= NumberOfClient)break;
		}
		fe.close();
	}
}
void Bill::find(char* s) {
	fstream f;
	char* ch = new char[30];
	f.open(FileName, ios::binary | ios::out|ios::in);
	if (NumberOfClient == 0) {
		cout << "Tep khong co du lieu:";
		cin.get(); return;
	}
	cout << "_______________________________________________________________________________\n";
	cout << "|ID KHACH\t" << "TEN KHACH HANG\t" << "\tTONG HOA DON" << "\t\tNGAY HOA DON  |" << endl;
	cout << "-------------------------------------------------------------------------------\n";
	cout.setf(ios::left);
	for (int i = 0; i <NumberOfClient; i++) {
		ch == NULL;
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		ch = strstr(Dulieu.Nameclient,s);
		if (ch!=NULL) {
			cout <<"|" << setw(17) << Dulieu.ID << setw(24) << Dulieu.Nameclient << setw(23) << Dulieu.SumPrices << Dulieu.Day << "/" << Dulieu.Mont << "/"<<setw(9) << Dulieu.Year << "|" << endl;
		}
	}
	cout << "-------------------------------------------------------------------------------\n";
	f.close();
}
void Bill::OutF() {
	string Name;
	char Key,*ch=new char[30];
	int x = 10;
	cout << "\tESC: THOAT" << "\t\tSHIFT+3: XOA THONG TIN" << endl;
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
		case 35:
			Out(); Delete(); system("cls");  Out(); _getch(); break;
		default:
			break;
		}
		if (Key == 27) break;
		ch = (char*)Name.c_str();
		system("cls");
		cout << "\tESC: THOAT" << "\t\tSHIFT+3: XOA THONG TIN" << endl;
		cout << "\nTIM KIEM: " << Name; Check_::gotoxy(x + Name.length(), 2);
		cout << endl;
		find(ch);
	}
}
int Bill::Check(int M, int Y) {
	int a=0;
	fstream f; f.open(FileName, ios::binary | ios::in | ios::out);
	for (int i = 0; i < NumberOfClient; i++) {
		f.seekg(i * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		if (Dulieu.Mont == M && Dulieu.Year == Y) {
			a = a + Dulieu.SumPrices;
		}
	}
	return a;
}
void Bill::ChiTietHoaDon() {
	char Sto[30] = "CuaHang";
	Store_s* St = new Store_s(Sto);
	Out();
	int o = 1, b = 0, a, ch = Check_::TranCharToIn("Nhap ID cua chi tiet hoa don:");
	fstream f; f.open(FileName, ios::binary | ios::in|ios::out);
	for (int i = 0; i < NumberOfClient; i++) {
		f.seekg(i*size, ios::beg);
		f.read((char*)(&Dulieu), size);
		if (ch == Dulieu.ID) { a = i; b++; }
	}
	if (b == 0) { cout << "Khong co khach hang nay"; _getch(); return; }
	system("cls");
	f.seekg(a * size, ios::beg);
	f.read((char*)(&Dulieu), size);
	cout << setw(40) << St->GetNameStore() << endl;
	cout << "Ma hoa don:" << Dulieu.ID << endl;
    cout << "Ten khach hang: " << Dulieu.Nameclient << endl;
	cout << "______________________________________________________";
	cout << "\n|STT\t" << "\tTEN MON\t\t" << "\tGIA           |\n";
	cout << "------------------------------------------------------\n";
	for (int i = 0; i < 20; i++) {
		f.seekg(a * size, ios::beg);
		f.read((char*)(&Dulieu), size);
		if (Dulieu.M[i].Gia > 0) {
			cout <<"|"<< o << setw(19) << Dulieu.M[i].Mon << setw(26) << Dulieu.M[i].Gia << setw(8) << "|" << endl;o++;
		}
	}
	
	f.seekg(a * size, ios::beg);
	f.read((char*)(&Dulieu), size);
	cout << "|Tong"<<setw(42) << Dulieu.SumPrices<< setw(8) << "|";
	cout << "\n------------------------------------------------------";
	cout << "\n\nHoa don ngay:" << Dulieu.Day << "/" << Dulieu.Mont << "/" << Dulieu.Year << endl;
	f.close();
	_getch();
}