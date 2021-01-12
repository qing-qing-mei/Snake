#include "CMap.h"
#include<iostream>
#include<windows.h>
#include"Cunit.h"
using namespace std;

const int CMap::KLEFT = 1;
const int CMap::KUP = 3;
const int CMap::KWIDTH = 80;     //长
const int CMap::KHEIGHT = 30;    //高
const int CMap::KSCORE_OFFSET = 0;
const int CMap::KLEVEL_OFFSET = 1;

void CMap::drawGameWindows()
{
	SMALL_RECT win_size = { 0,0,KWIDTH ,KHEIGHT + 2 };  //定义上下左右四个点
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &win_size);
}

void CMap::drawGameArea()
{
	drawGameWindows();
	int wall[KHEIGHT][KWIDTH] = { {0} };
	for (int i = 1; i < KHEIGHT - 1; i++)
		for (int j = 1; j < KWIDTH - 1; j++)
			wall[i][j] = 1;
	for (int i = 0; i < KHEIGHT; i++)
	{
		for (int j = 0; j < KWIDTH; j++)
		{
			if (wall[i][j]) cout << " ";
			else
			{
				if (i == 0 || i == KHEIGHT - 1) cout << "-";
				else cout << "|";
			}
		}
		cout << endl;
	}
}

void CMap::drawGameInfo()
{
	Cunit::gotoxy(1, 2);
	for (int i = 0; i < KWIDTH - 2; i++)
	{
		cout << '-';
	}
	Cunit::gotoxy(KLEFT, 1);
	cout << "游戏名称：贪吃蛇";
	Cunit::gotoxy(KLEFT + 1 * (KWIDTH / 4), 1);
	cout << "编写者：***";
	Cunit::gotoxy(KLEFT + 2 * (KWIDTH / 4), 1);
	cout << "游戏得分：" << KSCORE_OFFSET;
	Cunit::gotoxy(KLEFT + 3 * (KWIDTH / 4), 1);
	cout << "游戏等级：" << KLEVEL_OFFSET;
}
