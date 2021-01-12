#pragma once
#include"CFood.h"
#include<iostream>
#include<vector>
#include<iostream>
#include<Windows.h>
using namespace std;

typedef enum {
	w,s,a,d
}Directions;
class CSnake
{
public:
	CSnake(int x = 40, int y = 15, int length = 4, Directions direction = d, int speed = 400, char pic = '*');
	virtual~CSnake();
	bool move();
	void eraseSnake();
	void eraseSnake(int flag);
	bool changeDirections(char vkValue);
	void changeDirections(Directions dir);  //�ı䷽��
	bool quitGame();
	bool eatFood(CFood* pfood);
	bool checkFoodPos(CFood *pFood);    //���ʳ��λ��
	void movePos();
	void growup();
	void showSnake();
public:
	int m_iLength;
	int m_iHeadX;
	int m_iHeadY;
	int m_iSpeed;       //�ߵ�ǰ�ٶ�
	char m_pic;
	Directions m_enumCurrentDirection;  //�ߵ�ǰ����
	vector<Cunit> m_vecBody;   //�洢�ߵ�λ��
};