#ifndef DSCAUHOITHI_H
#define DSCAUHOITHI_H
#include "thuvienlaptrinh.h"
#include "DSMonHoc.h"
//#include "DSlop.h"
using namespace std;
#define MAX3 10000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct cauhoithi
{
	int id;
	char MAMH[15];
	string noidung;
	string A;
	string B;
	string C;
	string D;
	char dapan;
};typedef struct cauhoithi CAUHOI;
struct node
{
	CAUHOI data; // du lieu cua cai node ==>du lieu node luu tru 
	struct node *pLEFT;// node lien ket ben trai cua cay => cây con trai
	struct node *pRIGHT;// node lien ket ben phai cua cay => cay con phai 
};
typedef struct node NODE;
typedef NODE* TREE;
void KhoiTaoCay(TREE &t);
void themDuLieu(TREE &t, CAUHOI &ch);
bool KT_MaCH_DSMH(listMH &lmh, string mamh);
void nhapCauHoi(TREE &t, CAUHOI &ch, listMH &lmh);

















//struct Stackid //danh sach id ngau nhien
//{
//	int top = 0;
//	int *listid;
//	int top;
//};typedef struct Stackid STACKID;
//struct cauhoithitheoma // danh sach cau hoi thi theo ma dc boc tu danh sach cau hoi thi
//{
//	int count;
//	CAUHOI *stkch[MAX3];
//};typedef struct cauhoithitheoma CAUHOIMA;
//struct cautraloi// cau tra loi cua sinh vien
//{
//	char answer;		
//};typedef struct cautraloi CAUTRALOI;
//struct listctl// danh sach cau tra loi cua sinh vien 
//{
//	int vitri_ctl;
//	CAUTRALOI *ctd;
//};typedef struct listctl LISTCTL;
//struct cauhoingaunhien// danh sach cau hoi ngau nhien duoc boc tu danh sach cau hoi thi theo ma
//{
//	int socauhoithi;// so cau hoi se thi ma nguoi dung nhap vao
//	int vitri_chnn ;// bien vi tri cau hoi thi trong danh sach
//	CAUHOI *chnn[MAX3];
//};typedef struct cauhoingaunhien CAUHOINGAUNHIEN;

//void TimKiemCauHoi(TREE &t);
//void Khoitaoidngaunhien(STACKID &stkid);
//bool KT_MaCH_DSMH(listMH &lmh, string mamh);
//void Nhap_Cau_Hoi(CAUHOI &ch, STACKID &stk,listMH &lmh);
//void Xuat_Cau_Hoi(CAUHOI &ch);
//void Rotate_Left(TREE &t);
//void Rotate_Right(TREE &t);
//void Rotate_Right_Left(TREE &t);
//void Rotate_Left_Right(TREE &t);
//int balanceLeft(TREE &t);
//int balaneceRight(TREE &t);
//int searchStandFor(TREE &p, TREE &q);
//int Xoa_Cau_Hoi_Thi(TREE &t,int x);
//int DemSoHang(TREE &t);
//int Insert_balance(TREE &t,CAUHOI &ch);
//void Hieu_Chinh_Cau_Hoi_Ma(TREE &t,string mact,string mamoi);
//void Duyet_LRN_Khudequi(TREE &t);
//void ThemCauHoiThi(TREE &t,CAUHOI &ch);
//void XemBF(TREE &t);
//void Save_CauHoi(ofstream &fo, CAUHOI &ch);
//void Save_ListCauHoi(TREE &t);
//void Read_CauHoi(ifstream &fi,CAUHOI &ch,STACKID &stk);
//void Read_ListCauHoi(TREE &t,STACKID &stk);
//void Xuat_Cau_Hoi_Theo_Ma(TREE &t,char mamh[15]);
//void Boc_Cau_Hoi_Thi_Theo_MA(TREE &t,char maMH[15],CAUHOIMA &chm);
//void Boc_Cau_Hoi_Thi_Ngau_Nhien(TREE &t,CAUHOIMA &chm,CAUHOINGAUNHIEN &randomquestion);
//void menuCAUHOI(TREE &t,listMH &lmh,STACKID &stk);
//bool Kiem_Tra_Mon_Do_Da_Co_Cau_Hoi_Chua(TREE &t,char mamh[15]);
//struct id


#endif

