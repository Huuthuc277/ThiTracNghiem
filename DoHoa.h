void gotoXY(short x,short y) {
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
} 
int whereX( void ) {
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int whereY( void ) {
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void textcolor(WORD color) {
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color) {
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Normal () {
	textcolor(0);
	SetBGColor(7);
}
void LOGO () {
	textcolor(44);
	SetBGColor(11);
}
void HighLight () {
	textcolor(0);
	SetBGColor(59);
}
void Error () {
	textcolor(12);
	SetBGColor(7);
}
void HeadTable() {
	textcolor(228);
	SetBGColor(186);
}
void BodyTable() {
	textcolor(0);
	SetBGColor(238);
}
void HCNText(int toadoX, int toadoY, int chieudai, int chieucao, int mau) {
	for (int i = toadoX; i < toadoX + chieudai; i++) {
		gotoXY(i, toadoY);
		SetBGColor(mau);
		cout << " ";
	}
	for (int i = toadoY; i < toadoY + chieucao; i++) {
		gotoXY(toadoX + chieudai - 1, i);
		SetBGColor(mau);
		cout << " ";
		
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--) {
		gotoXY(i, toadoY + chieucao - 1);
		SetBGColor(mau);
		cout << " ";
		
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--) {
		gotoXY(toadoX, i);
		SetBGColor(mau);
		cout << " ";
	}
}

void XoaManHinh(int X1, int X2, int Y1, int Y2) {
	Normal();
	int x=X2-X1;
	for (int i = Y1; i < Y2; i++) {
		gotoXY(X1,i);
		cout<<string(x,' ');			
	}
}
string CanDeuChuoi(string str, int ChieuRong) {
	if (str.empty()) {
		return str;
	}
	else if (str.length() > ChieuRong) 	{
		return str;
	}
	else if((ChieuRong - str.length()) % 2==0) 	{
		return string((ChieuRong - str.length()) / 2, ' ') + str + string((ChieuRong - str.length()) / 2, ' ');
	}
	else if((ChieuRong - str.length()) % 2!=0) 	{
		return string((ChieuRong - str.length()) / 2, ' ') + str + string((ChieuRong - str.length()) / 2+1, ' ');
	}
}

void ThongBao(string s){
	gotoXY(BoxTB[0],BoxTB[2]);
	Error();
	cout<<CanDeuChuoi(s,45);
	getch();
	XoaManHinh(BoxTB[0], BoxTB[1], BoxTB[2],BoxTB[3]);
	Normal();
}

void GiaoDienLop(int toadoX, int toadoY, int n){
	int chieucao = 3 + 2 * n;
	int chieudai = 84;
	
	HeadTable();
	gotoXY(toadoX + 1, toadoY);
	cout<<"                                                                                    ";
	gotoXY(toadoX + 1, toadoY + 1);
	cout<<"           Ma Lop                                  Ten Lop                          ";
	gotoXY(toadoX + 1, toadoY + 2);
	cout<<"                                                                                    ";
	BodyTable();
	
	for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
	{
		if (i == toadoX + 30) {
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j < toadoY + 3)
				{
					HeadTable();
				}
				else
					BodyTable();
				cout << (char)179;
			}
		}else {
			for (int j = toadoY+3; j < chieucao + toadoY + 1; j++) {
				gotoXY(i, j);
				cout<<" ";
			}
		}
	}
	for (int j = 5; j < chieucao; j = j + 2)
	{
		for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX + 30)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
	Normal();
}


void GiaoDienSV(int toadoX, int toadoY, int n) {
	int chieucao = 3 + 2 * n;
	int chieudai = 84;
	
	HeadTable();
	gotoXY(toadoX + 1, toadoY);
	cout<<"                                                                                    ";
	gotoXY(toadoX + 1, toadoY + 1);
	cout<<"        Ma SV                        Ho va Ten                            Phai      ";
	gotoXY(toadoX + 1, toadoY + 2);
	cout<<"                                                                                    ";
	BodyTable();
	
	for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
	{
		if (i == toadoX + 30 || i == toadoX + 70)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j < toadoY + 3)
				{
					HeadTable();
				}
				else
					BodyTable();
				cout << (char)179;
			}
		}
		else
		{
			for (int j = toadoY+3; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				cout<<" ";
			}
		}
	}
	for (int j = 5; j < chieucao; j = j + 2)
	{
		for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX + 30 || i == toadoX + 70)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
	Normal();
}


void GiaoDienMH(int toadoX, int toadoY, int n){
	int chieucao = 3 + 2 * n;
	int chieudai = 84;
	
	HeadTable();
	gotoXY(toadoX + 1, toadoY);
	cout<<"                                                                                    ";
	gotoXY(toadoX + 1, toadoY + 1);
	cout<<"     Ma Mon Hoc                                        Ten Mon Hoc                  ";
	gotoXY(toadoX + 1, toadoY + 2);
	cout<<"                                                                                    ";
	BodyTable();
	
	for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
	{
		if (i == toadoX + 30)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j < toadoY + 3)
				{
					HeadTable();
				}
				else
					BodyTable();
				cout << (char)179;
			}
		}
		else
		{
			for (int j = toadoY+3; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				cout<<" ";
			}
		}
	}
	for (int j = 5; j < chieucao; j = j + 2)
	{
		for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX + 30)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
	Normal();
}

void GiaoDienDT(int toadoX, int toadoY, int n) {
	int chieucao = 3 + 2 * n;
	int chieudai = 84;
	
	HeadTable();
	gotoXY(toadoX + 1, toadoY);
	cout<<"                                                                                    ";
	gotoXY(toadoX + 1, toadoY + 1);
	cout<<"          Ma SV                             Ho va Ten                     Diem      ";
	gotoXY(toadoX + 1, toadoY + 2);
	cout<<"                                                                                    ";
	BodyTable();
	
	for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
	{
		if (i == toadoX + 30 || i == toadoX + 70)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j < toadoY + 3)
				{
					HeadTable();
				}
				else
					BodyTable();
				cout << (char)179;
			}
		}
		else
		{
			for (int j = toadoY+3; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				cout<<" ";
			}
		}
	}
	for (int j = 5; j < chieucao; j = j + 2)
	{
		for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX + 30 || i == toadoX + 70)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
	Normal();
}

void GiaoDienTL(int toadoX, int toadoY, int n) {
	int chieucao = 3 + 2 * n;
	int chieudai = 84;
	
	HeadTable();
	gotoXY(toadoX + 1, toadoY);
	cout<<"                                                                                    ";
	gotoXY(toadoX + 1, toadoY + 1);
	cout<<"   ID Cau hoi                  Noi Dung                                     DA      ";
	gotoXY(toadoX + 1, toadoY + 2);
	cout<<"                                                                                    ";
	BodyTable();
	
	for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
	{
		if (i == toadoX + 15 || i == toadoX + 70)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j < toadoY + 3)
				{
					HeadTable();
				}
				else
					BodyTable();
				cout << (char)179;
			}
		}
		else
		{
			for (int j = toadoY+3; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				cout<<" ";
			}
		}
	}
	for (int j = 5; j < chieucao; j = j + 2)
	{
		for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX + 15 || i == toadoX + 70)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
	Normal();
}

void HDMainMenu() {
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut Enter: de chon";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut Esc: de thoat";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nut mui ten len, xuong : de dieu khien thanh sang";
}

void HDNhapLop() {
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut mui ten len, xuong: de nhap";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut mui ten trai, phai : de dieu khien thanh sang";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nut Enter: de chon";
}

void HDXuatLop() {
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut mui ten trai, phai : de lat trang";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nut Esc: de thoat";
}

void HDXoaLop() {
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut Enter: de chon";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut mui ten trai, phai : de dieu khien thanh sang";
}

void HDXemThongTinLop() {
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut Enter: de chon";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut Esc: de thoat";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nut mui ten len, xuong : de dieu khien thanh sang";	
}

void HDThi() {
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut A,B,C,D: de chon dap an";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut mui ten trai, phai : de chuyen cau hoi";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nut Esc: de thoat va nop bai";
}


void GiaoDienDangNhap() {
	gotoXY(70, 11);
	cout << "Ten dang nhap:";
	gotoXY(70, 14);
	cout << "Mat khau:";
	gotoXY(90,  17);
	cout << "Dang nhap";
	gotoXY(115,  17);
	cout << "Thoat";
}

void GiaoDienNhapCHVaPhut() {
	gotoXY(70,8);
	cout<<"Ma Mon Hoc";
	gotoXY(70,11);
	cout<<"Ten Mon Hoc";
	gotoXY(70, 14);
	cout << "So Cau";
	gotoXY(70, 15);
	cout << "0<Cau Hoi<=60";		
	gotoXY(70, 17);
	cout << "So phut:";
	gotoXY(70, 18);
	cout << "0<t<=60";
	gotoXY(90,  20);
	cout << "Vao Thi";
	gotoXY(115,  20);
	cout << "Thoat";
}

void GiaoDienKetQua() {
	gotoXY(70,8);
	cout<<"Ma Mon Hoc";
	gotoXY(70,11);
	cout<<"Ten Mon Hoc";
	gotoXY(70, 14);
	cout << "So Cau Dung";		
	gotoXY(70, 17);
	cout << "Diem:";
}


void GiaoDienThemMH() {
	gotoXY(70, 8);
	cout << "Ma Mon Hoc:";
	gotoXY(70, 11);
	cout << "Ten Mon Hoc:";
	gotoXY(90,  14);
	cout << "Them";
	gotoXY(115,  14);
	cout << "Thoat";

}

void GiaoDienThemLop() {
	gotoXY(70, 8);
	cout << "Ma Lop:";
	gotoXY(70, 11);
	cout << "Ten Lop:";
	gotoXY(90,  14);
	cout << "Them";
	gotoXY(115,  14);
	cout << "Thoat";

}

void GiaoDienThemSV() {
	gotoXY(70, 8);
	cout << "Ma Lop:";
	gotoXY(70, 11);
	cout << "Ma Sinh Vien:";
	gotoXY(70, 14);
	cout << "Nhap Ho:";
	gotoXY(70, 17);
	cout << "Nhap Ten:";
	gotoXY(70, 20);
	cout << "Chon Phai:";
	gotoXY(100, 20);
	cout << "Nam";
	gotoXY(115,  20);
	cout << "Nu";
	gotoXY(70, 23);
	cout << "Nhap Mat Khau:";
	gotoXY(90,  26);
	cout << "Them";
	gotoXY(115,  26);
	cout << "Thoat";
}

void GiaoDienThemCH() {	
	gotoXY(60,5);
	cout<<"Ten Mon Hoc";
	gotoXY(130, 5);
	cout<<"So Luong Cau Hoi";
	gotoXY(60, 8);
	cout << "ID Cau Hoi:";
	gotoXY(60, 11);
	cout << "Noi dung:";
	gotoXY(60, 14);
	cout << "Cau A:";
	gotoXY(60, 17);
	cout << "Cau B:";
	gotoXY(60, 20);
	cout << "Cau C";
	gotoXY(60,  23);
	cout << "Cau D";
	gotoXY(60, 26);
	cout << "Dap an:";
	gotoXY(90,  29);
	cout << "Them";
	gotoXY(115,  29);
	cout << "Thoat";
}

void GiaoDienThiTracNghiem() {
	gotoXY(60, 8);
	cout << "Cau Hoi:";
	gotoXY(60, 11);
	cout << "Noi dung:";
	gotoXY(60, 14);
	cout << "Cau A:";
	gotoXY(60, 17);
	cout << "Cau B:";
	gotoXY(60, 20);
	cout << "Cau C";
	gotoXY(60,  23);
	cout << "Cau D";
}


void GiaoDienTimkiemMH()
{

	gotoXY(BoxMain[0]+10,BoxMain[2]+2);
	HeadTable(); 
	cout <<"     Ma Mon Hoc     "<<char(179)<<"              Ten Mon Hoc                    ";
	Normal();
}

void GiaoDienTimkiemLop() {

	gotoXY(BoxMain[0]+10,BoxMain[2]+2);
	HeadTable();
	cout <<"        Ma Lop      "<<char(179)<<"                    Ten Lop                  ";
	Normal();
}


void GiaoDienTimkiemSV() {

	gotoXY(BoxMain[0]+10,BoxMain[2]+2);
	HeadTable();
	cout <<"  Ma Sinh Vien      "<<char(179)<<"                     Ho Ten                  ";
	Normal();
}


void GiaoDienTimkiemSV2() {

	gotoXY(BoxMain[0]+10,BoxMain[2]+2);
	HeadTable();
	cout <<"  Ma Sinh Vien  "<<char(179)<<"                     Ho Ten                 "<<char(179)<<" Diem ";
	Normal();
}

