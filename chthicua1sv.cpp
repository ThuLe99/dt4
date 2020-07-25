#include "chthicua1sv.h"
int x = 60;
int xdong;
NODECHDT *KhoiTaoNode_CHDT(CH_DATHI_SV &x)
{
	NODECHDT *p = new NODECHDT;
	p->chdtsv=x;
	p->nNEXT=NULL;
	return p;
}
void Khoi_Tao_List_CHDT(LISTCHDT_SV &lchdt_sv)
{
	lchdt_sv.pheadCH=NULL;
	lchdt_sv.ptailCH=NULL;
}
void Them_CHDT_Vao_Cuoi(LISTCHDT_SV &lchdt_sv, NODECHDT *pch)
{
	if(lchdt_sv.pheadCH==NULL)
	{
		lchdt_sv.pheadCH=lchdt_sv.ptailCH=pch;
	}
	else
	{
		lchdt_sv.ptailCH->nNEXT=pch;
		lchdt_sv.ptailCH=pch;
	}
}
bool Kiem_Tra_SV_Da_Thi_Chua(LISTCHDT_SV &lchdt_sv,string &massv)
{
	for(NODECHDT *k = lchdt_sv.pheadCH;k!=NULL;k=k->nNEXT)
	{
		if(stricmp(massv.c_str(),k->chdtsv.mssv.c_str())==0)
		{
			return true;
		}
	}
	return false;
}
// kiem tra sinh vien da thi mon do chua
bool Kiem_Tra_Mon(LISTCHDT_SV &lchdt_sv,string &massv,char mamon[15])
{
	for(NODECHDT *k = lchdt_sv.pheadCH;k!=NULL;k=k->nNEXT)
	{
		if(stricmp(k->chdtsv.mssv.c_str(),massv.c_str())==0)
		{
			for(int i = 0 ; i<k->chdtsv.chiso;i++)
			{
				if(stricmp(mamon,k->chdtsv.chdt[i]->MAMH)==0)
				{
					return true;
				}
			}
			break;
		}
	}
	return false;
}
// sau khi thi cac cau hoi se dc luu vao trong danh sach cac cau hoi da thi
//void Nap_CH_Sau_Khi_Thi(LISTCHDT_SV &lchdt_sv,CAUHOINGAUNHIEN &rdqt,LISTLOP &dsl,string &massv)
//{
//	// truong hop 1: sinh vien do da co ten trong danh sach va thi tiep mot mon moi
//	// tiep tuc luu cac cau hoi moi sau cac cau hoi cu
//	if(Kiem_Tra_SV_Da_Thi_Chua(lchdt_sv,massv)==true)// kiem tra sinh vien do da thi lan dau hay da thi r
//	{
//		for(NODECHDT *p=lchdt_sv.pheadCH;p!=NULL;p=p->nNEXT)// duyet danh sach sinh vien da thi
//		{
//			if(stricmp(p->chdtsv.mssv.c_str(),massv.c_str())==0)// neu co ten sinh vien da thi
//			{
//				// tiep tuc luu cac cau moi phia sau cac cau hoi cu
//				for(int i =0;i<rdqt.socauhoithi;i++)
//				{
//					p->chdtsv.chdt[p->chdtsv.chiso] = new CAUHOI;
//					p->chdtsv.chdt[p->chdtsv.chiso] = rdqt.chnn[i];
//					p->chdtsv.chiso++;
//				}
//				break;
//			}
//		}
//	}
//	// truong hop 2 : sinh vien do thi lan dau tien 
//	else if(Kiem_Tra_SV_Da_Thi_Chua(lchdt_sv,massv)==false)// neu sinh vien do thi lan dau
//	{
//		CH_DATHI_SV chdtsv;
//		chdtsv.chiso=0;// cho chi so chdt cua sinh vien = 0
//		chdtsv.mssv = massv;
//		for(int i =0;i<rdqt.socauhoithi;i++)// rang cau hoi thi vao danh sach cau da thi cua 1 sinh vien
//		{
//			chdtsv.chdt[chdtsv.chiso] = new CAUHOI;
//			chdtsv.chdt[chdtsv.chiso] = rdqt.chnn[i];
//			chdtsv.chiso++;
//		}
//		// rang ho va ten nguoi thi  vao danh sach sinh vien da thi
//		for(int i = 0;i<dsl.soluonglop;i++)
//		{
//			for(NODESV *k=dsl.dslop[i]->lsv->pHEAD;k!=NULL;k=k->pNEXT)
//			{
//				if(stricmp(massv.c_str(),k->datasv.masv.c_str())==0)
//				{
//					chdtsv.hosv=k->datasv.ho;
//					chdtsv.tensv=k->datasv.ten;
//					break;
//				}
//			}
//		}
//		NODECHDT *pch = KhoiTaoNode_CHDT(chdtsv);// khoi tao node chdt
//		Them_CHDT_Vao_Cuoi(lchdt_sv,pch);// them vao cuoi danh sach sinh vien da thi
//	}
//}
int Dem_SoLuong_SV_Da_Thi(LISTCHDT_SV &lchdt_sv)
{
	int dem = 0;
	for(NODECHDT *k = lchdt_sv.pheadCH;k!=NULL;k=k->nNEXT)
	{
		dem++;
	}
	return dem;
}
// luu danh sach sinh vien da thi, moi sinh vien chua mot danh sach cau hoi da thi
void Save_CH_Thi_1_SV(LISTCHDT_SV &lchdt_sv)
{
	ofstream fo;
	fo.open("danhsachcauhoithicua1sinhvien.txt",ios::out);
	fo<<Dem_SoLuong_SV_Da_Thi(lchdt_sv)<<endl<<endl;// so luong sinh vien da thi
	for(NODECHDT *k = lchdt_sv.pheadCH;k!=NULL;k=k->nNEXT)
	{
		fo<<k->chdtsv.mssv<<"|";
		fo<<k->chdtsv.hosv<<" "<<k->chdtsv.tensv<<endl;
		fo<<k->chdtsv.chiso<<endl;// so luong cau hoi da thi
		// danh sach cau hoi da thi
		for(int i =0;i<k->chdtsv.chiso;i++)
		{
			fo<<k->chdtsv.chdt[i]->MAMH<<".";
			fo<<k->chdtsv.chdt[i]->noidung<<endl;
			fo<<k->chdtsv.chdt[i]->A<<endl;
			fo<<k->chdtsv.chdt[i]->B<<endl;
			fo<<k->chdtsv.chdt[i]->C<<endl;
			fo<<k->chdtsv.chdt[i]->D<<endl;
			fo<<k->chdtsv.chdt[i]->dapan<<endl;
		}
	}
	fo.close();
}
// doc du lieu danh sach sinh vien da thi
void Read_CH_Thi_1_SV(LISTCHDT_SV &lchdt_sv)
{
	ifstream fi;
	int soluongsv;
	string str;
	fi.open("danhsachcauhoithicua1sinhvien.txt",ios::in);
	Khoi_Tao_List_CHDT(lchdt_sv);// khoi tao danh sach sinh vien da thi
	fi>>soluongsv;// doc vao so luong sinh vien
	getline(fi,str);
	getline(fi,str);
	for(int i = 0 ;i<soluongsv;i++)
	{
		CH_DATHI_SV chdtsv;
		getline(fi,chdtsv.mssv,'|');
		getline(fi,chdtsv.hosv,' ');
		getline(fi,chdtsv.tensv);
		fi>>chdtsv.chiso;// doc vao so luong cau hoi da thi
		getline(fi,str);
		// doc danh sach cau hoi da thi dua vao chdtsv.chi so
		for(int j = 0;j<chdtsv.chiso;j++)
		{
			chdtsv.chdt[j] = new CAUHOI;
			fi.getline(chdtsv.chdt[j]->MAMH,15,'.');
			getline(fi,chdtsv.chdt[j]->noidung);
			getline(fi,chdtsv.chdt[j]->A);
			getline(fi,chdtsv.chdt[j]->B);
			getline(fi,chdtsv.chdt[j]->C);
			getline(fi,chdtsv.chdt[j]->D);
			fi>>chdtsv.chdt[j]->dapan;
			getline(fi,str);
		}
		NODECHDT *p = KhoiTaoNode_CHDT(chdtsv);// khoi tao node chdt
		Them_CHDT_Vao_Cuoi(lchdt_sv,p);// them vao cuoi danh sach sinh vien da thi
	}
	fi.close();
}
// xem cau hoi thi cua 1 sinh vien
void Xem_CH_Thi_1_SV(LISTCHDT_SV &lchdt_sv,listMH &lmh)
{
		xdong=7;
		int flag;
		int dem=1;
		int x=60;
		string mssv;
		string tenmonhoc;
		char mamon[15];
		VemenuTONG();
		gotoxy(x+40,3);
		cout<<"Danh Sach Sinh Vien";
		VeKhungCH(x,2,100,2,true);
		gotoxy(x,5);
		cout<<setw(15)<<right<<" "<<setw(35)<<left<<"Ma Sinh Vien"<<char(179);
		cout<<setw(15)<<right<<" "<<setw(34)<<left<<"Ho Ten"<<char(179);
		VeKhungCH(x,4,100,2,true);
		for(NODECHDT *k=lchdt_sv.pheadCH;k!=NULL;k=k->nNEXT)
		{
			gotoxy(x,xdong++);
			cout<<setw(10)<<right<<" "<<setw(40)<<left<<k->chdtsv.mssv<<char(179);
			cout<<setw(10)<<right<<" "<<setw(39)<<left<<k->chdtsv.hosv+" "+k->chdtsv.tensv;
			dem++;
		}
		VeKhungCH(x,6,100,dem,true);
		xdong++;
		gotoxy(x,xdong++);
		cout<<"Ban muon tiep tuc thuc thien thao tac nay ?(Enter : DONG Y, Esc : Thoat) ";
		char key = getch();
		if(key==13)
		{
			do
			{
				flag = 0;
				gotoxy(x,xdong++);
				fflush(stdin);
				mssv.clear();
				cout<<" Nhap vao ma sinh vien muon xem cau hoi thi : ";
				XuLiNhap(mssv);
				if(Kiem_Tra_SV_Da_Thi_Chua(lchdt_sv,mssv)==false)
				{
					gotoxy(x,xdong++);
					cout<<"Thi sinh nay chua thi ! Nhap Lai !";
					flag=1;
				}
			}while(flag==1);
			VeKhungCH(x,++xdong,100,2,true);
			gotoxy(x+30,++xdong);
			cout<<"DANH SACH CAC MON DA THI CUA SINH VIEN NAY";
			xdong=xdong+2;
			int k=xdong;
			int l = 1;
			for(NODECHDT *h=lchdt_sv.pheadCH;h!=NULL;h=h->nNEXT)
			{
				if(stricmp(h->chdtsv.mssv.c_str(),mssv.c_str())==0)
				{
					for(int j = 0;j<lmh.soluong;j++)
					{
						for(int i =0;i<h->chdtsv.chiso;i++)
						{
							if(strcmp(h->chdtsv.chdt[i]->MAMH,lmh.dsmh[j]->MAMH)==0)
							{
								gotoxy(x,++xdong);
								//cout<<setw(20)<<left<<k->chdtsv.chdt->MAMH<<setw(40)<<lelft<<lmh.dsmh[i]->
								Xuat_MonHoc(*lmh.dsmh[j]);
								l++;
								break;
							}
						}
					}
					break;
				}
			}
			VeKhungCH(x,k,100,l,true);
			xdong=xdong+2;
			tenmonhoc.clear();
			gotoxy(x,++xdong);
			cout<<" Nhap vao ten mon hoc muon xem cau hoi thi : ";
			XuLiNhap(tenmonhoc);
			for(int i = 0;i<lmh.soluong;i++)
			{
				if(stricmp(tenmonhoc.c_str(),lmh.dsmh[i]->tenMH.c_str())==0)
				{
					strcpy(mamon,lmh.dsmh[i]->MAMH);
					break;
				}
			}
			
			if(Kiem_Tra_Mon(lchdt_sv,mssv,mamon)==false)
				{
					gotoxy(x,++xdong);
					cout<<" Thi sinh chua thi mon nay ! Nhap Lai ! ";
					return;
				}
				
			for(NODECHDT *p=lchdt_sv.pheadCH;p!=NULL;p=p->nNEXT)
			{
				if(stricmp(mssv.c_str(),p->chdtsv.mssv.c_str())==0)
				{
					gotoxy(x+15,++xdong);
					cout<<" DANH SACH CAU HOI DA THI ";
					for(int i=0;i<p->chdtsv.chiso;i++)
					{
						if(strcmp(mamon,p->chdtsv.chdt[i]->MAMH)==0)
						{
							gotoxy(x,++xdong);
							cout<<p->chdtsv.chdt[i]->noidung;
							gotoxy(x,++xdong);
							cout<<p->chdtsv.chdt[i]->A;
							gotoxy(x,++xdong);
							cout<<p->chdtsv.chdt[i]->B;
							gotoxy(x,++xdong);
							cout<<p->chdtsv.chdt[i]->C;
							gotoxy(x,++xdong);
							cout<<p->chdtsv.chdt[i]->D;
							gotoxy(x,++xdong);
							cout<<"Dap an : "<<p->chdtsv.chdt[i]->dapan;
						}
					}
				}
			}
		}
		else if(key==27)
		{
			return;
		}
}
void Xoa_SV_Da_THi(LISTCHDT_SV &lchdt_sv,string &macx)
{
	if(stricmp(lchdt_sv.pheadCH->chdtsv.mssv.c_str(),macx.c_str())==0)
	{
		NODECHDT *p = lchdt_sv.pheadCH;
		lchdt_sv.pheadCH=lchdt_sv.pheadCH->nNEXT;
		delete p;
		return;
	}
	if(stricmp(lchdt_sv.ptailCH->chdtsv.mssv.c_str(),macx.c_str())==0)
	{
		for(NODECHDT *p = lchdt_sv.pheadCH;p!=NULL;p=p->nNEXT)
		{
			if(p->nNEXT==lchdt_sv.ptailCH)
			{
				delete lchdt_sv.ptailCH;
				p->nNEXT=NULL;
				lchdt_sv.ptailCH=p;
				return;
			}
		}
	}
	NODECHDT *g = new NODECHDT; // node g la node tro den node nam truoc node can xoa : x
	for(NODECHDT *k=lchdt_sv.pheadCH;k!=NULL;k=k->nNEXT)
	{
		// phat hien phan tu can xoa
		if(stricmp(k->chdtsv.mssv.c_str(),macx.c_str())==0)
		{
			g->nNEXT=k->nNEXT;// cap nhat moi lien ket giua node k (node q)voi node sau node g
//			for(int i =0 ;i<k->chdtsv.chiso;i++)
//			{
//				delete k->chdtsv.chdt[i];
//			}
			
			delete k;// xoa node nam sau nodeq
			return ;
		}
		g=k;// cho node g tro den node k
	}
}
void Xem_Diem_SV(LISTCHDT_SV &lchdt_sv,SINHVIEN &sv)
{
	gotoxy(x,xdong);
	cout<<sv.ho+" "+sv.ten;// xuat ho ten cua mot sinh vien 
	string temp = sv.masv;
	int dem1=0;
	gotoxy(x+30,xdong);
	// xuat danh sach diem thi cua sinh vien do
	for(NODEDT *pdt=sv.ldt->pHeadDt;pdt!=NULL;pdt=pdt->NEXT)
	{
		if(Kiem_Tra_Mon(lchdt_sv,temp,pdt->datadt.Mamh)==true)
		{
			dem1++;
			cout<<setw(5)<<right<<" "<<setw(15)<<left<<pdt->datadt.diemthi<<char(179);
		}
		else
		{
			dem1++;
			cout<<setw(5)<<right<<" "<<setw(15)<<left<<"chua thi"<<char(179);
		}
	}
}
// xem diem cua danh sach sinh vien cua 1 lop
void Xem_List_Diem_SV(listMH &lmh,LISTCHDT_SV &lchdt_sv,LISTSINHVIEN &lsv)
{
	int dem=0;
	gotoxy(x+30,7);
	// xuat danh sach ma mon hoc phai thi cua mot sinh vien ( trong danh sach diem thi )
//	for(int i = 0;i<lmh.soluong;i++)
//	{
//		dem++;
//		cout<<setw(5)<<right<<" "<<setw(15)<<left<<lmh.dsmh[i]->MAMH<<char(179);
//	}
	for(NODEDT *k = lsv.pHEAD->datasv.ldt->pHeadDt;k!=NULL;k=k->NEXT)
	{
		dem++;
		cout<<setw(5)<<right<<" "<<setw(15)<<left<<k->datadt.Mamh<<char(179);
	}
	VeKhungCH(x+30,4,dem*21-1,2,true);
	VeKhungCH(x+30,6,dem*21-1,2,true);
	xdong = 9;
	int l=1;
	// xuat danh sach diem thi cua tung sinh vien
	for(NODESV *psv=lsv.pHEAD;psv!=NULL;psv=psv->pNEXT)
	{
		Xem_Diem_SV(lchdt_sv,psv->datasv);
		xdong=xdong+2;
		l=l+2;
	}
	VeKhungCH(58,8,32,l,true);
	VeKhungCH(x+30,8,dem*21-1,l,true);
}
void Xem_Diem_Cua_1_Lop(listMH &lmh,LISTCHDT_SV &lchdt_sv,LISTLOP &dsl)
{
	//nhap vao ma lop de truy xuat diem thi cua danh sach sinh vien cua lop do  
	gotoxy(x+40,3);
	cout<<"Danh Sach Lop Hoc";
	VeKhungCH(x,2,100,2,true);
	gotoxy(x,5);
	cout<<setw(5)<<right<<" "<<setw(45)<<left<<"Ma lop"<<char(179)<<setw(5)<<" "<<setw(45)<<left<<"Ten Lop";
	VeKhungCH(x,2,100,4,true); 
	int k = 6;
	xdong = 6;
	for(int i=0;i<dsl.soluonglop;i++)
	{
		xdong=xdong+2;
		gotoxy(x,xdong);
		Xuat_1_LOP(*dsl.dslop[i]);
		k=k+2;
	}
	VeKhungCH(x,2,100,k,true);
	xdong=xdong+2;
	gotoxy(x,++xdong);
	cout<<"Ban muon tiep tuc thuc thien thao tac nay ?(Enter : DONG Y, Esc : Thoat) ";
	char key = getch();
	if(key==13)
	{
		string strmalop;
		string strtenlop;
		strmalop.clear();
		strtenlop.clear();
		gotoxy(x,++xdong);
		cout<<"Nhap vao ten lop muon xem diem thi : ";
		XuLiNhap(strtenlop);
		int flag=0;
		for(int i =0 ;i<dsl.soluonglop;i++)
		{
			if(stricmp(strtenlop.c_str(),dsl.dslop[i]->tenLOP.c_str())==0)
			{
				strmalop=dsl.dslop[i]->maLOP;
				flag=1;
				break;
			}
		}
		if(flag==0)// neu ko tim thay dc lop thi thong bao cho ng dung
		{
			gotoxy(x,++xdong);
			cout<<"Khong tim thay lop ";
			return;
		}
		else
		{
			for(int i = 0 ;i<dsl.soluonglop;i++)
			{
				if(stricmp(strmalop.c_str(),dsl.dslop[i]->maLOP.c_str())==0)// tim thay lop can xem diem thi
				{
					system("cls");
					VemenuTONG();
					gotoxy(x+60,5);
					cout<<"Danh Sach Diem Thi Cua Lop "<<dsl.dslop[i]->tenLOP;
					// xuat danh sach diem thi cua lop do ra
					Xem_List_Diem_SV(lmh,lchdt_sv,*dsl.dslop[i]->lsv);
					break;	
				}
			}
		}
	}
	else if(key==27)
	{
		return;
	}
}
