#ifndef THUVIENLAPTRINH_H
#define THUVIENLAPTRINH_H
#include <string>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <dos.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
using namespace std;
void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x,int y);
void Xoa_KT_Thua_O_Dau_Cuoi(string &a);
void Xoa_KT_Thua_Giua_Ky_Tu(string &a);
void Xoa_KT_Thua_O_giua(string &a);
void Xoa_Ky_Tu_DB(string &a);
void Viet_Hoa_Ky_Tu(string &a);
void Chuan_Hoa_Chuoi(string &a);
int wherex(void);
int wherey(void);
void VeKhungCH(int x, int y, int width, int height, bool draw);
void VemenuTONG(void);
void XuLyNhap_Pass(string& x);
void XuLyNhap_Ten(string& x);
void NhapSoKoChu(string &x);
void XuLiNhap(string &x);
void XuLiNhapMa(string &x);
#endif
