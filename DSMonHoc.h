#ifndef DSMONHOC_H
#define DSMONHOC_H
#include "thuvienlaptrinh.h"
#include "DSLop.h"
#define MAX 300
#define MAX2 6
using namespace std;
struct monhoc
{
	char MAMH[15];
	string tenMH;
};typedef struct monhoc MONHOC;
struct list 
{
	int soluong  ;
	MONHOC *dsmh[MAX];
};typedef struct list listMH;

bool TimKiemMONHOC(listMH &lmh,string &str);
void Nhap_MonHoc(listMH &lmh,MONHOC &mh);
void Xuat_MonHoc(MONHOC &mh);
bool EmptyMOHOC(listMH &lmh);
void Nhap_ListMH(listMH &lmh,LISTLOP &dsl);
void SwapMonHoc(MONHOC &a, MONHOC &b);
void SapXep(listMH &lmh);
void Xuat_ListMH(listMH &lmh);
void Save_MH(ofstream &fo,MONHOC &mh);
void Save_List(listMH &lmh);
void Read_MH(ifstream &fi,listMH &lmh ,MONHOC &mh);
void Read_listMH(listMH &lmh);
void ThemMONHOC(listMH &lmh,MONHOC &mh,LISTLOP &dsl);
void XoaMONHOC(listMH &lmh, char mact[15],LISTLOP &dsl);
void Fill_MH_Cho_Sv_Moi(listMH &lmh,LISTLOP &dsl);
void Hieu_Chinh_MONHOC(listMH &lmh,char mact[15],LISTLOP &dsl);
void menuMONHOC(listMH &lmh,LISTLOP &dsl);
#endif
