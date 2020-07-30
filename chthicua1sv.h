#ifndef CHTHICUA1SV_H
#define CHTHICUA1SV_H
#include "thuvienlaptrinh.h"
#include "dscauhoi.h"
#define MAX4 10000 
using namespace std;
// 1 sinh vien co 1 danh sach cac cau hoi da thi cua 1 mon
struct cauhoidathi_sv
{
	string mssv;
	string hosv;
	string tensv;
	int chiso;// so luong cau hoi da thi cua mot tg sinh vien
	CAUHOI *chdt[MAX4];// mang con tro chua cac cau hoi da thi cua mot sinh vien
};typedef struct cauhoidathi_sv CH_DATHI_SV;
struct nodechdt
{
	CH_DATHI_SV chdtsv;
	struct nodechdt *nNEXT;
};typedef struct nodechdt NODECHDT;
struct list_cauhoidathi_sv
{
	NODECHDT *pheadCH;
	NODECHDT *ptailCH;
};typedef struct list_cauhoidathi_sv LISTCHDT_SV;// danh sach sinh vien da thi
//void Nap_CH_Sau_Khi_Thi(LISTCHDT_SV &lchdt_sv,CAUHOINGAUNHIEN &rdqt,LISTLOP &dsl,string &massv);
NODECHDT *KhoiTaoNode_CHDT(CH_DATHI_SV &x);
void Khoi_Tao_List_CHDT(LISTCHDT_SV &lchdt_sv);
void Them_CHDT_Vao_Cuoi(LISTCHDT_SV &lchdt_sv, NODECHDT *pch);
void Xem_CH_Thi_1_SV(LISTCHDT_SV &lchdt_sv,listMH &lmh);
int Dem_SoLuong_SV_Da_Thi(LISTCHDT_SV &lchdt_sv);
bool Kiem_Tra_SV_Da_Thi_Chua(LISTCHDT_SV &lchdt_sv,string &massv);
bool Kiem_Tra_Mon(LISTCHDT_SV &lchdt_sv,string &massv,char mamon[15]);
void Save_CH_Thi_1_SV(LISTCHDT_SV &lchdt_sv);
void Read_CH_Thi_1_SV(LISTCHDT_SV &lchdt_sv);
void Xoa_SV_Da_THi(LISTCHDT_SV &lchdt_sv,string &macx);
void Xem_Diem_SV(LISTCHDT_SV &lchdt_sv,SINHVIEN &sv);
void Xem_List_Diem_SV(listMH &lmh,LISTCHDT_SV &lchdt_sv,LISTSINHVIEN &lsv);
void Xem_Diem_Cua_1_Lop(listMH &lmh,LISTCHDT_SV &lchdt_sv,LISTLOP &dsl);
#endif
