#include"Header.h"
void main() {
	char sto[30] = "CuaHang";
	Store_s* S = new Store_s(sto);
	int Control = 1, chose[5], Control2 = 1,TK;
	char CTRL, CTRL2; int io = 0;
	while (1) {
		while (1) {
			system("cls");
			if (Control < 1) Control = 6;
			if (Control > 6) Control = 1;
			Check_::SET_COLOR(7);
			cout << "______________________________________________\n";
			Check_::SET_COLOR(7);
			cout << "||_______________THONG TIN___________________||\n";
			if (Control == 1) { Check_::SET_COLOR(4); }
			else Check_::SET_COLOR(7);
			cout << "||   Thong tin cua hang                      ||\n";
			if (Control == 2) { Check_::SET_COLOR(4); }
			else Check_::SET_COLOR(7);
			cout << "||   Thong tin nhan vien                     ||\n";
			if (Control == 3) { Check_::SET_COLOR(4); }
			else Check_::SET_COLOR(7);
			cout << "||   Thong tin hoa don                       ||\n";
			if (Control == 4) { Check_::SET_COLOR(4); }
			else Check_::SET_COLOR(7);
			cout << "||   Thong tin nguyen lieu                   ||\n";
			if (Control == 5) { Check_::SET_COLOR(4); }
			else Check_::SET_COLOR(7); 
			cout << "||   Menu                                    ||\n";
			if (Control == 6) { Check_::SET_COLOR(4); }
			else Check_::SET_COLOR(7);
			cout << "||   Thong ke                                ||\n";
			Check_::SET_COLOR(7);
			cout << "||___________________________________________||\n";
			CTRL = _getch();
			if (CTRL == 72)Control--;
			if (CTRL == 80)Control++;
			if (CTRL == 13) break;
			else Control = Control;
		}
		switch (Control)
		{
		case 1:
			system("cls");
			Run::RunIn4Store(); break;
		case 2:
			if (S->getCalam()<=0 || S->getCalam()>50) { cout << "Cua hang chua co thong tin:"; _getch(); break; }
			system("cls");
			Run::RunJob(); break;
		case 3:
			while (1) {
				system("cls");
				if (Control2 < 1) Control2 = 3;
				if (Control2 > 3) Control2 = 1;
				Check_::SET_COLOR(7);
				cout << "______________________________________________\n";
				Check_::SET_COLOR(7);
				cout << "||_______________THONG TIN__________________||\n";
				if (Control2 == 1) { Check_::SET_COLOR(4); }
				else Check_::SET_COLOR(7);
				cout << "||   Thong tin ve hoa don tai quan          ||\n";
				if (Control2 == 2) { Check_::SET_COLOR(4); }
				else Check_::SET_COLOR(7);
				cout << "||   Thong tin ve hoa don hang duoc dat     ||\n";
				if (Control2 == 3) { Check_::SET_COLOR(4); }
				else Check_::SET_COLOR(7);
				cout << "||   Thoat                                  ||\n";
				Check_::SET_COLOR(7);
				cout << "||__________________________________________||\n";
				CTRL2 = _getch();
				if (CTRL2 == 72)Control2--;
				if (CTRL2 == 80)Control2++;
				if (CTRL2 == 13) break;
				else Control2 = Control2;
			}
			switch (Control2)
			{
			case 1:
				system("cls");
				Run::RunBill(); break;
			case 2:
				system("cls");
				Run::RunBillShip(); break;
			case 3:
				break;
			default:
				break;
			}break;
		case 4:
			system("cls");
			Run::RunNguyenLieu(); break;
		case 5:
			system("cls");
			Run::RunThucDon(); break;
		case 6:
			system("cls");
			TK=Run::ThongKe_();
			if (TK >= 0) cout << "Cua hang lai:" << TK << endl;
			if (TK < 0) cout << "Cua hang lo:" << 0 - TK << endl;			
			_getch(); break;
		default:
			break;
		}
	}
}