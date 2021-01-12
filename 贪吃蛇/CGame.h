#pragma once

#include"CFood.h"
#include"CSnake.h"

class CGame
{
public:
	CGame();
	~CGame();
	void run();   //����
	//void quitGame();   //�˳���Ϸ
	void hideCursor();  //���ع��
	bool checkFailed();   //�����Ϸ�Ƿ����
	bool checkLevel();   //���ȼ�
	void changeInfo();    //�ı���ʾ��Ϣ
	void GameOver();
public:
	CFood* m_pFood;
	CSnake* m_pSnake;
	int m_iScore;
	int m_iLevel;
};

