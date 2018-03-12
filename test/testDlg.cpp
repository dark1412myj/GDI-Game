// testDlg.cpp : 实现文件
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


// CtestDlg 对话框




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


// CtestDlg 消息处理程序

HANDLE CtestDlg::m_out;
int CtestDlg::xBitmap[800]={0};
int CtestDlg::yBitmap[800]={0};

BOOL CtestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	srand((unsigned)time(NULL));
	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	j=0;
	AllocConsole();
	world=NULL;
	m_out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindowText(__T("穆永嘉"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
		__T("图片/地面A.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	CClientDC dc(this);
	for(int i=0;i<800;i++)
	{
		CString sFileName;
		sFileName.Format(__T("图片/人/c%05d.bmp"),i);
		hBitmap[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
			sFileName,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		DIBSECTION ds;
		BITMAPINFOHEADER &bm = ds.dsBmih;
		GetObject(hBitmap[i],sizeof(ds),&ds);
		iBitmap[i].m_width= bm.biWidth;
		iBitmap[i].m_height= bm.biHeight;
		sFileName.Format(__T("图片/人/c%05d.txt"),i);
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
		str.Format(__T("图片/景/c%05d.bmp"),i);
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
		str.Format(__T("图片/兽/c%05d.bmp"),i);
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
		__T("图片/人/c00001.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
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
