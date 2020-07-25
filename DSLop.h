#ifndef DSLOP_H
#define DSLOP_H
#include "thuvienlaptrinh.h"
#include "dssinhvien.h"
#define MAX3 500
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct lop
{
	string maLOP;
	string tenLOP;
	string nienKhoa;
	LISTSINHVIEN *lsv;// con tro danh sach sinh vien
};
typedef struct lop LOP;
struct listlop // dsl.dslop[i]->lsv
{
	int soluonglop ;
	LOP *dslop[MAX3];
};

//sua theo cau truc mang con tro
typedef struct listlop LISTLOP;
bool TimKiemMaLop(LISTLOP &dsl,string &strmalop);
bool EmptyLop(LISTLOP &dsl);
void Nhap_1_lop(LISTLOP &dsl,LOP &l);
void Nhap_List_Lop(LISTLOP &dsl);
void Xuat_1_LOP(LOP &l);
void Xuat_ListLop(LISTLOP &dsl);
void Save_Lop(ofstream &fo, LOP &l);
void Save_List_Lop(LISTLOP &dsl);
void Save_Lop_SV(ofstream &fo, LOP &l);
void Save_List_Lop_SV(LISTLOP &dsl);
void Read_Lop(ifstream &fi,LISTLOP &dsl, LOP &l);
void Read_ListLop(LISTLOP &dsl);
void Read_Lop_SV(ifstream &fi,LISTLOP &dsl, LOP &l);
void Read_ListLop_SV(LISTLOP &dsl);
void SwapLop(LOP &a,LOP &b);
void SapXepLop(LISTLOP &dsl);
void Them_Lop(LISTLOP &dsl, LOP &lct);
void Hieu_Chinh_DSLop(LISTLOP &dsl, string &mactt);
void Xoa_Lop(LISTLOP &dsl,string &mact);
void QuanLiSV_LOP(LISTLOP &dsl);

void menuLOP(LISTLOP &dsl,LOP &l);
#endif
