string DangNhap(DSLOP ds_lop);
//================Xy ly danh sach lop ==================
//Them
void ThemMotLop(DSLOP &ds_lop);
bool Nhap1Lop(DSLOP &ds_lop);
bool KTTenLop(string TenLop);
bool kt_ma_lop_trung(DSLOP ds_lop, string a);
int kt_ma_lop_trung2(DSLOP ds_lop, string a);
//Xuat
void chuyen_mct_thanh_mang(DSLOP ds_lop,Lop ds[]);
void sap_xep_ds_mang(Lop ds[], int n);
void XuatDanhSachLop(DSLOP ds_lop);
//Hieu chinh
void LayDSLop(DSLOP ds_lop, string ma[],string ten[]);
void LayMaLop(DSLOP ds_lop, string &maLop);
void LayThongTinLop(DSLOP ds_lop, string maLop, LOP &lop);
void HieuChinhLop(DSLOP ds_lop);
//Xoa
void XoaLop(DSLOP &ds_lop);
//================Xy ly danh sach sinh vien ==================
NODESV* Khoi_Tao_NODE(SV sv);
void Them_Cuoi(DSSV& l, NODESV* sv);
int CountSV(DSSV l);
void sap_xep_ds_sv(SV ds[], int n);
bool KtMaSV(DSLOP ds_lop, string maSV);
SV LaySV(DSLOP ds_lop, string maSV);
//Them
void NhapSV(DSLOP l, string maLop);
void ChonPhai(string& Phai, int& pointer2);
void ThemSV(DSLOP ds_lop);
//Xuat
void chuyen_lkd_thanh_mang(DSSV l, SV ds[]);
void XuatDanhSachSV(DSSV ds_sv, string maLop );
void XuatDanhSachLop2(DSLOP ds_lop);
//Hieu Chinh
void LayDSSV(DSSV l, string ma[],string ten[], int soluong);
void LayMaSV(DSSV l, string &maSV);
SV LayThongTinSV(DSSV l, string maSV);
void HieuChinhSV(DSLOP ds_lop);
bool KtMaSV2(DSLOP ds_lop, string maSV, string maBD);
//Xoa
void XoaSV(DSLOP ds_lop);
//================Xy ly danh sach mon hoc ==================
NODEMH* KhoiTaoNodeMH(MH mh);
void kt_ma_mh_trung(TREE t, string a, int& kt);
int SoNodeTrongTREE(TREE t);
//Them
void ThemNode(TREE &t, MH x);
void ThemMH(TREE &t);
bool NhapMH(TREE& t);
//Xuat
void XuatDanhSachMH(TREE t);
void chuyen_cay_sang_mang(TREE T,MH ds[], int& nds);
void sap_xep_ds_mon_hoc(MH ds[], int& nds);
//Hieu Chinh
void HieuChinhMH(TREE& t);
void LayThongTinMH(TREE t, string maMH, TREE &tam);
void LayMaMH(TREE t, string &maMH);
void LayDSMH(MH ds[], int n, string maMH[], string tenMH[]);
//Xoa
void NodeTheMang(TREE &X, TREE &Y);
void Xoa_1_MH(TREE &t, string ma);
void XoaMH(TREE &t);
//================Xy ly danh cau hoi ==================
void ThemCauHoi(TREE &t);
//================Xy ly danh sach diem ==================
int CountDiem(DSDIEM l);
NODEDT* Khoi_Tao_NODE_DT(DT dt);
void Them_Cuoi_DSDT(DSDIEM& l, NODEDT* dt);
float LayDiem(DSDIEM l, string maMon);
void XuatDSDiem(DSSV ds_sv, string maLop,string maMon);
void XuatDanhSachDiem(TREE t, DSLOP ds_lop);
//================Xy ly thi trac nghiem ==================
int LayMaLop2(DSLOP ds_lop, string a);
void LaySoCHVaPhut(TREE t,string maMon,int &soCau, int &phut);
int tao_ma(int so);
bool kt_ma_ch_trung(DSCAUHOI ds, int a);
void InSLCH(DSTL l, int temp);
//================Xy ly chi tiet cau tra loi ==================
void XuatDanhSachCT(TREE t, DSLOP ds_lop);
void XuatDSCT(DSTL l,SV sv,string maMon);
void LayMaSV2(DSSV l, string &maSV, string maMH, float& diemThi);
DT LayThongTinDT(DSDIEM l, string maMH);
void LayDSSV2(DSSV l, string ma[], string ten[], float diem[], string maMH ,int soluong);
void sap_xep_mangt_theo_ten2(string ma[], string ten[], float diem[],int n);
//================Xu ly dang nhap ================================
bool KtMaSV(DSLOP ds_lop, string maSV) {
	for (int i = 0; i < ds_lop.sl; i++) {
		for (NODESV* k = ds_lop.ds[i]->listSV.pHead; k != NULL; k = k->pNext) {
			if (k->data.maSV.compare(maSV) == 0) {
				return true;
			}
		}
	}
	return false;
}

SV LaySV(DSLOP ds_lop, string maSV) {
	for (int i = 0; i < ds_lop.sl; i++) {
		for (NODESV* k = ds_lop.ds[i]->listSV.pHead; k != NULL; k = k->pNext) {
			if (k->data.maSV.compare(maSV) == 0) {
				return k->data;
			}
		}
	}	
}

string DangNhap(DSLOP ds_lop) {
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
	HDNhapLop();
	GiaoDienDangNhap();
	string username;
	string password;
	int pointer1 =11; 
	ShowCur(1);
	SV sv;
	bool kt = false;
	while (true) 	{
		ShowCur(1);
		if (pointer1 == 11) {
			gotoXY(90+username.length(), pointer1);
			XuLyNhap1(username, 90, pointer1,30); 
			if (pointer1 < 11) 
				pointer1 = 14;				
			if (username.empty()) {
				gotoXY(130, 11);
				cout << "Username Rong";			
			}else {
				gotoXY(130, 11);
				cout << "                ";			
			}	
			
		}else if (pointer1 == 14) {	
			gotoXY(90+password.length(), pointer1);
			XuLyNhapPassword(password,90, pointer1,30);			
			if (password.empty()) {
				gotoXY(130, 14);
				cout << "Password Rong";			
			}else {
				gotoXY(130, 14);
				cout << "                 ";			
			}				
		}else if (pointer1 == 17) {// save hoac huy		
			ShowCur(0);
			int pointer2 = 90;
			while (true) {
				if (kbhit()) {
					char c = getch();
					if (c == 13) {
						if (!username.empty() && !password.empty() && pointer2 == 90) {	
							username = trim(username);								
							kt = KtMaSV(ds_lop, username);
							if(kt) {
								sv = LaySV(ds_lop, username);
							}
							
							if(username == "GV" && password == "GV") {
								return username;	
							}		
							else if(sv.maSV == username && sv.password == password) {								
								return username;
							}				
							else {
								ThongBao("Ten dang nhap va mat khau khong dung");
							}																						
						}else if (pointer2 == 115) 							
							exit(0);
						else 
							ThongBao("Vui long dien day du thong tin");					
					}else if (c == -32) {
						c = getch();
						if (c == 72) {
							Normal();
							gotoXY(115, 17);
							cout << "Thoat";
							gotoXY(90, 17);
							cout << "Dang nhap";
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80) 	{
							Normal();
							gotoXY(115, 17);
							cout << "Thoat";
							gotoXY(90, 17);
							cout << "Dang nhap";
							ShowCur(1);
							pointer1 = 11;
							break;
						}
						else  if (c == 75) {
							if (pointer2 == 115) 
								pointer2 = 90;
							
							else
								pointer2 = 115;
						}
						else if (c == 77) {
							if (pointer2 == 90) 
								pointer2 = 115;
							
							else
								pointer2 = 100;
						}
						gotoXY(pointer2, 17);
					}
				}
				HighLight();
				gotoXY(pointer2, pointer1);
				if (pointer2 == 90) {
					cout << "Dang nhap";
					Normal();
					gotoXY(115, 17);
					cout << "Thoat";
				}
				else if (pointer2 == 115) {
					cout << "Thoat";
					Normal();
					gotoXY(90, 17);
					cout << "Dang nhap";
				}
			}
		}
	}

}


//================Xy ly danh sach lop  ==================
void chuyen_mct_thanh_mang(DSLOP ds_lop,Lop ds[]) {
	for (int i = 0; i< ds_lop.sl; i++) {			
		ds[i].maLop = ds_lop.ds[i]->maLop;
		ds[i].tenLop = ds_lop.ds[i]->tenLop;
	}
}

void sap_xep_ds_mang(Lop ds[], int n) {
	Lop temp;
	for(int i = 0; i <n -1; i++) {
		for(int j= i + 1; j < n; j++) {
			if(ds[i].maLop > ds[j].maLop) {
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}

void XuatDanhSachLop(DSLOP ds_lop) {

	int n = ds_lop.sl; // So luong phan tu cua ds lop
	int trang = 1;
	int sotrang = 1;
	int phantutrang=10;	
	int i=0; 
	int dem = 0;
	Lop* ds = new Lop[n];
	chuyen_mct_thanh_mang(ds_lop,ds);
	sap_xep_ds_mang(ds, n);
	HDXuatLop();
	
	if(n==0) {
		ThongBao("Danh Sach Lop Trong!");
		return;
	}
	
	if(n%10==0)
		sotrang= n/10;
	else
		sotrang= n/10+1;
	
	if(n<=10) {
		GiaoDienLop(BoxMain[0]+6, BoxMain[2], n);
		for(int i=0;i<n;i++) {
			BodyTable();
			gotoXY(60, toadoY + 5 + dem*2);
			cout <<CanDeuChuoi(ds[i].maLop,29);
			gotoXY(90, toadoY + 5 + dem*2 );
			cout <<CanDeuChuoi(ds[i].tenLop,52);			
			dem++;
		}
	
	}else {
		GiaoDienLop(BoxMain[0]+6, BoxMain[2], 10);
		for(int i=0;i<10;i++) {			
			BodyTable();
			gotoXY(60, toadoY + 5 + dem*2);
			cout <<CanDeuChuoi(ds[i].maLop,29);
			gotoXY(90, toadoY + 5 + dem*2 );
			cout <<CanDeuChuoi(ds[i].tenLop,52);	
			dem++;
		}
	}
		
	gotoXY(95,BoxMain[2]-2);
	cout<<"DANH SACH LOP";
	gotoXY(100,31);
	cout<<"<< "<<trang<<" >>";
	char c;
	
	while(true) {
		
		
		if(kbhit) {
			c=getch();
			if(c == -32) {

				c=getch();
				if(c == 77) {
					dem = 0;					
					
					if(sotrang>1 && trang<sotrang)
					{
						phantutrang = n-trang*10;
						if(phantutrang>=10)
							phantutrang=10;
							
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
						GiaoDienLop(BoxMain[0]+6, BoxMain[2],phantutrang);
						for(int i=trang*10;i<trang*10+phantutrang;i++) {
							BodyTable();
							gotoXY(60, toadoY + 5 + dem*2);
							cout <<CanDeuChuoi(ds[i].maLop,29);
							gotoXY(90, toadoY + 5 + dem*2 );
							cout <<CanDeuChuoi(ds[i].tenLop,52);	
							dem++;
						}
						trang++;
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}
				else  if(c==75) {
					dem = 0;
					if(trang>1) {
						phantutrang=10;
						trang--;
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
						GiaoDienLop(BoxMain[0]+6, BoxMain[2],phantutrang);
						for(int i=trang*10-10;i<trang*10;i++) {
							BodyTable();
							gotoXY(60, toadoY + 5 + dem*2);
							cout <<CanDeuChuoi(ds[i].maLop,29);
							gotoXY(90, toadoY + 5 + dem*2 );
							cout <<CanDeuChuoi(ds[i].tenLop,52);	
							dem++;
						}
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}
				
			
			} else if(c==27) {
				delete[]ds;
				XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
				return;
			}	
		}
	}
	Normal();
}

bool Nhap1Lop(DSLOP &ds_lop) {
	HDNhapLop();
	GiaoDienThemLop();

	char c;
	int pointer1 = 8;
	int pointer2 = 90;
	ShowCur(1);
	while (true) {
		if (pointer1 == 8) {
			gotoXY(80 + ds_lop.ds[ds_lop.sl]->maLop.length(), pointer1);
			XuLyNhap2(ds_lop.ds[ds_lop.sl]->maLop,80, pointer1);			
			if (pointer1 < 8)	{
				pointer1 = 14;
			}
			
			if (ds_lop.ds[ds_lop.sl]->maLop.empty()) 		{
				gotoXY(120, 8);
				cout << "Ma Rong";
			}else if (kt_ma_lop_trung(ds_lop, ds_lop.ds[ds_lop.sl]->maLop)) {
				gotoXY(116, 8);
				cout << "Ma Lop Trung";
			}else {
				gotoXY(120, 8);
				cout << "                           ";
			}
		}else if (pointer1 == 11) {
			gotoXY(80 + ds_lop.ds[ds_lop.sl]->tenLop.length(), pointer1);
			XuLyNhap1(ds_lop.ds[ds_lop.sl]->tenLop, 80, pointer1, 30);
			if (ds_lop.ds[ds_lop.sl]->tenLop.empty()) {
				gotoXY(120, 11);
				cout << "Ten Lop Rong";
			} else {
				gotoXY(120, 11);
				cout << "                  ";
			}
		}		
	
		else if (pointer1 == 14) {
			ShowCur(0);
			HighLight();
			gotoXY(90, 14);
			cout << "Them";
			Normal();
			while (true) {
				if (kbhit())
				{
					c = getch();
					if (c == 13) {
						if (!ds_lop.ds[ds_lop.sl]->maLop.empty() && 								
							!ds_lop.ds[ds_lop.sl]->tenLop.empty() && 
							!kt_ma_lop_trung(ds_lop, ds_lop.ds[ds_lop.sl]->maLop) &&						
							pointer2 == 90) {							
							DinhDangChuoi(ds_lop.ds[ds_lop.sl]->tenLop);												
							ShowCur(0);
							return true;
						}
						else if (pointer2 == 115)
						{
							ShowCur(0);
							XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
							return false;
							
						}
					}
					else if (c == -32) {
						c = getch();
						if (c == 72) {
							Normal();
							textcolor(0);
							gotoXY(115, 14);
							cout << "Thoat";
							gotoXY(115, 14);
							cout << "Them";
							ShowCur(1);
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80) {
							Normal();
							textcolor(0);
							gotoXY(115, 14);
							cout << "Thoat";
							gotoXY(90, 14);
							cout << "Them";
							ShowCur(1);
							pointer1 = 8;
							break;
						}
						else if (c == 75) {
							if (pointer2 == 115)
								pointer2 = 90;
							else
								pointer2 = 115;
						}
						else if (c == 77) {
							if (pointer2 == 90)
								pointer2 = 115;
							else
								pointer2 = 90;
						}						
					}
				}

				if (pointer2 == 90) {
					textcolor(0);
					gotoXY(115, 14);
					cout << "Thoat";
					HighLight();
					gotoXY(90, 14);
					cout << "Them";
					Normal();
				}
				else if (pointer2 == 115) {
					textcolor(0);
					gotoXY(90, 14);
					cout << "Them";
					HighLight();
					gotoXY(115, 14);
					cout << "Thoat";
					Normal();
				}
			
			}
		}
	}
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
}

void ThemMotLop(DSLOP &ds_lop) {

	if (ds_lop.sl == 100)
	{
		ThongBao("Loi! Bo nho da day");
		return;
	}

	ds_lop.ds[ds_lop.sl] = new LOP;	

	if (!Nhap1Lop(ds_lop)) 	{
		delete ds_lop.ds[ds_lop.sl];
		return;
	}
	
	ds_lop.ds[ds_lop.sl]->listSV.pHead = NULL;
	ds_lop.ds[ds_lop.sl]->listSV.pTail = NULL;
	ds_lop.sl++;
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	ThongBao("Them Lop Thanh Cong!");
}



bool kt_ma_lop_trung(DSLOP ds_lop, string a) {
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (ds_lop.ds[i]->maLop.compare(a) == 0) {
			return true;
		}
	}
	return false;
}

int kt_ma_lop_trung2(DSLOP ds_lop, string a) {
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (ds_lop.ds[i]->maLop.compare(a) == 0) {
			return i;
		}
	}
	return -1;
}

bool KTTenLop(string TenLop) {
	for (int i = 0; i < TenLop.length(); i++)
	{
		if ((TenLop[i] >= 65 && TenLop[i] <= 90) || (TenLop[i] >= 97 && TenLop[i] <= 122))
		{
			return true;
		}
	}
	return false;
}

void LayDSLop(DSLOP ds_lop, string ma[],string ten[]) {
	if (ds_lop.sl==0) 	{
		return;
	}
	for (int i = 0; i < ds_lop.sl; i++) {
		ma[i]= ds_lop.ds[i]->maLop;
		ten[i] = ds_lop.ds[i]->tenLop;		
	}
}

void SapXepDSLop(string ma[],string ten[], int n) {
	if (n==0) 	{
		return;
	}
	string temp, temp1;
	for (int i = 0; i < n-1; i++) {
		for(int j = i+1; j< n; j++) {
			if(ma[i] > ma[j]){
                swapChuoi(ma[i], ma[j]);
                swapChuoi(ten[i], ten[j]);
            }
		}	
	}
}




void LayMaLop(DSLOP ds_lop, string &maLop) {	
	int n = ds_lop.sl; // So luong phan tu cua ds lop
	int toadoX= 63;
	int toadoY = 9;
	int pointer=toadoY;
	GiaoDienTimkiemLop();
	string *ten=new string[n];	
	string *ma=new string[n];//ma lop

	LayDSLop(ds_lop,ma,ten);
	SapXepDSLop(ma,ten, n);
	char c;
	int i=0;
	int vitri=0;
	bool key=true; 
	

	do {
		if(n==0)  {
			ThongBao("Khong co lop nao !!");
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			return;
		}else {
			BodyTable();
			for(int i = vitri; i < n; i++) {
				if((i-(vitri))==20) break;				
				gotoXY(BoxMain[0] +10 , toadoY+i-(vitri));
				cout<<CanDeuChuoi(ma[i],20)<<char(179)<<CanDeuChuoi(ten[i],45);
			}
			gotoXY(BoxMain[0]+10,pointer);
			HighLight();
			cout<<CanDeuChuoi(ma[pointer-(BoxMain[2]+3)+vitri],20)<<char(179)<<CanDeuChuoi(ten[pointer-(BoxMain[2]+3)+vitri],45);
			i=pointer-(BoxMain[2]+3)+vitri;
			Normal();
			ShowCur(0);
			if(kbhit) {
				a:c=getch();
				if(c == 13) { //enter
					maLop=ma[i];					
					key=false;	
				}else if(c == 27) { 
					key=false;	
				} else if(c == -32)	{
					c = getch(); 
					if(c == 72) { 
						if(pointer > toadoY)						
							pointer--;						
						else if(pointer == toadoY && vitri > 0) {
							vitri--;
						}
					} else if(c == 80) { 
						if(vitri> n-21 && vitri< n-1)	{
							if( i > n-2) goto a;
							else {
								if(pointer < MaxBox)	
									pointer++;
								else if(pointer==MaxBox && vitri<n-21)	
									vitri++;
							}						
						}
						else if (vitri == n-1) goto a;
						 else if(pointer < MaxBox)		
							pointer++;
						 else if(pointer == MaxBox && vitri<n-20)	{
							vitri++;
						}
					}
				}
			}
		}
	}while(key);
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	delete[]ten;
	delete[]ma;
	ShowCur(0);
}

void LayThongTinLop(DSLOP ds_lop, string maLop, LOP &lop) {
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if(ds_lop.ds[i]->maLop.compare(maLop) == 0) {
			lop.maLop = ds_lop.ds[i]->maLop;
			lop.tenLop = ds_lop.ds[i]->tenLop;
		}		
	}
}

bool kt_ma_lop_trung3(DSLOP ds_lop, string a, string maBD) {
	if(maBD.compare(a) == 0) {
		return false;
	}
	
	for (int i = 0; i < ds_lop.sl; i++) {
	
		if (ds_lop.ds[i]->maLop.compare(a) == 0) {
			return true;
		}
	}
	return false;
}

void HieuChinhLop(DSLOP ds_lop) {
	while(true) {
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maLop="";
		LayMaLop(ds_lop, maLop);
		
		if (maLop.compare("") == 0)
			return;
		
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	
		int vt = kt_ma_lop_trung2(ds_lop, maLop);
		HDNhapLop();
		string maLopTam;
		string tenLopTam;
		maLopTam = ds_lop.ds[vt]->maLop;
		tenLopTam = ds_lop.ds[vt]->tenLop;
		
		
		int pointer = 8;
		char c;
		GiaoDienThemLop();
		gotoXY(90,  14);
		cout << "Cap Nhat";
		gotoXY(80,8);
		cout << ds_lop.ds[vt]->maLop;
		gotoXY(80, 11);
		cout << ds_lop.ds[vt]->tenLop;
		gotoXY(80, 8);	
		pointer = 8;
		Normal();
		ShowCur(1);
		
		while (true) {			
			if (pointer == 8) 	{
				ShowCur(1);
				gotoXY(80 + maLopTam.length(), pointer);
				XuLyNhap2(maLopTam,80, pointer);
				if (pointer < 8)
					pointer = 14;
				
				if (maLopTam.empty()) {
					gotoXY(120, 8);
					cout << "Ma Rong";
				}else if (kt_ma_lop_trung3(ds_lop, maLopTam, ds_lop.ds[vt]->maLop)) {
					gotoXY(116, 8);
					cout << "Ma Lop Trung";
				}else {					
					gotoXY(120, 8);
					cout << "                           ";
				}
			}else if (pointer == 11) 	{
				ShowCur(1);
				gotoXY(80+ds_lop.ds[vt]->tenLop.length(), pointer);
				XuLyNhap1(ds_lop.ds[vt]->tenLop, 80, pointer,30); 				
					
				if (ds_lop.ds[vt]->tenLop.empty()) {
					gotoXY(120, 11);
					cout << "Ten Lop Rong";
				} else {
					gotoXY(120, 11);
					cout << "                  ";
				}		
			}			
			else if (pointer == 14) {
				ShowCur(0);
				int pointer2 = 90;
				while (true) {
					if (kbhit()) {
						char c = getch();
						if (c == 13) {
							if (!maLopTam.empty() && !kt_ma_lop_trung3(ds_lop, maLopTam, ds_lop.ds[vt]->maLop) &&
							!ds_lop.ds[vt]->tenLop.empty() && pointer2 == 90) {
								ds_lop.ds[vt]->maLop = maLopTam;
								DinhDangChuoi(ds_lop.ds[vt]->tenLop);								
								ThongBao("Cap nhat thanh cong");
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
							else if (pointer2 == 115) {	
								ds_lop.ds[vt]->tenLop = tenLopTam;							
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
							else
								ThongBao("Vui long dien day du thong tin");
						}
						else if (c == -32) {
							c = getch();
							if (c == 72) {
								Normal();
								gotoXY(115, 14);
								cout << "Thoat";
								gotoXY(90, 14);
								cout << "Cap Nhat";
								pointer = pointer - 3;
								break;
							}
							else if (c == 80) {
								Normal();
								gotoXY(115, 14);
								cout << "Thoat";
								gotoXY(90, 14);
								cout << "Cap Nhat";
								pointer = 8;
								break;
							}
							else if (c == 75) {
								if (pointer2 == 115)
									pointer2 = 90;
								else
									pointer2 = 115;
							}else if (c == 77) {
								if (pointer2 == 90)
									pointer2 = 115;
								else
									pointer2 = 90;
							}
							gotoXY(pointer2, 14);
						}
					}
					HighLight();
					gotoXY(pointer2, pointer);
					if (pointer2 == 90) {
						cout << "Cap Nhat";
						Normal();
						gotoXY(115, 14);
						cout << "Thoat";
					}
					else if (pointer2 == 115) {
						cout << "Thoat";
						Normal();
						gotoXY(90, 14);
						cout << "Cap Nhat";
					}
				}
			}
		}
			
	}
}


void XoaLop(DSLOP &ds_lop) {
	while(true)
	{
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maLop="";
		LayMaLop(ds_lop, maLop);
		
		if (maLop.compare("") == 0)
		{
			return;
		}
		
		int vt = kt_ma_lop_trung2(ds_lop, maLop);
		
		if(ds_lop.ds[vt]->listSV.pHead != NULL) {
			ThongBao("Khong the xoa lop vi lop co danh sach SV");
			goto a;
		}

		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	
		HDXoaLop();
				
		char c;
		GiaoDienThemLop();	
		gotoXY(80,8);
		cout << ds_lop.ds[vt]->maLop;
		gotoXY(80, 11 );
		cout << ds_lop.ds[vt]->tenLop;
		Normal();		
		
		int pointer = 90;
		
		while (true) {			
			gotoXY(90,14);
			ShowCur(0);
			cout << "Xoa Lop";	
			gotoXY(115, 14);
			Normal();
			cout << "Tro Lai";			
			if (kbhit()) {
				char c = getch();
				if (c == -32) {
					c = getch();
					if (c == 75) {
						if (pointer == 115) 
							pointer = 90;
						else
							pointer = 115;
					}
					else if (c == 77) {
						if (pointer == 90) 
							pointer = 115;
						else
							pointer = 90;
					}
							
				}else if (c == 13) 	{
					switch (pointer) {
						case 90: {
							delete ds_lop.ds[vt];
							for (int j = vt+1 ; j < ds_lop.sl; j++) {
									ds_lop.ds[j -1] = ds_lop.ds[j];
							}
							ds_lop.sl--;
							
//							for (int i = vt; i < ds_lop.sl - 1; i++) {
//									ds_lop.ds[i]->maLop = ds_lop.ds[i + 1]->maLop;
//									ds_lop.ds[i]->tenLop = ds_lop.ds[i + 1]->tenLop;
//							}
//							LOP* tam = ds_lop.ds[ds_lop.sl - 1];
//							ds_lop.sl--;
							ThongBao("Xoa Thanh Cong");
							XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
							goto a;
						}
						case 115:// tro lai
						{
							XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
							goto a;
						}
					}
				}
			}
			gotoXY(pointer, 14);
			HighLight();
			switch (pointer){
			case 90:
				cout << "Xoa Lop";
				break;
			case 115:
				cout << "Tro Lai";
				break;
			}
			Sleep(100);
			Normal();			
			
		}
			
	}
}

//================Xy ly danh sach sinh vien ==================
NODESV* Khoi_Tao_NODE(SV sv) {
	NODESV* p = new NODESV;
	if (p == NULL) {
		cout << "Cap phat that bai";
		return NULL;
	}
	p->data = sv;
	p->pNext = NULL;
	return p;
}

void Them_Cuoi(DSSV& l, NODESV* sv) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = sv;		
	}
	else {		
		l.pTail->pNext = sv;
		l.pTail = sv;		
	}	
}

void sap_xep_ds_sv(SV ds[], int n) {
	SV temp, temp1;
	for(int i = 0; i <n -1; i++) {
		for(int j= i + 1; j < n; j++) {
			string teni =cat_ho_ten(ds[i].ho + " " + ds[i].ten, 2);
			string tenj =cat_ho_ten(ds[j].ho + " " + ds[j].ten, 2);
			if(teni.compare(tenj) > 0) {
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}else if(teni.compare(tenj) == 0) {
				string hoi =cat_ho_ten(ds[i].ho + " " + ds[i].ten, 1);
				string hoj =cat_ho_ten(ds[j].ho + " " + ds[j].ten, 1);
				if(hoi.compare(hoj) > 0) {					
					temp1 = ds[i];
					ds[i] = ds[j];
					ds[j] = temp1;
				}	
			}
		}
	}
}


void chuyen_lkd_thanh_mang(DSSV l, SV ds[]) {
	int dem = 0;
	for (NODESV* k = l.pHead; k != NULL; k = k->pNext) {			
		ds[dem] = k->data;
		dem++;
	}
}

int CountSV(DSSV l) {
	int dem = 0;
	for (NODESV* k = l.pHead; k != NULL; k = k->pNext) {
			
		dem++;
	}
	return dem;
}

void XuatDanhSachSV(DSSV ds_sv, string maLop ) {

	int n = CountSV(ds_sv);	// so luong sv
	int trang = 1;
	int sotrang = 1;
	int phantutrang=10;	
	int i=0; 
	int dem = 0;	
	SV* ds = new SV[n];
	chuyen_lkd_thanh_mang(ds_sv, ds);
	sap_xep_ds_sv(ds, n);	
	HDXuatLop();
	
	if(n==0) {
		ThongBao("Danh Sach Sinh Vien Trong!");
		return;
	}
	
	if(n%10==0) {
		sotrang= n/10;
	
	}else {
		sotrang= n/10+1;		
	}
	
	if(n<=10)
	{
		GiaoDienSV(BoxMain[0]+6, BoxMain[2], n);
		for(int i=0; i<n; i++)		
		{
			BodyTable();
			gotoXY(toadoX + 10, toadoY + 5 + dem*2);
			cout <<ds[i].maSV;
			gotoXY(toadoX + 40, toadoY + 5 + dem*2 );
			cout <<ds[i].ho + " " + ds[i].ten;
			gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
			cout <<ds[i].phai;
			dem++;
		}
	
	}
	else
	{
		GiaoDienSV(BoxMain[0]+6, BoxMain[2], 10);
		for(int i=0;i<10;i++)
		{			
			BodyTable();
			gotoXY(toadoX + 10, toadoY + 5 + dem*2);
			cout <<ds[i].maSV;
			gotoXY(toadoX + 40, toadoY + 5 + dem*2 );
			cout <<ds[i].ho + " " + ds[i].ten;
			gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
			cout <<ds[i].phai;
			dem++;
		}
	}
		
	gotoXY(85,BoxMain[2]-2);
	cout<<"DANH SACH SINH VIEN LOP " + maLop;
	gotoXY(100,31);
	cout<<"<< "<<trang<<" >>";
	char c;
	

	while(true)
	{
		
		
		if(kbhit)
		{
			c=getch();
			if(c == -32)
			{

				c=getch();
				if(c == 77) // qua phai
				{
					dem = 0;					
					
					if(sotrang>1 && trang<sotrang)
					{
						phantutrang = n-trang*10;
						if(phantutrang>=10)
						{
							phantutrang=10;
							
						}
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);			
						GiaoDienSV(BoxMain[0]+6, BoxMain[2],phantutrang);
						for(int i=trang*10;i<trang*10+phantutrang;i++)
						{
							BodyTable();
							gotoXY(toadoX + 10, toadoY + 5 + dem*2);
							cout <<ds[i].maSV;
							gotoXY(toadoX + 40, toadoY + 5 + dem*2 );
							cout <<ds[i].ho + " " + ds[i].ten;
							gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
							cout <<ds[i].phai;							
							dem++;
						}
						trang++;
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}
				else  if(c==75)// qua trai
				{
					dem = 0;
					if(trang>1)
					{
						phantutrang=10;
						trang--;
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
						GiaoDienSV(BoxMain[0]+6, BoxMain[2],phantutrang);
						for(int i=trang*10-10;i<trang*10;i++)
						{
							BodyTable();
							gotoXY(toadoX + 10, toadoY + 5 + dem*2);
							cout <<ds[i].maSV;
							gotoXY(toadoX + 40, toadoY + 5 + dem*2 );
							cout <<ds[i].ho + " " + ds[i].ten;
							gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
							cout <<ds[i].phai;
							dem++;
						}
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}
				
			
			}
			else if(c==27)
			{
				delete[] ds;
				XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
				return;
			}	
		}
	}
	Normal();
}

void XuatDanhSachLop2(DSLOP ds_lop) {
	while(true)
	{
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maLop="";
		LayMaLop(ds_lop, maLop);
		
		if (maLop.compare("") == 0)
		{
			return;
		}
				
	
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);		  	
	
		int vt = kt_ma_lop_trung2(ds_lop,maLop);
		XuatDanhSachSV(ds_lop.ds[vt]->listSV, maLop);		
	}
}


void ThemSV(DSLOP ds_lop) {
	while(true) {
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maLop="";
		LayMaLop(ds_lop, maLop);
		
		if (maLop.compare("") == 0)
			return;
			
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);		  	
	
		NhapSV(ds_lop, maLop);
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	}
}

void ChonPhai(string& Phai, int& pointer2) {
	ShowCur(0);
	int pointer1 = 100;
	while (true) {
		gotoXY(100, 20);
		cout << "Nam";
		gotoXY(115, 20);
		cout << "Nu";

		if (kbhit()) {
			char c = getch();
			if (c == -32) {
				c = getch();
				if (c == 75) {
					if (pointer1 == 100)
						pointer1 = 115;
					else
						pointer1 = 100;
				}else if (c == 77) 	{
					if (pointer1 == 115)
						pointer1 = 100;
					else
						pointer1 = 115;
				}else if (c == 72) {
					ShowCur(1);
					pointer2 = pointer2 - 3;
					break;
				}
				else if (c == 80) {
					pointer2 = pointer2 + 3;
					break;
				}
			}
			if (c == 13) {
				HighLight();
				if (pointer1 == 100)
				{
					gotoXY(100, 20);
					cout << "Nam";
					Phai = "Nam";
					pointer2 = pointer2 + 3;
				}
				else if (pointer1 == 115)
				{
					gotoXY(115, 20);
					cout << "Nu";
					gotoXY(100,20);
					Normal();
					cout<<"Nam";
					Phai = "Nu";
					pointer2 = pointer2 + 3;
				}
				Normal();
				break;
			}
		}

		gotoXY(pointer1, 20);
		HighLight();
		if (pointer1 == 100)
			cout << "Nam";
		else if (pointer1 == 115)
			cout << "Nu";
		Normal();
		Sleep(100);
	}
}

void NhapSV(DSLOP l, string maLop) {
	ShowCur(1);
	int pointer1 =11; 
	GiaoDienThemSV();
	gotoXY(90,  8);
	cout<<maLop;
	SV sv;
	
	int vt = kt_ma_lop_trung2(l,maLop);
	while (true) 	{
		if (pointer1 == 11) {	
			gotoXY(90 + sv.maSV.length(), pointer1);
			XuLyNhap2(sv.maSV, 90, pointer1); 
			if (pointer1 < 11) {
				pointer1 = 26;
			}
			
			if (sv.maSV.empty()) 		{
				gotoXY(120, 11);
				cout << "Ma Sv Rong";
			}else if (KtMaSV(l, sv.maSV)) {
				gotoXY(120, 11);
				cout << "Ma SV Trung";
			}else {
				gotoXY(120, 11);
				cout << "                           ";
			}
		}else if (pointer1 == 14) {	
			gotoXY(90 + sv.ho.length(), pointer1);
			XuLyNhap1(sv.ho, 90, pointer1,30); 	
			if (sv.ho.empty()) 		{
				gotoXY(120, 14);
				cout << "Ho Rong";
			}else {
				gotoXY(120, 14);
				cout << "                           ";
			}		
		}else if (pointer1 == 17) { 		
			gotoXY(90 + sv.ten.length(), pointer1);
			XuLyNhap1(sv.ten, 90, pointer1, 8);
			
			if (sv.ten.empty()) 		{
				gotoXY(120, 17);
				cout << "Ten Rong";
			}else {
				gotoXY(120, 17);
				cout << "                           ";
			}
		}else if (pointer1 == 20) {	
			ChonPhai(sv.phai, pointer1);
		}else if (pointer1 == 23) {	
			ShowCur(1);
			gotoXY(90 + sv.password.length(), pointer1);
			XuLyNhap1(sv.password, 90, pointer1,30); 
			if (sv.password.empty()) 		{
				gotoXY(120, 23);
				cout << "Password Rong";
			}else {
				gotoXY(120, 23);
				cout << "                           ";
			}
		}else if (pointer1 == 26) {// save hoac huy		
			ShowCur(0);
			int pointer2 = 90;
			while (true) {
				if (kbhit()) {
					char c = getch();
					if (c == 13) {
						if (!sv.maSV.empty() && !KtMaSV(l, sv.maSV)
							&& !sv.ho.empty() && !sv.ten.empty() && !sv.phai.empty() && pointer2 == 90) {
							DinhDangChuoi(sv.ho);
							DinhDangChuoi(sv.ten);
							NODESV* p = Khoi_Tao_NODE(sv);
							Them_Cuoi(l.ds[vt]->listSV, p);
							ThongBao("Them sinh vien thanh cong");
							return;
						}
						else if (pointer2 == 115) {
							return;
						}
						else {
							ThongBao("Vui long dien day du thong tin");
						}
					}
					else if (c == -32) 	{
						c = getch();
						if (c == 72) {
							Normal();
							gotoXY(115, 26);
							cout << "Thoat";
							gotoXY(90, 26);
							cout << "Them";
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80) 	{
							Normal();
							gotoXY(115, 26);
							cout << "Thoat";
							gotoXY(90, 26);
							cout << "Them";
							ShowCur(1);
							pointer1 = 11;
							break;
						}
						else if (c == 75) {
							if (pointer2 == 115) 
								pointer2 = 90;
							else
								pointer2 = 115;
						}
						else if (c == 77) {
							if (pointer2 == 90) 
								pointer2 = 115;
							else
								pointer2 = 90;
						}
						gotoXY(pointer2, 26);
					}
				}

				HighLight();
				gotoXY(pointer2, pointer1);
				if (pointer2 == 90) {
					cout << "Them";
					Normal();
					gotoXY(115, 26);
					cout << "Thoat";
				}
				else if (pointer2 == 115) {
					cout << "Thoat";
					Normal();
					gotoXY(90, 26);
					cout << "Them";
				}
			}
		}
	}
}



void LayDSSV(DSSV l, string ma[],string ten[], int soluong) {
	int i = 0;
	if (soluong == 0) {
		return;
	}
	for (NODESV* k = l.pHead; k != NULL; k = k->pNext) {			
		ma[i]= k->data.maSV;
		ten[i] = k->data.ho + " " +k->data.ten;
		i++;
	}
}

void sap_xep_mangt_theo_ten(string ma[], string ten[], int n) {	
	string temp;
	for(int i = 0; i <n - 1; i++) {			
		for(int j= i + 1; j < n; j++) {
			if(ma[i].compare(ma[j]) == 1) {				
				temp = ma[i];
				ma[i] = ma[j];
				ma[j] = temp;
				
				temp = ten[i];
				ten[i] = ten[j];
				ten[j] = temp;
			}
		}
	}
}

void LayMaSV(DSSV l, string &maSV) {
	HDXemThongTinLop();
	
	int n = CountSV(l); // So luong phan tu cua ds lop
	int toadoX= BoxMain[0]+10;
	int toadoXtam;
	int toadoY = BoxMain[2]+3;
	int pointer=toadoY;
	GiaoDienTimkiemSV();
	string *ten=new string[n];	
	string *ma=new string[n];//ma sv

	LayDSSV(l,ma,ten, n);
	sap_xep_mangt_theo_ten(ma, ten,n);
	char c;
	int i=0;
	int vitri=0;
	bool key=true; 
	

	do{
		if(n==0) 
		{
			ThongBao("Khong co sinh vien nao !!");
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			return;
		}
		else{
			BodyTable();
			for(int i = vitri; i < n; i++) {
				if((i-(vitri))==20) break;
				gotoXY(BoxMain[0] +10 , toadoY+i-(vitri));
				cout<<CanDeuChuoi(ma[i],20)<<char(179)<<CanDeuChuoi(ten[i],45);
			}
			gotoXY(BoxMain[0]+10,pointer);
			HighLight();
			cout<<CanDeuChuoi(ma[pointer-(BoxMain[2]+3)+vitri],20)<<char(179)<<CanDeuChuoi(ten[pointer-(BoxMain[2]+3)+vitri],45);
			i=pointer-(BoxMain[2]+3)+vitri;
			Normal();
			ShowCur(0);
			if(kbhit) {
				d:c=getch();
				if(c == 13) { //enter
					maSV=ma[i];					
					key=false;	
				}else if(c == 27) { 
					key=false;	
				} else if(c == -32)	{
					c = getch(); 
					if(c == 72) { 
						if(pointer > toadoY)						
							pointer--;						
						else if(pointer == toadoY && vitri > 0) {
							vitri--;
						}
					} else if(c == 80) { 
						if(vitri> n-21 && vitri< n-1)	{
							if( i > n-2) goto d;
							else {
								if(pointer < MaxBox)	
									pointer++;
								else if(pointer==MaxBox && vitri<n-21)	
									vitri++;
							}						
						}
						else if (vitri == n-1) goto d;
						else if(pointer < MaxBox)		
							pointer++;
						else if(pointer == MaxBox && vitri<n-20)	{
							vitri++;
						}
					}
				}
			}
		}
	}while(key);
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	delete[]ten;
	delete[]ma;
	ShowCur(0);
}

SV LayThongTinSV(DSSV l, string maSV) {
	for (NODESV* k = l.pHead; k != NULL; k = k->pNext) {			
		if (k->data.maSV.compare(maSV) == 0) {
				return k->data;
		}	
	}
}

bool KtMaSV2(DSLOP ds_lop, string maSV, string maBD) {
	if(maBD.compare(maSV) == 0) {
		return false;
	}
	
	for (int i = 0; i < ds_lop.sl; i++) {
		for (NODESV* k = ds_lop.ds[i]->listSV.pHead; k != NULL; k = k->pNext) {
			if (k->data.maSV.compare(maSV) == 0) {
				return true;
			}
		}
	}
	return false;
}

void HieuChinhSV(DSLOP ds_lop) {
	while(true) {
		b:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maLop = "";
		string maSV = "";
		LayMaLop(ds_lop, maLop);
		
		if (maLop.compare("") == 0)
			return;
				
		int vt = kt_ma_lop_trung2(ds_lop,maLop);
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);	
			  	
		if(!maSV.empty()) 
			maSV = "";
		
		LayMaSV(ds_lop.ds[vt]->listSV, maSV);		
		if(maSV.compare("") == 0) {
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			goto b;
		}
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		
		HDNhapLop();
		
		SV sv = LayThongTinSV(ds_lop.ds[vt]->listSV, maSV);
		string maBD = sv.maSV;
		
		int pointer = 11;
		char c;
		GiaoDienThemSV();
		gotoXY(90,  26);
		cout << "Cap Nhat";
		gotoXY(85,  8);
		cout<<maLop;
		gotoXY(90,11);
		cout << sv.maSV;
		gotoXY(90, 14);
		cout << sv.ho;
		gotoXY(90, 17);	
		cout << sv.ten;		
		if(sv.phai=="Nam"){
			gotoXY(100,20);
			HighLight();
			cout<<"Nam";
		}
		else{
			gotoXY(115,20);
			HighLight();
			cout<<"Nu";
		}
		Normal();
		gotoXY(90, 23);	
		cout <<sv.password;
		Normal();
		ShowCur(1);
		
		
		while (true) {			
			if (pointer == 11){ 			
				ShowCur(1);
				gotoXY(90+sv.maSV.length(), pointer);
				XuLyNhap2(sv.maSV, 90, pointer); 
				if (pointer < 11) {
					pointer = 26;
				}	
				
				if (sv.maSV.empty()) 		{
					gotoXY(120, 11);
					cout << "Ma SV Rong";
				}else if (KtMaSV2(ds_lop, sv.maSV, maBD)) {
					gotoXY(120, 11);
					cout << "Ma SV Trung";
				}
				else {
					gotoXY(120, 11);
					cout << "                           ";
				}				
			}else if (pointer == 14){ 			
				ShowCur(1);
				gotoXY(90+sv.ho.length(), pointer);
				XuLyNhap1(sv.ho, 90, pointer,30); 	
				
				if (sv.ho.empty()) 		{
					gotoXY(120, 14);
					cout << "Ho Rong";
				}else {
					gotoXY(120, 14);
					cout << "                           ";
				}				
			}else if (pointer == 17){ 
				gotoXY(90+sv.ten.length(), pointer);
				XuLyNhap1(sv.ten, 90, pointer,8); 
				
				if (sv.ten.empty()) 		{
					gotoXY(120, 17);
					cout << "Ten Rong";
				}else {
					gotoXY(120, 17);
					cout << "                           ";
				}			
			}else if (pointer == 20){ 		
				ChonPhai( sv.phai, pointer);			
			}else if (pointer == 23){ 
				ShowCur(1);
				gotoXY(90+sv.password.length(), pointer);
				XuLyNhap1(sv.password, 90, pointer,30); 
				
				if (sv.password.empty()) 		{
					gotoXY(120, 23);
					cout << "Password Rong";
				}else {
					gotoXY(120, 23);
					cout << "                           ";
				}				
			}			
			else if (pointer == 26) { 				
				ShowCur(0);
				int pointer2 = 90;
				while (true)
				{
					if (kbhit())
					{
						char c = getch();
						if (c == 13) {
							if (!sv.maSV.empty() && !KtMaSV2(ds_lop, sv.maSV, maBD) &&
							!sv.ho.empty() && !sv.ten.empty() && !sv.phai.empty() && !sv.password.empty() && pointer2 == 90) {
								DinhDangChuoi(sv.ho);
								DinhDangChuoi(sv.ten);
								sv.password = trim(sv.password);	
								for (NODESV* k = ds_lop.ds[vt]->listSV.pHead; k != NULL; k = k->pNext) {			
									if (k->data.maSV.compare(maSV) == 0) {
										k->data.maSV = sv.maSV;
										k->data.ho = sv.ho;
										k->data.ten = sv.ten;
										k->data.phai = sv.phai;
										k->data.password = sv.password;
									}	
								}				
								ThongBao("Cap nhat thanh cong");
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
							else if (pointer2 == 115)	{							
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
							else 
								ThongBao("Vui long dien day du thong tin");
						}
						else if (c == -32) {
							c = getch();
							if (c == 72) {
								Normal();
								gotoXY(115, 26);
								cout << "Thoat";
								gotoXY(90, 26);
								cout << "Cap Nhat";
								pointer = pointer - 3;
								break;
							}
							else if (c == 80) {
								Normal();
								gotoXY(115, 26);
								cout << "Thoat";
								gotoXY(90, 26);
								cout << "Cap Nhat";
								pointer = 11;
								break;
							}
							else if (c == 75) {
								if (pointer2 == 115) {
									pointer2 = 90;
								}
								else
									pointer2 = 115;
							}
							else if (c == 77) {
								if (pointer2 == 90) {
									pointer2 = 115;
								}
								else
									pointer2 = 90;
							}
							gotoXY(pointer2, 26);
						}
					}
					HighLight();
					
					gotoXY(pointer2, pointer);
					if (pointer2 == 90)
					{
						cout << "Cap Nhat";
						Normal();
						gotoXY(115, 26);
						cout << "Thoat";
					}
					else if (pointer2 == 115)
					{
						cout << "Thoat";
						Normal();
						gotoXY(90, 26);
						cout << "Cap Nhat";
					}
				}
			}
		} 	
	}
}

void XoaDau(DSSV& l) {
		NODESV* p = l.pHead;
		l.pHead = p->pNext;
		delete p;
	}
void XoaCuoi(DSSV& l) {
	for (NODESV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pNext == l.pTail) {
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k;
		}
	}
}
void xoa_node(DSSV& l, string maSV) {
	if (l.pHead == NULL) {
			return;
	}
	if (l.pHead->data.maSV.compare(maSV) == 0) {
		XoaDau(l);
	}
	if (l.pTail->data.maSV.compare(maSV) == 0) {
		XoaCuoi(l);
	}
	NODESV* g = new NODESV;
	for (NODESV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data.maSV.compare(maSV) == 0) {
			g->pNext = k->pNext;
			delete k;
			return;
		}
		g = k;
	}
}

void XoaSV(DSLOP ds_lop) {
	while(true)
	{
		b:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maLop = "";
		string maSV = "";
		LayMaLop(ds_lop, maLop);
		
		if (maLop.compare("") == 0) {
			return;
		}
				
		int vt = kt_ma_lop_trung2(ds_lop,maLop);
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);		  	
		if(!maSV.empty()) {
			maSV = "";
		}
		
		LayMaSV(ds_lop.ds[vt]->listSV, maSV);
		if(maSV.compare("") == 0){
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			goto b;
		}
		
					
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		SV sv = LayThongTinSV(ds_lop.ds[vt]->listSV, maSV);	
		if(sv.listDiem.pHead != NULL) {
			ThongBao("Khong the xoa SV vi SV co danh sach diem");
			goto a;
		}
		HDXoaLop();
		
		int pointer;
		char c;
		GiaoDienThemSV();
		gotoXY(90, 8);
		cout<<maLop;		
		gotoXY(90, 11);
		cout << sv.maSV;
		gotoXY(90, 14);
		cout << sv.ho;
		gotoXY(90, 17);	
		cout << sv.ten;		
		if(sv.phai=="Nam") {
			gotoXY(100,20);
			HighLight();
			cout<<"Nam";
		}
		else {
			gotoXY(115,20);
			HighLight();
			cout<<"Nu";
		}
		Normal();
		gotoXY(90, 23);	
		cout << sv.password;
		Normal();
		ShowCur(1);
		pointer = 90; 
		
		while (true) {			
			gotoXY(90,26);
			ShowCur(0);
			cout << "Xoa Sinh Vien";	
			gotoXY(115, 26);
			Normal();
			cout << "Tro Lai";				
			if (kbhit()) {
				char c = getch();
				if (c == -32) {
					c = getch();
					if (c == 75) {
						if (pointer == 115) 
							pointer = 90;
						else
							pointer = 115;
					}
					else if (c == 77) {
						if (pointer == 90) 
							pointer = 115;
						else
							pointer = 90;
					}
							
				}
				else if (c == 13) 	{
					switch (pointer) {
						case 90:// xoa the
						{
							xoa_node(ds_lop.ds[vt]->listSV, maSV);
							ThongBao("Xoa Sinh Vien Thanh Cong");
							XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
							goto a;
						}
						case 115:// tro lai
						{
							XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
							goto a;
						}
					}
				}
			}
			gotoXY(pointer, 26);
			HighLight();
			switch (pointer){
			case 90:
				cout << "Xoa Sinh Vien";
				break;
			case 115:
				cout << "Tro Lai";
				break;
			}
			Sleep(100);
			Normal();			
		} 	
	}
}

void NodeTheMang(TREE &X, TREE &Y) {    
    if (Y->pLeft != NULL)
        NodeTheMang(X, Y->pLeft);
    else {
        X->data = Y->data; 
        X = Y; 
        Y = Y->pRight; 
   	}
}
 
void Xoa_1_MH(TREE &t, string ma) {
	
	int ma1 = chuoi_to_so(t->data.maMH);
	int ma2 = chuoi_to_so(ma);
	
    if (t == NULL)
        return; 
    else{	
        if (ma2 < ma1) 
            Xoa_1_MH(t->pLeft, ma); 
        else if (ma2 > ma1) 
            Xoa_1_MH(t->pRight, ma);
        else {
            NODEMH *X = t;            
            if (t->pLeft == NULL)                       
                t = t->pRight; 
            else if (t->pRight == NULL)
               t = t->pLeft; 
            else {
               	NODEMH *Y = t->pRight; 
            	NodeTheMang(X, t->pRight);               
            }
            delete X; 
        }
    }
}

void XoaMH(TREE &t) {
	while(true) {
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maMH="";
		LayMaMH(t, maMH);
		if (maMH.compare("") == 0)
		{
			return;
		}
		
		TREE tam = NULL;
		
		LayThongTinMH(t, maMH, tam);
		
		if(tam->listCauHoi.sl > 0) {
			ThongBao("Khong the xoa MH vi MH co danh sach cau hoi");
			goto a;
		}
		
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		
	  	HDXoaLop();
		
		char c;
		GiaoDienThemMH();
		gotoXY(100,8);
		cout << tam->data.maMH;
		gotoXY(100, 11);
		cout << tam->data.tenMH;
		Normal();
		int pointer = 90;
		
		while (true) {			
			gotoXY(90,14);
			ShowCur(0);
			cout << "Xoa Mon Hoc";	
			gotoXY(115, 14);
			Normal();
			cout << "Tro Lai";				
			if (kbhit()) {
				char c = getch();
				if (c == -32) {
					c = getch();
					if (c == 75) {
						if (pointer == 115) 
							pointer = 90;
						else
							pointer = 115;
					}
					else if (c == 77) {
						if (pointer == 90) 
							pointer = 115;
						else
							pointer = 90;
					}
							
				}else if (c == 13) 	{
					switch (pointer) {
						case 90: {
							Xoa_1_MH(t, tam->data.maMH);
							ThongBao("Xoa Mon Hoc Thanh Cong");
							XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
							goto a;
						}
						case 115: {
							XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
							goto a;
						}
					}
				}
			}
			gotoXY(pointer, 14);
			HighLight();
			switch (pointer){
			case 90:
				cout << "Xoa Mon Hoc";
				break;
			case 115:
				cout << "Tro Lai";
				break;
			}
			Sleep(100);
			Normal();			
		} 	
		
	}
}


//================== Xu ly danh sach mon hoc ================

NODEMH* KhoiTaoNodeMH(MH mh) {
	NODEMH* p = new NODEMH;
	if (p != NULL) {		
		p->data = mh;
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}

void ThemNode(TREE &t, MH x) {
	if (t == NULL)
	{
		NODEMH *p = new NODEMH;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		int ma1 = chuoi_to_so(t->data.maMH);
		int ma2 = chuoi_to_so(x.maMH);
		if ( ma1 > ma2 ){
			
			ThemNode(t->pLeft, x);
		}
		else if (ma1 < ma2) {
			
			ThemNode(t->pRight, x);
		}
	}
}

void Them1MH(TREE& t, NODEMH* p) {
  
  	if (t == NULL)
	{
		t = p;
	}
	else
	{
		int ma1 = chuoi_to_so(t->data.maMH);
		int ma2 = chuoi_to_so(p->data.maMH);
		if (ma1 > ma2) {

			Them1MH(t->pLeft, p);
		}
		else if (ma1 < ma2) {

			Them1MH(t->pRight, p);
		}
	}
}

int SoNodeTrongTREE(TREE t) {
	if(t == NULL)
		return 0;
	else return (SoNodeTrongTREE(t->pRight) + SoNodeTrongTREE(t->pLeft)) + 1;
}

void chuyen_cay_sang_mang(TREE T,MH ds[], int& nds) {
	if (T != NULL) {
		ds[nds] = T->data;
		nds++;
		chuyen_cay_sang_mang(T->pLeft, ds, nds);
		chuyen_cay_sang_mang(T->pRight, ds, nds);
	}
}


void sap_xep_ds_mon_hoc(MH ds[], int& nds) {
	MH temp;
	for (int i = 0; i < nds - 1; i++)
	{
		for (int j = i + 1; j < nds; j++)
		{
			if (ds[i].tenMH > ds[j].tenMH) {
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}

void kt_ma_mh_trung(TREE t, string a, int& kt) {
	int x = chuoi_to_so(a);
	
    if(t == NULL) {
    	kt = 0;
    	return;
	}else {
		int ma = chuoi_to_so(t->data.maMH);
		if(ma == x) {
			kt = 1;				
			return;
		}
		else if (ma < x) {
			kt_ma_mh_trung(t->pRight, a, kt);
		}
		else if (ma > x) {
			kt_ma_mh_trung(t->pLeft, a, kt);
		}
	}	
}



void XuatDanhSachMH(TREE t) {
	int n = 0;
	int trang = 1;
	int sotrang = 1;
	int phantutrang=10;
	MH ds[1000];		
	int dem = 0;
	chuyen_cay_sang_mang(t, ds, n);
	sap_xep_ds_mon_hoc(ds, n);
	
	HDXuatLop();
	
	if(n==0)
	{
		ThongBao("Danh sach mon hoc rong!");
		return;
	}
	if( n%10==0)
	{
		sotrang= n/10;
	
	}
	else
	{
		sotrang= n/10+1;
		
	}
	if(n<=10)
	{
		GiaoDienMH(BoxMain[0]+6, BoxMain[2], n);
		for (int i = 0; i < n; i++)
		{
			BodyTable();
			gotoXY(toadoX + 10, toadoY + 5 + dem*2);
			cout <<ds[i].maMH;
			gotoXY(toadoX + 50, toadoY + 5 + dem*2 );
			cout <<ds[i].tenMH;
			dem++;
		}
	}
	else
	{
		GiaoDienMH(BoxMain[0]+6, BoxMain[2], 10);
		for (int i = 0; i < 10; i++)
		{
			BodyTable();
			gotoXY(toadoX + 10, toadoY + 5 + dem*2);
			cout <<ds[i].maMH;
			gotoXY(toadoX + 50, toadoY + 5 + dem*2 );
			cout <<ds[i].tenMH;
			dem++;
		}
	}
	gotoXY(90,BoxMain[2]-2);
	cout<<"DANH SACH MON HOC";
	gotoXY(100,31);
	cout<<"<< "<<trang<<" >>";
	char c;
	

	while(true)
	{
		
		if(kbhit)
		{
			c=getch();
			if(c == -32)
			{

				c=getch();
				if(c == 77) // qua phai
				{
					dem = 0;
					if(sotrang>1 && trang<sotrang)
					{
						phantutrang = n-trang*10;
						if(phantutrang>=10)
						{
							phantutrang=10;
							
						}
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);						
						GiaoDienMH(BoxMain[0]+6, BoxMain[2], phantutrang);
						for(int i=trang*10;i<trang*10+phantutrang;i++)
						{
							BodyTable();
							gotoXY(toadoX + 10, toadoY + 5 + dem*2);
							cout <<ds[i].maMH;
							gotoXY(toadoX + 50, toadoY + 5 + dem*2 );
							cout <<ds[i].tenMH;
							dem++;
						}
						trang++;
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}
				else  if(c==75)// qua trai
				{
					dem = 0;
					if(trang>1) {
						phantutrang=10;
						trang--;
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
						GiaoDienMH(BoxMain[0]+6, BoxMain[2], phantutrang);
						for (int i=trang*10-10;i<trang*10;i++)
						{
							BodyTable();
							gotoXY(toadoX + 10, toadoY + 5 + dem*2);
							cout <<ds[i].maMH;
							gotoXY(toadoX + 50, toadoY + 5 + dem*2 );
							cout <<ds[i].tenMH;
							dem++;
						}
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}
				
			
			}
			else if(c==27)
			{
				XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
				return;
			}	
		}
	}
	Normal();
}



bool NhapMH(TREE& t) {
	ShowCur(1);
	int pointer1 =8; 
	GiaoDienThemMH();
	MH mh;
	int kt = 0;
	string temp;
	while (true) 	{
		if (pointer1 == 8) {
			ShowCur(1);	
			gotoXY(85 + mh.maMH.length() , pointer1);
			XuLyNhap4(mh.maMH, 85, pointer1, 15); 			
			kt_ma_mh_trung(t, mh.maMH, kt);
			if (pointer1 < 8) {
				pointer1 = 14;
			}
			
			if (mh.maMH.empty()) {
				gotoXY(120, 8);
				cout << "Ma Mon Hoc Rong";
			}else if (kt == 1) {
				gotoXY(120, 8);
				cout << "Ma Mon Hoc Trung";
			}else {
				kt = 0;
				gotoXY(120, 8);
				cout << "                        ";
			}
			
		}
		else if (pointer1 == 11) {
			ShowCur(1);
			gotoXY(85 + mh.tenMH.length(), pointer1);
			XuLyNhap1(mh.tenMH, 85, pointer1,30);		
			if (mh.tenMH.empty()) {
				gotoXY(120, 11);
				cout << "Ten Mon Hoc Rong";
			}else {
				gotoXY(120, 11);
				cout << "                   ";
			}	
		}		
		else if (pointer1 == 14) {
			ShowCur(0);
			int pointer2 = 90;
			while (true) {
				if (kbhit()) {
					char c = getch();
					if (c == 13) {
						if (kt == 0 && 	!mh.maMH.empty() && !mh.tenMH.empty() && pointer2 == 90) {							
							DinhDangChuoi(mh.tenMH);
							ThemNode(t,mh);
							return true;
						}
						else if (pointer2 == 115) {
							return false;
						}
						else {
							ThongBao("Vui long dien day du thong tin");
						}
					}
					else if (c == -32) 	{
						c = getch();
						if (c == 72) {
							Normal();
							gotoXY(115, 14);
							cout << "Thoat";
							gotoXY(90, 14);
							cout << "Them";
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80) 	{
							Normal();
							gotoXY(115, 14);
							cout << "Thoat";
							gotoXY(90, 14);
							cout << "Them";
							pointer1 = 8;
							break;
						}
						else if (c == 75) {
							if (pointer2 == 115) 
								pointer2 = 90;
							else
								pointer2 = 115;
						}
						else if (c == 77) {
							if (pointer2 == 90) 
								pointer2 = 115;
							else
								pointer2 = 90;
						}
						gotoXY(pointer2, 14);
					}
				}

				HighLight();
				gotoXY(pointer2, pointer1);
				if (pointer2 == 90) {
					cout << "Them";
					Normal();
					gotoXY(115, 14);
					cout << "Thoat";
				}
				else if (pointer2 == 115) {
					cout << "Thoat";
					Normal();
					gotoXY(90, 14);
					cout << "Them";
				}
			}
		}
	}
}


void ThemMH(TREE &t) {
	XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	HDXemThongTinLop();
	
	if (!NhapMH(t)) {
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		return;
	}	
	ThongBao("Them mon hoc thanh cong");
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);	
}

void LayDSMH(MH ds[], int n, string maMH[], string tenMH[]) {
	if (n==0)
		return;
	for (int i = 0; i < n; i++) {
		maMH[i] = ds[i].maMH;
		tenMH[i] = ds[i].tenMH;	
	}
}

void LayThongTinMH(TREE t, string maMH, TREE &tam) {
	
	int ma1 = chuoi_to_so(t->data.maMH);
	int ma2 = chuoi_to_so(maMH);
	
	if (t == NULL) 
		return;
	else if (ma1 == ma2) {
		tam = t;
		return;
	}
	else if (ma2 > ma1) {
		LayThongTinMH(t->pRight, maMH, tam);
	}
	else {
		LayThongTinMH(t->pLeft, maMH, tam);
	}
}



void LayMaMH(TREE t, string &maMH) {
	
	int toadoX= BoxMain[0]+10;
	int toadoXtam;
	int toadoY = BoxMain[2]+3;
	int pointer=toadoY;
	GiaoDienTimkiemMH();
	
	MH ds[1000];		
	int nds = 0;	
	chuyen_cay_sang_mang(t, ds, nds);
	sap_xep_ds_mon_hoc(ds, nds);
	string *ten=new string[nds];	
	string *ma=new string[nds];

	LayDSMH(ds, nds, ma, ten);
	char c;

	int i=0;
	int vitri=0;
	bool key=true; 
	

	do {
		if(nds == 0)  {
			ThongBao("Khong co mon hoc nao !!");
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			return;
		} else {
			BodyTable();
			for(int i=vitri;i<nds;i++) {
				if((i-(vitri))==20) break;
				gotoXY(BoxMain[0] +10 , toadoY+i-(vitri));
				cout<<CanDeuChuoi(ma[i],20)<<char(179)<<CanDeuChuoi(ten[i],45);
			}
			gotoXY(BoxMain[0]+10,pointer);
			HighLight();
			cout<<CanDeuChuoi(ma[pointer-(BoxMain[2]+3)+vitri],20)<<char(179)<<CanDeuChuoi(ten[pointer-(BoxMain[2]+3)+vitri],45);
			i=pointer-(BoxMain[2]+3)+vitri;
			Normal();
			ShowCur(0);
			if(kbhit) {
				a:c=getch();
				if(c == 13) { //enter
					maMH=ma[i];					
					key=false;	
				}else if(c == 27) { 
					key=false;	
				} else if(c == -32)	{
					c = getch(); 
					if(c == 72) { 
						if(pointer > toadoY)						
							pointer--;						
						else if(pointer == toadoY && vitri > 0) {
							vitri--;
						}
					} else if(c == 80) { 
						if(vitri> nds-21 && vitri< nds-1)	{
							if( i > nds-2) goto a;
							else {
								if(pointer < MaxBox)	
									pointer++;
								else if(pointer==MaxBox && vitri<nds-21)	
									vitri++;
							}						
						}
						else if (vitri == nds-1) goto a;
						 else if(pointer < MaxBox)		
							pointer++;
						 else if(pointer == MaxBox && vitri<nds-20)	{
							vitri++;
						}
					}
				}
			}
		}
	}while(key);
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	delete[]ma;
	delete[]ten;
	ShowCur(0);
}



void HieuChinhMH(TREE &t) {
	while(true)
	{
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maMH="";
		LayMaMH(t, maMH);
		if (maMH.compare("") == 0)
			return;
		TREE tam = NULL;
		LayThongTinMH(t, maMH, tam);
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		
	  	HDNhapLop();
		// luu lai cac gia tri
		string tenMHTam;		
		tenMHTam = tam->data.tenMH;
		int kt = 0;
		int pointer = 11;
		char c;
		GiaoDienThemMH();
		gotoXY(90,  14);
		cout << "Cap Nhat";
		gotoXY(85,8);
		cout << tam->data.maMH;
		gotoXY(85, 11);
		cout << tam->data.tenMH;
		gotoXY(100, 14);	
		Normal();
		ShowCur(1);
		pointer = 11;
		
		while (true) {	
			if (pointer == 11) {
				ShowCur(1);
				gotoXY(85+tam->data.tenMH.length(), pointer);
				XuLyNhap1(tam->data.tenMH, 85, pointer,30); 
				if (pointer < 11) {
					pointer = 14;
				}	
				
				if (tam->data.tenMH.empty()) {
					gotoXY(120, 11);
					cout << "Ten Mon Hoc Rong";
				}else {
					gotoXY(120, 11);
					cout << "                   ";
				}	
			}			
			else if (pointer == 14) {
				ShowCur(0);
				int pointer2 = 90;
				while (true)
				{
					if (kbhit())
					{
						char c = getch();
						if (c == 13)
						{
							if (!tam->data.tenMH.empty() &&  pointer2 == 90) {
								DinhDangChuoi(tam->data.tenMH);
								ThongBao("Cap nhat thanh cong");
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);								
								goto a;
							}
							else if (pointer2 == 115) {
								tam->data.tenMH = tenMHTam;								
								XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
							else
								ThongBao("Vui long dien day du thong tin");
						}
						else if (c == -32) {
							c = getch();
							if (c == 72) {
								Normal();
								gotoXY(115, 14);
								cout << "Thoat";
								gotoXY(90, 14);
								cout << "Cap Nhat";
								pointer = pointer - 3;
								break;
							}
							else if (c == 80) {
								Normal();
								gotoXY(115, 14);
								cout << "Thoat";
								gotoXY(90, 14);
								cout << "Cap Nhat";
								pointer = 11;
								break;
							}
							else if (c == 75) {
								if (pointer2 == 115)
									pointer2 = 90;
								else
									pointer2 = 115;
							}
							else if (c == 77) {
								if (pointer2 == 90)
									pointer2 = 115;
								else
									pointer2 = 90;
							}
							gotoXY(pointer2, 14);
						}
					}
					HighLight();
					gotoXY(pointer2, pointer);
					if (pointer2 == 90) {
						cout << "Cap Nhat";
						Normal();
						gotoXY(115, 14);
						cout << "Thoat";
					}
					else if (pointer2 == 115) {
						cout << "Thoat";
						Normal();
						gotoXY(90, 14);
						cout << "Cap Nhat";
					}
				}
			}
		}
		
	}
}
//================================Xu ly them cau hoi==============================
void ThemCauHoi(TREE &t) {
	while(true) {
		a:XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maMH="";
		LayMaMH(t, maMH);
		if (maMH.compare("") == 0)	
			return;		
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);		
		TREE tam = NULL;
		LayThongTinMH(t,maMH,tam);
		
		if(tam->listCauHoi.sl >= 200) {
			ThongBao("Danh sach cau hoi day");
			goto a;
		}
			
		CAUHOI ch;
		ch.id = tam->listCauHoi.sl + 1;		
		int pointer = 11;
		char c;
		
		GiaoDienThemCH();
		HDNhapLop();
		Normal();
		ShowCur(1);
		gotoXY(76,5);
		cout<<tam->data.tenMH<<"(Ma "<<tam->data.maMH<<")";
		gotoXY(147, 5);
		cout<<ch.id - 1<<"/200";
		gotoXY(100, 8);		
		cout<<ch.id;
	
		while (true) {			
			if (pointer == 11) {
				ShowCur(1);
				gotoXY(70+ch.noiDung.length(), pointer);
				XuLyNhapND(ch.noiDung, 70, pointer,30); 
				if (pointer < 11) {
					pointer = 29;
				}
				
				if (ch.noiDung.empty()) {
					gotoXY(120, 11);
					cout << "Noi dung Rong";					
				}else {
					gotoXY(120, 11);
					cout << "                   ";
				}	
			}else if (pointer == 14)	{
				ShowCur(1);
				gotoXY(70+ch.A.length(), pointer);
				XuLyNhap1(ch.A, 70, pointer,30); 
				if (ch.A.empty()) {
					gotoXY(120, 14);
					cout << "Cau A Rong";
				}else if (ch.A.compare(ch.B) == 0 || ch.A.compare(ch.C) == 0 || ch.A.compare(ch.D) == 0) {
					gotoXY(120, 14);
					cout << "Trung dap an";
				} else {
					gotoXY(120, 14);
					cout << "                   ";
				}	
			}		
			else if (pointer == 17) {
				ShowCur(1);
				gotoXY(70+ch.B.length(), pointer);
				XuLyNhap1(ch.B, 70, pointer,30); 
				if (ch.B.empty()) {
					gotoXY(120, 17);
					cout << "Cau B Rong";
				}else if (ch.B.compare(ch.A) == 0 || ch.B.compare(ch.C) == 0 || ch.B.compare(ch.D) == 0) {
					gotoXY(120, 17);
					cout << "Trung dap an";
				}else {
					gotoXY(120, 17);
					cout << "                   ";
				}	
			}else if (pointer == 20) {
				ShowCur(1);
				gotoXY(70+ch.C.length(), pointer);
				XuLyNhap1(ch.C, 70, pointer,30); 
				if (ch.C.empty()) {
					gotoXY(120, 20);
					cout << "Cau C Rong";
				}else if (ch.C.compare(ch.B) == 0 || ch.C.compare(ch.A) == 0 || ch.C.compare(ch.D) == 0) {
					gotoXY(120, 20);
					cout << "Trung dap an";
				}else {
					gotoXY(120, 20);
					cout << "                   ";
				}	
			}else if (pointer == 23) {
				ShowCur(1);
				gotoXY(70+ch.D.length(), pointer);
				XuLyNhap1(ch.D, 70, pointer,30); 
				if (ch.D.empty()) {
					gotoXY(120, 23);
					cout << "Cau D Rong";
				}else if (ch.D.compare(ch.B) == 0 || ch.D.compare(ch.C) == 0 || ch.D.compare(ch.A) == 0){
					gotoXY(120, 23);
					cout << "Trung dap an";
				}else {
					gotoXY(120, 23);
					cout << "                   ";
				}	
			}else if (pointer == 26) {
				ShowCur(1);
				gotoXY(70+ch.DA.length(), pointer);
				XuLyNhapDA(ch.DA, 70, pointer); 
				if (ch.DA.empty()) {
					gotoXY(120, 26);
					cout << "Dap an rong";
				}else {
					gotoXY(120, 26);
					cout << "                   ";
				}	
			}else if (pointer == 29)	{
				ShowCur(0);
				int pointer2 = 90;
				while (true) {
					if (kbhit()) {
						char c = getch();
						if (c == 13) {
							if (!ch.noiDung.empty() && !ch.A.empty() && !ch.B.empty() && !ch.C.empty() && !ch.D.empty() && !ch.DA.empty() && 
							   (ch.A.compare(ch.B) == 0 && ch.A.compare(ch.B) == 0 && ch.A.compare(ch.D) == 0) == 0 &&
							   (ch.B.compare(ch.A) == 0 || ch.B.compare(ch.C) == 0 || ch.B.compare(ch.D) == 0) == 0 &&
							   (ch.C.compare(ch.A) == 0 || ch.C.compare(ch.B) == 0 || ch.C.compare(ch.D) == 0) == 0 &&
							   (ch.D.compare(ch.B) == 0 || ch.D.compare(ch.C) == 0 || ch.D.compare(ch.A) == 0) == 0 &&	pointer2 == 90) {
								DinhDangChuoi(ch.noiDung);
								DinhDangChuoi(ch.A);
								DinhDangChuoi(ch.B);
								DinhDangChuoi(ch.C);
								DinhDangChuoi(ch.D);
								tam->listCauHoi.ds[tam->listCauHoi.sl] = ch;								
								tam->listCauHoi.sl++;								
								ThongBao("Them cau hoi thanh cong");
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}else if (pointer2 == 115){
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
							else {
								ThongBao("Them cau hoi that bai");
							}
						} else if (c == -32) 	{
							c = getch();
							if (c == 72) {
								Normal();
								gotoXY(115, 29);
								cout << "Thoat";
								gotoXY(90, 29);
								cout << "Them";
								pointer = pointer - 3;
								break;
							}
							else if (c == 80) {
								Normal();
								gotoXY(115, 29);
								cout << "Thoat";
								gotoXY(90, 29);
								cout << "Them";
								pointer = 11;
								break;
							}
							else if (c == 75) {
								if (pointer2 == 115) 
									pointer2 = 90;
								else
									pointer2 = 115;
							}
							else if (c == 77) {
								if (pointer2 == 90) 
									pointer2 = 115;
								else
									pointer2 = 90;
							}
							gotoXY(pointer2, 29);
						}
					}
					HighLight();
					gotoXY(pointer2, pointer);
					if (pointer2 == 90) {
						cout << "Them";
						Normal();
						gotoXY(115, 29);
						cout << "Thoat";
					}
					else if (pointer2 == 115) {
						cout << "Thoat";
						Normal();
						gotoXY(90, 29);
						cout << "Them";
					}
				}
			}
		}
		
	}
}
//===================Xu ly danh sach diem
int CountDiem(DSDIEM l) {
	int dem = 0;
	for (NODEDT* k = l.pHead; k != NULL; k = k->pNext) {

		dem++;
	}
	return dem;
}

NODEDT* Khoi_Tao_NODE_DT(DT dt) {
	NODEDT* p = new NODEDT;
	if (p == NULL) {
		cout << "Cap phat that bai";
		return NULL;
	}
	p->data = dt;
	p->pNext = NULL;
	return p;
}

void Them_Cuoi_DSDT(DSDIEM& l, NODEDT* dt) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = dt;
	}
	else {
		l.pTail->pNext = dt;
		l.pTail = dt;
	}
}

float LayDiem(DSDIEM l, string maMon) {
	for (NODEDT* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data.maMH.compare(maMon) == 0) {
			return k->data.diem;
		}
	}
	return -1;
	
}

void XuatDSDiem(DSSV ds_sv, string maLop,string maMon) {

	int n = CountSV(ds_sv);	// so luong sv
	int trang = 1;
	int sotrang = 1;
	int phantutrang=10;	
	int i=0; 
	int dem = 0;	
	SV* ds = new SV[n];
	chuyen_lkd_thanh_mang(ds_sv, ds);	
	sap_xep_ds_sv(ds, n);	
	HDXuatLop();
	
	if(n==0){
		ThongBao("Danh Sach Sinh Vien Trong!");
		return;
	}
	
	if(n%10==0)	
		sotrang= n/10;
	else
		sotrang= n/10+1;		
	
	
	if(n<=10) {
		GiaoDienDT(BoxMain[0]+6, BoxMain[2], n);
		for(int i=0; i<n; i++) 	{
			BodyTable();
			gotoXY(toadoX + 10, toadoY + 5 + dem*2);
			cout <<ds[i].maSV;
			gotoXY(toadoX + 40, toadoY + 5 + dem*2 );
			cout <<ds[i].ho + " " + ds[i].ten;
			gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
			if (LayDiem(ds[i].listDiem, maMon) <0 ) 
				cout << "CT";
			else 
				cout << LayDiem(ds[i].listDiem, maMon);
						
			dem++;
		}	
	}else {
		GiaoDienDT(BoxMain[0]+6, BoxMain[2], 10);
		for(int i=0;i<10;i++) {			
			BodyTable();
			gotoXY(toadoX + 10, toadoY + 5 + dem*2);
			cout <<ds[i].maSV;
			gotoXY(toadoX + 40, toadoY + 5 + dem*2 );
			cout <<ds[i].ho + " " + ds[i].ten;
			gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
			if (LayDiem(ds[i].listDiem, maMon) <0 ) 
				cout << "CT";
			else 
				cout << LayDiem(ds[i].listDiem, maMon);
				
			dem++;
		}
	}
		
	gotoXY(85,BoxMain[2]-2);
	cout<<"DANH SACH DIEM LOP" + maLop;
	gotoXY(100,31);
	cout<<"<< "<<trang<<" >>";
	char c;
	

	while(true) {		
		if(kbhit) {
			c=getch();
			if(c == -32) {

				c=getch();
				if(c == 77){ // qua phai
					dem = 0;					
					
					if(sotrang>1 && trang<sotrang)	{
						phantutrang = n-trang*10;
						if(phantutrang>=10)	
							phantutrang=10;
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);			
						GiaoDienDT(BoxMain[0]+6, BoxMain[2],phantutrang);
						for(int i=trang*10;i<trang*10+phantutrang;i++){
							BodyTable();
							gotoXY(toadoX + 10, toadoY + 5 + dem*2);
							cout <<ds[i].maSV;
							gotoXY(toadoX + 40, toadoY + 5 + dem*2 );
							cout <<ds[i].ho + " " + ds[i].ten;
							gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
							if (LayDiem(ds[i].listDiem, maMon) <0 )
								cout << "CT";
							else 
								cout << LayDiem(ds[i].listDiem, maMon);														
							dem++;
						}
						trang++;
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}else  if(c==75) {// qua trai
					dem = 0;
					if(trang>1)
					{
						phantutrang=10;
						trang--;
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
						GiaoDienDT(BoxMain[0]+6, BoxMain[2],phantutrang);
						for(int i=trang*10-10;i<trang*10;i++)
						{
							BodyTable();
							gotoXY(toadoX + 10, toadoY + 5 + dem*2);
							cout <<ds[i].maSV;
							gotoXY(toadoX + 40, toadoY + 5 + dem*2 );
							cout <<ds[i].ho + " " + ds[i].ten;
							gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
							if (LayDiem(ds[i].listDiem, maMon) <0 ) 
								cout << "CT";
							else 
								cout << LayDiem(ds[i].listDiem, maMon);
							dem++;
						}
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}							
			}else if(c==27)	{
				delete[] ds;
				XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
				return;
			}	
		}
	}
	Normal();
}



void XuatDanhSachDiem(TREE t, DSLOP ds_lop) {
	while(true) {
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maMH="";
		LayMaMH(t, maMH);
		if (maMH.compare("") == 0) 
			return;	
		b:XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);		
		string maLop="";
		LayMaLop(ds_lop, maLop);		
		if (maLop.compare("") == 0) {
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			goto a;
		}	
		
		int vt = kt_ma_lop_trung2(ds_lop,maLop);	
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);	
		XuatDSDiem(ds_lop.ds[vt]->listSV, maLop, maMH);	
		
		goto b;
		
	}
}

//================ Thi trac nghiem =====================================
int LayMaLop2(DSLOP ds_lop, string a) {
	for (int i = 0; i < ds_lop.sl; i++) {
		for (NODESV* k = ds_lop.ds[i]->listSV.pHead; k != NULL; k = k->pNext) {			
			if (k->data.maSV.compare(a) == 0) {
				return i;			
			}	
		}
	}
	return -1;
}

void LaySoCHVaPhut(TREE t,string maMon,int &soCau, int &phut) {

	TREE tam = NULL;
	LayThongTinMH(t,maMon,tam);
	
	GiaoDienNhapCHVaPhut();	
	gotoXY(90,8);
	cout<<maMon;
	gotoXY(90,11);
	cout<<tam->data.tenMH;
	int pointer1 =14; 
	ShowCur(1);
	bool kt = true;
	string soCauTemp;
	string phutTemp;	
	
	while (true) 	{
		ShowCur(1);
		if (pointer1 == 14) {
			gotoXY(90+soCauTemp.length(), pointer1);
			XuLyNhapCH(soCauTemp, 90, pointer1); 
			if (pointer1 < 14) 
				pointer1 = 20;
				
			if (soCauTemp.empty()) {
				gotoXY(130, 14);
				cout << "So Cau Rong";
				kt = false;
			}else if(soCauTemp.compare("0") == 0 || soCauTemp.compare("00") == 0) {			
				gotoXY(130, 14);
				cout << "So CH > 0";
				kt = false;
			}else if(chuoi_to_so(soCauTemp) > tam->listCauHoi.sl) {
				gotoXY(130, 14);
				cout << "DS Thieu Cau Hoi";
				kt = false;
			}else if(chuoi_to_so(soCauTemp) > 60) {
				gotoXY(130, 14);
				cout << "So CH < 60";
				kt = false;
			}else {
				gotoXY(130, 14);
				cout << "                           ";
				kt = true;
			}	
			
		}else if (pointer1 == 17) {	
			gotoXY(90+phutTemp.length(), pointer1);
			XuLyNhap4(phutTemp, 90, pointer1, 2); 			
			if (phutTemp.empty()) {
				gotoXY(130, 17);
				cout << "So Phut Rong";
				kt = false;
			}else if(phutTemp.compare("0") == 0) {
				gotoXY(130, 17);
				cout << "So Phut > 0";
				kt = false;
			}else if(chuoi_to_so(phutTemp) > 60) {
				gotoXY(130, 17);
				cout << "So Phut < 60";
				kt = false;
			}
			else {
				gotoXY(130, 17);
				cout << "                 ";
				kt = true;
			}				
		}else if (pointer1 == 20) {// save hoac huy		
			ShowCur(0);
			int pointer2 = 90;
			while (true) {
				if (kbhit()) {
					char c = getch();
					if (c == 13) {
						if (kt == true && pointer2 == 90) {
							soCau = chuoi_to_so(soCauTemp);
							phut = chuoi_to_so(phutTemp);							
							return;
						}else if (pointer2 == 115) 
							return;						
						else {
							ThongBao("Vui long nhap day du cac truong");
						}
					}else if (c == -32) 	{
						c = getch();
						if (c == 72) {
							Normal();
							gotoXY(115, 20);
							cout << "Thoat";
							gotoXY(90, 20);
							cout << "Vao Thi";
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80) 	{
							Normal();
							gotoXY(115, 20);
							cout << "Thoat";
							gotoXY(90, 20);
							cout << "Vao Thi";
							ShowCur(1);
							pointer1 = 14;
							break;
						}
						else  if (c == 75) {
							if (pointer2 == 115) 
								pointer2 = 90;
							else
								pointer2 = 115;
						}
						else if (c == 77) {
							if (pointer2 == 90) 
								pointer2 = 115;
							else
								pointer2 = 100;
						}
						gotoXY(pointer2, 20);
					}
				}

				HighLight();
				gotoXY(pointer2, pointer1);
				if (pointer2 == 90) {
					cout << "Vao Thi";
					Normal();
					gotoXY(115, 20);
					cout << "Thoat";
				}
				else if (pointer2 == 115) {
					cout << "Thoat";
					Normal();
					gotoXY(90, 20);
					cout << "Vao Thi";
				}
			}
		}
	}
}

int tao_ma(int so) {
	srand(time(NULL));
	int a; 
	a = rand() % (so - 1 + 1) + 1;
	return a;
}

bool kt_ma_ch_trung(DSCAUHOI ds, int a) {
	for (int i = 0; i < ds.sl; i++) {
		if (ds.ds[i].id == a) {
			return true;
		}
	}
	return false;
}

int kt_ma_ch_trung2(DSCAUHOI ds, int a) {
	for (int i = 0; i < ds.sl; i++) {
		if (ds.ds[i].id == a) {
			return i;
		}
	}
	return -1;
}

void tao_list_ch(DSCAUHOI l, DSCAUHOI &ds, int sl) {
	int dem = 0;
	int ma;
	do{			
		ma = tao_ma(l.sl);		
		bool kt = kt_ma_ch_trung(ds, ma);
		if(kt == false) {
		for(int i =0; i < l.sl; i++) {
			if(l.ds[i].id == ma) {
				ds.ds[dem].id = l.ds[i].id;
				ds.ds[dem].noiDung = l.ds[i].noiDung;
				ds.ds[dem].A = l.ds[i].A;
				ds.ds[dem].B = l.ds[i].B;
				ds.ds[dem].C = l.ds[i].C;
				ds.ds[dem].D = l.ds[i].D;
				ds.ds[dem].DA = l.ds[i].DA;
				ds.sl++;
				dem++;
				break;
				}
			}
		}
					
	}while(dem < sl);
}

void InSLCH(DSTL l, int temp) {
	//int dem = 0;
	for(int i = 0; i< l.sl; i++) {
		if(i == temp) {
			HighLight();
			gotoXY(57 + i*5, 26);
			cout<<i+1;			
			cout<<l.ds[i].DA;
			Normal();
		}else if(i < 20) {
			gotoXY(57 + i*5, 26);
			cout<<i+1;
			cout<<l.ds[i].DA;
		}else if(i >= 20 && i< 40) {
			gotoXY(57 + (i-20)*5, 27);
			cout<<i+1;
			cout<<l.ds[i].DA;
		}else if(i >= 40 && i<60) {			
			gotoXY(57 + (i-40)*5, 28);
			cout<<i+1;
			cout<<l.ds[i].DA;
		}
	}
}


void ThiTracNghiem(TREE t, DSLOP& ds_lop, string username) {	
	a:XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	HDXemThongTinLop();
	string maMH="";
	LayMaMH(t, maMH);
	if (maMH.compare("") == 0)
		return;
	

	if(username !="GV") {
		int vt = LayMaLop2(ds_lop, username);
		for (NODESV* k = ds_lop.ds[vt]->listSV.pHead; k != NULL; k = k->pNext) {					
			if (k->data.maSV.compare(username) == 0) {
				for (NODEDT* g = k->data.listDiem.pHead; g != NULL; g = g->pNext) {
					if(g->data.maMH.compare(maMH) == 0) {
						ThongBao("Ban da thi mon nay!");
						goto a;
					}
				}				
			}	
		}
	}	
	
	TREE tam = NULL;
	LayThongTinMH(t,maMH,tam);
	int soCau;
	int phut = 0;
	XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
	HDNhapLop();
	LaySoCHVaPhut(t,maMH,soCau, phut);
	
	if (phut == 0) {
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		goto a;
	}
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		
	DSCAUHOI list; 
	tao_list_ch(tam->listCauHoi, list, soCau);
	int n = list.sl; //so cau hoi
	int i = 0; 
	int check = 0;
	float diem = 0;
	DT dt;
		
	for(int i=0; i<n; i++) {
		dt.listCT.ds[i].id = list.ds[i].id;
		dt.listCT.ds[i].noiDung = list.ds[i].noiDung;
		dt.listCT.sl++;		
	}
	
	XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	HDThi();
	
	if(n==0) {
		ThongBao("Danh sach cau hoi rong!");
		return;
	}
		
	GiaoDienThiTracNghiem();
	gotoXY(70, 8);
	cout<<i + 1<<"(ID: "<<list.ds[i].id<<")";
	gotoXY(70, 11);
	cout<<list.ds[i].noiDung;
	gotoXY(70, 14);
	cout<<list.ds[i].A;
	gotoXY(70, 17);
	cout<<list.ds[i].B;
	gotoXY(70, 20);
	cout<<list.ds[i].C;
	gotoXY(70, 23);
	cout<<list.ds[i].D;
	ShowCur(0);
	
	InSLCH(dt.listCT, i);
	thread timer;
	timer = thread(demnguoc,phut);
	char c;	
	while(true) {		
		
		if(kbhit) {
			b:c=getch();
			if(c == -32) {
				c=getch();
				if(c == 77) { //qua phai
					if(i == n -1) {
						goto b;
					}else {
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]-3);
						GiaoDienThiTracNghiem();
						i++;
						gotoXY(70, 8);
						cout<<i + 1<<"(ID: "<<list.ds[i].id<<")";
						gotoXY(70, 11);
						cout<<list.ds[i].noiDung;
						if (dt.listCT.ds[i].DA == "" ) {
							gotoXY(70, 14);
							cout<<list.ds[i].A;
							gotoXY(70, 17);
							cout<<list.ds[i].B;
							gotoXY(70, 20);
							cout<<list.ds[i].C;
							gotoXY(70, 23);
							cout<<list.ds[i].D;
							InSLCH(dt.listCT, i);	
						}else {					
							if(dt.listCT.ds[i].DA == "A") {
								HighLight();
								gotoXY(70, 14);
								cout<<list.ds[i].A;
								Normal();
								gotoXY(70, 17);
								cout<<list.ds[i].B;
								gotoXY(70, 20);
								cout<<list.ds[i].C;
								gotoXY(70, 23);
								cout<<list.ds[i].D;	
								InSLCH(dt.listCT, i);
							} else if(dt.listCT.ds[i].DA == "B") {
								Normal();
								gotoXY(70, 14);
								cout<<list.ds[i].A;							
								HighLight();
								gotoXY(70, 17);
								cout<<list.ds[i].B;
								Normal();
								gotoXY(70, 20);
								cout<<list.ds[i].C;
								gotoXY(70, 23);
								cout<<list.ds[i].D;
								InSLCH(dt.listCT, i);
							} else if(dt.listCT.ds[i].DA == "C") {
								Normal();
								gotoXY(70, 14);
								cout<<list.ds[i].A;				
								gotoXY(70, 17);
								cout<<list.ds[i].B;								
								HighLight();
								gotoXY(70, 20);
								cout<<list.ds[i].C;
								Normal();
								gotoXY(70, 23);
								cout<<list.ds[i].D;
								InSLCH(dt.listCT, i);
							} else if(dt.listCT.ds[i].DA == "D") {
								Normal();
								gotoXY(70, 14);
								cout<<list.ds[i].A;				
								gotoXY(70, 17);
								cout<<list.ds[i].B;							
								gotoXY(70, 20);
								cout<<list.ds[i].C;
								HighLight();
								gotoXY(70, 23);
								cout<<list.ds[i].D;	
								Normal();
								InSLCH(dt.listCT, i);							
							}					
						}
					}
				} else  if(c==75) {// qua trai				
					if(i == 0) {
						goto b;
					}else {
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3] -3);
						GiaoDienThiTracNghiem();
						i--;
						gotoXY(70, 8);
						cout<<i + 1<<"(ID: "<<list.ds[i].id<<")";
						gotoXY(70, 11);
						cout<<list.ds[i].noiDung;
						if (dt.listCT.ds[i].DA == "" ) {
							gotoXY(70, 14);
							cout<<list.ds[i].A;
							gotoXY(70, 17);
							cout<<list.ds[i].B;
							gotoXY(70, 20);
							cout<<list.ds[i].C;
							gotoXY(70, 23);
							cout<<list.ds[i].D;	
							InSLCH(dt.listCT, i);
						}else {
							if(dt.listCT.ds[i].DA == "A") {
								HighLight();
								gotoXY(70, 14);
								cout<<list.ds[i].A;
								Normal();
								gotoXY(70, 17);
								cout<<list.ds[i].B;
								gotoXY(70, 20);
								cout<<list.ds[i].C;
								gotoXY(70, 23);
								cout<<list.ds[i].D;	
								InSLCH(dt.listCT, i);	
							} else if(dt.listCT.ds[i].DA == "B") {
								Normal();
								gotoXY(70, 14);
								cout<<list.ds[i].A;							
								HighLight();
								gotoXY(70, 17);
								cout<<list.ds[i].B;
								Normal();
								gotoXY(70, 20);
								cout<<list.ds[i].C;
								gotoXY(70, 23);
								cout<<list.ds[i].D;	
								InSLCH(dt.listCT, i);	
							} else if(dt.listCT.ds[i].DA == "C") {
								Normal();
								gotoXY(70, 14);
								cout<<list.ds[i].A;				
								gotoXY(70, 17);
								cout<<list.ds[i].B;								
								HighLight();
								gotoXY(70, 20);
								cout<<list.ds[i].C;
								Normal();
								gotoXY(70, 23);
								cout<<list.ds[i].D;	
								InSLCH(dt.listCT, i);	
							} else if(dt.listCT.ds[i].DA == "D") {
								Normal();
								gotoXY(70, 14);
								cout<<list.ds[i].A;				
								gotoXY(70, 17);
								cout<<list.ds[i].B;							
								gotoXY(70, 20);
								cout<<list.ds[i].C;
								HighLight();
								gotoXY(70, 23);
								cout<<list.ds[i].D;	
								Normal();
								InSLCH(dt.listCT, i);	
							}					
						}
					}
				} 	
			} 	else if(c == 65 || c==97) {				
				GiaoDienThiTracNghiem();
				gotoXY(70, 8);
				cout<<i + 1<<"(ID: "<<list.ds[i].id<<")";
				gotoXY(70, 11);
				cout<<list.ds[i].noiDung;
				gotoXY(70, 14);
				HighLight();
				cout<<list.ds[i].A;
				Normal();
				gotoXY(70, 17);
				cout<<list.ds[i].B;
				gotoXY(70, 20);
				cout<<list.ds[i].C;
				gotoXY(70, 23);
				cout<<list.ds[i].D;
				ShowCur(0);		
				dt.listCT.ds[i].DA = "A";
				InSLCH(dt.listCT, i);		
			} else if(c == 66 || c==98) {				
				GiaoDienThiTracNghiem();
				gotoXY(70, 8);
				cout<<i + 1<<"(ID: "<<list.ds[i].id<<")";
				gotoXY(70, 11);
				cout<<list.ds[i].noiDung;
				gotoXY(70, 14);			
				cout<<list.ds[i].A;				
				HighLight();
				gotoXY(70, 17);				
				cout<<list.ds[i].B;
				Normal();
				gotoXY(70, 20);
				cout<<list.ds[i].C;
				gotoXY(70, 23);
				cout<<list.ds[i].D;
				ShowCur(0);		
				dt.listCT.ds[i].DA = "B";
				InSLCH(dt.listCT, i);	
			}else if(c == 67 || c==99) {				
				GiaoDienThiTracNghiem();
				gotoXY(70, 8);
				cout<<i + 1<<"(ID: "<<list.ds[i].id<<")";
				gotoXY(70, 11);
				cout<<list.ds[i].noiDung;
				gotoXY(70, 14);				
				cout<<list.ds[i].A;			
				gotoXY(70, 17);
				cout<<list.ds[i].B;
				HighLight();
				gotoXY(70, 20);
				cout<<list.ds[i].C;
				Normal();
				gotoXY(70, 23);
				cout<<list.ds[i].D;
				ShowCur(0);			
				dt.listCT.ds[i].DA = "C";
				InSLCH(dt.listCT, i);	
			}else if(c == 68 || c==100) {				
				GiaoDienThiTracNghiem();
				gotoXY(70, 8);
				cout<<i + 1<<"(ID: "<<list.ds[i].id<<")";
				gotoXY(70, 11);
				cout<<list.ds[i].noiDung;
				gotoXY(70, 14);			
				cout<<list.ds[i].A;			
				gotoXY(70, 17);
				cout<<list.ds[i].B;
				gotoXY(70, 20);
				cout<<list.ds[i].C;
				HighLight();
				gotoXY(70, 23);
				cout<<list.ds[i].D;
				Normal();
				ShowCur(0);	
				dt.listCT.ds[i].DA = "D";	
				InSLCH(dt.listCT, i);	
			}
			else if(c== 27) {				
				stop = 1;
				goto c;
			}else if(stop == 1) 
				goto c;
		}
	}	
	c:XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
	for(int i=0; i < dt.listCT.sl; i++) {										
		if(dt.listCT.ds[i].DA.compare(list.ds[i].DA) == 0) 
			check++;
	}	
	timer.join();
	diem = roundf(((float)10* check/n) * 10) / 10;;
	GiaoDienKetQua();
	gotoXY(90,8);
	cout<<maMH;
	gotoXY(90,11);
	cout<<tam->data.tenMH;
	gotoXY(90,14);
	cout<<check;
	gotoXY(90,17);
	cout<<diem;	
	if(username !="GV") {	
		dt.diem = diem;
		dt.maMH = maMH;
		for(int i=0; i < dt.listCT.sl; i++) {										
			if(dt.listCT.ds[i].DA.compare("") == 0) 
				dt.listCT.ds[i].DA = " ";
		}
		NODEDT* g = Khoi_Tao_NODE_DT(dt);
		int vt = LayMaLop2(ds_lop, username);
		for (NODESV* k = ds_lop.ds[vt]->listSV.pHead; k != NULL; k = k->pNext) {					
			if (k->data.maSV.compare(username) == 0) {
				Them_Cuoi_DSDT(k->data.listDiem, g); 				
			}	
		}
	}
	Normal();
}

//==============Chi tiet cau tra loi=============================
DT LayThongTinDT(DSDIEM l, string maMH) {
	for (NODEDT* k = l.pHead; k != NULL; k = k->pNext) {			
		if (k->data.maMH.compare(maMH) == 0) {
				return k->data;
		}	
	}
}
void LayDSSV2(DSSV l, string ma[], string ten[], float diem[], string maMH ,int soluong) {
	int i = 0;
	if (soluong == 0) 
		return;
	gotoXY(1,1);
	//Xuat_DSSV(l);
	for (NODESV* k = l.pHead; k != NULL; k = k->pNext) {			
		ma[i]= k->data.maSV;
		ten[i] = k->data.ho + " " +k->data.ten;	
		diem[i] = LayDiem(k->data.listDiem, maMH);
		i++;
	}
}

void sap_xep_mangt_theo_ten2(string ma[], string ten[], float diem[],int n) {	
	string temp;
	float temp1;
	for(int i = 0; i <n - 1; i++) {			
		for(int j= i + 1; j < n; j++) {
			if(ma[i].compare(ma[j]) == 1) {				
				temp = ma[i];
				ma[i] = ma[j];
				ma[j] = temp;
				
				temp = ten[i];
				ten[i] = ten[j];
				ten[j] = temp;
				
				temp1 = diem[i];
				diem[i] = diem[j];
				diem[j] = temp1;
				
			}
		}
	}
}

void LayMaSV2(DSSV l, string &maSV, string maMH, float& diemThi) {
	HDXemThongTinLop();
	
	int n = CountSV(l); // So luong phan tu cua ds lop
	int toadoX= BoxMain[0]+10;
	int toadoXtam;
	int toadoY = BoxMain[2]+3;
	int pointer=toadoY;
	GiaoDienTimkiemSV2();
	string *ten = new string[n];	
	string *ma = new string[n];//ma sv
	float *diem = new float[n];
	LayDSSV2(l, ma, ten, diem, maMH, n);
	sap_xep_mangt_theo_ten2(ma, ten, diem, n);
	char c;
	int i=0;
	int vitri=0;
	bool key=true; 
	

	do{
		if(n==0) 
		{
			ThongBao("Khong co sinh vien nao !!");
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			return;
		}
		else{
			BodyTable();
			for(int i = vitri; i < n; i++) {
				if((i-(vitri))==20) break;
				gotoXY(63, toadoY + i-(vitri));
				cout<<CanDeuChuoi(ma[i],16)<<char(179)<<CanDeuChuoi(ten[i],44)<<char(179)<<"      ";
				gotoXY(126, 9+i);
				if(diem[i] == -1) 
					cout<<"CT";
				else 
					cout<<diem[i];
											
			}
			gotoXY(63,pointer);
			HighLight();
			cout<<CanDeuChuoi(ma[pointer-(BoxMain[2]+3)+vitri],16)<<char(179)<<CanDeuChuoi(ten[pointer-(BoxMain[2]+3)+vitri],44)<<char(179)<<"      ";					
			i=pointer-(BoxMain[2]+3)+vitri;
			gotoXY(126, 9+i);
			if(diem[i] == -1) 
				cout<<"CT";
			else 
				cout<<diem[i];
			Normal();
			ShowCur(0);
			if(kbhit) {
				d:c=getch();
				if(c == 13) { //enter
					maSV=ma[i];	
					diemThi = diem[i];				
					key=false;	
				}else if(c == 27) { 
					key=false;	
				} else if(c == -32)	{
					c = getch(); 
					if(c == 72) { 
						if(pointer > toadoY)						
							pointer--;						
						else if(pointer == toadoY && vitri > 0) {
							vitri--;
						}
					} else if(c == 80) { 
						if(vitri> n-21 && vitri< n-1)	{
							if( i > n-2) goto d;
							else {
								if(pointer < MaxBox)	
									pointer++;
								else if(pointer==MaxBox && vitri<n-21)	
									vitri++;
							}						
						}
						else if (vitri == n-1) goto d;
						else if(pointer < MaxBox)		
							pointer++;
						else if(pointer == MaxBox && vitri<n-20)	{
							vitri++;
						}
					}
				}
			}
		}
	}while(key);
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	delete[]ten;
	delete[]ma;
	delete[]diem;
	ShowCur(0);
}

void XuatDSCT(DSTL l,SV sv,string maMon) {
	int n = l.sl;	// so luong CL
	int trang = 1;
	int sotrang = 1;
	int phantutrang=10;	
	int i=0; 
	int dem = 0;	
	HDXuatLop();
		
	if(n==0){
		ThongBao("Danh Sach Sinh Vien Trong!");
		return;
	}
	
	if(n%10==0)	
		sotrang= n/10;
	else
		sotrang= n/10+1;	
	
	if(n<=10) {
		GiaoDienTL(BoxMain[0]+6, BoxMain[2]+1, n);
		for(int i=0; i<n; i++) 	{
			BodyTable();
			gotoXY(toadoX + 10, toadoY + 6 + dem*2);
			cout <<l.ds[i].id;
			gotoXY(toadoX + 22, toadoY + 6 + dem*2 );
			cout <<l.ds[i].noiDung;
			gotoXY(toadoX + 80, toadoY + 6 + dem*2 );
			cout <<l.ds[i].DA;
			dem++;
		}	
	}else {
		GiaoDienTL(BoxMain[0]+6, BoxMain[2], 10);
		for(int i=0; i<10;i++) {			
			BodyTable();
			gotoXY(toadoX + 10, toadoY + 5 + dem*2);
			cout <<l.ds[i].id;
			gotoXY(toadoX + 22, toadoY + 5 + dem*2 );
			cout <<l.ds[i].noiDung;
			gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
			cout <<l.ds[i].DA;			
			dem++;
		}
	}
		
	gotoXY(77,BoxMain[2]-2);
	cout<<"DANH SACH CAU TRA LOI " + sv.ho + " " + sv.ten;
	gotoXY(90,BoxMain[2]-1);
	cout<<"MA SO SV " + sv.maSV;
	gotoXY(100,31);
	cout<<"<< "<<trang<<" >>";
	char c;
	

	while(true) {		
		if(kbhit) {
			c=getch();
			if(c == -32) {

				c=getch();
				if(c == 77){ // qua phai
					dem = 0;					
					
					if(sotrang>1 && trang<sotrang)	{
						phantutrang = n-trang*10;
						if(phantutrang>=10)	
							phantutrang=10;
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);			
						GiaoDienTL(BoxMain[0]+6, BoxMain[2],phantutrang);
						for(int i=trang*10;i<trang*10+phantutrang;i++){
							BodyTable();
							gotoXY(toadoX + 10, toadoY + 5 + dem*2);
							cout <<l.ds[i].id;
							gotoXY(toadoX + 22, toadoY + 5 + dem*2 );
							cout <<l.ds[i].noiDung;
							gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
							cout <<l.ds[i].DA;																
							dem++;
						}
						trang++;
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}else  if(c==75) {// qua trai
					dem = 0;
					if(trang>1)
					{
						phantutrang=10;
						trang--;
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
						GiaoDienTL(BoxMain[0]+6, BoxMain[2],phantutrang);
						for(int i=trang*10-10;i<trang*10;i++)
						{
							BodyTable();
							gotoXY(toadoX + 10, toadoY + 5 + dem*2);
							cout <<l.ds[i].id;
							gotoXY(toadoX + 22, toadoY + 5 + dem*2 );
							cout <<l.ds[i].noiDung;
							gotoXY(toadoX + 80, toadoY + 5 + dem*2 );
							cout <<l.ds[i].DA;			
							dem++;
						}
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}							
			}else if(c==27)	{			
				XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
				return;
			}	
		}
	}
	Normal();
}


void XuatDanhSachCT(TREE t, DSLOP ds_lop) {
	while(true) {
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinLop();
		string maMH="";
		string maSV;
	
		LayMaMH(t, maMH);
		if (maMH.compare("") == 0) 
			return;	
		b:XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);		
		string maLop="";
		
		LayMaLop(ds_lop, maLop);		
		if (maLop.compare("") == 0) {
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			goto a;
		}	
		
		int vt = kt_ma_lop_trung2(ds_lop,maLop);	
		c:XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		float diemThi;
		
		if(!maSV.empty())  {
			maSV = "";
		}	
		
		LayMaSV2(ds_lop.ds[vt]->listSV, maSV, maMH, diemThi);		
		if(maSV.compare("") == 0) {
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			goto b;
		}
		
		if(diemThi == -1) {
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			ThongBao("SV chua thi mon nay");
			goto c;
		}
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		
		SV sv = LayThongTinSV(ds_lop.ds[vt]->listSV, maSV);
		DT dt = LayThongTinDT(sv.listDiem, maMH);
		XuatDSCT(dt.listCT, sv, maMH);
		
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		goto c;
		
	}
}




