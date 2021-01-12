#include "CFood.h"
#include"CUnit.h"
#include"CMap.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

CFood::CFood(int x, int y, char pic) : Cunit(x, y, pic)
{

}

CFood::~CFood()
{

}

void CFood::createPos()
{
	/*m_ix = CMap::KLEFT + rand() % (CMap::KWIDTH - 2);
	m_iy = CMap::KUP + rand() % (CMap::KHEIGHT - 4);*/
	m_ix = CMap::KLEFT + rand() % (CMap::KWIDTH - CMap::KLEFT - 1);
	m_iy = CMap::KUP + rand() % (CMap::KHEIGHT - CMap::KUP - 1);
}
