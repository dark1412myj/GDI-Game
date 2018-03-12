#include "stdafx.h"
#include "Animal.h"
#include "Thing.h"
#include "testDlg.h"

CAnimal::~CAnimal(void)
{
}

bool CAnimal::drawHeself( HDC hdc )
{
	/*int old_X=this->m_posX;
	int old_Y=this->m_posY;
	int t = run();*/
	int t = m_img_pos;
	CtestDlg::DrawNBGImg(hdc,CtestDlg::hAnimal[t],this->m_posX,this->m_posY);

	/*if(old_X==this->m_posX&&old_Y==this->m_posY){
		m_targetX=rand()%600;
		m_targetY=rand()%460;
	}*/
	return true;
}


int CAnimal::run()
{
	int old_X=this->m_posX;
	int old_Y=this->m_posY;
	int old_t=this->m_img_pos;
	int t = CThing::run(m_targetX,m_targetY);
	
	if(old_X==this->m_posX&&old_Y==this->m_posY){
		m_targetX=rand()%600;
		m_targetY=rand()%460;
	}
	int hehe = CThing::run(m_targetX,m_targetY);
	m_endX=this->m_posX+CtestDlg::iAnimal[t].m_width;
	m_endY=this->m_posY+CtestDlg::iAnimal[t].m_height;
	return hehe;
}
