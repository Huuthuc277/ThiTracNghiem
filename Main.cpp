#include "Run.h"

int main(int argc, char** argv) {	
	string username;
	DSLOP ds_lop;
	TREE t;
	t = NULL;
	doc_file_lop(ds_lop);	
	doc_file_ds_mh(t);
	SetUp();
	username = DangNhap(ds_lop);	
	if(username == "GV") {	
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);	
		RunMENU1(ds_lop, t, username);		
	}else if(!username.empty()) {
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1] + 1,BoxHuongDan[2],BoxHuongDan[3]);
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);	
		RunMENU2(ds_lop, t, username);
	}
	GiaiPhongTREE(t);
	DeleteLop(ds_lop);	
	system("pause");
	return 0;	

}
