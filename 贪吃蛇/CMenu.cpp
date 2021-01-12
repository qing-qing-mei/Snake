#include<iostream>
#include<windows.h>
//#include<conio.h>
#include "CMenu.h"
#include"CUnit.h"

using namespace std;

CMenu::CMenu()
{
	m_iMap = new CMap;
	m_iGame = new CGame;
}

CMenu::~CMenu()
{
	delete m_iMap;
	delete m_iGame;
}

void CMenu::loadGame()
{
	system("color f5\n");
	Cunit::gotoxy(CMap::KWIDTH / 2, CMap::KHEIGHT / 2);
	cout << "正在加载游戏";
	for (int i = 0; i < 6; i++)
	{
		Sleep(400);
		cout << " .";
	}
	Sleep(500);
}

bool CMenu::showMenu()
{
	system("cls");
	system("color f0\n");
	bool flag = false;
	m_iMap->drawGameArea();
	Cunit::gotoxy(CMap::KWIDTH / 2, CMap::KHEIGHT / 3);
	cout << "贪吃蛇";
	Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2); 
	cout << "2. 退出游戏";
	Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2 - 2);
	cout << "1. 开始游戏";
	Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2 + 2);
	cout << "3. 游戏帮助";
	Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2 + 4);
	cout << "请输入你的选择：";
	char your_choose;
	cin >> your_choose;
	while (your_choose != '1' && your_choose != '2' && your_choose != '3')
	{
		Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2 + 4);
		cout << "输入无效，请重新输入：";
		//if (_kbhit()) your_choose = _getch();
		cin >> your_choose;
	}
	if (your_choose == '1')
	{
		startGame();
		return false;
	}
	else if (your_choose == '2')
	{
		quitGame();
		return true;
	}
	else return gameHelp();
}

void CMenu::startGame()
{
	system("cls");
	m_iGame->run();
}
void CMenu::quitGame()
{
	system("cls");
	m_iMap->drawGameArea();
	Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2);
	cout << "游戏结束... ";
}

bool CMenu::gameHelp()
{
	system("cls");
	m_iMap->drawGameArea();
	Cunit::gotoxy(0, CMap::KHEIGHT / 3 - 2);
	cout << "\t\t游戏说明" << endl << endl;
	cout << "\t\t1. 按w,s,a,d控制蛇的上下左右" << endl << endl;
	cout << "\t\t2. 按方向键以外的任意键暂停，再按任意键继续游戏" << endl << endl;
	cout << "\t\t3. 一个食物10分,每30提升一个等级" << endl << endl;
	cout << "\t\t4.游戏过程中，可按q键退出游戏" << endl << endl;
	cout << "\t\t5. 按q返回上一级,按e直接退出游戏"<<endl<<endl;
	char ch;
	Cunit::gotoxy(CMap::KWIDTH / 3, CMap::KHEIGHT - 4);
	cout << "请输入q or e：";
	cin >> ch;
	while (ch != 'q' && ch != 'e')
	{
		Cunit::gotoxy(CMap::KWIDTH / 3, CMap::KHEIGHT - 4);
		cout << "请输入q or e：";
		cin >> ch;
	}
	if (ch == 'q')
	{
		showMenu();
		return false;
	}
	else
	{
		quitGame();
		return true;
	}
}