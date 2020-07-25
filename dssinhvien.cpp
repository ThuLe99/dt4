#include "dssinhvien.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int x = 60;
const int y = 22;
int xuongdong3;
NODESV *KhoiTaoSV(SINHVIEN sv)
{
	NODESV *p = new NODESV;
	p->datasv=sv;
	p->pNEXT=NULL;
	return p;
}
void KhoiTaoListSV(LISTSINHVIEN &lsv)
{
	lsv.pHEAD=NULL;
	lsv.pTAIL=NULL;
}
bool TimkiemSv(LISTSINHVIEN &lsv,string &temp)
{
	for(NODESV *k=lsv.pHEAD;k!=NULL;k=k->pNEXT)
	{
		if(stricmp((char*)k->datasv.masv.c_str(),(char *)temp.c_str())==0)
		{
			return true;
		}
	}
	return false;
}
int So_Luong_Sinh_Vien(LISTSINHVIEN &lsv)
{
	int dem=0;
	for(NODESV *k=lsv.pHEAD;k!=NULL;k=k->pNEXT)
	{
		dem++;
	}
	return dem;
}
void ThemSVVaoCuoi(LISTSINHVIEN &lsv, NODESV *p)
{
	// danh sách ?ang r?ng
	if (lsv.pHEAD == NULL)
	{
		lsv.pHEAD=lsv.pTAIL=p;
	}
	else
	{
		lsv.pTAIL->pNEXT=p;
		lsv.pTAIL = p; // c?p nh?t l?i l.pTail là p
	}
}
bool EmptySinhVien(LISTSINHVIEN &lsv)
{
	if(lsv.pHEAD==NULL)
	{
		return true;
	}
	return false;
}
void GiaiPhongSinhVien(LISTSINHVIEN &lsv)
{
	NODESV *k=NULL;
	while(lsv.pHEAD!=NULL)
	{
		k=lsv.pHEAD;
		lsv.pHEAD=lsv.pHEAD->pNEXT;
		delete k;
	}
}
void ThemSVVaoDau(LISTSINHVIEN &lsv,NODESV *p)
{
	if (lsv.pHEAD == NULL)
	{
		lsv.pHEAD=lsv.pTAIL=p;
	}
	else
	{
		p->pNEXT=lsv.pHEAD;
		lsv.pHEAD= p; // c?p nh?t l?i l.pTail là p
	}
}
void Nhap_SV(LISTSINHVIEN &lsv,SINHVIEN &sv)
{
	fflush(stdin);
	int flag;
	do
	{	
		sv.masv.clear();
		flag=0;
		gotoxy(x,++xuongdong3);
		cout<<"Nhap ma sv : ";
		XuLiNhap(sv.masv);
		if(TimkiemSv(lsv,sv.masv)==true)
		{
			gotoxy(x,++xuongdong3);
			cout<<"(Nhap lai .Ma Ban nhap bi trung xin nhap lai!!!):";
			flag=1;
		}
	}while(flag==1);
	Chuan_Hoa_Chuoi(sv.masv);
	gotoxy(x,++xuongdong3);
	cout<<"Nhap vao ho sv : ";
	sv.ho.clear();
	XuLiNhap(sv.ho);
	Chuan_Hoa_Chuoi(sv.ho);	
	gotoxy(x,++xuongdong3);
	cout<<"Nhap vao ten sv : ";
	sv.ten.clear();
	XuLiNhap(sv.ten);
	Chuan_Hoa_Chuoi(sv.ten);
	gotoxy(x,++xuongdong3);
	cout<<"Nhap vao gioi tinh : (Nhan 0 : Nam, Nhan 1 : Nu)";
	while(true)
	{
		if(kbhit())
		{
			char key = getch();
			if(key==48)// 0
			{
				sv.phai = "NAM";
				break;
			}
			if(key==49)//1
			{
				sv.phai = "NU";
				break;
			}
		}
	}
	gotoxy(x,++xuongdong3);
	cout<<"Nhap vao password sinh vien : " ;
	sv.password.clear();
	XuLyNhap_Pass(sv.password);
	Xoa_KT_Thua_O_giua(sv.password);
	Xoa_KT_Thua_O_Dau_Cuoi(sv.password);
	sv.ldt = new LISTDT;// cap phat vung nho cho con tro danh sach diem thi cua 1 tg sinh vien
	KTList_DiemThi(*sv.ldt);// khoi tao danh sach diem thi cua 1 tg sinh vien 
}
void Xuat_SV(SINHVIEN &sv)
{
	cout<<setw(5)<<right<<" "<<setw(25)<<left<<sv.masv<<char(179);
	cout<<setw(5)<<right<<" "<<setw(55)<<left<<sv.ho+" "+sv.ten<<char(179);
	cout<<setw(5)<<right<<" "<<setw(10)<<left<<sv.phai<<char(179);
	cout<<setw(5)<<right<<" "<<setw(30)<<left<<sv.password;
}
void Xuat_DS_SV(LISTSINHVIEN &lsv)
{
	gotoxy(x+40,3);
	cout<<"Danh Sach Sinh Vien";
	VeKhungCH(x,2,140,2,true);
	gotoxy(x,5);
	cout<<setw(5)<<right<<" "<<setw(25)<<left<<"Ma Sinh Vien"<<char(179);
	cout<<setw(5)<<right<<" "<<setw(55)<<left<<"Ho Ten"<<char(179);
	cout<<setw(5)<<right<<" "<<setw(10)<<left<<"Phai"<<char(179);
	cout<<setw(5)<<right<<" "<<setw(30)<<left<<"Password";
	VeKhungCH(x,2,140,4,true); 
	int k = 6;
	xuongdong3 = 6;
	for(NODESV *sv=lsv.pHEAD;sv!=NULL;sv=sv->pNEXT)
	{
		xuongdong3=xuongdong3+2;
		gotoxy(x,xuongdong3);
		Xuat_SV(sv->datasv);
		k=k+2;
	}
	VeKhungCH(x,2,140,k,true);
	xuongdong3=xuongdong3+2;
}
void Swap_Sv(SINHVIEN &a,SINHVIEN &b)
{
	SINHVIEN temp = a;
	a=b;
	b=temp;
}
void Sap_Xep_SinhVien(LISTSINHVIEN &lsv)
{
	for(NODESV *k=lsv.pHEAD;k!=NULL;k=k->pNEXT)
	{
		for(NODESV *h=k->pNEXT;h!=NULL;h=h->pNEXT)
		{
			if(stricmp((char*)k->datasv.masv.c_str(),(char*)h->datasv.masv.c_str())==1)
			{
				Swap_Sv(k->datasv,h->datasv);
			}
		}
	}
}
void Xoa_SinhVien_Dau(LISTSINHVIEN &lsv)
{
	if(EmptySinhVien(lsv)==true)
	{
		return;
	}
	NODESV *p = lsv.pHEAD;// node p la node se xoa 
	lsv.pHEAD = lsv.pHEAD->pNEXT;
	delete p;
}
void Xoa_SinhVien_Cuoi(LISTSINHVIEN &lsv)
{
	if(EmptySinhVien(lsv)==true)
	{
		return;
	}
	if(lsv.pHEAD->pNEXT==NULL)
	{
		Xoa_SinhVien_Dau(lsv);
		return;
	}
	for(NODESV *k =lsv.pHEAD;k!=NULL;k=k->pNEXT)
	{
		if(k->pNEXT==lsv.pTAIL)
		{
			delete lsv.pTAIL;
			k->pNEXT=NULL;
			lsv.pTAIL = k;
			return;
		}
	}
}
void Xoa_SinhVien_BatKi(LISTSINHVIEN &lsv,string &macx)
{
	if(stricmp((char*)lsv.pHEAD->datasv.masv.c_str(),(char *)macx.c_str())==0)
	{
		Xoa_SinhVien_Dau(lsv);
		return;
	}
	if(stricmp((char*)lsv.pTAIL->datasv.masv.c_str(),(char *)macx.c_str())==0)
	{
		Xoa_SinhVien_Cuoi(lsv);
		return;
	}
	NODESV *g = new NODESV; // node g la node tro den node nam truoc node can xoa : x
	for(NODESV *k=lsv.pHEAD;k!=NULL;k=k->pNEXT)
	{
		// phat hien phan tu can xoa
		if(stricmp((char*)k->datasv.masv.c_str(),(char *)macx.c_str())==0)
		{
			g->pNEXT=k->pNEXT;// cap nhat moi lien ket giua node k (node q)voi node sau node g
			delete k;// xoa node nam sau nodeq
			return ;
		}
		g=k;// cho node g tro den node k
	}
//	Xoa_SV_Da_THi(lchdt_sv)
}
void Hieu_Chinh_SinhVien(LISTSINHVIEN &lsv,string &matemp)
{
	int flag = 0;
		for(NODESV *k=lsv.pHEAD;k!=NULL;k=k->pNEXT)
		{
			if(stricmp((char*)k->datasv.masv.c_str(),(char*)matemp.c_str())==0)
			{
				gotoxy(x,++xuongdong3);
				cout<<" Nhap vao sinh vien moi :";
				SINHVIEN sv;
				Nhap_SV(lsv,sv);
				k->datasv.masv=sv.masv;
				k->datasv.ho=sv.ho;
				k->datasv.ten=sv.ten;
				k->datasv.phai=sv.phai;
				k->datasv.password=sv.password;
				flag = 1;
			}
		}
	if(flag==0)// ko tim dc ma sinh vien the, thong bao cho ng dung
	{
		gotoxy(x,++xuongdong3);
		cout<<"Khong co ma sinh vien can thay the";
	}
}
void Save_SV(ofstream &fo,SINHVIEN &sv)
{
//	Chuan_Hoa_Chuoi(sv.masv);
//	Chuan_Hoa_Chuoi(sv.ho);
//	Chuan_Hoa_Chuoi(sv.ten);
//	Chuan_Hoa_Chuoi(sv.phai);
//	Chuan_Hoa_Chuoi(sv.password);
	fo<<sv.masv<<"|"<<sv.ho+" "+sv.ten<<"|"<<sv.phai<<"|"<<sv.password<<endl;
	Save_ListDiemThi(fo,*sv.ldt);
}
void Save_List_Sv(ofstream &fo,LISTSINHVIEN &lsv)
{
	fo<<So_Luong_Sinh_Vien(lsv)<<endl;
	for(NODESV *psv=lsv.pHEAD;psv!=NULL;psv=psv->pNEXT)
	{
		Save_SV(fo,psv->datasv);
	}
}
void Read_Sv(ifstream &fi,LISTSINHVIEN &lsv,SINHVIEN &sv)
{
	getline(fi,sv.masv,'|');
	if(TimkiemSv(lsv,sv.masv)==true)
	{
		cout<<"\n"<<setw(x)<<right<<" "<<"Xin kiem tra lai file. Co ma sv bi trung !!!";
		GiaiPhongSinhVien(lsv);
	}
	getline(fi,sv.ho,' ');
	getline(fi,sv.ten,'|');
	getline(fi,sv.phai,'|');
	getline(fi,sv.password);
	sv.ldt = new LISTDT;// cap phat cung nho cho con tro danh sach diem thi
	Read_List_DiemThi(fi,*sv.ldt);// doc danh sach diem thi
}
void Read_List_Sv(ifstream &fi,LISTSINHVIEN &lsv)
{
	KhoiTaoListSV(lsv);
	int soluong;
	fi>>soluong;
	string str;
	getline(fi,str);
	for(int i=0;i<soluong;i++)
	{
		SINHVIEN sv;
		Read_Sv(fi,lsv,sv);
		NODESV *psv = KhoiTaoSV(sv);
		ThemSVVaoCuoi(lsv,psv);
	}
}
void menuSINHVIEN(LISTSINHVIEN &lsv)
{
	int pointer2 = 0;
	int Amount_Menu =6;
	while(true)
	{
		system("cls");
		textcolor(10);
		VemenuTONG();
		char* menusinhvien[]={	"0.Tao moi danh sach sinh vien ",
								"1.Them Sinh Vien Vao Danh Sach",
								"2.Xem Danh Sach Sinh Vien",
								"3.Xoa Sinh Vien",
								"4.Hieu Chinh Sinh Vien",
								"5.Exit"};
		gotoxy(10,26);
		cout<<"Quan Li Danh Sach Sinh Vien";
		VeKhungCH(1,25,50,3,true);
		//VeKhungCH(1,25,50,44,true);
		gotoxy(1,28);						
		for(int i=0;i<Amount_Menu;i++)
		{
			if(pointer2==i)
			{
				textcolor(20);
				cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<menusinhvien[i];
			}
			else
			{
				textcolor(10);
				cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<menusinhvien[i];
			}
		}
		textcolor(10);
		while(1)	// xu li key board
		{
			if(kbhit())// neu co phim nao nhap vao 
			{
				char key =getch();// luu phim do lai de xu li 
				if(key == 72)// len
				{
					if(pointer2>0){
						--pointer2;
					}
					else{
						pointer2=Amount_Menu-1;
					}
						break;
					}
				if(key==80)//xuong
				{
					if(pointer2<Amount_Menu-1)
					{
						++pointer2;
					}
					else
					{
						pointer2 = 0;
					}
						break;
					}
				if(key==13)//enter
				{
					char key2;
					if(pointer2==0)
					{
						xuongdong3 = 2;
						gotoxy(x,xuongdong3);
						cout<<" Ban muon tiep tuc thao tac nay chu?Thao tac nay se tao moi lai toan bo du lie trong file danhsachsv.txt";
						key2=getch();
						if(key2==13)
						{
							gotoxy(x+20,20);
							KhoiTaoListSV(lsv);
							cout<<"TAO MOI THANH CONG ";
							gotoxy(x,++xuongdong3);
							system("pause");
						}
						else if(key2==27)
						{
							break;
						}
					}
					else if(pointer2==1)
					{
						if(EmptySinhVien(lsv)==true)
						{
							xuongdong3 = 2;
							gotoxy(x,xuongdong3);
							cout<<" Danh sach sinh vien rong.";
							gotoxy(x,++xuongdong3);
							cout<<" Ban muon tiep tuc thao tac nay chu?Thao tac nay se tao moi lai toan bo du lie trong file danhsachsv.txt?";
							gotoxy(x,++xuongdong3);
							cout<<"(Nhan Enter : YES, ESc : NO)";
							key2=getch();
							if(key2==13)
							{
								DIEMTHI dt;
								SINHVIEN sv;
								Nhap_SV(lsv,sv);
								NODESV *p = KhoiTaoSV(sv);
								ThemSVVaoCuoi(lsv,p);
								Sap_Xep_SinhVien(lsv);
								gotoxy(x,++xuongdong3);
								system("pause");
								break;
							}
							else if(key2==27)
							{
								break;
							}
						}
						Xuat_DS_SV(lsv);
						DIEMTHI dt;
						SINHVIEN sv;
						Nhap_SV(lsv,sv);
						NODESV *p = KhoiTaoSV(sv);
						ThemSVVaoCuoi(lsv,p);
						Sap_Xep_SinhVien(lsv);
						gotoxy(x,++xuongdong3);
						system("pause");
						break;
					}
					else if(pointer2==2)
					{
						gotoxy(x+20,20);
						if(EmptySinhVien(lsv)==true)
						{
							cout<<"Danh sach sinh vien rong";
							system("pause");
							break;
						}
						Xuat_DS_SV(lsv);
						gotoxy(x,++xuongdong3);	
						system("pause");
						break;
					}
					else if(pointer2==3)
					{
						if(EmptySinhVien(lsv)==true)
						{
							gotoxy(x+20,20);
							cout<<"Danh sach sinh vien rong";
							system("pause");
							break;
						}
						Xuat_DS_SV(lsv);
						string macx;
						gotoxy(x,++xuongdong3);
						cout<<"Moi ban Nhap vao ma muon xoa : ";
						macx.clear();
						XuLiNhap(macx);
						Xoa_KT_Thua_O_giua(macx);
						gotoxy(x,++xuongdong3);
						cout<<"Ban muon tiep tuc thao tac nay chu?(Nhan ENTER : yes, ESC : no) ";
						key2=getch();
						if(key2==13)
						{
							Xoa_SinhVien_BatKi(lsv,macx);
							Sap_Xep_SinhVien(lsv);
							gotoxy(x,++xuongdong3);
							system("pause");
						}
						else if(key2==27)
						{
							break;
						}
					}
					else if(pointer2==4)
					{	
						if(EmptySinhVien(lsv)==true)
						{
							gotoxy(x+20,20);
							cout<<"Danh sach sinh vien rong";
							system("pause");
							break;
						}
						Xuat_DS_SV(lsv);
						string mact;
						gotoxy(x,++xuongdong3);
						cout<<"Moi ban Nhap vao ma muon thay the : ";
						mact.clear();
						XuLiNhap(mact);
						Xoa_KT_Thua_O_giua(mact);
						gotoxy(x,++xuongdong3);
						cout<<" Ban muon tiep tuc thao tac nay chu?(Nhan ENTER : yes, ESC : no) ";
						key2=getch();
						if(key2==13)
						{
							Hieu_Chinh_SinhVien(lsv,mact);
							Sap_Xep_SinhVien(lsv);
							gotoxy(x,++xuongdong3);
							system("pause");
						}
						else if(key2==27)
						{
							break;
						}
					}
					else if(pointer2==5)
					{
						return;
					}
					break;
				}
			}
		}
	}
}
