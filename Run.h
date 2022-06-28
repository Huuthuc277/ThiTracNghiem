#include"ctdl.h"
#include"DoHoa.h"
#include"XuLyLinhTinh.h"
#include"test.h"
#include"XuLyDe.h"
#include"DocGhiFile.h"
#include"GiaiPhong.h"

char mainMENU[7][100]= {
						"Lop          ",
						"Sinh Vien    ",
						"Mon Hoc      ",
						"Them Cau Hoi ",
						"Thi Trac Nghiem ",
						"Xuat Danh Sach Diem ",	
						"Xuat Chi Tiet Cau TL",	
						};
char mainMENU2[2][100]= {
						"Thi Trac Nghiem",
						"Thoat",
						};
char MENULOP[4][100]={
						"Nhap lop",
						"In danh sach lop",
						"Hieu chinh lop",
						"Xoa lop"
						};

char MENUSINHVIEN[4][100]={
						"Nhap sinh vien",
						"In danh sach sinh vien",
						"Hieu chinh sinh vien",
						"Xoa sinh vien"
						};
char MENUTMONHOC[4][100]={
						"Them mon hoc        ",
						"In danh sach mon hoc",
						"Hieu chinh mon hoc  ",
						"Xoa mon hoc         "
						};



void SetUp() {	
	system("color 7f");
	resizeConsole(1280, 1024);
	HCNText(1, 3, 159, 39, 248);
	for (int i = 1; i < 160; i++) {
		SetBGColor(248);
		gotoXY(i, 33);
		cout << " ";
	}
	gotoXY(3, 20);
	textcolor(244);
	SetBGColor(7);
	cout << "Thong bao\n";
	for (int i = 4; i < 33; i++)  {
		SetBGColor(248);
		gotoXY(50, i);
		cout << " ";
	}
	gotoXY(1, 19);
	SetBGColor(248);
	cout << "                                                 ";
	HighLight();
	gotoXY(BoxHuongDan[0] + 1, BoxHuongDan[2] - 1);
	cout << "Huong dan";
	Normal();	
}


void inmanhinhmenu(char menu[][100],int so_item)
{
	int x=BoxMenu[0]+5;
	int y=BoxMenu[2];
	for (int i = 0; i < so_item; i++) {
		gotoXY(x,y++);
		cout << menu[i];
	}
}

int Menu(char menu[][100],int so_item) 
{	
	int chon = 0;
	int i;  
	for (i = 0; i < so_item; i++) {
		gotoXY(BoxMenu[0]+5, BoxMenu[2] + i);
		cout << menu[i];
	}
	HighLight();
	gotoXY(BoxMenu[0]+5, BoxMenu[2] + chon);
	cout << menu[chon];
	Normal();
	char kytu;
	
	do {
		kytu = getch();
		if (kytu == 224) kytu = getch();
		switch (kytu) {
			case 72:if (chon + 1 > 1)	{
				Normal();
				gotoXY(BoxMenu[0]+5, BoxMenu[2] + chon);
				cout << menu[chon];
				chon--;
				HighLight();
				gotoXY(BoxMenu[0]+5, BoxMenu[2] + chon);
				cout << menu[chon];
				Normal();
			}
				break;
			case 80:if (chon + 1 < so_item) {
				Normal();
				gotoXY(BoxMenu[0]+5, BoxMenu[2] + chon);
				cout << menu[chon];
				chon++;
				HighLight();
				gotoXY(BoxMenu[0]+5, BoxMenu[2] + chon);
				cout << menu[chon];
				Normal();
				}
				break;
			case 13: {
					XoaManHinh(BoxMenu[0],BoxMenu[1],BoxMenu[2],BoxMenu[3]);
					return chon + 1;
			}
			case 27:
				return 0;
		}  // end switch
	} while (1);
}

void RunMENU1(DSLOP &ds_lop, TREE t, string username){
	HDMainMenu();
	gotoXY(148,2);
	cout<<"Username: "<<username;
	do{		
		ShowCur(0);
		XoaManHinh(BoxMenu[0],BoxMenu[1],BoxMenu[2],BoxMenu[3]);
		int chon=Menu(mainMENU,7);
		switch(chon) {
			case 1: {
				int tam=1;
				do {
					int chon1=Menu(MENULOP,4);
					switch(chon1) {
						case 1: {
							inmanhinhmenu(MENULOP,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							ThemMotLop(ds_lop);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HDMainMenu();
							break;
						}
						case 2: {
							inmanhinhmenu(MENULOP,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							XuatDanhSachLop(ds_lop);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);																							
							HDMainMenu();
							break;
						}
						case 3: {
							inmanhinhmenu(MENULOP,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HieuChinhLop(ds_lop);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HDMainMenu();
							break;
						}
						case 4: {	
							inmanhinhmenu(MENULOP,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							XoaLop(ds_lop);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HDMainMenu();
							break;
						}
						case 0: tam=0;break;
					}
				}while(tam==1);break;
			}	
			case 2: {
				int tam=1;
				do {
					int chon2=Menu(MENUSINHVIEN,4);
					switch(chon2){
						case 1: {
							inmanhinhmenu(MENUSINHVIEN,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							ThemSV(ds_lop);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HDMainMenu();
							break;
						}
						case 2: {
							inmanhinhmenu(MENUSINHVIEN,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							XuatDanhSachLop2(ds_lop);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HDMainMenu();
							break;
						}
						case 3: {
							inmanhinhmenu(MENUSINHVIEN,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HieuChinhSV(ds_lop);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HDMainMenu();
							break;
						}
						case 4: {			
							inmanhinhmenu(MENUSINHVIEN,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							XoaSV(ds_lop);	
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);							
							HDMainMenu();
							break;
						}
						case 0: tam=0;break;
					}
				}while(tam==1);break;
			
			}
			case 3: {
				int tam=1;
				do {
					int chon3=Menu(MENUTMONHOC,4);
					switch(chon3) {
						case 1:	{
							inmanhinhmenu(MENUTMONHOC,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							ThemMH(t);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HDMainMenu();
							break;
						}
						case 2:	{
							inmanhinhmenu(MENUTMONHOC,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							XuatDanhSachMH(t);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HDMainMenu();
							break;
						}
						case 3: {
							inmanhinhmenu(MENUTMONHOC,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HieuChinhMH(t);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HDMainMenu();
							break;
						}
						case 4: {	
							inmanhinhmenu(MENUTMONHOC,4);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							XoaMH(t);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
							HDMainMenu();
							break;
						}
						case 0: tam=0;break;
					}
				}while(tam==1);break;			
			}	
			case 4: {
				inmanhinhmenu(mainMENU,7);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
				ThemCauHoi(t);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
				HDMainMenu();
				break;
			}	
			case 5: {
				inmanhinhmenu(mainMENU,7);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
				ThiTracNghiem(t, ds_lop, username);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
				HDMainMenu();
				break;
			}	
			case 6: {
				inmanhinhmenu(mainMENU,7);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
				XuatDanhSachDiem(t, ds_lop);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
				HDMainMenu();
				break;
			}	
			case 7: {
				inmanhinhmenu(mainMENU,7);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
				XuatDanhSachCT(t, ds_lop);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
				HDMainMenu();
				break;
			}			
			case 0: {   
				ghi_file_lop(ds_lop);							
				ghi_file_ds_mh(t);
				return;
			}		
		} 
	}while(1);
}

void RunMENU2(DSLOP &ds_lop, TREE t, string username){
	HDMainMenu();
	SV user = LaySV(ds_lop, username);
	gotoXY(120,1);
	cout<<"Ma so SV: "<<username;
	gotoXY(120,2);
	cout<<"Ho va ten: "<<user.ho<<" "<<user.ten;
	do{		
		ShowCur(0);
		XoaManHinh(BoxMenu[0],BoxMenu[1],BoxMenu[2],BoxMenu[3]);
		int chon=Menu(mainMENU2,2);
		switch(chon) {
			case 1:	{
				inmanhinhmenu(mainMENU2,2);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
				ThiTracNghiem(t, ds_lop, username);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
				HDMainMenu();
				break;
			}	
			case 2:	{
				ghi_file_lop(ds_lop);							
				ghi_file_ds_mh(t);
				return;									
			}	
			case 0: {   
				ghi_file_lop(ds_lop);							
				ghi_file_ds_mh(t);
				return;
			}		
		} 
	}while(1);
}


