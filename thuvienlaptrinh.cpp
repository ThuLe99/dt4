#include "thuvienlaptrinh.h"
// H�m thay d?i k�ch c? c?a khung cmd v?i tham s? truy?n v�o l� chi?u cao, chi?u r?ng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// H�m t� m�u.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// H�m d?ch chuy?n con tr? d?n t?a d? x, y.
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// H�m x�a m�n h�nh.

// H�m l?y Key t? b�n ph�m
/* GetAsyncKeyState(VK_ESCAPE) => b?t s? ki?n ph�m Esc */ 

// H�m t? vi?t
void Xoa_KT_Thua_O_Dau_Cuoi(string &a)
{
	while(a[0]==' ')
	{
		a.erase(a.begin()+0);
	}
	while(a[a.length()-1]==' ')
	{
		a.erase(a.begin()+a.length()-1);
	}
}
void Xoa_KT_Thua_Giua_Ky_Tu(string &a)
{
	for(int i = 0 ;i<a.length();i++)
	{
		if(a[i] == ' ' && a[i+1]== ' ')
		{
			a.erase(a.begin()+(i+1));
			i--;
		}
	}
}
void Xoa_KT_Thua_O_giua(string &a)
{
	for(int i =0;i<a.length();i++)
	{
		if(a[i]==' ')
		{
			a.erase(a.begin()+(i));
			i--;
		}
	}
}
void Xoa_Ky_Tu_DB(string &a)
{
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>32 && a[i]<48 && a[i]>57 && a[i]<65 && a[i]>90 && a[i]<97 && a[i]>122 && a[i]<127) 
		{
			a.erase(a.begin()+i);
			i--;
		}
	}	
}
void Viet_Hoa_Ky_Tu(string &a)
{
	// ep kieu string ve char
	strlwr((char *)a.c_str());
	if(a[0]>=97 && a[0]<=122)
	{
		a[0]-=32;
	}
	for(int i = 0;i<a.length()-1;i++)
	{
		if(a[i]== ' ' && a[i+1]!=' ' )
		{
			if(a[i + 1]>= 97 && a[i+1]<=122)
			{
				a[i+1]=a[i+1]-32;
			}
		}
	}
}
void Chuan_Hoa_Chuoi(string &a)
{
	Viet_Hoa_Ky_Tu(a);
	Xoa_KT_Thua_Giua_Ky_Tu(a);
	Xoa_KT_Thua_O_Dau_Cuoi(a);
	Xoa_Ky_Tu_DB(a);
}
int wherex(void){
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

int wherey(void){
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}

void VeKhungCH(int x, int y, int width, int height, bool draw) {
	//vẽ khung chữ nhật
	if (draw){
		//vẽ trước 4 góc
		//góc trên bên trái
		gotoxy(x, y);
		cout << char(218);
		//vẽ góc trên bên phải
		gotoxy(x + width, y);
		cout << char(191);
		//vẽ góc dưới bên trái
		gotoxy(x, y + height);
		cout << char(192);
		//vẽ góc dưới bên phải
		gotoxy(x + width, y + height);
		cout << char(217);
		//vẽ chiều ngang bên trên
		for (int i = x + 1; i < (x + width); i++){
			gotoxy(i, y);
			cout << char(196);
		}
		//vẽ chiều ngang bên dưới
		for (int i = x + 1; i < (x + width); i++){
			gotoxy(i, y+height);
			cout << char(196);
		}
		//vẽ chiều dọc bên trái
		for (int i = y + 1; i < (y + height); i++){
			gotoxy(x, i);
			cout << char(179);
		}
		//vẽ chiều dọc bên phải
		for (int i = y + 1; i < (y + height); i++){
			gotoxy(x+width, i);
			cout << char(179);
		}
	}
	else {
		//vẽ trước 4 góc
		//góc trên bên trái
		gotoxy(x, y);
		cout << " ";
		//vẽ góc trên bên phải
		gotoxy(x + width, y);
		cout << " ";
		//vẽ góc dưới bên trái
		gotoxy(x, y + height);
		cout << " ";
		//vẽ góc dưới bên phải
		gotoxy(x + width, y + height);
		cout << " ";

		//vẽ chiều ngang bên trên
		for (int i = x + 1; i < (x + width); i++){
			gotoxy(i, y);
			cout << " ";
		}
		//vẽ chiều ngang bên dưới
		for (int i = x + 1; i < (x + width); i++){
			gotoxy(i, y + height);
			cout << " ";
		}
		//vẽ chiều dọc bên trái
		for (int i = y + 1; i < (y + height); i++){
			gotoxy(x, i);
			cout << " ";
		}
		//vẽ chiều dọc bên phải
		for (int i = y + 1; i < (y + height); i++){
			gotoxy(x + width, i);
			cout << " ";
		}

	}
}
void XuLyNhap_Ten(string& x)
{
	while (true)
	{
		char c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)||(c >= 97 && c <= 122))&&x.length()<20)
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			x.clear();
			return;
		}
		else if (c == 13 && x.length() > 0)// n?u l� ph�m enter
		{
			return;
		}
	}
}
void XuLyNhap_Pass(string& x)
{
	while (true)
	{
		char c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)||(c >= 97 && c <= 122))&&x.length()<25)
		{
			x.insert(x.begin() + x.length(), c);
			cout << "*";
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";// lui con tro ve mot don vi
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			x.clear();
			return;
		}
		else if (c == 13 && x.length() > 0)// n?u l� ph�m enter
		{
			return;
		}
	}
}
void XuLiNhap(string &x)
{	
	while (true)
	{
		char c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)||(c >= 97 && c <= 122))&&x.length()<50)
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";// lui con tro ve mot don vi
			cout << " ";
			cout << "\b";
		}
		else if(c==32)
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
//		else if (c == 27)
//		{
//			x.clear();
//			return;
//		}
		else if (c == 13 && x.length() > 0)// n?u l� ph�m enter
		{
			return;
		}
	}
}
void NhapSoKoChu(string &x)
{
	while(true)
	{
		char c = getch();
		if ((c >= 48 && c <= 57) && x.length()<10)
		{
			x.insert(x.begin()+x.length(),c);
			cout<<c;
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";// lui con tro ve mot don vi
			cout << " ";
			cout << "\b";
		}
		else if(c==13 && x.length()>0)
		{
			break;
		}
	}
}
void XuLiNhapMa(string &x)
{
	while (true)
	{
		char c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)||(c >= 97 && c <= 122))&&x.length()<15)
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";// lui con tro ve mot don vi
			cout << " ";
			cout << "\b";
		}
		else if(c==32)
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
//		else if (c == 27)
//		{
//			x.clear();
//			return;
//		}
		else if (c == 13 && x.length() > 0)// n?u l� ph�m enter
		{
			return;
		}
	}
}
void VemenuTONG(void)
{	
	VeKhungCH(1,1,50,3,true);
	VeKhungCH(1,5,50,68,true);
	gotoxy(20,2);
	cout<<"MENU";
	gotoxy(1,5);
	cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<"1.Quan Li Mon Hoc";
	cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<"2.Quan Li Lop";
	cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<"3.Quan Li Sinh Vien";
	cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<"4.Quan Li Cau Hoi Thi";
	cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<"5.Thi Trac Nghiem";	
	cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<"6.Xem Cac Cau Hoi Da Thi Cua Sinh Vien";
	cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<"7.In bang diem cua mot lop";
	cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<"8.Dang xuat";
	//VeKhungCH(1,1,50,68,true);
}
