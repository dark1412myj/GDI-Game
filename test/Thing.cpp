#include "StdAfx.h"
#include "Thing.h"
#include "algorithm"
using namespace std;

CThing::~CThing(void)
{
}

int CThing::run()
{
	return true;
}

int CThing::run( int m_targetX,int m_targetY)
{
	if(m_posX<m_targetX)m_posX+=m_speed;
	if(m_posX>m_targetX)m_posX-=m_speed;
	if(m_posY<m_targetY)m_posY+=m_speed;
	if(m_posY>m_targetY)m_posY-=m_speed;
	int choic=0;
	//下
	if(m_posX==m_targetX&&m_posY<m_targetY){
		choic=(choic+m_r)%10+40;
		m_pic_begin_pos=0;
	}
	//上
	if(m_posX==m_targetX&&m_posY>m_targetY){
		choic=(choic+m_r)%10+80;
		m_pic_begin_pos=4;
	}
	//__T("右");
	if(m_posY==m_targetY&&m_posX<m_targetX){
		choic=(choic+m_r)%10+100;
		m_pic_begin_pos=6;
	}
	//左
	if(m_posY==m_targetY&&m_posX>m_targetX){
		choic=(choic+m_r)%10+60;
		m_pic_begin_pos=2;
	}
	//右下
	if(m_posX<m_targetX&&m_posY<m_targetY){
		choic=(choic+m_r)%10+110;
		m_pic_begin_pos=7;
	}
	//右上
	if(m_posX<m_targetX&&m_posY>m_targetY){
		choic=(choic+m_r)%10+90;
		m_pic_begin_pos=5;
	}
	//左下
	if(m_posX>m_targetX&&m_posY<m_targetY){
		choic=(choic+m_r)%10+50;
		m_pic_begin_pos=1;
	}
	//左上
	if(m_posX>m_targetX&&m_posY>m_targetY){
		choic=(choic+m_r)%10+70;
		m_pic_begin_pos=2;
	}

	if(m_posX==m_targetX&&m_posY==m_targetY){
		choic=(m_r%5+5*m_pic_begin_pos);
	}

	//CClientDC dc(this);

	//DrawImg(dc.m_hDC,hBg);
	//DrawNBGImg(dc.m_hDC,hBitmap[choic],m_posX,m_posY);
	m_r++;
	if(m_r>500)m_r-=500;
	return m_img_pos = (m_pic_base+choic);
}

int CThing::getNowPicPos()
{
	return 0;
}

int CThing::getX()
{
	return m_posX;
}

int CThing::getY()
{
	return m_posY;
}

