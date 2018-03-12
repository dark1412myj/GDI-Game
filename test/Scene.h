#pragma once
#include "stdafx.h"
#include "thing.h"

class CScene :
	public CThing
{
public:
	CScene(void);
	CScene(int x,int y,int num=rand()%97);
	//CScene(int x,int y);
	bool drawHeself( HDC hdc );
	~CScene(void);
	int run();
};


