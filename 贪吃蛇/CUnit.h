#pragma once
#include<Windows.h>
class Cunit
{
public:
	Cunit(int x = 0, int y = 0, char pic = '*');
	virtual ~Cunit();
	void show();
	void erase();
	static void gotoxy(int x, int y);

public:
	int m_ix;
	int m_iy;
	char m_cPic;
};

