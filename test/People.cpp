#include "stdafx.h"
#include "People.h"
#include "testDlg.h"

CPeople::CPeople(void)
{
}


CPeople::~CPeople(void)
{
}

bool CPeople::drawHeself( HDC hdc )
{
	//int t = run();
	int t = m_img_pos;
	CtestDlg::DrawNBGImg(hdc,CtestDlg::hBitmap[t],this->m_posX,this->m_posY);
	//m_endX=this->m_posX+CtestDlg::iBitmap[t].m_width;
	//m_endY=this->m_posY+CtestDlg::iBitmap[t].m_height;
	return true;
}

int CPeople::run()
{
	int t = CThing::run(m_targetX,m_targetY);
	m_endX=this->m_posX+CtestDlg::iBitmap[t].m_width;
	m_endY=this->m_posY+CtestDlg::iBitmap[t].m_height;
	return t;
}

void CPeople::setTarget( int x,int y )
{
	m_targetX=x;
	m_targetY=y;
}

int CPeople::mesure()
{
	int x=m_posX;
	int y=m_posY;
	if(m_posX<m_targetX)x=m_posX+m_speed;
	if(m_posX>m_targetX)x=m_posX-m_speed;
	if(m_posY<m_targetY)y=m_posY+m_speed;
	if(m_posY>m_targetY)y=m_posY-m_speed;
	int jx = x+CtestDlg::xBitmap[m_img_pos];
	int jy = y+CtestDlg::yBitmap[m_img_pos];
	return !CtestDlg::theMap[jx][jy];
	//return 1;
}

