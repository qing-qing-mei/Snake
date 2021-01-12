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
	void changeDirections(Directions dir);  //改变方向
	bool quitGame();
	bool eatFood(CFood* pfood);
	bool checkFoodPos(CFood *pFood);    //检查食物位置
	void movePos();
	void growup();
	void showSnake();
public:
	int m_iLength;
	int m_iHeadX;
	int m_iHeadY;
	int m_iSpeed;       //蛇当前速度
	char m_pic;
	Directions m_enumCurrentDirection;  //蛇当前方向
	vector<Cunit> m_vecBody;   //存储蛇的位置
};