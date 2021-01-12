#pragma once
#include "CUnit.h"
class CFood :
    public Cunit
{
public:
    CFood(int x =0, int y=0, char pic = '#');
    virtual ~CFood();
    void createPos();
};

