#include"Header.h"
void Run::RunJob() {
	int check;
	bool Nhap = false;
	while (true) {
		char FN[30] = "CongViec";
		char CH[30] = "CuaHang";
		JOB_s* a = new JOB_s(FN, CH);
		cout << "========================\n";
		cout << "|| 1 Nhap thong tin   ||" << endl;
		cout << "|| 2 Xuat thong tin   ||" << endl;
		cout << "|| 3 Cham cong        ||\n";
		cout << "|| 4 Tra luong        ||\n";
		cout << "========================\n";
		check = Check_::TranCharToIn("Nhap lua chon cua ban:");
		switch (check)
		{
		case 1:
			system("cls");
			a->In(); break;
		case 2:
			system("cls");
			a->OutF(); break;
		case 3:
			system("cls");
			a->ChamCong(); break;
		case 4:
			system("cls");
			a->TraLuong(); break;
		default:
			break;
		}
		break;
	}
}
void Run::RunIn4Store() {
	char N[30] = "CuaHang";
	Store_s *a = new Store_s(N);
	bool Nhap = false;
	while (true) {
		system("cls");
		cout << "========================\n";
		cout << "|| 1 Nhap thong tin   ||" << endl;
		cout << "|| 2 Xuat thong tin   ||" << endl;
		cout << "========================\n";
		int check = Check_::TranCharToIn("Nhap lua chon cua ban:");
		switch (check)
		{
		case 1:
			a->In(); break;
		case 2:
			system("cls");
			a->Out(); break;
		default:
			break;
		}
		break;
	}
}
void Run::RunBill() {
	char HD[30] = "HoaDon";	
	Bill* a = new Bill(HD);
	bool Nhap = false;
	while (true) {
		system("cls");
		cout << "========================\n";
		cout << "|| 1 Nhap thong tin   ||" << endl;
		cout << "|| 2 Xuat thong tin   ||" << endl;
		cout << "|| 3 Chi tiet hoa don ||\n";
		cout << "========================\n";
		int check = Check_::TranCharToIn("Nhap lua chon cua ban:");
		switch (check)
		{
		case 1:
			system("cls");
			a->Create(); break;
		case 2:
			system("cls");
			a->OutF(); break;
		case 3:
			system("cls");
			a->ChiTietHoaDon();
			break;
		default:
			break;
		}
		break;
	}
}
void Run::RunBillShip() {
	char HD[30] = "HoaDonShip";
	bool Nhap = false;
	while (true) {
		system("cls");
		BillShip* a = new BillShip(HD);
		cout << "========================\n";
		cout << "|| 1 Nhap thong tin   ||" << endl;
		cout << "|| 2 Xuat thong tin   ||" << endl;
		cout << "|| 3 Chi tiet hoa don ||\n";
		cout << "========================\n";
		int check = Check_::TranCharToIn("Nhap lua chon cua ban:");
		switch (check)
		{
		case 1:
			system("cls");
			a->Create(); break;
		case 2:
			system("cls");
			a->OutF(); break;
		case 3:
			system("cls");
			a->ChiTietHoaDon();
			break;
		default:
			break;
		}
		break;
	}
}
void Run::RunNguyenLieu() {
	char HD[30] = "NguyenLieu";
	bool Nhap = false;
	while (true) {
		system("cls");
		material* a = new material(HD);
		cout << "========================\n";
		cout << "|| 1 Nhap thong tin   ||" << endl;
		cout << "|| 2 Xuat thong tin   ||" << endl;
		cout << "|| 3 Xuat DS hang hoa ||\n";
		cout << "========================\n";
		int check = Check_::TranCharToIn("Nhap lua chon cua ban:");
		switch (check)
		{
		case 1:
			system("cls");
			a->Input(); break;
		case 2:
			system("cls");
			a->OutF(); break;
		case 3:
			system("cls");
			a->SapXep(); _getch(); break;
		default:
			break;
		}
		break;
	}
}
void Run::RunThucDon() {
	char HD[30] = "ThucDon";
	bool Nhap = false;
	while (true) {
		system("cls");
		_ThucDon* a = new _ThucDon(HD);
		cout << "========================\n";
		cout << "|| 1 Nhap thong tin   ||" << endl;
		cout << "|| 2 Xuat thong tin   ||" << endl;
		cout << "========================\n";
		int check = Check_::TranCharToIn("Nhap lua chon cua ban:");
		switch (check)
		{
		case 1:
			system("cls");
			a->In(); break;
		case 2:
			system("cls");
			a->OutF(); break;
		default:
			break;
		}
		break;
	}
}
int Run::ThongKe_() {
	int M = Check_::TranCharToIn("Nhap thoi gian muon thong ke(Thang-Nam):"); Check_::gotoxy(42, 0); cout << "/"; Check_::gotoxy(44,0); int Y = Check_::TranCharToIn("");
	char BillS[30] = "HoaDonShip";
	char B[30] = "HoaDon";
	char J[30] = "CongViec";
	char NL[30] = "NguyenLieu";
	char CH[30] = "CuaHang";
	bool Nhap = false;
	while (true) {
		Bill* b = new Bill(B);
		cout<<"Thu nhap tu khach tai quan:"<<b->Check(M, Y)<<endl;
		BillShip* BS = new BillShip(BillS);
		cout<<"Thu nhap tu khach dat hang:"<<BS->Check(M, Y)<<endl;
		JOB_s* j = new JOB_s(J, CH);
		cout << "Chi phi tra luong:" << j->Check(M, Y) << endl;
		material* Ma = new material(NL);
		cout<<"Chi phi mua nguyen lieu:"<<Ma->Check(M, Y)<<endl;
		int ThongKe = BS->Check(M,Y) + b->Check(M, Y) - j->Check(M, Y) - Ma->Check(M, Y);
		return ThongKe; break;
	}
}