#include"NguyenLieu.h"
#include<cctype>
#include<iomanip>
using namespace std;
int material::sizeMa = sizeof(Mate);
material::material(char* fileNameMa) {
	strcpy_s(FileNameMa, fileNameMa);
	if (FileNameMa == NULL)return;
	fstream f; f.open(FileNameMa, ios::binary | ios::in | ios::ate);
	NumberOfMa = (f.tellg()) / sizeMa;
	if (!f.good()) NumberOfMa = 0;
	f.close();
}
void material::Input() {
	fstream f; char ch;
	int a, b, k;
	f.open(FileNameMa, ios::binary | ios::out | ios::app );
	while (1) {
		int x = 3, o = 0;
		system("cls");
		cout.setf(ios::left);
		do {
			x++; k = Check_::TranCharToIn("Nhap ID giao dich:");
			o = 0;
			cout.setf(ios::left);
			for (int i = 0; i < NumberOfMa; i++) {
				f.seekg(i * sizeMa, ios::beg);
				f.read((char*)(&DulieuMa), sizeMa);
				if (k == DulieuMa.IdHistoryTran) { o++; }
			}
		} while (o != 0);
		DulieuMa.IdHistoryTran = k;
		cin.ignore(1);
		cout << "Nhap ten nguyen vat lieu :"; cin.get(DulieuMa.NameMaterial, 30);
		a = Check_::TranCharToIn("Nhap gia ca tren mot don vi san pham :"); DulieuMa.PricePerQuantity = a;
		b = Check_::TranCharToIn("Nhap so luong nhap:"); DulieuMa.NumberMa = b;
		cout << "Nhap ngay dien ra giao dich:"; cin >> DulieuMa.Day; Check_::gotoxy(30, x); cout << "/";
		Check_::gotoxy(31, x); cin >> DulieuMa.Month; Check_::gotoxy(33, x); cout << "/";
		Check_::gotoxy(34, x); cin >> DulieuMa.Year;
		DulieuMa.Price = DulieuMa.NumberMa * DulieuMa.PricePerQuantity;

		f.write((char*)(&DulieuMa), sizeMa); ++NumberOfMa;
		cout << "Nhan ESC de thoat hoac an phim bat ki de tiep tuc:"; ch = _getch();
		if (ch == 27) break;
	}
	f.close();
}
void material::DeteleMa() {
	int check;
	fstream f;
	f.open(FileNameMa, ios::binary | ios::in | ios::out);
	if (!f.good()) {
		cout << "Tep khong co du lieu:";
		cin.get(); return;
	}Mate DS[100];
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfMa; i++) {
		f.seekg(i * sizeMa, ios::beg);
		f.read((char*)(&DulieuMa), sizeMa);
		DS[i] = DulieuMa;
	}
	f.close();
	do { cout << "Nhap phan tu muon xoa:"; cin >> check; } while (check > NumberOfMa || check < 0);
	int ret = remove(FileNameMa);
	if (ret == 0) {
		cout << "Xoa thanh cong\n";
		fstream fe;
		fe.open(FileNameMa, ios::binary | ios::in | ios::app);
		for (int i = check; i < NumberOfMa; i++) {
			DS[i - 1] = DS[i];
		}NumberOfMa--;
		int j = 0; while (1) {
			fe.write((char*)(&DS[j]), sizeMa);  j++;
			if (j >= NumberOfMa)break;
		}
		fe.close();
	}
}
void material::ChangeMa() {
	fstream f; int n;
	int x = 4, o = 0, k, a, b;
	f.open(FileNameMa, ios::binary | ios::in | ios::out);
	if (!f.good()) {
		cout << "Tep khong co du lieu:"; cin.get(); return;
	}
	cout << "Nhap so thu tu muon sua:"; cin >> n;
	cin.ignore(1);
	if (n<0 || n>NumberOfMa) {
		cout << "So thu tu khong hop le!!!!!!"; cin.get();
		return;
	}system("cls");

	cout << "Nhap ID lich su giao dich :"; cin >> k;
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfMa; i++) {
		f.seekg(i * sizeMa, ios::beg);
		f.read((char*)(&DulieuMa), sizeMa);
		if (DulieuMa.IdHistoryTran == k) { o++; x++; }
	}
	if (o != 0)do {
		cout << "Nhap ID lich su giao dich :"; cin >> k;
		o = 0;
		cout.setf(ios::left);
		for (int i = 0; i < NumberOfMa; i++) {
			f.seekg(i * sizeMa, ios::beg);
			f.read((char*)(&DulieuMa), sizeMa);
			if (k == DulieuMa.IdHistoryTran) { o++; x++; }
		}
	} while (o != 0);
	f.seekg((n - 1) * sizeMa, ios::beg);
	f.read((char*)(&DulieuMa), sizeMa);
	f.seekg(-sizeMa, ios::cur);
	DulieuMa.IdHistoryTran = k; cin.ignore(1);
	cout << "Nhap ten nguyen vat lieu :"; cin.get(DulieuMa.NameMaterial, 30);
	a = Check_::TranCharToIn("Nhap gia ca tren mot don vi san pham :"); DulieuMa.PricePerQuantity = a;
	b = Check_::TranCharToIn("Nhap so luong nhap:"); DulieuMa.NumberMa = b;
	cout << "Nhap ngay dien ra giao dich:"; cin >> DulieuMa.Day; Check_::gotoxy(30, x); cout << "/";
	Check_::gotoxy(31, x); cin >> DulieuMa.Month; Check_::gotoxy(33, x); cout << "/";
	Check_::gotoxy(34, x); cin >> DulieuMa.Year;
	DulieuMa.Price = DulieuMa.NumberMa * DulieuMa.PricePerQuantity;
	f.write((char*)(&DulieuMa), sizeMa);
	f.close();
}
void material::Ouput() {
	fstream f;
	f.open(FileNameMa, ios::binary | ios::in | ios::out);
	if (NumberOfMa == 0) {
		cout << "Tep khong co du lieu:\n";
		cin.get(); return;
	}
	cout << "__________________________________________________________________________________________________________\n";
	cout << "|_______________________________________BANG LICH SU GIAO DICH___________________________________________|\n";
	cout << " [ STT ] [ Ten vat lieu ]  [ ID giao dich ]  [ So luong ]  [Gia/DVSP]  [     Gia     ]  [ Thoi gian nhap ]\n";
	cout << " |=======================================================================================================|\n";
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfMa; i++) {
		f.seekg((i)*sizeMa, ios::beg);
		f.read((char*)(&DulieuMa), sizeMa);
		cout << " [ " << i + 1 << "\t" << setw(17) << DulieuMa.NameMaterial << "\t" << setw(10) << DulieuMa.IdHistoryTran << "\t " << setw(7) << DulieuMa.NumberMa << "\t" << setw(7) << DulieuMa.PricePerQuantity << "\t" << setw(18) << DulieuMa.Price << DulieuMa.Day << "/" << DulieuMa.Month << "/" << DulieuMa.Year << "\t ]" << endl;
	}
	cout << " [=======================================================================================================]\n";
	f.close();
}
int material::SapXep() {
	int check;
	int a = 0;
	fstream f;
	f.open(FileNameMa, ios::binary | ios::in | ios::out);
	if (!f.good()) {
		cout << "Tep khong co du lieu:";
		cin.get(); return 0;
	}Mate DS[100];
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfMa; i++) {
		f.seekg(i * sizeMa, ios::beg);
		f.read((char*)(&DulieuMa), sizeMa);
		DS[i] = DulieuMa;
	}
	f.close();
	int i, j, k;
	for (i = 0; i < NumberOfMa - 1; i++) {
		j = i + 1;
		while (j < NumberOfMa)
			if (strcmp(DS[i].NameMaterial, DS[j].NameMaterial) == 0) {
				DS[i].Price = DS[j].Price + DS[i].Price;
				DS[i].NumberMa = DS[j].NumberMa + DS[i].NumberMa;
				for (k = j; k < NumberOfMa - 1; k++) {

					DS[k] = DS[k + 1];
				}
				NumberOfMa--;
			}
			else j = j + 1;
	}
	cout << ">_____________________________________________________________________<\n";
	cout << " {______________________DANH SACH NGUYEN VAT LIEU_____________________}\n";
	cout << " | STT ]  [ Ten vat lieu ]   [     Gia thanh      ]   [    So luong   |\n";
	cout << " {====================================================================}\n";
	for (int i = 0; i < NumberOfMa; i++) {
		cout << " [ " << setw(3) << i + 1 << "\t| " << setw(10) << DS[i].NameMaterial << "\t   |  " << setw(15) << DS[i].Price << "\t   | " << setw(11) << DS[i].NumberMa << "      ]" << endl;
		a = a + DS[i].Price;
	}
	cout << " {====================================================================}\n";
	return a;
}
void material::Find(char* Name) {
	char* s;
	fstream f; f.open(FileNameMa, ios::in | ios::binary);
	if (!f.good()) return;
	cout << "__________________________________________________________________________________________________________\n";
	cout << "|_______________________________________BANG LICH SU GIAO DICH___________________________________________|\n";
	cout << " [ STT ] [ Ten vat lieu ]  [ ID giao dich ]  [ So luong ]  [Gia/DVSP]  [     Gia     ]  [ Thoi gian nhap ]\n";
	cout << " |=======================================================================================================|\n";
	cout.setf(ios::left);
	for (int i = 0; i < NumberOfMa; i++) {
		s == NULL;
		f.seekg((i * sizeMa), ios::beg);
		f.read((char*)(&DulieuMa), sizeMa);
			s = strstr(DulieuMa.NameMaterial, Name);
			if (s != NULL) {
				cout << " [ " << i + 1 << "\t" << setw(17) << DulieuMa.NameMaterial << "\t" << setw(10) << DulieuMa.IdHistoryTran << "\t " << setw(7) << DulieuMa.NumberMa << "\t" << setw(7) << DulieuMa.PricePerQuantity << "\t" << setw(18) << DulieuMa.Price << DulieuMa.Day << "/" << DulieuMa.Month << "/" << DulieuMa.Year << "\t ]" << endl;
		}
	}
	cout << " |=======================================================================================================|\n";
	f.close();
}
void material::OutF() {
	char* ch;
	string Name;
	char Key;
	cout << "\tESC: THOAT" << "\t SHIFT+2 THAY DOI THONG TIN\t\t" << "SHIFT+3: XOA THONG TIN" << endl;
	cout << "\nTIM KIEM: \n"; Ouput(); Check_::gotoxy(10, 2);
	while (1) {
		Key = _getch(); system("cls");
		if (Key != 27) { Name += Key; }
		if (Key == 8) {
			if (Name.length() > 1) {
				Name.pop_back(); Name.pop_back();
			}
			else {}
		}
		switch (Key)
		{
		case 64:
			Ouput(); ChangeMa(); system("cls"); Ouput(); _getch(); break;
		case 35:
			Ouput(); DeteleMa(); system("cls");  Ouput(); _getch(); break;
		default:
			break;
		}
		if (Key == 27) break;
		ch = (char*)Name.c_str();
		system("cls");
		cout << "\tESC: THOAT" << "\t SHIFT+2: THAY DOI THONG TIN\t\t" << "SHIFT+3: XOA THONG TIN" << endl;
		cout << "\nTIM KIEM: " << ch;
		cout << endl;
		Find(ch);
	}
}
int material::Check(int a, int b) {
	int s = 0;
	fstream f; f.open(FileNameMa, ios::binary | ios::in | ios::out);
	for (int i = 0; i < NumberOfMa; i++) {
		f.seekg(i * sizeMa, ios::beg);
		f.read((char*)(&DulieuMa), sizeMa);
		if (DulieuMa.Month == a && DulieuMa.Year== b) {
			s = s + DulieuMa.Price;
		}
	}
	return s;
}