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
	cout << "���ڼ�����Ϸ";
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
	cout << "̰����";
	Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2); 
	cout << "2. �˳���Ϸ";
	Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2 - 2);
	cout << "1. ��ʼ��Ϸ";
	Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2 + 2);
	cout << "3. ��Ϸ����";
	Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2 + 4);
	cout << "���������ѡ��";
	char your_choose;
	cin >> your_choose;
	while (your_choose != '1' && your_choose != '2' && your_choose != '3')
	{
		Cunit::gotoxy(CMap::KWIDTH / 2 - 10, CMap::KHEIGHT / 2 + 4);
		cout << "������Ч�����������룺";
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
	cout << "��Ϸ����... ";
}

bool CMenu::gameHelp()
{
	system("cls");
	m_iMap->drawGameArea();
	Cunit::gotoxy(0, CMap::KHEIGHT / 3 - 2);
	cout << "\t\t��Ϸ˵��" << endl << endl;
	cout << "\t\t1. ��w,s,a,d�����ߵ���������" << endl << endl;
	cout << "\t\t2. �������������������ͣ���ٰ������������Ϸ" << endl << endl;
	cout << "\t\t3. һ��ʳ��10��,ÿ30����һ���ȼ�" << endl << endl;
	cout << "\t\t4.��Ϸ�����У��ɰ�q���˳���Ϸ" << endl << endl;
	cout << "\t\t5. ��q������һ��,��eֱ���˳���Ϸ"<<endl<<endl;
	char ch;
	Cunit::gotoxy(CMap::KWIDTH / 3, CMap::KHEIGHT - 4);
	cout << "������q or e��";
	cin >> ch;
	while (ch != 'q' && ch != 'e')
	{
		Cunit::gotoxy(CMap::KWIDTH / 3, CMap::KHEIGHT - 4);
		cout << "������q or e��";
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