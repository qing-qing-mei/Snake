#include "CUnit.h"
#include<iostream>
using namespace std;
Cunit::Cunit(int x, int y, char pic)
{
	m_ix = x;
	m_iy = y;
	m_cPic = pic;
}
Cunit::~Cunit()
{
}
void Cunit::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	pos.X = x;
	pos.Y = y;
	//设置光标位置 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Cunit::show()
{
	gotoxy(m_ix, m_iy);
	cout << m_cPic;
}
void Cunit::erase()
{
	gotoxy(m_ix, m_iy);
	cout << " ";
}
