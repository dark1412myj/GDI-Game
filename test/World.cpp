#include "stdafx.h"
#include "World.h"
#include "testDlg.h"
#include "algorithm"
#include "atlimage.h"
using namespace std;

CWorld::CWorld(void)
{
	people=NULL;
	V.clear();
	m_Init=0;
	//m_tmpImg=-1;
	//m_tmpImg=(HBITMAP)LoadImage(AfxGetInstanceHandle(),
	//	__T("Õº∆¨/µÿ√ÊX.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
} 


CWorld::~CWorld(void)
{
	for(size_t i=0;i<V.size();i++)
		delete V[i];
	V.clear();
}

bool cmp(CThing* a,CThing* b){
	return a->m_endY < b->m_endY;
}

bool CWorld::NotifyAllThing( HDC hdc )
{
	HDC hDCBitmap = ::CreateCompatibleDC(hdc);
	if(!m_Init){
		m_tmpImg = CreateCompatibleBitmap(hdc,640,480);
		m_Init=1;
	}
	HGDIOBJ old = ::SelectObject(hDCBitmap,m_tmpImg);

	CtestDlg::DrawImg(hDCBitmap,CtestDlg::hBg);

	//if(people)people->drawHeself(hDCBitmap);
	for(int i=0;i<V.size();i++){
		if(V[i]==people){
			if(people->mesure())people->run();
			else {
				//people->setTarget(people->m_posX,people->m_posY);
				//people->run();

			}
		}
		else V[i]->run();
	}
	sort(V.begin(),V.end(),cmp);
	for(size_t i=0;i<V.size();i++)
		V[i]->drawHeself(hDCBitmap);
	
	BitBlt(hdc,0,0,800,600,hDCBitmap,0,0,SRCCOPY);
	::SelectObject(hDCBitmap,old);
	::DeleteDC(hDCBitmap);
	return true;
}

void CWorld::AddThing( CThing* p )
{
	V.push_back(p);
}

void CWorld::AddPeople( CPeople* p )
{
	people=p;
	AddThing(p);
}

void CWorld::ChangeClick( int x,int y )
{
	people->setTarget(x,y);
}
