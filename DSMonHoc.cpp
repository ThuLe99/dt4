
#include "DSMonHoc.h"
const int x=60;
const int y=21;
int xuongdong2;
bool TimKiemMONHOC(listMH &lmh,string &str)
{
	for(int i=0;i<lmh.soluong;i++)
	{
		if(strcmp(lmh.dsmh[i]->MAMH,(char*)str.c_str())==0)// strcmp so sanh 2 char *
		{
			return true;// neu 2 ma giong nhau tra ve true
		}
	}
	return false;
}
void Nhap_MonHoc(listMH &lmh,MONHOC &mh)
{
	fflush(stdin);
	string str;// cai bien ma tam de chua ma nhap zo
	int flag;
	do
	{	
		str.clear();
		flag=0;
		gotoxy(x,++xuongdong2);// in ra vi tri tren man hinh console
		cout<<" Nhap ma mon hoc : ";
		XuLiNhapMa(str);
		if(TimKiemMONHOC(lmh,str)==true)//kiem tra ma bi trung thi nhap lai
		{
			gotoxy(x,++xuongdong2);
			cout<<" Nhap lai. Ma so bi trung : ";
			flag = 1;
		}
	}while(flag==1);// bien flag bang 1 de tiep tuc vong while cho den khi nao ko co ma bi trung
	strcpy(mh.MAMH,(char*)str.c_str());// ham copy mot chuoi qua mot chuoi moi, lay noi dung cua str gan qua ma mon hoc
	fflush(stdin);
	gotoxy(x,++xuongdong2);
	cout<<" Nhap ten mon hoc : ";
	mh.tenMH.clear();
	XuLiNhap(mh.tenMH);
	Chuan_Hoa_Chuoi(mh.tenMH);// ham dinh dang
}
void Xuat_MonHoc(MONHOC &mh)
{
	cout<<setw(10)<<" "<<setw(40)<<left<<mh.MAMH<<char(179)<<setw(5)<<" "<<setw(45)<<left<<mh.tenMH;
}
bool EmptyMOHOC(listMH &lmh)
{
	if(lmh.soluong==0)
	{
		return true;
	}
	return false;
}
void Nhap_ListMH(listMH &lmh,LISTLOP &dsl)
{
	for(int i =0;i<lmh.soluong;i++)
	{
		gotoxy(x,++xuongdong2);
		cout<<" Nhap vao mon hoc thu  "<<i+1;
		Nhap_MonHoc(lmh,*lmh.dsmh[i]);
	}
	// sau khi cap nhat mot list mon hoc moi thi moi sinh vien se co list mon hoc do de thi
	// thuc hien rang ma mon hoc cho vao danh sach diem thi cua moi sinh vien
	// ma mon hoc trong danh sach diem thi phai tuong ung va thay doi theo dua vao ma mon hoc trong danh sach mon hoc
	int dem = 0;
	for(int i = 0;i<dsl.soluonglop;i++)
	{
		for(NODESV *k=dsl.dslop[i]->lsv->pHEAD;k!=NULL;k=k->pNEXT)
		{
			KTList_DiemThi(*k->datasv.ldt);
			while(dem<lmh.soluong)
			{
				DIEMTHI dt;
				strcpy(dt.Mamh,lmh.dsmh[dem]->MAMH);
				NODEDT *pdt=KTN_DiemThi(dt);
				Them_Dt_VaoCuoi(*k->datasv.ldt,pdt);
				dem++;
			}
			dem=0;
		}
	}
}
void SwapMonHoc(MONHOC &a, MONHOC &b)
{
	MONHOC temp=a;
	a=b;
	b=temp;
}
void SapXep(listMH &lmh)
{
	for(int i=0;i<lmh.soluong-1;i++)
	{
		for(int j=i+1;j<lmh.soluong;j++)
		{
			if(strcmp(lmh.dsmh[i]->MAMH,lmh.dsmh[j]->MAMH)==1)
			{
				SwapMonHoc(*lmh.dsmh[i],*lmh.dsmh[j]);			
			}
		}
	}
}
void Xuat_ListMH(listMH &lmh)
{
	gotoxy(x+40,3);
	cout<<"Danh Sach Mon Hoc";
	VeKhungCH(x,2,100,2,true);
	gotoxy(x,5);
	cout<<setw(5)<<right<<" "<<setw(45)<<left<<"Ma mon hoc"<<char(179)<<setw(5)<<" "<<setw(45)<<left<<"Ten mon hoc";
	VeKhungCH(x,2,100,4,true); 
	int k = 6;
	xuongdong2 = 6;
	for(int i =0;i<lmh.soluong;i++)
	{
		xuongdong2=xuongdong2+2;
		gotoxy(x,xuongdong2);
		Xuat_MonHoc(*lmh.dsmh[i]);
		k=k+2;
	}
	VeKhungCH(x,2,100,k,true);
	xuongdong2=xuongdong2+2;
}
void Save_MH(ofstream &fo,MONHOC &mh)
{
	fo<<mh.MAMH<<",";
	fo<<mh.tenMH<<endl;
}
void Save_List(listMH &lmh)
{
	ofstream fo;
	fo.open("dsmonhoc.txt",ios::out);
	fo<<lmh.soluong<<endl;
	for(int i=0;i<lmh.soluong;i++)
	{
		Save_MH(fo,*lmh.dsmh[i]);
	}
	fo.close();
}
void Read_MH(ifstream &fi,listMH &lmh ,MONHOC &mh)
{
	string temp;// temp chua ma mon hoc
	getline(fi,temp,',');
	if(TimKiemMONHOC(lmh,temp)==true)// doc ma co ma bi trung bao loi
	{
		gotoxy(60,20);
		cout<<"\n"<<setw(x)<<right<<" "<<" XIN KIEM TRA LAI FILE.DANH SACH CO MA SO MON HOC BI TRUNG";
		delete[] lmh.dsmh;
	}
	Xoa_KT_Thua_O_giua(temp);
	Xoa_KT_Thua_O_Dau_Cuoi(temp);
	strcpy(mh.MAMH,(char*)temp.c_str());//gan temp qua ma mon mon hoc
	getline(fi,mh.tenMH);
	Chuan_Hoa_Chuoi(mh.tenMH);
}
void Read_listMH(listMH &lmh)
{
		string str;
		ifstream fi;
		fi.open("dsmonhoc.txt", ios::in);
		fi>>lmh.soluong;
		getline(fi,str);
		int n=0;
		while(n<lmh.soluong)
		{
			lmh.dsmh[n]=new MONHOC;
			n++;
		}
		for(int i=0;i<lmh.soluong;i++)
		{
			Read_MH(fi,lmh,*lmh.dsmh[i]);
		}
		fi.close();
		
}

void ThemMONHOC(listMH &lmh,MONHOC &mh,LISTLOP &dsl)
{	
 	int i;
	int vtd = 0;
	lmh.dsmh[lmh.soluong] = new MONHOC;// cap phat 1 o nho o sau phan tu cuoi cung
	for(i = lmh.soluong-1;i>=vtd;i--)
	{
		lmh.dsmh[i+1]=lmh.dsmh[i]; //dich cac phan tu qua phai mot don vi tinh tu vi tri can them  
	}
	lmh.dsmh[vtd] = new MONHOC;//cap phat vung nho cho o nho can them
	*lmh.dsmh[vtd] = mh; // o nho can them co du lieu moi nhap la mh 
	lmh.soluong++;// tang so luong o nho 
	// khi them mot mon hoc vao danh sach mon hoc thi so luong mon hoc va diem thi cua 1 sinh vien trong dsdt se cap nhat theo
	// them mot ma mh moi vao cho tung sinh vien
//	for(int i = 0;i<dsl.soluonglop;i++)
//	{
//		for(NODESV *k=dsl.dslop[i]->lsv->pHEAD;k!=NULL;k=k->pNEXT)
//		{
//			DIEMTHI dt;
//			strcpy(dt.Mamh,mh.MAMH);
//			NODEDT *pdt = KTN_DiemThi(dt);
//			Them_Dt_VaoCuoi(*k->datasv.ldt,pdt);
//		}
//	}
}
void XoaMONHOC(listMH &lmh, char mact[15],LISTLOP &dsl)
{
	int vtcx=-1;
	// kiem ra vi tri can xoa
	for(int i=0;i<lmh.soluong;i++)
	{
		if(stricmp(lmh.dsmh[i]->MAMH,mact)==0)
		{
			vtcx=i; // kiem dc vi tri can xoa
			break;
		}
	}
	if(vtcx!=-1)// neu co vi tri can xoa thi bien vtcx se khac -1
	{
		for(int i=vtcx+1;i<lmh.soluong;i++)
		{
			lmh.dsmh[i-1]=lmh.dsmh[i];//cac phan tu phia sau vtcx dich sang trai 1 don vi
		}
		lmh.soluong--;
		// xoa mon hoc cung tuong tu nhu them mon hoc
		// khi xoa ben danh sach mon hoc thi mon do se ko con nua
		// moi sinh vien se co danh sach diem thi ko co ma mon hoc do nua
		for(int i = 0;i<dsl.soluonglop;i++)
		{
			for(NODESV *k=dsl.dslop[i]->lsv->pHEAD;k!=NULL;k=k->pNEXT)
			{
				Xoa_Dt(*k->datasv.ldt,mact);
			}
		}
	}
	else// neu vtcx = -1 thi ko co ma can xoa
	{
		gotoxy(x,++xuongdong2);
		cout<<" Khong co ma can xoa ";	
	}
}

// khi them sinh vien moi vao trong danh sach lop , chuc nang nay se tu dong bo sung 
// danh sach diem thi gom ma mon hoc va diem thi cho sinh vien do nhu cac ban sinh vien khac
void Fill_MH_Cho_Sv_Moi(listMH &lmh,LISTLOP &dsl)
{
	int dem = 0;
	if(dsl.soluonglop>0)
	{
		for(int i = 0;i<dsl.soluonglop;i++)
		{
			for(NODESV *k=dsl.dslop[i]->lsv->pHEAD;k!=NULL;k=k->pNEXT)
			{
				if(k->datasv.ldt->pHeadDt==NULL)
				{
					while(dem<lmh.soluong)
					{
						DIEMTHI dt;
						strcpy(dt.Mamh,lmh.dsmh[dem]->MAMH);
						NODEDT *pdt=KTN_DiemThi(dt);
						Them_Dt_VaoCuoi(*k->datasv.ldt,pdt);
						
						dem++;
					}
					dem=0;
				}
				
			}
		}
		
	}
}
void Hieu_Chinh_MONHOC(listMH &lmh,char mact[15],LISTLOP &dsl)
{
	MONHOC *mhthaythe=new MONHOC; // cap phat vung nho cho mon hoc moi 
	int vt=-1;
	// kiem vi tri can thay the
	for(int i=0;i<lmh.soluong;i++)
	{
		if(stricmp(lmh.dsmh[i]->MAMH,mact)==0)// so sanh ma can tim voi ma trong danh sach mon hoc
		{
			vt=i;// kiem dc vi can thay the
			break;
		}
	}
	if(vt!=-1)//kiem dc vi tri can thay the
	{
		for(int i = 0;i<lmh.soluong;i++)
		{
			if(i==vt)
			{
				gotoxy(x,++xuongdong2);
				cout<<" Nhap vao Mon hoc moi ";
				Nhap_MonHoc(lmh,*mhthaythe);// Nhap mon hoc moi
				lmh.dsmh[i]=mhthaythe;//gan mon hoc moi vao o can thay the
			}
		}
		// hieu chinh mon hoc ben danh sach mon hoc thi ma mon hoc ben danh sach diem thi cua sinh vien cung phai cap nhat theo
		for(int i = 0;i<dsl.soluonglop;i++)
		{
			for(NODESV *k=dsl.dslop[i]->lsv->pHEAD;k!=NULL;k=k->pNEXT)
			{
				// ham hieu chinh diem thi trong danh sach diem thi
				Hieu_Chinh_Dt(*k->datasv.ldt,mact,mhthaythe->MAMH);
			}
		}
	}
	else// neu vt = -1 thi ko co vi tri can thay the
	{
		gotoxy(x,++xuongdong2);
		cout<<" Khong co ma can thay the";
		//delete[] mhthaythe;
	}
}
void menuMONHOC(listMH &lmh,LISTLOP &dsl)
{
	string str;
	MONHOC mh;
	int pointer = 0 ;
	while(1)
	{
		// so luong chuc nang trong menu
		char* menu[]={"0. Nhap Moi Danh Sach Mon Hoc",
					  "1. Xuat Danh Sach Mon Hoc",
					  "2. Them Mon Hoc",
					  "3. Hieu Chinh Mon Hoc",
					  "4. Xoa Mon Hoc",
					  "5. Exit"
					  };
		system("cls");
		textcolor(10);
		VemenuTONG();
		gotoxy(20,26);
		cout<<"Quan Li Mon Hoc";
		VeKhungCH(1,25,50,3,true);
		gotoxy(1,28);
		for(int i=0;i<MAX2;i++)
		{
			if(pointer==i)
			{
				textcolor(20);
				cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<menu[i];
			}
			else
			{
				textcolor(10);
				cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<menu[i];
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
					if(pointer>0){
						--pointer;
					}
					else{
						pointer=MAX2-1;
					}
					break;
				}
				if(key==80)//xuong
				{
					if(pointer<MAX2-1)
					{
						++pointer;
					}
					else
					{
						pointer = 0;
					}
					break;
				}
				if(key==13)//enter
				{
					char key2;
					if(pointer==0)
					{
						xuongdong2=2;
						gotoxy(x,++xuongdong2);
						cout<<" Ban muon tiep tuc thuc hien thao tac nay chu ?Thao tac nay se xoa toan bo du lieu truoc do. (Yes : Enter, No: Esc)";
						key2=getch();
						if(key2==13) //enter
						{
							string soluongmonhoc;
							do
							{
								soluongmonhoc.clear();
								gotoxy(x,++xuongdong2);
								cout<<" Nhap vao so luong mon hoc : ";
								NhapSoKoChu(soluongmonhoc);
								lmh.soluong= atoi(soluongmonhoc.c_str());
								if(lmh.soluong<=0||lmh.soluong>MAX)
								{
									gotoxy(x,++xuongdong2);			
									cout<<" so luong nam trong khoang 1 - 300";
								}
							}while(lmh.soluong<=0||lmh.soluong>MAX);					
							int n=0;
							while(n<lmh.soluong)
							{
								lmh.dsmh[n] = new MONHOC ;
								n++;
							}
							//lmh.dsmh = new MONHOC[lmh.soluong];
							Nhap_ListMH(lmh,dsl);
							SapXep(lmh);
							Save_List(lmh);
							gotoxy(x,++xuongdong2);
							system("pause");
						}
						else if(key2==27)//esc
						{
							break;
						}
					}
					else if(pointer==1)
					{
						if(EmptyMOHOC(lmh)==true)
						{
							gotoxy(x,20);
							cout<<"Danh sach chua co phan tu ";
							system("pause");
							break;
						}
						Xuat_ListMH(lmh);
						gotoxy(x,++xuongdong2);
						system("pause");
					}
					else if(pointer==2)
					{
							if(EmptyMOHOC(lmh)==true)
							{
								gotoxy(x,20);
								cout<<" Danh sach dang rong ";
								system("pause");
								break;
							}
							Xuat_ListMH(lmh);
							gotoxy(x,++xuongdong2);
							cout<<" Nhap vao mon hoc can them ";
							Nhap_MonHoc(lmh,mh);
							gotoxy(x,++xuongdong2);
							cout<<" Ban muon tiep tuc thuc hien thao tac nay chu ?(Yes : Enter, No: Esc)";
							key2=getch();
							if(key2==13)
							{
								ThemMONHOC(lmh,mh,dsl);
								SapXep(lmh);
								Save_List(lmh);
								gotoxy(x,++xuongdong2);
								system("pause");
							}
							else if(key2==27)
							{
								break;
							}
					}
					else if(pointer==3)
					{
						if(EmptyMOHOC(lmh)==true)
						{
							gotoxy(x,20);
							cout<<" Danh sach dang rong ";
							system("pause");
							break;
						}
						Xuat_ListMH(lmh);
						char mact[15];
						fflush(stdin);
						gotoxy(x,++xuongdong2);
						str.clear();
						cout<<" Nhap ma mon hoc can thay the : ";
						XuLiNhapMa(str);
						gotoxy(x,++xuongdong2);
						cout<<"Ban muon tiep tuc thuc hien thao tac nay chu ?(Yes : Enter, No: Esc)";
						key2=getch();
						if(key2==13)
						{
							strcpy(mact,(char*)str.c_str());
							Hieu_Chinh_MONHOC(lmh,mact,dsl);
							SapXep(lmh);
							Save_List(lmh);
							gotoxy(x,++xuongdong2);
							system("pause");
						}
						else if(key2==27)
						{
							break;
						}
					}
					else if(pointer==4)
					{
						if(EmptyMOHOC(lmh)==true)
						{
							gotoxy(x,20);
							cout<<" Danh sach dang rong ";
							system("pause");
								break;
						}
						Xuat_ListMH(lmh);
						fflush(stdin);
						char mact[15];
						string str3;
						gotoxy(x,++xuongdong2);
						cout<<" Nhap ma mon hoc can xoa : ";
						str3.clear();
						XuLiNhapMa(str3);
						gotoxy(x,++xuongdong2);
						cout<<"Ban muon tiep tuc thuc hien thao tac nay chu ?(Yes : Enter, No: Esc)";
						key2=getch();
						if(key2==13)
						{
							strcpy(mact,(char*)str3.c_str());
							XoaMONHOC(lmh,mact,dsl);
							SapXep(lmh);
							Save_List(lmh);
							gotoxy(x,++xuongdong2);
							system("pause");
						}
						else if(key2==27)
						{
							break;
						}
					}
					else if(pointer==5)
					{
						return;	
					}
					
					break;
				}
			}
		}
		SapXep(lmh);
		Save_List(lmh);
	}
}
