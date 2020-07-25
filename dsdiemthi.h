#ifndef DSDIEMTHI_H
#define DSDIEMTHI_H
#include "thuvienlaptrinh.h"
using namespace std;
struct diemthi
{
	char Mamh[15];
	//float diemthi =0.0;	
	float diemthi =0.0;
};typedef struct diemthi DIEMTHI;
struct nodeDIEMTHI
{
	DIEMTHI datadt;
	struct nodeDIEMTHI *NEXT;
};typedef struct nodeDIEMTHI NODEDT;
struct listdt
{
	NODEDT *pHeadDt;
	NODEDT *pTailDt;
};typedef struct listdt LISTDT;
NODEDT *KTN_DiemThi(DIEMTHI &dt);
int DemSoDiemThi(LISTDT &ldt);
void KTList_DiemThi(LISTDT &ldt);
void Them_Dt_VaoCuoi(LISTDT &ldt,NODEDT *pdt);
void Xoa_Dt(LISTDT &ldt, char macx[15]);
void Hieu_Chinh_Dt(LISTDT &ldt,char mact[15],char mamoi[15]);
void Save_ListDiemThi(ofstream &fo,LISTDT &ldt);
void Read_DiemThi(ifstream &fi, DIEMTHI &dt);
void Read_List_DiemThi(ifstream &fi,LISTDT &ldt);
void Xuat_Diem_Thi(DIEMTHI &dt);
void Xuat_List_Diem_Thi(LISTDT &ldt);
void Giai_Phong_DT(LISTDT &ldt);
void Swap_DT(DIEMTHI &a, DIEMTHI &b);
void Sap_Xep_DT(LISTDT &ldt);
#endif
