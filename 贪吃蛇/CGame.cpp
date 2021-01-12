#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include<mmSystem.h>//win�����ý���йصĴ�����ӿ�
#include "CGame.h"
#include"CMap.h"
#include"CSnake.h"
#include"CFood.h"
#pragma comment(lib, "winmm.lib")//����winmm.lib��

const int FOOD_SCORE = 10;  //ÿ��һ��ʳ��ĵ÷�
const int PRO_LEVEL = 30;   //ÿ��һ������Ҫ�ķ���
const int REDUCE_SPEED = 50;  //ÿ��һ���������ٶ�

CGame::CGame()
{
	m_iScore = CMap::KSCORE_OFFSET;
	m_iLevel = CMap::KLEVEL_OFFSET;
	m_pFood = new CFood;
	m_pSnake = new CSnake;
}

CGame::~CGame()
{
	delete m_pFood;
	delete m_pSnake;
}

void CGame::hideCursor()  //���ع��
{
	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}

void CGame::GameOver()
{
	PlaySound(L"dead_bgm", NULL, SND_FILENAME | SND_ASYNC);
	Cunit::gotoxy(CMap::KWIDTH / 3, CMap::KHEIGHT / 2);
	cout << "��Ϸ���������� ";
	m_pFood->erase();
	m_pSnake->eraseSnake(0);
	Cunit::gotoxy(CMap::KWIDTH / 3, CMap::KHEIGHT / 2 + 2);
}

//����
void CGame::run()
{
	hideCursor();
	srand((int)time(0));
	CMap map;
	map.drawGameArea();
	map.drawGameInfo();
	m_pFood->createPos();
	m_pFood->show();
	m_pSnake->showSnake();
	PlaySound(L"bgm.wav",
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //���뱳������
	_getch();
	m_pSnake->eraseSnake();
	while (1)
	{
		hideCursor();
		if (m_pSnake->eatFood(m_pFood))
		{
			m_pFood->createPos();
			while (m_pSnake->checkFoodPos(m_pFood)) //ֱ��ʳ�ﲻ����������
				m_pFood->createPos();
			m_pFood->show();
			m_pSnake->growup();
			changeInfo();
		}
		if (m_pSnake->move())
		{
			GameOver();
			break;
		}
		while (m_pSnake->m_iSpeed < 450 - REDUCE_SPEED * m_iLevel)
		{
			m_iLevel++;
			if (m_pSnake->m_iSpeed == 450 - REDUCE_SPEED * m_iLevel)
				break;
		}
		if (m_pSnake->m_iSpeed == 0) m_pSnake->m_iSpeed = 50;
		Cunit::gotoxy(CMap::KLEFT + 3 * (CMap::KWIDTH / 4) + 10, 1);
		cout << m_iLevel;
		if (checkFailed())
		{
			GameOver();
			break;
		}
	}
}

//�����ײǽ����ҧ���Լ�
bool CGame::checkFailed()
{
	int flag = 0;   //��ҧ���Լ��ı�־λ
	for (int i = 4; i < m_pSnake->m_iLength; i++)
		if (m_pSnake->m_vecBody[0].m_ix == m_pSnake->m_vecBody[i].m_ix &&
			m_pSnake->m_vecBody[0].m_iy == m_pSnake->m_vecBody[i].m_iy)
			flag = 1;
	if (flag) return true;
	else if (m_pSnake->m_vecBody[0].m_ix == CMap::KLEFT-1 ||
		m_pSnake->m_vecBody[0].m_ix == CMap::KWIDTH-1 ||
		m_pSnake->m_vecBody[0].m_iy == CMap::KUP-1 ||
		m_pSnake->m_vecBody[0].m_iy == CMap::KHEIGHT-1)
		return  true;
	else return false;
}

bool CGame::checkLevel()
{
	if (m_iScore % PRO_LEVEL == 0)
		return true;
	else return false;
}

void CGame::changeInfo()
{
	m_iScore += FOOD_SCORE;
	Cunit::gotoxy(CMap::KLEFT + 2 * (CMap::KWIDTH / 4) + 10, 1);
	cout << m_iScore;
	if (checkLevel())
	{
		m_iLevel++;
		m_pSnake->m_iSpeed -= REDUCE_SPEED;
		if (m_pSnake->m_iSpeed == 0) m_pSnake->m_iSpeed = 50;
	}
	Cunit::gotoxy(CMap::KLEFT + 3 * (CMap::KWIDTH / 4) + 10, 1);
	cout << m_iLevel;
}
