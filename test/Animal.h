#pragma once

#include "stdafx.h"
#include "thing.h"

class CAnimal :
	public CThing
{
	int m_targetX,m_targetY;
public:
	//CAnimal(void);
	~CAnimal(void);
	CAnimal(int x=0,int y=0,int num=0):CThing(x,y){
		m_targetX=rand()%600;
		m_targetY=rand()%460;
		while(num%7==4)num=rand()%7;
		setPicBase(num%7);
//		while()
//		setPicBase(6);
	}
	void setPicBase(int p){this->m_pic_base=p*400;}
	bool drawHeself(HDC hdc);
	virtual int run();
};

