#include<iostream>
#include<fstream>
#include<math.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<iomanip>
#include <thread>
#include <unistd.h>
using namespace std;
#define MAXLIST 200
int BoxMenu[4]={3,48,6,17}; //toa do hop menu x1,x2,y1,y2
int BoxMain[4]={53,158,6,32};
int BoxTB[4]={3,48,21,32};
int BoxHuongDan[4]={2,158,35,40};
const int MaxBox= 28; // so luong toi da dong cua Boxmain

int toadoX =55;
int toadoY=5;
int toadoX1 =52;
int toadoY1=4;
int stop = 0;
//======= Danh sach cau hoi======
struct CauHoi {
	int id;
	string noiDung;
	string A;
	string B;
	string C;
	string D;
	string DA;
}; typedef struct CauHoi CAUHOI;

struct dsCauHoi {
	CAUHOI ds[MAXLIST];
	int sl = 0;
}; typedef struct dsCauHoi DSCAUHOI;

//======= Danh sach mon hoc======
struct MonHoc {
	string maMH;
	string tenMH;
};typedef struct MonHoc MH;

struct nodeMonHoc {
	MH data;
	struct nodeMonHoc* pLeft;
	struct nodeMonHoc* pRight;
	DSCAUHOI listCauHoi;
}; 
typedef struct nodeMonHoc NODEMH;
typedef NODEMH* TREE;

//======= Cau hoi tra loi ======
struct ct
{
	int id;
	string noiDung;
	string DA;
}; typedef struct ct CT;

struct dsTraLoi{
	CT ds[60];
	int sl = 0;
};typedef struct dsTraLoi DSTL;

//======= Danh sach diem thi ======
struct DiemThi {
	string maMH;
	float diem;
	
	DSTL listCT;
}; typedef struct DiemThi DT;

struct nodeDiemThi {
	DT data;
	nodeDiemThi* pNext;
}; typedef struct nodeDiemThi NODEDT;

struct dsDiem
{
	nodeDiemThi* pHead = NULL;
	nodeDiemThi* pTail = NULL;
}; typedef struct dsDiem DSDIEM;


//======= Danh sach sinh vien ======
struct SinhVien {
	string maSV;
	string ho;
	string ten;
	string phai;
	string password;

	DSDIEM listDiem;
}; typedef struct SinhVien SV;

struct nodeSinhVien {
	SV data;
	nodeSinhVien* pNext;
}; typedef struct nodeSinhVien NODESV;

struct dsSinhVien {
	nodeSinhVien* pHead = NULL;
	nodeSinhVien* pTail = NULL;
}; typedef struct dsSinhVien DSSV;

//======= Danh sach lop ======
struct Lop {
	string maLop;
	string tenLop;	
	DSSV listSV;
};
typedef struct Lop LOP;

struct dsLop{
	LOP* ds[100];
	int sl = 0;
};typedef struct dsLop DSLOP;









