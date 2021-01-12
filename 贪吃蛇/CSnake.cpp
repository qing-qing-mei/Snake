#include<iostream>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include"CSnake.h"
#include"Cunit.h"
#include"CMap.h"
#include"CFood.h"
#include"CMenu.h"


using namespace std;

CSnake::CSnake(int x, int y, int length, Directions direct, int speed, char pic)
{
	m_iLength = length;
	m_iHeadX = x;
	m_iHeadY = y;
	m_iSpeed = speed;
	m_pic = pic;
	m_enumCurrentDirection = direct;
	Cunit c(0, 0, '@');
	m_vecBody.push_back(c);
	m_vecBody[0].m_ix = m_iHeadX;
	m_vecBody[0].m_iy = m_iHeadY;
	for (int i = 1; i < m_iLength; i++)
	{
		Cunit c;
		m_vecBody.push_back(c);
		switch (m_enumCurrentDirection)
		{
		case w:
			m_vecBody[i].m_ix = m_iHeadX;
			m_vecBody[i].m_iy = m_iHeadY + i;
			break;
		case s:
			m_vecBody[i].m_ix = m_iHeadX;
			m_vecBody[i].m_iy = m_iHeadY - i;
			break;
		case a:
			m_vecBody[i].m_ix = m_iHeadX + i;
			m_vecBody[i].m_iy = m_iHeadY;
			break;
		case d:
			m_vecBody[i].m_ix = m_iHeadX - i;
			m_vecBody[i].m_iy = m_iHeadY;
			break;
		}
	}

}

CSnake::~CSnake()
{

}

//显示蛇
void CSnake::showSnake()
{
	for (int i = 0; i < m_iLength; i++)
	{
		m_vecBody[i].show();
	}
}

//擦除
void CSnake::eraseSnake()
{
	/*for (int i = 0; i < m_iLength; i++)
	{
		m_vecBody[i].erase();
	}*/
	int i;
	for (i = 0; i < m_iLength - 1; i++);
	m_vecBody[i].erase();
}

void CSnake::eraseSnake(int flag)
{
	for (int i = 0; i < m_iLength; i++)
		m_vecBody[i].erase();
}

//改变方向
bool CSnake::changeDirections(char vkValue)
{
	switch (vkValue)
	{
	case'w':
		m_vecBody[0].m_iy--;
		m_enumCurrentDirection = w;
		return false;
	case's':
		m_vecBody[0].m_iy++;
		m_enumCurrentDirection = s;
		return false;
	case'a':
		if (m_enumCurrentDirection == a)
			m_iSpeed -= 20;
		m_vecBody[0].m_ix--;
		m_enumCurrentDirection = a;
		return false;
	case'd':
		m_vecBody[0].m_ix++;
		m_enumCurrentDirection = d;
		return false;
	case 'q':    //代表quit
		changeDirections(m_enumCurrentDirection);
		showSnake();
		if (quitGame())
		{
			return true;
		}
		return false;
	case '+':
		changeDirections(m_enumCurrentDirection);
		showSnake();
		m_iSpeed -= 50;
		return false;
	case ' ':
		changeDirections(m_enumCurrentDirection);
		showSnake();
		Cunit::gotoxy(CMap::KLEFT, CMap::KHEIGHT + 1);
		cout << "游戏暂停,请按任意键继续...";
		_getch();    //游戏暂停
		Cunit::gotoxy(CMap::KLEFT, CMap::KHEIGHT + 1);
		for (int i = 0; i < 27; i++)
			cout << ' ';
		return false;
	default:
		changeDirections(m_enumCurrentDirection);
		showSnake();
		return false;
	}
}

void CSnake::changeDirections(Directions dir)
{
	switch (dir)
	{
	case w:
		m_vecBody[0].m_iy--;
		break;
	case s:
		m_vecBody[0].m_iy++;
		break;
	case a:
		m_vecBody[0].m_ix--;
		break;
	case d:
		m_vecBody[0].m_ix++;
		break;
	default:
		break;
	}
}

bool CSnake::quitGame()  //退出游戏
{
	Cunit::gotoxy(CMap::KLEFT, CMap::KHEIGHT + 1);
	cout << "退出游戏？(y/n):";
	char ch;
	cin >> ch;
	Cunit::gotoxy(CMap::KLEFT, CMap::KHEIGHT + 1);
	for (int i = 0; i < 17; i++)
		cout << ' ';
	if (ch == 'y')
	{
      return true;
	}
  else return false;
}

//存储移动坐标
void CSnake::movePos()
{
	for (int i = m_iLength - 1; i > 0; i--)
	{
		m_vecBody[i].m_iy = m_vecBody[i - 1].m_iy;
		m_vecBody[i].m_ix = m_vecBody[i - 1].m_ix;
	}
}

//移动
bool CSnake::move()
{
	bool flag = false;
	movePos();
	if (_kbhit())
	{
		char key;
		key = _getch();
		if (key == 'a' && m_enumCurrentDirection == d)
		{
			key = 'd';
			flag=changeDirections(key);
		}
		else if (key == 'd' && m_enumCurrentDirection == a)
		{
			key = 'a';
			flag=changeDirections(key);
		}
		else if (key == 'w' && m_enumCurrentDirection == s)
		{
			key = 's';
			flag=changeDirections(key);
		}
		else if (key == 's' && m_enumCurrentDirection == w)
		{
			key = 'w';
			flag=changeDirections(key);
		}
		else flag=changeDirections(key);
	}
	else changeDirections(m_enumCurrentDirection);
	showSnake();
	Sleep(m_iSpeed);
	eraseSnake();
	return flag;
}

//判断是否吃到食物
bool CSnake::eatFood(CFood* pfood)
{
	if (pfood->m_ix == m_vecBody[0].m_ix && pfood->m_iy == m_vecBody[0].m_iy)
		return true;
	else
		return false;
}

//检查食物位置是否在蛇身上
bool CSnake::checkFoodPos(CFood *pFood)
{
	for (int i = 0; i < m_iLength; i++)
	{
		if (pFood->m_ix == m_vecBody[i].m_ix &&
			pFood->m_iy == m_vecBody[i].m_iy)
			return true;
	}
	return false;
}

//蛇吃到食物变长
void CSnake::growup()
{
	Cunit c;
	m_vecBody.push_back(c);
	m_iLength++;
}
