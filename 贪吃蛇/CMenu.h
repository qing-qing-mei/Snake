#pragma once

#include"CMap.h"
#include"CGame.h"

class CMenu
{
public:
	CMenu();
	~CMenu();
	bool showMenu();
	void startGame();
	void quitGame();
	bool gameHelp();
	static void loadGame();
public:
	CMap* m_iMap;
	CGame* m_iGame;
};

