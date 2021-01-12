#pragma once

#include"CFood.h"
#include"CSnake.h"

class CGame
{
public:
	CGame();
	~CGame();
	void run();   //运行
	//void quitGame();   //退出游戏
	void hideCursor();  //隐藏光标
	bool checkFailed();   //检测游戏是否结束
	bool checkLevel();   //检测等级
	void changeInfo();    //改变提示信息
	void GameOver();
public:
	CFood* m_pFood;
	CSnake* m_pSnake;
	int m_iScore;
	int m_iLevel;
};

