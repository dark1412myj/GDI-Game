#pragma once

#include "stdafx.h"
#include "vector"

using namespace std;

class CEngine
{
private:	
	CEngine(void);
	~CEngine(void);
public:
	static bool DrawListBmp(HDC hdc,vector<HBITMAP>& list);
};
