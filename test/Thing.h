#pragma once
#include "stdafx.h"
class CThing
{
public:
	int m_posX;
	int m_posY;
	int m_endX;
	//int m_wid;
	//int m_hei;
	int m_endY;
	int m_speed;
	int m_r;
	int m_pic_begin_pos;
	int m_img_pos;
	int m_pic_base;
	int getNowPicPos();
	int getX();
	int getY();
	void setSpeed(int sp){m_speed=sp;}
	CThing(int x=0,int y=0):m_posX(x),m_posY(y){m_posY=m_posX=m_pic_begin_pos=m_pic_base=m_r=m_posX=m_posY=m_img_pos=0;m_speed=1;m_endX=m_endY=0;}
	virtual int run();
	virtual int run(int target_x,int target_y);
	virtual bool drawHeself(HDC hdc)=0;
	~CThing(void);

};
