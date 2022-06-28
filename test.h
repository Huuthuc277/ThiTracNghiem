//void doc_file_lop(DSLOP& ds_lop) {
//	ifstream filein;
//	filein.open("dsLop.txt", ios_base::in);
//	int n;
//	int n1;
//	int n2;
//	filein >> n;
//	filein.ignore();
//	for (int i= 0; i < n; i++) {
//		ds_lop.ds[ds_lop.sl] = new LOP;
//		getline(filein, ds_lop.ds[ds_lop.sl]->maLop, ',');
//		getline(filein, ds_lop.ds[ds_lop.sl]->tenLop,',');
//		filein.ignore();	
//		ds_lop.ds[ds_lop.sl]->listSV.pHead = NULL;
//		ds_lop.ds[ds_lop.sl]->listSV.pTail = NULL;
//		filein >> n1;
//		filein.ignore();			
//		for (int j = 0; j < n1; j++) {
//			SV sv;
//			getline(filein, sv.maSV, ',');
//			getline(filein, sv.ho, ',');
//			getline(filein, sv.ten, ',');
//			getline(filein, sv.phai, ',');
//			getline(filein, sv.password, ',');
//			filein.ignore();					
//			filein >> n2;
//			filein.ignore();
//			for (int z = 0; z < n2; z++) {
//				DT dt;
//				getline(filein, dt.maMH, ',');
//				filein >> dt.diem;
//				filein.ignore();
//				NODEDT* k = Khoi_Tao_NODE_DT(dt);
//				Them_Cuoi_DSDT(sv.listDiem, k);
//			}
//			NODESV* p = Khoi_Tao_NODE(sv);
//			Them_Cuoi(ds_lop.ds[ds_lop.sl]->listSV, p);
//			
//		}
//		ds_lop.sl++;
//	}	
//	filein.close();
//}


//void ghi_file_lop(DSLOP ds_lop) {
//	ofstream fileout;
//	fileout.open("dsLop.txt", ios::out);
//	
//	int n;
//	int n1;
//	fileout << ds_lop.sl<<endl;
//	for (int i = 0; i < ds_lop.sl; i++) {
//		fileout << ds_lop.ds[i]->maLop << ",";
//		fileout << ds_lop.ds[i]->tenLop << "," << endl;
//		n = CountSV(ds_lop.ds[i]->listSV);
//		fileout << n<<endl;
//		for (NODESV* k = ds_lop.ds[i]->listSV.pHead; k != NULL; k = k->pNext) {
//			fileout << k->data.maSV << ",";
//			fileout << k->data.ho << ",";
//			fileout << k->data.ten << ",";
//			fileout << k->data.phai << ",";
//			fileout << k->data.password << "," << endl;
//			n1 = CountDiem(k->data.listDiem);			
//			fileout << n1 << endl;
//			for (NODEDT* g = k->data.listDiem.pHead; g != NULL; g = g->pNext) {
//				fileout << g->data.maMH << ",";
//				fileout << g->data.diem << endl;
//			}
//		}
//		
//	}
//	fileout.close();
//
//}

////========= DANH SACH SINH VIEN ==============
//void Xuat_SV(SV sv)	{
//		cout << "Ma SV " << sv.maSV << endl;
//		cout << "Ho  " << sv.ho << endl;
//		cout << "Ten  " << sv.ten << endl;
//		cout << "Phai " << sv.phai << endl;
//		cout << "Password " << sv.password << endl;
//}
//void Xuat_DSSV(DSSV l) {
//	for (NODESV* k = l.pHead; k != NULL; k = k->pNext) {
//		cout<<"=========";
//		Xuat_SV(k->data);
//		cout << endl;		
//	}	
//}
void xuat_1_cau_hoi(CAUHOI ch) {
	cout << "id: " << ch.id << endl;
	cout<<"Noi dung"<<ch.noiDung<<endl;
	cout << "Cau A: " << ch.A << endl;
	cout << "Cau B: " << ch.B << endl;
	cout << "Cau C: " << ch.C << endl;
	cout << "Cau D: " << ch.D << endl;
	cout << "Cau DA: " << ch.DA << endl;

}

void xuat_cau_hoi(CT ch) {
	cout << "id: " << ch.id << endl;
	cout << "Cau DA: " << ch.DA << endl;

}

void xuat_ds_ch(DSCAUHOI ds_ch) {
	if(ds_ch.sl == 0) {
		return;
	}
	cout << "\t\t========= Xuat Danh Sach Cau Hoi =========";
	for (int i = 0; i < ds_ch.sl; i++)
	{
		cout << "\n\t\t----- Mon: " << i << " ---------" << endl;
		xuat_1_cau_hoi(ds_ch.ds[i]);
	}	
}

void NLR(TREE t) {
	if(t != NULL) {	
		cout <<t->data.maMH<<endl;
		cout<<t->data.tenMH<<endl;
		xuat_ds_ch(t->listCauHoi);		
		NLR(t->pLeft);			
		NLR(t->pRight);	
	}
}

/*Hieu chinh moin hoc

void HieuChinhLop(DSLOP ds_lop) {
	
	while(true) {
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinMH();
		string maLop="";
		LayMaLop(ds_lop, maLop);
		
		if (maLop.compare("") == 0)
			return;
		
		
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		
		int vt = kt_ma_lop_trung2(ds_lop, maLop);
		HDThemMH();
		string tenLopTam;
		tenLopTam = ds_lop.ds[vt]->tenLop;
				
		int pointer = 11;
		char c;
		GiaoDienThemLop();
		gotoXY(90,  14);
		cout << "Cap Nhat";
		gotoXY(80,8);
		cout << ds_lop.ds[vt]->maLop;
		gotoXY(80, 11);
		cout << ds_lop.ds[vt]->tenLop;
		Normal();
		ShowCur(1); 	
		
		while (true) {			
			
			if (pointer == 11) {
				ShowCur(1);
				gotoXY(80+ds_lop.ds[vt]->tenLop.length(), pointer);
				XuLyNhap1(ds_lop.ds[vt]->tenLop, 80, pointer,30); 
				if (pointer < 11)
					pointer = 14;
					
				if (ds_lop.ds[ds_lop.sl]->tenLop.empty()) {
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
				while (true) 	{
					if (kbhit()) {
						char c = getch();
						if (c == 13) {
							if (!ds_lop.ds[vt]->tenLop.empty() && pointer2 == 90) {
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
						else if (c == -32) 	{
							c = getch();
							if (c == 72)
							{
								Normal();
								gotoXY(115, 14);
								cout << "Thoat";
								gotoXY(90, 14);
								cout << "Cap nhat";
								pointer = pointer - 3;
								break;
							}
							else if (c == 80)
							{
								Normal();
								gotoXY(115, 14);
								cout << "Thoat";
								gotoXY(90, 14);
								cout << "Cap nhat";
								//ShowCur(1);
								pointer = 11;
								break;
							}
							else if (c == 75)
							{
								if (pointer2 == 115)
									pointer2 = 90;
								else
									pointer2 = 115;
							}
							else if (c == 77)
							{
								if (pointer2 == 90)
									pointer2 = 115;
								else
									pointer2 = 90;
							}
							gotoXY(pointer2, 14);
						}
					}
					HighLight();
					//textcolor(28);
					gotoXY(pointer2, pointer);
					if (pointer2 == 90) {
						cout << "Cap nhat";
						Normal();
						gotoXY(115, 14);
						cout << "Thoat";
					}
					else if (pointer2 == 115) {
						cout << "Thoat";
						Normal();
						gotoXY(90, 14);
						cout << "Cap nhat";
					}
				}
			}
		}
			
	}
}

	if (pointer == 8) // nhap ten mon hoc
			{
				ShowCur(1);
				gotoXY(100+tam->data.maMH.length(), pointer);
				XuLyNhap1(tam->data.maMH, 100, pointer,30); 
				if (pointer < 8) {
					pointer = 14;
				}if (tam->data.tenMH.empty()) {
					gotoXY(120, 8);
					cout << "Ma Mon Hoc Rong";
				}	
				else {
					gotoXY(120, 11);
					cout << "                   ";
				}	
			} else if (pointer == 11) {
				ShowCur(1);
				gotoXY(100+tam->data.tenMH.length(), pointer);
				XuLyNhap1(tam->data.tenMH, 100, pointer,30); 
				
				if (tam->data.tenMH.empty()) {
					gotoXY(120, 11);
					cout << "Ten Mon Hoc Rong";
				}else {
					gotoXY(120, 11);
					cout << "                   ";
				}	
			}			
			
			
			
			
				while(true)
	{
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinMH();
		string maLop="";
		LayMaLop(ds_lop, maLop);
		
		if (maLop.compare("") == 0)
			return;				
		
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		
		int vt = kt_ma_lop_trung2(ds_lop, maLop);
		HDThemMH();
		string tenLopTam;
		string maLopTam;
		maLopTam = ds_lop.ds[vt]->maLop;
		tenLopTam = ds_lop.ds[vt]->tenLop;
		
		int pointer = 11;
		char c;
		GiaoDienThemLop();
		gotoXY(90,  14);
		cout << "Cap Nhat";		
		gotoXY(80,8);
		cout << ds_lop.ds[vt]->maLop;
		gotoXY(80, 11);
		cout << ds_lop.ds[vt]->tenLop;
		//gotoXY(90, 14);	
		Normal();
		ShowCur(1);
	
		
		while (true) {			
			if (pointer == 11) {
				ShowCur(1);
				gotoXY(80+ds_lop.ds[vt]->tenLop.length(), pointer);
				XuLyNhap1(ds_lop.ds[vt]->tenLop, 80, pointer,50); 
				if (pointer < 11) {
					pointer = 14;
				}
				if (ds_lop.ds[ds_lop.sl]->tenLop.empty()) {
					gotoXY(120, 11);
					cout << "Ten Lop Rong";
				} else {
					gotoXY(120, 11);
					cout << "                  ";
				}
								
			} else if (pointer == 14) {
				ShowCur(0);
				int pointer2 = 90;
				while (true) {
					if (kbhit()) {
						char c = getch();
						if (c == 13) {
							if (!ds_lop.ds[vt]->tenLop.empty() && pointer2 == 90) 	{
								DinhDangChuoi(ds_lop.ds[vt]->tenLop);								
								ThongBao("Cap nhat thanh cong");
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
							else if (pointer2 == 115) {		
								ds_lop.ds[vt]->maLop = maLopTam;					
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
								cout << "Cap nhat";
								pointer = pointer - 3;
								break;
							}
							else if (c == 80) {
								Normal();
								gotoXY(115, 14);
								cout << "Thoat";
								gotoXY(90, 14);
								cout << "Cap nhat";								
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
										
					gotoXY(pointer2, pointer);
					if (pointer2 == 90) {
						HighLight();
						cout << "Cap nhat";
						Normal();
						gotoXY(115, 14);
						cout << "Thoat";
					}
					else if (pointer2 == 115) {
						HighLight();
						cout << "Thoat";
						Normal();
						gotoXY(90, 14);
						cout << "Cap nhat";
					}
				}
			}
		}
			
	}

*/

//void ThiTracNghiem(TREE t, DSLOP& ds_lop, string username) {	
//	a:XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
//	XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
//	HDXemThongTinMH();
//	string maMH="";
//	LayMaMH(t, maMH);
//	if (maMH.compare("") == 0)
//		return;
//	
//
//	if(username !="GV") {
//		int vt = LayMaLop2(ds_lop, username);
//		for (NODESV* k = ds_lop.ds[vt]->listSV.pHead; k != NULL; k = k->pNext) {					
//			if (k->data.maSV.compare(username) == 0) {
//				for (NODEDT* g = k->data.listDiem.pHead; g != NULL; g = g->pNext) {
//					if(g->data.maMH.compare(maMH) == 0) {
//						ThongBao("Ban da thi mon nay!");
//						goto a;
//					}
//				}				
//			}	
//		}
//	}	
//	TREE tam = NULL;
//	LayThongTinMH(t,maMH,tam);
//	int soCau;
//	int phut = 0;
//	
//	LaySoCHVaPhut(t,maMH,soCau, phut);
//	
//	if (phut == 0) {
//		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
//		goto a;
//	}
//	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
//		
//	DSCAUHOI list; 
//	DSTL list2;	
//
//	tao_list_ch(tam->listCauHoi, list, soCau);
//	int n = list.sl; //so cau hoi
//	int i = 0; 
//	int check = 0;
//	float diem = 0;
//		
//	for(int i=0; i<n; i++) {
//		list2.ds[i].id = list.ds[i].id;
//		list2.ds[i].noiDung = list.ds[i].noiDung;
//		list2.sl++;		
//	}
//	
//	HDThi();
//	
//	if(n==0) {
//		ThongBao("Danh sach cau hoi rong!");
//		return;
//	}
//		
//	GiaoDienThiTracNghiem();
//	gotoXY(70, 8);
//	cout<<i + 1;
//	gotoXY(70, 11);
//	cout<<list.ds[i].noiDung;
//	gotoXY(70, 14);
//	cout<<list.ds[i].A;
//	gotoXY(70, 17);
//	cout<<list.ds[i].B;
//	gotoXY(70, 20);
//	cout<<list.ds[i].C;
//	gotoXY(70, 23);
//	cout<<list.ds[i].D;
//	ShowCur(0);
//	
//	
//	thread timer;
//	timer = thread(demnguoc,phut);
//	char c;	
//	while(true) {		
//		
//		if(kbhit) {
//			b:c=getch();
//			if(c == -32) {
//				c=getch();
//				if(c == 77) { //qua phai
//					if(i == n -1) {
//						goto b;
//					}else {
//						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
//						GiaoDienThiTracNghiem();
//						i++;
//						gotoXY(70, 8);
//						cout<<i + 1;
//						gotoXY(70, 11);
//						cout<<list.ds[i].noiDung;
//						if (list2.ds[i].DA == "" ) {
//							gotoXY(70, 14);
//							cout<<list.ds[i].A;
//							gotoXY(70, 17);
//							cout<<list.ds[i].B;
//							gotoXY(70, 20);
//							cout<<list.ds[i].C;
//							gotoXY(70, 23);
//							cout<<list.ds[i].D;	
//						}else {					
//							if(list2.ds[i].DA == "A") {
//								HighLight();
//								gotoXY(70, 14);
//								cout<<list.ds[i].A;
//								Normal();
//								gotoXY(70, 17);
//								cout<<list.ds[i].B;
//								gotoXY(70, 20);
//								cout<<list.ds[i].C;
//								gotoXY(70, 23);
//								cout<<list.ds[i].D;	
//							} else if(list2.ds[i].DA == "B") {
//								Normal();
//								gotoXY(70, 14);
//								cout<<list.ds[i].A;							
//								HighLight();
//								gotoXY(70, 17);
//								cout<<list.ds[i].B;
//								Normal();
//								gotoXY(70, 20);
//								cout<<list.ds[i].C;
//								gotoXY(70, 23);
//								cout<<list.ds[i].D;	
//							} else if(list2.ds[i].DA == "C") {
//								Normal();
//								gotoXY(70, 14);
//								cout<<list.ds[i].A;				
//								gotoXY(70, 17);
//								cout<<list.ds[i].B;								
//								HighLight();
//								gotoXY(70, 20);
//								cout<<list.ds[i].C;
//								Normal();
//								gotoXY(70, 23);
//								cout<<list.ds[i].D;	
//							} else if(list2.ds[i].DA == "D") {
//								Normal();
//								gotoXY(70, 14);
//								cout<<list.ds[i].A;				
//								gotoXY(70, 17);
//								cout<<list.ds[i].B;							
//								gotoXY(70, 20);
//								cout<<list.ds[i].C;
//								HighLight();
//								gotoXY(70, 23);
//								cout<<list.ds[i].D;	
//								Normal();
//							}					
//						}
//					}
//				} else  if(c==75) {// qua trai				
//					if(i == 0) {
//						goto b;
//					}else {
//						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
//						GiaoDienThiTracNghiem();
//						i--;
//						gotoXY(70, 8);
//						cout<<i + 1;
//						gotoXY(70, 11);
//						cout<<list.ds[i].noiDung;
//						if (list2.ds[i].DA == "" ) {
//							gotoXY(70, 14);
//							cout<<list.ds[i].A;
//							gotoXY(70, 17);
//							cout<<list.ds[i].B;
//							gotoXY(70, 20);
//							cout<<list.ds[i].C;
//							gotoXY(70, 23);
//							cout<<list.ds[i].D;	
//						}else {
//							if(list2.ds[i].DA == "A") {
//								HighLight();
//								gotoXY(70, 14);
//								cout<<list.ds[i].A;
//								Normal();
//								gotoXY(70, 17);
//								cout<<list.ds[i].B;
//								gotoXY(70, 20);
//								cout<<list.ds[i].C;
//								gotoXY(70, 23);
//								cout<<list.ds[i].D;	
//							} else if(list2.ds[i].DA == "B") {
//								Normal();
//								gotoXY(70, 14);
//								cout<<list.ds[i].A;							
//								HighLight();
//								gotoXY(70, 17);
//								cout<<list.ds[i].B;
//								Normal();
//								gotoXY(70, 20);
//								cout<<list.ds[i].C;
//								gotoXY(70, 23);
//								cout<<list.ds[i].D;	
//							} else if(list2.ds[i].DA == "C") {
//								Normal();
//								gotoXY(70, 14);
//								cout<<list.ds[i].A;				
//								gotoXY(70, 17);
//								cout<<list.ds[i].B;								
//								HighLight();
//								gotoXY(70, 20);
//								cout<<list.ds[i].C;
//								Normal();
//								gotoXY(70, 23);
//								cout<<list.ds[i].D;	
//							} else if(list2.ds[i].DA == "D") {
//								Normal();
//								gotoXY(70, 14);
//								cout<<list.ds[i].A;				
//								gotoXY(70, 17);
//								cout<<list.ds[i].B;							
//								gotoXY(70, 20);
//								cout<<list.ds[i].C;
//								HighLight();
//								gotoXY(70, 23);
//								cout<<list.ds[i].D;	
//								Normal();
//							}					
//						}
//					}
//				} 	
//			} 	else if(c == 65 || c==97) {				
//				GiaoDienThiTracNghiem();
//				gotoXY(70, 8);
//				cout<<i + 1;
//				gotoXY(70, 11);
//				cout<<list.ds[i].noiDung;
//				gotoXY(70, 14);
//				HighLight();
//				cout<<list.ds[i].A;
//				Normal();
//				gotoXY(70, 17);
//				cout<<list.ds[i].B;
//				gotoXY(70, 20);
//				cout<<list.ds[i].C;
//				gotoXY(70, 23);
//				cout<<list.ds[i].D;
//				ShowCur(0);		
//				list2.ds[i].DA = "A";	
//			} else if(c == 66 || c==98) {				
//				GiaoDienThiTracNghiem();
//				gotoXY(70, 8);
//				cout<<i + 1;
//				gotoXY(70, 11);
//				cout<<list.ds[i].noiDung;
//				gotoXY(70, 14);			
//				cout<<list.ds[i].A;				
//				HighLight();
//				gotoXY(70, 17);				
//				cout<<list.ds[i].B;
//				Normal();
//				gotoXY(70, 20);
//				cout<<list.ds[i].C;
//				gotoXY(70, 23);
//				cout<<list.ds[i].D;
//				ShowCur(0);		
//				list2.ds[i].DA = "B";	
//			}else if(c == 67 || c==99) {				
//				GiaoDienThiTracNghiem();
//				gotoXY(70, 8);
//				cout<<i + 1;
//				gotoXY(70, 11);
//				cout<<list.ds[i].noiDung;
//				gotoXY(70, 14);				
//				cout<<list.ds[i].A;			
//				gotoXY(70, 17);
//				cout<<list.ds[i].B;
//				HighLight();
//				gotoXY(70, 20);
//				cout<<list.ds[i].C;
//				Normal();
//				gotoXY(70, 23);
//				cout<<list.ds[i].D;
//				ShowCur(0);			
//				list2.ds[i].DA = "C";
//			}else if(c == 68 || c==100) {				
//				GiaoDienThiTracNghiem();
//				gotoXY(70, 8);
//				cout<<i + 1;
//				gotoXY(70, 11);
//				cout<<list.ds[i].noiDung;
//				gotoXY(70, 14);			
//				cout<<list.ds[i].A;			
//				gotoXY(70, 17);
//				cout<<list.ds[i].B;
//				gotoXY(70, 20);
//				cout<<list.ds[i].C;
//				HighLight();
//				gotoXY(70, 23);
//				cout<<list.ds[i].D;
//				Normal();
//				ShowCur(0);	
//				list2.ds[i].DA = "D";		
//			}
//			else if(c== 27) {
//				XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
//				stop = 1;
//				goto c;
//			}else if(stop == 1) {
//				XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
//				goto c;
//			}	
//		}
//	}
//	c:for(int i=0; i < list2.sl; i++) {										
//		if(list2.ds[i].DA.compare(list.ds[i].DA) == 0) {
//			check++;
//		}						
//	}				
//	timer.join();
//	diem = roundf(((float)10* check/n) * 10) / 10;;
//	GiaoDienKetQua();
//	gotoXY(90,8);
//	cout<<maMH;
//	gotoXY(90,11);
//	cout<<tam->data.tenMH;
//	gotoXY(90,14);
//	cout<<check;
//	gotoXY(90,17);
//	cout<<diem;	
//	if(username !="GV") {
//		DT dt;
//		dt.diem = diem;
//		dt.maMH = maMH;
//		NODEDT* g = Khoi_Tao_NODE_DT(dt);
//		int vt = LayMaLop2(ds_lop, username);
//		for (NODESV* k = ds_lop.ds[vt]->listSV.pHead; k != NULL; k = k->pNext) {					
//			if (k->data.maSV.compare(username) == 0) {
//				Them_Cuoi_DSDT(k->data.listDiem, g); 				
//			}	
//		}	
//	}
//	Normal();
//}
//



void Xuat_Diem(DT dt) {
	cout << "\tMa mon " << dt.maMH <<" ";
	cout << "Diem  " << dt.diem << endl;
}
void Xuat_DSDiem(DSDIEM l) {
	cout << "\n=========Diem==========\n";
	for (NODEDT* k = l.pHead; k != NULL; k = k->pNext) {
		Xuat_Diem(k->data);			
	}
}

void Xuat_SV(SV sv) {
	cout << "\t\tMa SV " << sv.maSV <<"H" <<endl;
	cout << "\t\tHo  " << sv.ho << endl;
	cout << "\t\tTen  " << sv.ten << endl;
	cout << "\t\tPhai " << sv.phai << endl;
	cout << "\t\tPassword " << sv.password << endl;
	Xuat_DSDiem(sv.listDiem);
}
void Xuat_DSSV(DSSV l) {
	cout << "\n\t\t=========Sinh vien============\n";
	for (NODESV* k = l.pHead; k != NULL; k = k->pNext) {	
		Xuat_SV(k->data);
		//cout << endl;
	}
}

void xuat_ds_lop(DSLOP ds_lop)
{	
	for (int i = 0; i < ds_lop.sl; i++)
	{
		cout << "\n\t\t=======Xuat danh sach lop" <<i+1<<" ==============="<<endl;
		cout << "\t\t\tMa lop: " << ds_lop.ds[i]->maLop << " ";
		cout << "Ten lop: " << ds_lop.ds[i]->tenLop << endl;
		Xuat_DSSV(ds_lop.ds[i]->listSV);
	}
}





