#pragma once
#include "stdafx.h"
#include "Thing.h"
#include "vector"
#include "People.h"
using namespace std;
class CWorld
{
	HBITMAP m_tmpImg;
	int m_Init;
public:
	vector<CThing*>V;
	//MyObject m_allObject[1000];
	CPeople* people;
	CWorld(void);
	bool NotifyAllThing(HDC hdc);
	void AddThing(CThing* p);
	void AddPeople(CPeople* p);
	void ChangePeople(){
		people->m_pic_base^=400;
	}
	void ChangeClick(int x,int y);
	~CWorld(void);
};

