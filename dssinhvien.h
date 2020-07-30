#ifndef DSSINHVIEN_H
#define DSSINHVIEN_H
#include "thuvienlaptrinh.h"
#include "dsdiemthi.h"
struct sinhvien
{
	string masv;
	string ho;
	string ten;
	string phai;
	string password;
	LISTDT *ldt;
};typedef struct sinhvien SINHVIEN;
struct nodesv
{
	SINHVIEN datasv;
	struct nodesv *pNEXT;
};typedef struct nodesv NODESV; 
struct listsinhvien
{
	NODESV *pHEAD;
	NODESV *pTAIL;
};typedef struct listsinhvien LISTSINHVIEN;
bool TimkiemSv(LISTSINHVIEN &lsv,string &temp);
bool EmptySinhVien(LISTSINHVIEN &lsv);
NODESV *KhoiTaoSV(SINHVIEN sv);
void KhoiTaoListSV(LISTSINHVIEN &lsv);
void Nhap_SV(LISTSINHVIEN &lsv,SINHVIEN &sv);
void Xuat_SV(SINHVIEN &sv);
int So_Luong_Sinh_Vien(LISTSINHVIEN &lsv);
void ThemSVVaoCuoi(LISTSINHVIEN &lsv, NODESV *p);
void ThemSVVaoDau(LISTSINHVIEN &lsv,NODESV *p);
void Xoa_SinhVien_BatKi(LISTSINHVIEN &lsv,string &macx);
void Xoa_SinhVien_Cuoi(LISTSINHVIEN &lsv);
void Xoa_SinhVien_Dau(LISTSINHVIEN &lsv);
void Hieu_Chinh_SinhVien(LISTSINHVIEN &lsv,string &matemp);
void Save_SV(ofstream &fo,SINHVIEN &sv);
void Save_List_Sv(ofstream &fo,LISTSINHVIEN &lsv);
void Read_Sv(ifstream &fi,LISTSINHVIEN &lsv,SINHVIEN &sv);
void Read_List_Sv(ifstream &fi,LISTSINHVIEN &lsv);
void Swap_Sv(SINHVIEN &a,SINHVIEN &b);
void Sap_Xep_SinhVien(LISTSINHVIEN &lsv);
void Xuat_DS_SV(LISTSINHVIEN &lsv);
void GiaiPhongSinhVien(LISTSINHVIEN &lsv);
void menuSINHVIEN(LISTSINHVIEN &lsv);
#endif
