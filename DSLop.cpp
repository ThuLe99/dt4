#include "DSLop.h"
const int x = 60;
const int y = 21;
int xuongdong ;
bool TimKiemMaLop(LISTLOP &dsl,string &str)
{
	// tim kiem theo ma lop
	for(int i = 0 ;i<dsl.soluonglop;i++)
	{
		if(strcmp((char*)dsl.dslop[i]->maLOP.c_str(),(char*)str.c_str())==0) //strcmp so sanh 2 char *
		
		{
			return true;
		}
	}
	return false;
}
bool EmptyLop(LISTLOP &dsl)
{
	// kiem tra lop co rong hay ko
	if(dsl.soluonglop==0)
	{
		return true ;
	}
	return false;
}

void Nhap_1_lop(LISTLOP &dsl,LOP &l)
{
	fflush(stdin);
	string strmalop;
	int flag;
	do
	{
		strmalop.clear();
		flag = 0;
		gotoxy(x,++xuongdong);
		cout<<" Nhap vao ma lop : ";
		XuLiNhap(strmalop);
		if(TimKiemMaLop(dsl,strmalop)==true)// kiem tra ma trung
		{
			gotoxy(x,++xuongdong);
			cout<<" Nhap lai. Ma lop bi trung !!!";
			flag=1;
		}
	}while(flag==1);
	l.maLOP=strmalop;
	Xoa_KT_Thua_O_giua(l.maLOP);
	Xoa_KT_Thua_O_Dau_Cuoi(l.maLOP);
	gotoxy(x,++xuongdong);
	cout<<" Nhap vao ten lop : ";
	fflush(stdin);
	l.tenLOP.clear();
	XuLiNhap(l.tenLOP);
	Chuan_Hoa_Chuoi(l.tenLOP);
	l.lsv = new LISTSINHVIEN ;//cap phat vung nho cho con tro danh sach sinh vien
	KhoiTaoListSV(*l.lsv);// khoi tao danh sach sinh vien
}

void Nhap_List_Lop(LISTLOP &dsl)
{
	// nhap danh sach lop
	for(int i=0;i<dsl.soluonglop;i++)
	{
		gotoxy(x,++xuongdong);
		cout<<" Nhap lop thu "<<i+1;
		Nhap_1_lop(dsl,*dsl.dslop[i]);//co dau sao vi dslop
	}
}

void Xuat_1_LOP(LOP &l)
{
	cout<<setw(5)<<right<<" "<<setw(45)<<left<<l.maLOP<<char(179)<<setw(5)<<" "<<setw(45)<<left<<l.tenLOP;
}
void Xuat_ListLop(LISTLOP &dsl)
{
	gotoxy(x+40,3);
	cout<<"Danh Sach Lop Hoc";
	VeKhungCH(x,2,100,2,true);
	gotoxy(x,5);
	cout<<setw(5)<<right<<" "<<setw(45)<<left<<"Ma lop"<<char(179)<<setw(5)<<" "<<setw(45)<<left<<"Ten Lop";
	VeKhungCH(x,2,100,4,true); 
	int k = 6;
	xuongdong = 6;
	for(int i=0;i<dsl.soluonglop;i++)
	{
		xuongdong=xuongdong+2;
		gotoxy(x,xuongdong);
		Xuat_1_LOP(*dsl.dslop[i]);
		k=k+2;
	}
	VeKhungCH(x,2,100,k,true);
	xuongdong=xuongdong+2;
}

void Save_Lop(ofstream &fo, LOP &l)
{
	fo<<l.maLOP<<"|";
	fo<<l.tenLOP<<endl;
}
void Save_List_Lop(LISTLOP &dsl)
{
	ofstream fo;
	fo.open("danhsachlop.txt",ios::out);
	fo<<dsl.soluonglop<<endl;
	for(int i=0;i<dsl.soluonglop;i++)
	{
		Save_Lop(fo,*dsl.dslop[i]);
	}
	fo.close();
}

void Read_Lop(ifstream &fi,LISTLOP &dsl, LOP &l)
{
	string strmalop;
	getline(fi,strmalop,'|');
	if(TimKiemMaLop(dsl,strmalop)==true)// kiem tra ma lop doc vo co bi trung voi ma truoc hay ko
	{
		gotoxy(70,30);
		cout<<" XIN KIEM TRA LAI FILE.DANH SACH CO MA SO BI TRUNG";
		delete[] dsl.dslop;
	}
	l.maLOP = strmalop;
	Xoa_KT_Thua_O_giua(l.maLOP);
	Xoa_KT_Thua_O_Dau_Cuoi(l.maLOP);
	getline(fi,l.tenLOP);	
	Chuan_Hoa_Chuoi(l.tenLOP);
	l.lsv = new LISTSINHVIEN ;//cap phat vung nho cho con tro danh sach sinh vien
	KhoiTaoListSV(*l.lsv);// khoi tao danh sach sinh vien 
}

void Read_ListLop(LISTLOP &dsl)
{
	string str;
	ifstream fi;
	fi.open("danhsachlop.txt",ios::in);
	fi>>dsl.soluonglop;
	getline(fi,str);
	int n=0;
	while(n<dsl.soluonglop)
	{
		dsl.dslop[n]=new LOP;
		n++;
	}
	for(int i=0;i<dsl.soluonglop;i++)
	{
		Read_Lop(fi, dsl,*dsl.dslop[i]);
	}
	fi.close();
}

//save danh sach sinh vien va diem cua tung sinh vien theo tung lop
void Save_Lop_SV(ofstream &fo, LOP &l)
{
	fo<<l.maLOP<<"|"<<l.tenLOP<<endl;
	Save_List_Sv(fo,*l.lsv);
	fo<<endl;
}

void Save_List_Lop_SV(LISTLOP &dsl)
{
	ofstream fo;
	fo.open("danhsachsinhvien.txt",ios::out);
	fo<<dsl.soluonglop<<endl<<endl;
	for(int i=0;i<dsl.soluonglop;i++)
	{
		Save_Lop_SV(fo,*dsl.dslop[i]);
	}
	fo.close();
}

// Doc danh sach sinh vien va diem so kem theo cua moi sinh vien theo tung lop
void Read_Lop_SV(ifstream &fi,LISTLOP &dsl, LOP &l)
{
	string strmalop;
	getline(fi,strmalop,'|');
	l.maLOP = strmalop;
	Xoa_KT_Thua_O_giua(l.maLOP);
	Xoa_KT_Thua_O_Dau_Cuoi(l.maLOP);
	getline(fi,l.tenLOP);	
	Chuan_Hoa_Chuoi(l.tenLOP);
	l.lsv = new LISTSINHVIEN;// cap phat vung nho cho con tro danh sach sinh vien
	Read_List_Sv(fi,*l.lsv);// doc danh sach sinh vien cua 1 lop
}

void Read_ListLop_SV(LISTLOP &dsl)
{
	ifstream fi;
	fi.open("danhsachsinhvien.txt",ios::in);
	string str;
	fi>>dsl.soluonglop;
	getline(fi,str);
	getline(fi,str);
	//dsl.dslop = new LOP[dsl.soluonglop];
	for(int i=0;i<dsl.soluonglop;i++)
	{
		dsl.dslop[i]=new LOP;
		Read_Lop_SV(fi,dsl,*dsl.dslop[i]);// doc tung lop, moi lop chua mot danh sach sinh vien rieng biet, moi sinh vien co mot danh sach diem thi 
		getline(fi,str);		
	}
	fi.close();
}

void SwapLop(LOP &a,LOP &b)
{
	LOP temp ;
	temp = a;
	a=b;
	b= temp;
}
void SapXepLop(LISTLOP &dsl)
{
	for(int i=0;i<dsl.soluonglop-1;i++)
	{
		for(int j=i+1;j<dsl.soluonglop;j++)
		{
			if(strcmp(dsl.dslop[i]->maLOP.c_str(),dsl.dslop[j]->maLOP.c_str())==1)
			{
				SwapLop(*dsl.dslop[i],*dsl.dslop[j]);
			}
		}
	}
}

//void Them_Lop(LISTLOP &dsl, LOP &lct)
//{
//	// cap phat dong mot mang tam co chieu dai bang voi danh sach lop
//	LOP *temp= new LOP[dsl.soluonglop];
//	for(int i=0;i<dsl.soluonglop;i++)
//	{
//			temp[i]=*dsl.dslop[i];// cho mang tam bang mang danh sach lop
//	}
//	delete[] dsl.dslop;// xoa danh sach lop di
//	dsl.dslop = new LOP[dsl.soluonglop+1];// cap phat mot vung nho moi cho mang lop co chieu dai nhu cu nhung + them 1
//	for(int i=0;i<dsl.soluonglop;i++)
//	{
//		dsl.dslop[i]=temp[i];// cho mang lop moi = voi mang temp 
//	}
//	delete[] temp;// xoa di mang tam
//	// luc nay them mot phan tu vao mang lop thi so luong o nho se vua du 
//	int vtd =0;
//	for(int i = dsl.soluonglop-1;i>=vtd;i--)
//	{
//		dsl.dslop[i+1]=dsl.dslop[i];
//	}
//	dsl.dslop[vtd]=lct;
//	dsl.soluonglop++;
//}
void Them_Lop(LISTLOP &dsl,LOP &lct)
{	
 	int i;
	int vtd = 0;
	dsl.dslop[dsl.soluonglop]=new LOP;
	for(i=dsl.soluonglop-1;i>vtd;i--)
	{
		dsl.dslop[i+1]=dsl.dslop[i];
	}
	dsl.dslop[vtd]=new LOP;
	*dsl.dslop[vtd]=lct;
	dsl.soluonglop++;
	
}

void Hieu_Chinh_DSLop(LISTLOP &dsl, string &mactt)
{
	int i;
	int vtctt=-1;
	LOP *lctt = new LOP;// cap phat 1 ptu mang con tro
	for(i=0;i<dsl.soluonglop;i++)
	{
		if(stricmp((char *)dsl.dslop[i]->maLOP.c_str(),(char*)mactt.c_str())==0)// 0=bang nhau, 1 
		{
			vtctt=i;
			break;
		}
	}
	if(vtctt!=-1)
	{
		for(i = 0 ;i<dsl.soluonglop;i++)
		{
			if(i==vtctt)
			{	gotoxy(x,++xuongdong);
				cout<<" Nhap vao lop thay the : ";
				Nhap_1_lop(dsl,*lctt);
				dsl.dslop[i]->maLOP=lctt->maLOP;
				dsl.dslop[i]->tenLOP=lctt->tenLOP;
			}
		}
	}
	else
	{
	gotoxy(x,++xuongdong);
	cout<<" Khong co ma de thay the";	
	}
}

void Xoa_Lop(LISTLOP &dsl,string &mact)
{
	int vtcx=-1;
	for(int i=0;i<dsl.soluonglop;i++)
	{
		if(stricmp((char *)dsl.dslop[i]->maLOP.c_str(),(char*)mact.c_str())==0)
		{
			vtcx=i;// kiem ra vi tri can xoa
			break;
		}
	}
	if(vtcx!=-1)
	{
		// thuc hien xoa o vi tri thu vtcx
		for(int i=vtcx+1;i<dsl.soluonglop;i++)
		{
			dsl.dslop[i-1]=dsl.dslop[i];
		}
		dsl.soluonglop--;
	}
	else
	{
		gotoxy(x,++xuongdong);
		cout<<" Khong co ma can xoa ";	
	}
	// cap phat mot mang tam = voi mang lop
	LOP *temp[dsl.soluonglop];
	for(int i=0;i<dsl.soluonglop;i++)
	{
			temp[i]=dsl.dslop[i];// cho mang temp = mang lop sau khi xoa mot phan tu
	}
	delete[] dsl.dslop;//xoa mang lop cu di
	//dsl.dslop = new LOP[];// cap phat dong mot mang lop moi co chieu dai bang voi so luong lop da cap nhat
	for(int i=0;i<dsl.soluonglop;i++)
	{
		dsl.dslop[i]= new LOP;
		dsl.dslop[i]=temp[i];// cho mang lop moi = temp 
	}
	delete[] temp;// xoa di mang temp
	// sau khi thuc hien so luong o nho se vua du voi so luong phan tu cua mang lop
}

// ham nay dung de truy xuat den mot lop de thao tac voi danh sach sinh vien trong lop do 
void QuanLiSV_LOP(LISTLOP &dsl)
{
	// nhap vao ma lop de tim kiem troong danh sach lop 
	string strmalop;
	string tenlop;
	gotoxy(x,++xuongdong);
	tenlop.clear();
	cout<<"Nhap vao ten lop  : ";
	XuLiNhap(tenlop);
	int flag=0;
	for(int i = 0 ;i<dsl.soluonglop;i++)
	{
		if(stricmp(tenlop.c_str(),dsl.dslop[i]->tenLOP.c_str())==0)
		{
			//sau khi tim dc ma lop trung voi ma ma nguoi dung nhap vao
			//vao menu sinh vien de thao tac voi danh sach sinh vien tren lop do 
			menuSINHVIEN(*dsl.dslop[i]->lsv);
			flag=1;
			break;	
		}
	}
	if(flag==0)// neu ko tim thay dc lop thi thong bao cho ng dung bik
	{
		gotoxy(x,++xuongdong);
		cout<<"Khong tim thay lop ";
		system("pause");
	}
}
// ham xem diem cua mot sinh vien

void menuLOP(LISTLOP &dsl,LOP &l)
{
	int pointer2 = 0;
	int Amount_Menu =6;
	while(1)
	{
		system("cls");
		textcolor(10);
		VemenuTONG();
		char* menulop[]={"1. Tao moi danh sach lop",
						"2. Xem danh sach lop",
						"3. Them lop",
						"4. Hieu Chinh lop",
						"5. Xoa lop",
						"6. Exit"};
			gotoxy(15,26);
			cout<<"Quan Li Lop Hoc";
			VeKhungCH(1,25,50,3,true);
			gotoxy(1,28);
			for(int i=0;i<Amount_Menu;i++)
			{
				if(pointer2==i)
				{
					textcolor(20);
					cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<menulop[i];
				}
				else
				{
					textcolor(10);
					cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<menulop[i];
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
							xuongdong=2;
							gotoxy(x,xuongdong);
							cout<<"Ban muon tiep tuc thuc hien thao tac nay chu ?(Nhan Enter : YES, ESc : NO)";
							key2=getch();
							if(key2==13)
							{
								gotoxy(x,++xuongdong);
								cout<<" Nhap vao so luong lop : ";
								string soluonglop;
								do
								{
									soluonglop.clear();
									gotoxy(x,++xuongdong);
									cout<<"Nhap vao so luong lop ";
									NhapSoKoChu(soluonglop);
									dsl.soluonglop = atoi(soluonglop.c_str());
									if( dsl.soluonglop<=0 || dsl.soluonglop >500)
									{
										gotoxy(x,++xuongdong);
										cout<<" Nhap lai. So luong lop phai lon hon 0 va nho hon 500: ";
									}
								}while(dsl.soluonglop<=0 || dsl.soluonglop >500);
								int n=0;
								while(n<dsl.soluonglop)
								{
									dsl.dslop[n]= new LOP;
									n++;
								}
								
								//*dsl.dslop = new LOP[dsl.soluonglop];// dong
							
								Nhap_List_Lop(dsl);
								SapXepLop(dsl);
								Save_List_Lop(dsl);
								Save_List_Lop_SV(dsl);
								gotoxy(x,++xuongdong);
								system("pause");
							}
							else if(key2==27)
							{
								break;
							}
						}
						else if(pointer2==1)
						{
							gotoxy(x+20,15);
							if(EmptyLop(dsl)==true)
							{
								cout<<"Danh sach lop trong !!!";
								system("pause");
								break;
							}
							Xuat_ListLop(dsl);
							gotoxy(x,++xuongdong);
							system("pause");
						}
						else if(pointer2==2)
						{
							gotoxy(x+20,15);
							if(EmptyLop(dsl)==true)
							{
								cout<<"Danh sach lop trong !!!";
								system("pause");
								break;
							}
							Xuat_ListLop(dsl);
							gotoxy(x,++xuongdong);
							cout<<" Nhap vao lop can them  ";
							LOP lct;
							Nhap_1_lop(dsl,lct);
							gotoxy(x,++xuongdong);
							cout<<"Ban muon tiep tuc thuc hien thao tac nay chu ?(Nhan Enter : YES, ESc : NO)";
							key2=getch();
							if(key2==13)
							{
								Them_Lop(dsl,lct);
								SapXepLop(dsl);
								Save_List_Lop(dsl);
								Save_List_Lop_SV(dsl);
								gotoxy(x,++xuongdong);
								system("pause");
							}
							else if(key2==27)
							{
								break;
							}
						}
						else if(pointer2==3)
						{
							gotoxy(x+20,15);
							if(EmptyLop(dsl)==true)
							{
								cout<<" Danh sach lop trong !!! ";
								system("pause");
								break;
							}
							Xuat_ListLop(dsl);
							string mactt;
							gotoxy(x,++xuongdong);
							cout<<" Nhap vao ma can thay the : ";
							mactt.clear();
							XuLiNhap(mactt);
							Xoa_KT_Thua_O_giua(mactt);
							gotoxy(x,++xuongdong);
							cout<<" Ban muon tiep tuc thuc hien thao tac nay chu ?(Nhan Enter : YES, ESc : NO)";
							key2=getch();
							if(key2==13)
							{
								Hieu_Chinh_DSLop(dsl,mactt);
								SapXepLop(dsl);
								Save_List_Lop(dsl);
								Save_List_Lop_SV(dsl);
								system("pause");
							}
							else if(key2==27)
							{
								break;
							}
						}
						else if(pointer2==4)
						{
							gotoxy(x+20,15);
							if(EmptyLop(dsl)==true)
							{
								cout<<"Danh sach lop trong ";
								break;
							}
							Xuat_ListLop(dsl);
							string macx;
							gotoxy(x,++xuongdong);
							cout<<" Nhap vao ma can xoa ";
							macx.clear();
							XuLiNhap(macx);
							Xoa_KT_Thua_O_giua(macx);
							gotoxy(x,++xuongdong);
							cout<<"Ban muon tiep tuc thuc hien thao tac nay chu ?(Nhan Enter : YES, ESc : NO)";
							key2=getch();
							if(key2==13)
							{
								Xoa_Lop(dsl,macx);
								SapXepLop(dsl);
								Save_List_Lop(dsl);
								Save_List_Lop_SV(dsl);
								gotoxy(x,++xuongdong);
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
