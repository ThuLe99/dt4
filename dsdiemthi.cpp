#include "dsdiemthi.h"
const int x=60;
const int y =22;
NODEDT *KTN_DiemThi(DIEMTHI &dt)
{
 	NODEDT *pdt=new NODEDT;
 	pdt->datadt=dt;
 	pdt->NEXT=NULL;
 	return pdt;
}
void KTList_DiemThi(LISTDT &ldt)
{
 	ldt.pHeadDt=NULL;
 	ldt.pTailDt=NULL;
}
void Them_Dt_VaoCuoi(LISTDT &ldt,NODEDT *pdt)
{
  	if(ldt.pHeadDt==NULL)
  	{
  		ldt.pHeadDt=ldt.pTailDt=pdt;
	}
	else
	{
		ldt.pTailDt->NEXT=pdt;
		ldt.pTailDt=pdt;
	}
}
void Xoa_Dt(LISTDT &ldt, char macx[15])
{
	if(stricmp(ldt.pHeadDt->datadt.Mamh,macx)==0)
	{
		NODEDT *p = ldt.pHeadDt;
		ldt.pHeadDt = ldt.pHeadDt->NEXT;
		delete p;
		return;
	}
	if(stricmp(ldt.pTailDt->datadt.Mamh,macx)==0)
	{
		for(NODEDT *k =ldt.pHeadDt;k!=NULL;k=k->NEXT)
		{
			if(k->NEXT==ldt.pTailDt)
			{
				delete ldt.pTailDt;
				k->NEXT=NULL;
				ldt.pTailDt= k;
				return;
			}
		}
	}
	NODEDT *g = new NODEDT;
	for(NODEDT *k = ldt.pHeadDt;k!=NULL;k=k->NEXT)
	{
		if(stricmp(k->datadt.Mamh,macx)==0)
		{
			g->NEXT=k->NEXT;
			delete k;
			return ;
		}
		g=k;
	}
}
void Hieu_Chinh_Dt(LISTDT &ldt,char mact[15],char mamoi[15])
{
	for(NODEDT *k = ldt.pHeadDt;k!=NULL;k=k->NEXT)
	{
		if(stricmp(k->datadt.Mamh,mact)==0)
		{
			strcpy(k->datadt.Mamh,mamoi);
			k->datadt.diemthi=0.0;
		}
	}
}
int DemSoDiemThi(LISTDT &ldt)
{
	int dem=0;
	for(NODEDT *k=ldt.pHeadDt;k!=NULL;k=k->NEXT)
  	{
  		dem++;
	}
	return dem;
}
void Save_ListDiemThi(ofstream &fo,LISTDT &ldt)
{
	fo<<DemSoDiemThi(ldt)<<endl;
	for(NODEDT *k = ldt.pHeadDt;k!=NULL;k=k->NEXT)
	{
		fo<<k->datadt.Mamh<<"|"<<k->datadt.diemthi<<endl;
	}
}
void Read_DiemThi(ifstream &fi, DIEMTHI &dt)
{
 	fi.getline(dt.Mamh,15,'|');
 	fi>>dt.diemthi;
}
void Read_List_DiemThi(ifstream &fi,LISTDT &ldt)
{
	KTList_DiemThi(ldt);
	int sohang;
	fi>>sohang;
	string str;
	getline(fi,str);
	for(int i =0;i<sohang;i++)
	{
		DIEMTHI dt;
 		Read_DiemThi(fi,dt);
 		NODEDT *pdt = KTN_DiemThi(dt);
 		Them_Dt_VaoCuoi(ldt,pdt);
 		getline(fi,str);
	}
}
void Xuat_Diem_Thi(DIEMTHI &dt)
{
	cout<<"\n"<<setw(x)<<right<<char(179)<<setw(5)<<" "<<setw(45)<<left<<dt.Mamh<<char(179)<<setw(5)<<" "<<setw(43)<<left<<dt.diemthi<<char(179);
}
void Giai_Phong_DT(LISTDT &ldt)
{
	NODEDT *k= NULL;
	while(ldt.pHeadDt!=NULL)
	{
		k=ldt.pHeadDt;
		ldt.pHeadDt=ldt.pHeadDt->NEXT;
		delete k;
	}
}
void Xuat_List_Diem_Thi(LISTDT &ldt)
{
	gotoxy(100,23);
	cout<<"Danh Sach Diem Thi";
	VeKhungCH(x,y,100,2,true);
	gotoxy(1,25);
	cout<<setw(x)<<right<<char(179)<<setw(5)<<left<<" "<<setw(45)<<"Ma Mon Hoc"<<char(179)<<setw(5)<<" "<<setw(45)<<"Diem Mon Hoc";
	VeKhungCH(x,y,100,4,true);
	cout<<"\n";
	int t = 5;
	for(NODEDT *k=ldt.pHeadDt;k!=NULL;k=k->NEXT)
	{
		Xuat_Diem_Thi(k->datadt);
		t++;
	}
	VeKhungCH(x,y,100,t,true);
}
void Swap_DT(DIEMTHI &a, DIEMTHI &b)
{
	DIEMTHI temp=a;
	a=b;
	b=temp;
}
void Sap_Xep_DT(LISTDT &ldt)
{
	for(NODEDT *k=ldt.pHeadDt;k!=ldt.pTailDt;k=k->NEXT)
	{
		for(NODEDT *h=k->NEXT;h!=NULL;h=h->NEXT)
		{
			if(strcmp(k->datadt.Mamh,h->datadt.Mamh)==1);
			{
				Swap_DT(k->datadt,h->datadt);
			}
		}
	}
}
