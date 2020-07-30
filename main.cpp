#include "dssinhvien.h"
//#include "dsdiemthi.h"
#include "DSLop.h"
#include "DSMonHoc.h"
//#include "dscauhoi.h"
//#include "chthicua1sv.h"
#include "thuvienlaptrinh.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string tendangnhap = "giaovien";//ten dang nhap cua giao vien
string password = "123";//pass giao vien
string ten ;// ten dang nhap (ma sinh vien)
string pass;// password trong danh sach sinh vien
// dong ho thi trac nghiem
bool stop ;
int thoigian;
struct Hour {
	int hour;
	int minute;
	int second;
};
Hour h;
char inToA(int k);
void insertarray(char* h, Hour* j);
bool changetime(Hour* h);
void WriteBlockChar(char* Arraych, int row, int col, int x, int y, int color);
void printClock(Hour &h);
//void Cap_Nhat_SV_Da_Thi(LISTLOP &dsl,LISTCHDT_SV &lchdt_sv);
//float TINH_DIEM_CHO_GV(LISTCTL &lctl,CAUHOINGAUNHIEN &rdqt);
//void ThiTracNghiemGV(listMH &lmh,TREE &t,CAUHOIMA &chm,CAUHOINGAUNHIEN &randomquestion,LISTCTL &lctl);
//void GiaoDienThi(TREE &t,CAUHOIMA &chm,CAUHOINGAUNHIEN &randomquestion,LISTCTL &lctl);
//float TINH_DIEM_CHO_SV(LISTCTL &lctl,CAUHOINGAUNHIEN &rdqt);
bool Kiem_Tra_Pass_Sv(LISTLOP &dsl,string &ma, string &pass);
//void Sinh_Vien_Thi_Trac_Nghiem(listMH &lmh,LISTLOP &dsl,TREE &t,LISTCHDT_SV &lchdt_sv,CAUHOIMA &chm,LISTCTL &lctl,CAUHOINGAUNHIEN &randomquestion,string &masv);
void menuTONG(listMH &lmh,LISTLOP &dsl);
void DangNhapGiaoVien_SinhVien(listMH &lmh,LISTLOP &dsl);
//bool Sinh_Vien_Da_Thi(LISTCHDT_SV &lchdt_sv,string mssv ,char mamh[15]);

char inToA(int k)
{
	switch (k)
	{
	case 0:return '0';
	case 1:return '1';
	case 2:return '2';
	case 3:return '3';
	case 4:return '4';
	case 5:return '5';
	case 6:return '6';
	case 7:return '7';
	case 8:return '8';
	case 9:return '9';
	default:
		break;
	}
}
void insertarray(char* h, Hour* j)
{
	int bait = 0;
	bait = j->second;
	h[7] = inToA(bait % 10);
	h[6] = inToA(bait /= 10);

	bait = j->minute;
	h[4] = inToA(bait % 10);
	h[3] = inToA(bait /= 10);

	bait = j->hour;
	h[1] = inToA(bait % 10);
	h[0] = inToA(bait /= 10);

}
bool changetime(Hour * h)
{
	if (h->second > 0) --h->second;
	else if (h->minute > 0)
	{
		h->second = 59;
		--h->minute;
	}
	else if (h->hour > 0)
	{
		--h->hour;
		h->minute = 59;
		h->second = 59;
	}
	else return 0;
	return 1;
}
//dung de in ra mot chuoi thay the ham cout
void WriteBlockChar(char* Arraych, int row, int col, int x, int y, int color)
{
	CHAR_INFO* charater = new CHAR_INFO[row * col];
	for (int i = 0; i < row * col; i++)
	{
		charater[i].Attributes = color;
		charater[i].Char.AsciiChar = Arraych[i];
	}
	COORD sizebuff = { col,row };
	COORD pos = { 0,0 };
	SMALL_RECT earea = { x,y,x + col - 1,y + row - 1 };
	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
	delete[] charater;
}
void printClock(Hour &h) {
	char a[8] = { '0','0',':','0','0',':','0','0' };
	while (stop)
	{
		if (!changetime(&h)) stop = 0;
		insertarray(a, &h);
		WriteBlockChar(a, 1, 8, 17, 1, 0x008);
		Sleep(970);
	}
	return;
}
DWORD WINAPI ThreadProc(LPVOID param)
{
	printClock(h);
	return 1;
}

// kiem tra sinh vien da thi mon do chua
//bool Sinh_Vien_Da_Thi(LISTCHDT_SV &lchdt_sv, string mssv ,char mamh[15])
//{
//	// duyet danh sach sinh vien da thi kiem tra sinh vien da thi mon do chua
//	for(NODECHDT *k=lchdt_sv.pheadCH;k!=NULL;k=k->nNEXT)
//	{
//		if(stricmp(k->chdtsv.mssv.c_str(),mssv.c_str())==0)
//		{
//			for(int i = 0; i<k->chdtsv.chiso;i++)
//			{
//				if(strcmp(mamh,k->chdtsv.chdt[i]->MAMH)==0)
//				{
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}
//void Cap_Nhat_SV_Da_Thi(LISTLOP &dsl,LISTCHDT_SV &lchdt_sv)
//{
//	string mssvtemp;
//	for(NODECHDT *k=lchdt_sv.pheadCH;k!=NULL;k=k->nNEXT)
//	{
//		int flag = 0;
//		for(int i = 0 ; i<dsl.soluonglop;i++)
//		{
//			for(NODESV *p= dsl.dslop[i]->lsv->pHEAD;p!=NULL;p=p->pNEXT)
//			{
//				if(stricmp(k->chdtsv.mssv.c_str(),p->datasv.masv.c_str())==0)
//				{
//					flag = 1;
//					break;
//				}
//			}
//		}
//		if(flag==0)
//		{
//			mssvtemp=k->chdtsv.mssv;
//			break;
//		}
//	}
//	Xoa_SV_Da_THi(lchdt_sv,mssvtemp);
//}
//float TINH_DIEM_CHO_GV(LISTCTL &lctl,CAUHOINGAUNHIEN &rdqt)
//{
//	float diem = 0.0;
//	for(int i = 0 ;i<rdqt.socauhoithi ; i++)
//	{
//		//if(strcmp((char*)lctl.ctd[i].answer,(char*)rdqt.chnn[i]->dapan)==0)
//		if(lctl.ctd[i].answer==rdqt.chnn[i]->dapan)
//		{
//			diem = diem + 0.5;
//		}
//	}
//	return diem;
//}
// giao dien thi trac nghiem
//void GiaoDienThi(TREE &t,CAUHOIMA &chm,CAUHOINGAUNHIEN &randomquestion,LISTCTL &lctl)
//{
//	int x=60;
//	int k=30;
//	int xd;
//	stop = 1;
//	lctl.ctd = new CAUTRALOI[randomquestion.socauhoithi];// khoi tao list cau tra loi co so luong = voi so luong cau hoi thi ma nguoi dung nhap vao
//	int xuongdong;
//	int pointer;
//	for(int i = 0; i<randomquestion.socauhoithi;i++)// rang cho tung phan tu trong mang cau tra loi ki tu khoang trang
//	{
//		lctl.ctd[i].answer=char(7);
//	}
//	 dong ho thi trac nghiem
//	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)& ThreadProc, NULL, 0, NULL);
//	while(true)
//	{
//		system("cls");
//		textcolor(10);
//		gotoxy(3,2);
//		cout<<"THOI GIAN THI : ";
//		gotoxy(10,4);
//		cout<<"DAP AN";
//		VeKhungCH(27,3,200,3,true);
//		gotoxy(80,4);
//		cout<<"CAU HOI THI";
//		VeKhungCH(1,3,25,3,true);
//		VeKhungCH(1,7,25,randomquestion.socauhoithi+2,true);
//		gotoxy(40,randomquestion.socauhoithi+20);
//		cout<<"(Enter : Nhap dap an A B C D ,"<<char(24)<<" : LEN ,"<<char(25)<<" : XUONG ,"<<"ESC : Ket thuc bai thi)";
//		gotoxy(1,7);
//		xuongdong=8;
//		 mot day lua chon cau tra loi
//		for(int i=0;i<randomquestion.socauhoithi;i++)
//		{
//			if(pointer==i)
//			{
//				xd=7;
//				textcolor(20);
//				cout<<"\n"<<char(179)<<setw(4)<<right<<" "<<" Cau "<<i+1<<": ";
//				textcolor(10);
//				gotoxy(k+2,++xd);
//				cout<<randomquestion.chnn[i]->noidung;
//				gotoxy(k,++xd);
//				cout<<randomquestion.chnn[i]->A;
//				gotoxy(k,++xd);
//				cout<<randomquestion.chnn[i]->B;
//				gotoxy(k,++xd);
//				cout<<randomquestion.chnn[i]->C;
//				gotoxy(k,++xd);
//				cout<<randomquestion.chnn[i]->D;
//				xuongdong=xuongdong+i;
//				lctl.vitri_ctl=i;
//			}
//			else
//			{
//				textcolor(10);
//				xd=7;
//				xd=xd+i+1;
//				gotoxy(1,xd);
//				cout<<char(179)<<setw(4)<<right<<" "<<" Cau "<<i+1<<" : ";
//			}
//			xd=7;
//			xd=xd+i+1;
//			gotoxy(17,xd);
//			cout<<lctl.ctd[i].answer;
//		}
//		textcolor(10);
//		 dieu khien len xuong de danh cau tra loi
//		while(true)
//		{
//			if(kbhit())// neu co phim nao nhap vao 
//			{
//				char key =getch();// luu phim do lai de xu li 
//				if(key == 72)// len
//				{
//					if(pointer>0){
//						--pointer;
//					}
//					else{
//						pointer=randomquestion.socauhoithi-1;
//					}
//					break;
//				}
//				if(key==80)//xuong
//				{
//					if(pointer<randomquestion.socauhoithi-1)
//					{
//						++pointer;
//					}
//					else
//					{
//						pointer = 0;
//					}
//					break;
//					}
//				if(key==13)//enter
//				{
//					 nhap cau tra loi  A B C D
//					gotoxy(15,xuongdong);
//					char key2=getch();
//					cout<<key2;
//					if(key2==65||key2==97)
//					{
//						lctl.ctd[lctl.vitri_ctl].answer=char(65);
//					}
//					if(key2==66||key2==98)
//					{
//						lctl.ctd[lctl.vitri_ctl].answer=char(66);
//					}
//					if(key2==67||key2==99)
//					{
//						lctl.ctd[lctl.vitri_ctl].answer=char(67);
//					}
//					if(key2==68||key2==100)
//					{
//						lctl.ctd[lctl.vitri_ctl].answer=char(68);
//					}
//				}
//				if(key==27)// bam esc de ket thuc bai thi
//				{
//					system("cls");
//					VeKhungCH(60,24,80,4,true);
//					gotoxy(70,26);
//					cout<<"Ban co chac muon ket thuc bai thi ";
//					cout<<"(Enter : DONG Y , ESC : THOAT";
//					char key3 = getch();
//					if(key3==13)
//					{
//						system("cls");
//						stop = 0 ;
//						/*for(int i = 0;i<randomquestion.socauhoithi;i++)
//						{
//							cout<<" Cau "<<i+1<<lctl.ctd[i].answer<<endl;
//						}
//						system("pause");*/
//						return;
//					}
//					if(key3==27)
//					{
//						break;
//					}
//				}
//				break;
//			}
//		}
//		if(stop==0)// dong ho het gio tu dong dung bai thi
//		{
//			system("cls");
//			return;
//		}
//	}
//}
// neu la giao vien truy cap vao chuc nang thi trac nghiem
//void ThiTracNghiemGV(listMH &lmh,TREE &t,CAUHOIMA &chm,CAUHOINGAUNHIEN &randomquestion,LISTCTL &lctl)
//{
//	char temp[] = "   ";
//	int flag;
//	bool ktm_cochchua;
//	int inloi;
//	int x=60;
//	int xd;
//	char maMH[15];
//	string tenmonthi;
//	gotoxy(x+40,3);
//	cout<<"Danh Sach Mon Hoc";
//	VeKhungCH(x,2,100,2,true);
//	gotoxy(x,5);
//	cout<<setw(5)<<right<<" "<<setw(45)<<left<<"Ma mon hoc"<<char(179)<<setw(5)<<" "<<setw(45)<<left<<"Ten mon hoc";
//	VeKhungCH(x,2,100,4,true); 
//	int k = 5;
//	xd = 7;
//	for(int i =0;i<lmh.soluong;i++)
//	{
//		gotoxy(x,xd++);
//		Xuat_MonHoc(*lmh.dsmh[i]);
//		k++;
//	}
//	VeKhungCH(x,2,100,k,true);
//	xd++;
//	gotoxy(x,xd++);
//	cout<<"Ban muon tiep tuc vao thi ? (ENTER : dong y, ESC : thoat)";
//	char key = getch();
//	VeKhungCH(x,xd,90,30,true);
//	VeKhungCH(x+30,xd+5,57,3,true);
//	VeKhungCH(x+30,xd+10,57,3,true);
//	VeKhungCH(x+30,xd+15,57,3,true);
//	VeKhungCH(x+30,xd+20,57,3,true);
//	gotoxy(x+5,xd+7);
//	cout<<"Nhap vao ten mon hoc :";
//	gotoxy(x+5,xd+12);
//	cout<<"Nhap vao so cau hoi thi :";
//	gotoxy(x+5,xd+17);
//	cout<<"Nhap vao so gio ";
//	gotoxy(x+5,xd+22);
//	cout<<"Nhap vao so phut thi ";
//	if(key==13)
//	{
//		do
//		{
//			gotoxy(x+32,xd+7);
//			cout<<"\b"<<setw(55)<<left<<" "<<"\b";
//			strcpy(maMH,temp);
//			ktm_cochchua = true;
//			tenmonthi.clear();
//			flag=1;
//			gotoxy(x+32,xd+7);
//			XuLiNhap(tenmonthi);
//			for(int i =0;i<lmh.soluong;i++)
//			{
//				if(stricmp((char*)tenmonthi.c_str(),(char*)lmh.dsmh[i]->tenMH.c_str())==0)
//				{
//					strcpy(maMH,lmh.dsmh[i]->MAMH);
//					flag=0;
//					break;
//				}
//			}
//			inloi=xd;
//			if(flag==1)
//			{
//				gotoxy(x+15,inloi+25);
//				cout<<"Ma mon hoc khong ton tai ";
//				gotoxy(x+15,inloi+26);
//				system("pause");
//				gotoxy(x+15,inloi+25);
//				cout<<setw(70)<<left<<" ";
//			}
//			ktm_cochchua = Kiem_Tra_Mon_Do_Da_Co_Cau_Hoi_Chua(t,maMH);
//			if(ktm_cochchua==false)
//			{
//				gotoxy(x+15,inloi+25);
//				cout<<"Mon nay chua co cau hoi thi !";
//				gotoxy(x+15,inloi+26);
//				system("pause");
//				gotoxy(x+15,inloi+25);
//				cout<<setw(70)<<left<<" ";
//			}
//		}while(flag == 1||ktm_cochchua==false);
//		string socauhoi;
//		string sogiothi;
//		string sophutthi;
//		int count;
//		Boc_Cau_Hoi_Thi_Theo_MA(t,maMH,chm);// khoi tao cau hoi thi theo ma
//		do
//		{
//			count = 0;
//			socauhoi.clear();
//			gotoxy(x+32,xd+12);
//			cout<<"\b"<<setw(55)<<left<<" "<<"\b";
//			gotoxy(x+32,xd+12);
//			NhapSoKoChu(socauhoi);
//			count = atoi(socauhoi.c_str());
//			if(socauhoi.length()<=0||count<=0||count>=chm.count)
//			{
//				gotoxy(x+15,inloi+25);
//				cout<<"So cau hoi phai lon hon 0 va nho hon so luong trong ngan hang de thi";
//				gotoxy(x+15,inloi+26);
//				system("pause");
//				gotoxy(x+15,inloi+25);
//				cout<<setw(70)<<left<<" ";
//			}
//		}while(socauhoi.length()<=0||count<=0||count>=chm.count);
//		randomquestion.socauhoithi = atoi(socauhoi.c_str());
//		gotoxy(x+32,xd+17);
//		NhapSoKoChu(sogiothi);
//		h.hour = atoi(sogiothi.c_str());
//		gotoxy(x+32,xd+22);
//		NhapSoKoChu(sophutthi);
//		h.minute = atoi(sophutthi.c_str());
//		h.second = 0;
//		Boc_Cau_Hoi_Thi_Ngau_Nhien(t,chm,randomquestion);// khoi tao cau hoi thi ngau nhien
//		GiaoDienThi(t,chm,randomquestion,lctl);// bat giao dien thi
//		VeKhungCH(60,24,80,4,true);
//		gotoxy(70,26);
//		int diem=TINH_DIEM_CHO_SV(lctl,randomquestion);// tinh diem
//		cout<<" Ket qua bai thi cua ban la : "<<diem;
//	}
//	else
//	{
//		return;
//	}
//}
//float TINH_DIEM_CHO_SV(LISTCTL &lctl,CAUHOINGAUNHIEN &rdqt)
//{
//	float diem = 0.0;
//	for(int i = 0 ;i<rdqt.socauhoithi ; i++)
//	{
//		if(lctl.ctd[i].answer==rdqt.chnn[i]->dapan)
//		{
//			diem = diem + 0.5;
//		}
//	}
//	return diem;
//}
// neu la sinh vien truy cap vao chuc nang thi trac nghiem
//void Sinh_Vien_Thi_Trac_Nghiem(listMH &lmh,LISTLOP &dsl,TREE &t,LISTCHDT_SV &lchdt_sv,CAUHOIMA &chm,LISTCTL &lctl,CAUHOINGAUNHIEN &randomquestion,string &masv)
//{
//	bool ktsv_dtchua;
//	bool ktm_cochchua;
//	int x=60;
//	int xd;
//	fflush(stdin);
//	char maMH[15];
//	char temp[] = "   ";
//	int flag;
//	int k = 5;
//	xd = 7;
//	int inloi;
//	string tenmonthi;
//	gotoxy(x+40,3);
//	cout<<"Danh Sach Mon Hoc";
//	VeKhungCH(x,2,100,2,true);
//	gotoxy(x,5);
//	cout<<setw(5)<<right<<" "<<setw(45)<<left<<"Ma mon hoc"<<char(179)<<setw(5)<<" "<<setw(45)<<left<<"Ten mon hoc";
//	VeKhungCH(x,2,100,4,true); 
//	for(int i =0;i<lmh.soluong;i++)
//	{
//		gotoxy(x,xd++);
//		Xuat_MonHoc(*lmh.dsmh[i]);
//		k++;
//	}
//	VeKhungCH(x,2,100,k,true);
//	xd++;
//	gotoxy(x,xd++);
//	cout<<"Ban muon tiep tuc thi chu ?(ENTER : dong y , ESC : thoat)";
//	char key = getch();
//	VeKhungCH(x,xd,90,30,true);
//	VeKhungCH(x+30,xd+5,57,3,true);
//	VeKhungCH(x+30,xd+10,57,3,true);
//	VeKhungCH(x+30,xd+15,57,3,true);
//	VeKhungCH(x+30,xd+20,57,3,true);
//	gotoxy(x+5,xd+7);
//	cout<<"Nhap vao ten mon hoc :";
//	gotoxy(x+5,xd+12);
//	cout<<"Nhap vao so cau hoi thi :";
//	gotoxy(x+5,xd+17);
//	cout<<"Nhap vao so gio ";
//	gotoxy(x+5,xd+22);
//	cout<<"Nhap vao so phut thi ";
//	if(key==13)
//	{
//		do
//		{
//			gotoxy(x+32,xd+7);
//			cout<<"\b"<<setw(55)<<left<<" "<<"\b";
//			strcpy(maMH,temp);
//			ktsv_dtchua = false;
//			ktm_cochchua = true;
//			tenmonthi.clear();
//			flag=1;
//			gotoxy(x+32,xd+7);
//			XuLiNhap(tenmonthi);
//			for(int i =0;i<lmh.soluong;i++)
//			{
//				if(stricmp((char*)tenmonthi.c_str(),(char*)lmh.dsmh[i]->tenMH.c_str())==0)
//				{
//					strcpy(maMH,lmh.dsmh[i]->MAMH);
//					flag=0;
//					break;
//				}
//			}
//			inloi=xd;
//			if(flag==1)
//			{
//				gotoxy(x+15,inloi+25);
//				cout<<"Ma mon hoc khong ton tai ";
//				gotoxy(x+15,inloi+26);
//				system("pause");
//				gotoxy(x+15,inloi+25);
//				cout<<setw(70)<<left<<" ";
//			}
//			ktsv_dtchua = Sinh_Vien_Da_Thi(lchdt_sv,masv,maMH);
//			if(ktsv_dtchua==true)// kiem tra sinh vien da thi mon nay chua
//			{
//				gotoxy(x+15,inloi+25);
//				cout<<"Ban da thi mon nay roi !";
//				gotoxy(x+15,inloi+26);
//				system("pause");
//				gotoxy(x+15,inloi+25);
//				cout<<setw(70)<<left<<" ";
//			}
//			ktm_cochchua = Kiem_Tra_Mon_Do_Da_Co_Cau_Hoi_Chua(t,maMH);
//			if(ktm_cochchua==false)
//			{
//				gotoxy(x+15,inloi+25);
//				cout<<"Mon nay chua co cau hoi thi !";
//				gotoxy(x+15,inloi+26);
//				system("pause");
//				gotoxy(x+15,inloi+25);
//				cout<<setw(70)<<left<<" ";
//			}
//		}while(flag == 1||ktsv_dtchua==true||ktm_cochchua==false);
//		string socauhoi;
//		string sogiothi;
//		string sophutthi;
//		int count;
//		Boc_Cau_Hoi_Thi_Theo_MA(t,maMH,chm);// khoi tao cau hoi thi theo ma
//		do
//		{
//			count = 0;
//			socauhoi.clear();
//			gotoxy(x+32,xd+12);
//			cout<<"\b"<<setw(55)<<left<<" "<<"\b";
//			gotoxy(x+32,xd+12);
//			NhapSoKoChu(socauhoi);
//			count = atoi(socauhoi.c_str());
//			if(socauhoi.length()<=0||count<=0||count>=chm.count)
//			{
//				gotoxy(x+15,inloi+25);
//				cout<<"So cau hoi phai lon hon 0 va nho hon so luong trong ngan hang de thi";
//				gotoxy(x+15,inloi+26);
//				system("pause");
//				gotoxy(x+15,inloi+25);
//				cout<<setw(70)<<left<<" ";
//			}
//		}while(socauhoi.length()<=0||count<=0||count>=chm.count);
//		randomquestion.socauhoithi = atoi(socauhoi.c_str());
//		gotoxy(x+32,xd+17);
//		NhapSoKoChu(sogiothi);
//		h.hour = atoi(sogiothi.c_str());
//		gotoxy(x+32,xd+22);
//		NhapSoKoChu(sophutthi);
//		h.minute = atoi(sophutthi.c_str());
//		h.second = 0;
//		Boc_Cau_Hoi_Thi_Ngau_Nhien(t,chm,randomquestion);// khoi tao cau hoi thi ngau nhien
//		GiaoDienThi(t,chm,randomquestion,lctl);// mo giao dien thi
//		VeKhungCH(60,24,80,4,true);
//		gotoxy(70,26);
//		int diem=TINH_DIEM_CHO_SV(lctl,randomquestion);// tinh diem cho sinh vien
//		cout<<" Ket qua bai thi cua ban la : "<<diem;
//		// luu diem cho sinh vien
//		for(int i = 0 ; i<dsl.soluonglop;i++)
//		{
//			for(NODESV *k=dsl.dslop[i]->lsv->pHEAD;k!=NULL;k=k->pNEXT)
//			{
//				if(stricmp(masv.c_str(),k->datasv.masv.c_str())==0)
//				{
//					for(NODEDT *dt=k->datasv.ldt->pHeadDt;dt!=NULL;dt=dt->NEXT)
//					{
//						if(stricmp(maMH,dt->datadt.Mamh)==0)
//						{
//							dt->datadt.diemthi=diem;
//							break;
//						}
//					}
//					break;
//				}
//			}
//		}
//		Save_List_Lop_SV(dsl);
//		//luu nhung cau hoi moi vua thi cua sinh vien vao danh sach sinh vien da thi
//		Nap_CH_Sau_Khi_Thi(lchdt_sv,randomquestion,dsl,masv);
//		Save_CH_Thi_1_SV(lchdt_sv);
//	}
//	else
//	{
//		return;
//	}
//}
void menuTONG(listMH &lmh,LISTLOP &dsl)
{
	LOP l;
	LISTSINHVIEN lsv;
	//Read_CH_Thi_1_SV(lchdt_sv);
	int soluong=8;
	char *menutong[]={	"0.Quan Li Mon Hoc",
						"1.Quan Li Lop ",
						"2.Quan Li Sinh Vien",
						"3.Quan Li Cau Hoi Thi",
						"4.Thi Trac Nghiem ",
						"5.Xem Cac Cau Hoi Da Thi Cua Sinh Vien",
						"6.In bang diem cua mot lop ",
						"7.Dang Xuat"};
	int pointer = 0;
	while(true)
	{
		system("cls");
		gotoxy(20,2);
		textcolor(10);
		cout<<"MENU";
		VeKhungCH(1,1,50,3,true);
		VeKhungCH(1,5,50,68,true);
		gotoxy(1,5);
		for(int i=0;i<soluong;i++)
		{
			if(pointer==i)
			{
				textcolor(20);
				cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<menutong[i];
			}
			else
			{
				textcolor(10);
				cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<menutong[i];
			}
		}
		textcolor(10);
		while(true)	// xu li key board
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
						pointer=soluong-1;
					}
					break;
				}
				if(key==80)//xuong
				{
					if(pointer<soluong-1)
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
					if(pointer==0)
					{
						menuMONHOC(lmh,dsl);
					}
					else if(pointer==1)
					{	
						menuLOP(dsl,l);
						
					}
					else if(pointer==2)
					{
//						gotoxy(80,15);
//						if(EmptyLop(dsl)==true)
//						{
//							cout<<"Danh sach lop trong ";
//							system("pause");
//							break;
//						}
//						Xuat_ListLop(dsl);
//						QuanLiSV_LOP(dsl);
//						Fill_MH_Cho_Sv_Moi(lmh,dsl);
					}
					else if(pointer==3)
					{
						gotoxy(80,15);
						cout<<"cau hoi";
						system("pause");
					//	menuCAUHOI(t,lmh,stk);
					}
					else if(pointer==4)
					{
						gotoxy(80,15);
						cout<<"thi trac ngjiei";
						system("pause");
//						ThiTracNghiemGV(lmh,t,chm,rdqt,lctl);
//						system("pause");
					}
					else if(pointer==5)
					{
						gotoxy(80,15);
						cout<<"xem cau hoi thi cua sinh vien";
						system("pause");
//						Xem_CH_Thi_1_SV(lchdt_sv,lmh);
//						system("pause");
//						break;
					}
					else if(pointer==6)
					{
						gotoxy(80,15);
						cout<<"xem bang diem cua moj lop";
						system("pause");
//						Xuat_ListLop(dsl);
//						Xem_Diem_Cua_1_Lop(lmh,lchdt_sv,dsl);
//						system("pause");
					}
					else if(pointer==7)
					{
						return;
					}
				}
				break;
			}
			
//			for(int i = 0 ; i<dsl.soluonglop;i++)
//			{
//				for(NODESV *k=dsl.dslop[i]->lsv->pHEAD;k!=NULL;k=k->pNEXT)
//				{
//					Sap_Xep_DT(*k->datasv.ldt);
//				}
//			}
			Save_List_Lop_SV(dsl);
//			Save_ListCauHoi(t);
//			Cap_Nhat_SV_Da_Thi(dsl,lchdt_sv);
//			Save_CH_Thi_1_SV(lchdt_sv);
		}
	}
//	delete[] lctl.ctd;
//	for(int i = 0 ;i<chm.count;i++)
//	{
//		delete chm.stkch[i];
//	}
//	for(int i = 0 ;i<rdqt.vitri_chnn;i++)
//	{
//		delete rdqt.chnn[i];
//	}
}
bool Kiem_Tra_Pass_Sv(LISTLOP &dsl,string &ma, string &pass)
{
	for(int i = 0 ; i<dsl.soluonglop;i++)
	{
		for(NODESV *k=dsl.dslop[i]->lsv->pHEAD;k!=NULL;k=k->pNEXT)
		{
			if(stricmp(ma.c_str(),k->datasv.masv.c_str())==0&&stricmp(pass.c_str(),k->datasv.password.c_str())==0)
			{
				return true;
			}
		}
	}
	return false;
}
void DangNhapGiaoVien_SinhVien(listMH &lmh,LISTLOP &dsl)
{
	while(true)
	{
		int flag ;
		while(true)
		{
			ten.clear();
			pass.clear();
			fflush(stdin);
			system("cls");
			textcolor(14);
			flag =0;
			gotoxy(87,15);
			cout<<"CHUONG TRINH THI TRAC NGHIEM ";
			VeKhungCH(60,10,82,35,true);
			VeKhungCH(75,20,50,12,true);
			VeKhungCH(94,23,25,2,true);
			VeKhungCH(94,26,25,2,true);
			gotoxy(85,40);
			cout<<"<Nhan 'ESC' de thoat chuong trinh>";
			gotoxy(78,24);
			cout<<"Ten dang nhap : ";
			gotoxy(78,27);
			cout<<"Password : ";
			gotoxy(95,24);
			XuLyNhap_Ten(ten);
			gotoxy(95,27);
			XuLyNhap_Pass(pass);
			if(ten==tendangnhap&&pass==password)
			{
				menuTONG(lmh,dsl);
				system("pause");
				break;
			}
//			else if(Kiem_Tra_Pass_Sv(dsl,ten,pass)==true)
//			{
//				gotoxy(60,60);
//				system("cls");
//				Sinh_Vien_Thi_Trac_Nghiem(lmh,dsl,t,lchdt_sv,chm,lctl,randomquestion,ten);
//				system("pause");
//				break;
//			}
			else
			{
				gotoxy(65,33);
				cout<<" Xin kiem tra lai ten dang nhap va passwork";
				system("pause");
				break;
			}
		}
		char key = getch();
		if(key==27)
		{
			break ;
		}
	}
}
int main(int argc, char** argv) {
	listMH lmh;
	//CAUHOIMA chm;
//	LISTCTL lctl;
	//CAUHOINGAUNHIEN rdqt;
	LISTLOP dsl;
	//TREE t;
	//STACKID stk;
	//LISTCHDT_SV lchdt_sv;
//	Khoitaoidngaunhien(stk);
//	KhoiTaoCay(t);
	//Read_ListCauHoi(t,stk);
	Read_ListLop(dsl);
	Read_ListLop_SV(dsl);
	Read_listMH(lmh);
	//Read_CH_Thi_1_SV(lchdt_sv);
	DangNhapGiaoVien_SinhVien(lmh,dsl);
	for(int i=0;i<dsl.soluonglop;i++)
	{
		GiaiPhongSinhVien(*dsl.dslop[i]->lsv);
	}
	for(int i = 0 ;i<lmh.soluong;i++)
	{
		delete lmh.dsmh[i]; 
	}
	delete[] dsl.dslop;
	return 0;
}
