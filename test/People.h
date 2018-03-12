#pragma once

//#include "stdafx.h"
#include "thing.h"

class CPeople :
	public CThing
{
	int m_targetX,m_targetY;
public:
	CPeople(void);
	CPeople(int x,int y):CThing(x,y){}
	void setPicBase(int p){this->m_pic_base=p;}
	void setTarget(int x,int y);
	virtual int run();
	int mesure();
	~CPeople(void);
	bool drawHeself(HDC hdc);
};

