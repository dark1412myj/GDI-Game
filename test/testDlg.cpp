// testDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "stdio.h"
#include "People.h"
#include "World.h"
#include "Scene.h"
#include "Animal.h"
#include "stdlib.h"
#include "ImageInfo.h"
#include "fstream"
#include "sstream"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestDlg �Ի���




CtestDlg::CtestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CtestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CtestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CtestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON4, &CtestDlg::OnBnClickedButton4)
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_TOUMING, &CtestDlg::OnBnClickedTouming)
	ON_BN_CLICKED(IDC_WordMode, &CtestDlg::OnBnClickedWordmode)
	ON_BN_CLICKED(IDC_SCENCE, &CtestDlg::OnBnClickedScence)
	ON_BN_CLICKED(IDC_ANIMAL, &CtestDlg::OnBnClickedAnimal)
	//ON_BN_CLICKED(IDC_BUTTON5, &CtestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_PEOPLECHANGE, &CtestDlg::OnBnClickedPeoplechange)
END_MESSAGE_MAP()


// CtestDlg ��Ϣ�������

HANDLE CtestDlg::m_out;
int CtestDlg::xBitmap[800]={0};
int CtestDlg::yBitmap[800]={0};

BOOL CtestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	srand((unsigned)time(NULL));
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	j=0;
	AllocConsole();
	world=NULL;
	m_out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindowText(__T("������"));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CtestDlg::OnBnClickedOk()
{
	//MSG msg={0};
	//msg.message=WM_QUIT;
	//::PostQuitMessage(0);
	exit(0);
}

void CtestDlg::OnBnClickedCancel()
{
	OnCancel();
}


void CtestDlg::OnBnClickedButton4()
{
	hBg = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		__T("ͼƬ/����A.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	CClientDC dc(this);
	for(int i=0;i<800;i++)
	{
		CString sFileName;
		sFileName.Format(__T("ͼƬ/��/c%05d.bmp"),i);
		hBitmap[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
			sFileName,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		DIBSECTION ds;
		BITMAPINFOHEADER &bm = ds.dsBmih;
		GetObject(hBitmap[i],sizeof(ds),&ds);
		iBitmap[i].m_width= bm.biWidth;
		iBitmap[i].m_height= bm.biHeight;
		sFileName.Format(__T("ͼƬ/��/c%05d.txt"),i);
		ifstream fin(sFileName);
		string s;
		getline(fin,s,',');
		istringstream is(s);
		is>>xBitmap[i];
		fin>>yBitmap[i];
		CString str;
		str.Format(__T("x=%d y=%d\n"),xBitmap[i],yBitmap[i]);
		WriteConsole(m_out,str,str.GetLength(),NULL,NULL);
	}
	for(int i = 0;i<97;i++){
		CString str;
		str.Format(__T("ͼƬ/��/c%05d.bmp"),i);
		hBackGround[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
			str,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);

		DIBSECTION ds;
		BITMAPINFOHEADER &bm = ds.dsBmih;
		GetObject(hBackGround[i],sizeof(ds),&ds);
		iBackGround[i].m_width= bm.biWidth;
		iBackGround[i].m_height= bm.biHeight;
	}
	for(int i = 0;i<2800;i++){

		CString str;
		str.Format(__T("ͼƬ/��/c%05d.bmp"),i);
		hAnimal[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
			str,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);

		DIBSECTION ds;
		BITMAPINFOHEADER &bm = ds.dsBmih;
		GetObject(hAnimal[i],sizeof(ds),&ds);
		iAnimal[i].m_width= bm.biWidth;
		iAnimal[i].m_height= bm.biHeight;

	}
}

void CtestDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch(nIDEvent){
		case 5:{
			CClientDC dc(this);
			world->NotifyAllThing(dc.m_hDC);
			   }break;
	}

}


void CtestDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	world->ChangeClick(point.x,point.y);
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CtestDlg::TransparentBlt( HDC hDesDC,	
							  int iDesX, int iDesY,
							  int iWide, int iHigh,
							  HDC hSurDC,
							  int iSurX,int iSurY,
							  UINT iMaskCol
							  )
{	
	HBITMAP hTmpBmp   = CreateCompatibleBitmap( hDesDC, iWide, iHigh );
	HBITMAP hMaskBmp   = CreateBitmap( iWide, iHigh, 1, 1, NULL );	
	HDC		hTmpDC    = CreateCompatibleDC( hDesDC );
	HDC		hMaskDC    = CreateCompatibleDC( hDesDC );
	HBITMAP hOldTmpBmp = (HBITMAP)SelectObject( hTmpDC, hTmpBmp );
	HBITMAP hOldMaskBmp = (HBITMAP)SelectObject( hMaskDC, hMaskBmp );

	BitBlt( hTmpDC, 0, 0, iWide, iHigh, hSurDC, iSurX, iSurY, SRCCOPY );

	COLORREF colOld = SetBkColor( hTmpDC, iMaskCol );
	BitBlt( hMaskDC, 0, 0, iWide, iHigh, hTmpDC, 0, 0, SRCCOPY );
	SetBkColor( hTmpDC, colOld );

	BitBlt( hMaskDC, 0, 0, iWide, iHigh, hMaskDC, 0, 0, NOTSRCCOPY );

	BitBlt( hTmpDC, 0, 0, iWide, iHigh, hMaskDC, 0, 0, SRCAND );


	BitBlt( hMaskDC, 0, 0, iWide, iHigh, hMaskDC, 0, 0, NOTSRCCOPY );
	BitBlt( hDesDC, iDesX, iDesY, iWide, iHigh, hMaskDC, 0, 0, SRCAND );
	BitBlt( hDesDC, iDesX, iDesY, iWide, iHigh, hTmpDC, 0, 0, SRCPAINT);

	SelectObject(hTmpDC, hOldTmpBmp);				
	DeleteDC(hTmpDC);
	SelectObject(hMaskDC, hOldMaskBmp);
	DeleteDC(hMaskDC);

	DeleteObject(hTmpBmp);
	DeleteObject(hMaskBmp);
}

void CtestDlg::OnBnClickedTouming()
{
	CClientDC dc(this);
	HBITMAP hBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		__T("ͼƬ/��/c00001.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	HDC hDCBitmap = CreateCompatibleDC(dc);
	SelectObject(hDCBitmap,hBitmap);

	DIBSECTION ds;
	BITMAPINFOHEADER &bm = ds.dsBmih;
	GetObject(hBitmap,sizeof(ds),&ds);
	int iWidth = bm.biWidth;
	int iHeight = bm.biHeight;

	TransparentBlt(dc.m_hDC,0,0,iWidth,iHeight,hDCBitmap,0,0,SRCCOPY);
}

void CtestDlg::DrawImg(HDC hdc, HBITMAP hBitmap)
{
	HDC hDCBitmap = ::CreateCompatibleDC(hdc);

	SelectObject(hDCBitmap,hBitmap);

	DIBSECTION ds;
	BITMAPINFOHEADER &bm = ds.dsBmih;
	GetObject(hBitmap,sizeof(ds),&ds);

	int iWidth = bm.biWidth;
	int iHeight = bm.biHeight;

	BitBlt(hdc,0,0,iWidth,iHeight,hDCBitmap,0,0,SRCCOPY);
	DeleteDC(hDCBitmap);
}

void CtestDlg::DrawNBGImg(HDC hdc, HBITMAP hBitmap,int x,int y)
{
	HDC hDCBitmap = ::CreateCompatibleDC(hdc);

	SelectObject(hDCBitmap,hBitmap);

	DIBSECTION ds;
	BITMAPINFOHEADER &bm = ds.dsBmih;
	GetObject(hBitmap,sizeof(ds),&ds);

	int iWidth = bm.biWidth;
	int iHeight = bm.biHeight;
	TransparentBlt(hdc,x,y,iWidth,iHeight,hDCBitmap,0,0,RGB(255,255,255));
	//BitBlt(hdc,0,0,iWidth,iHeight,hDCBitmap,0,0,SRCCOPY);
	DeleteDC(hDCBitmap);
}


HBITMAP CtestDlg::hBitmap[]={0};
HBITMAP CtestDlg::hBackGround[]={0};
HBITMAP CtestDlg::hAnimal[]={0};
HBITMAP CtestDlg::hBg=0;
CImageInfo CtestDlg::iBitmap[];
CImageInfo CtestDlg::iBackGround[];
CImageInfo CtestDlg::iAnimal[];
bool CtestDlg::theMap[641][481]={0};
void CtestDlg::OnBnClickedWordmode()
{
	if(world){
		delete world;
		world=NULL;
		KillTimer(5);
	}
	world=new CWorld;
	world->AddPeople(new CPeople(0,0));
	SetTimer(5,10,NULL);
}


void CtestDlg::OnBnClickedScence()
{
	CScene* pp=new CScene(rand()%640,rand()%480,rand()%97);
	world->AddThing(pp);
}


void CtestDlg::OnBnClickedAnimal()
{
	CAnimal* pp = new CAnimal(rand()%640,rand()%480,rand());
	pp->setSpeed(rand()%3+1);
	world->AddThing( pp );
}

void CtestDlg::OnBnClickedPeoplechange()
{
	world->ChangePeople();
}
