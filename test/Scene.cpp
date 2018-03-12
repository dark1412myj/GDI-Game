#include "stdafx.h"
#include "Scene.h"
#include "testDlg.h"
#include "atlimage.h"


CScene::CScene(void)
{
}

CScene::CScene( int x,int y,int num/*=rand()%97*/ )
{
	this->m_posX=x;
	this->m_posY=y;
	this->m_pic_base=num;
	if(num<13||(num>84&&num<90)){
		CString str;
		str.Format(__T("Í¼Æ¬/¾°/b%05d.bmp"),num);
		CImage cover;
		cover.Load(str);
		int lenx = cover.GetWidth();
		int leny = cover.GetHeight();
		for(int i=0;i<lenx;i++)
		{
			for(int j=0;j<leny;j++)
				if (cover.GetPixel(i,j)==RGB(0,0,0))
				{
					if(x+i<640&&y+j<480)
					{
						CtestDlg::theMap[x+i][y+j]=1;
						//CString str;
						//str.Format(__T("i=%d   j=%d   x+i=%d y+j=%d   "),i,j,x+i,y+j);
						//::WriteConsole(CtestDlg::m_out,str,str.GetLength(),NULL,NULL);
					}
				}
		}
	}
/*	CBitmap bt;
	bt.SetBitmapBits()
	HBITMAP hBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		__T("Í¼Æ¬/ÈË/c00001.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);*/
}


CScene::~CScene(void)
{
}

bool CScene::drawHeself( HDC hdc )
{
	CtestDlg::DrawNBGImg(hdc,CtestDlg::hBackGround[m_pic_base],m_posX,m_posY);
	return true;
}

int CScene::run()
{
	m_endX=this->m_posX+CtestDlg::iBackGround[m_pic_base].m_width;
	m_endY=this->m_posY+CtestDlg::iBackGround[m_pic_base].m_height;
	return m_pic_base;
}
