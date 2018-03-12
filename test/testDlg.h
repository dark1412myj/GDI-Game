// testDlg.h : 头文件
//

#pragma once
#include "stdafx.h"
#include "Thing.h"
#include "World.h"
#include "resource.h" 
#include "ImageInfo.h"


// CtestDlg 对话框
class CtestDlg : public CDialog
{
	// 构造
public:
	static HANDLE m_out;

	CThing* m_pThing;
	static bool theMap[641][481];
	static CImageInfo iBitmap[800];
	static HBITMAP hBitmap[800];
	static int xBitmap[800];
	static int yBitmap[800];
	static CImageInfo iBackGround[97];
	static HBITMAP hBackGround[97];
	CWorld* world;
	static CImageInfo iAnimal[2800];
	static HBITMAP hAnimal[2800];
	static HBITMAP hBg;
	CtestDlg(CWnd* pParent = NULL);	// 标准构造函数

	// 对话框数据
	enum { IDD = IDD_TEST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


	// 实现
protected:
	HICON m_hIcon;
	int j;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_posX;
	int m_posY;
	int m_targetX;
	int m_targetY;
	int m_last;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	static void TransparentBlt( HDC hDesDC,	
		int iDesX, int iDesY,
		int iWide, int iHigh,
		HDC hSurDC,
		int iSurX,int iSurY,
		UINT iMaskCol
		);
	afx_msg void OnBnClickedTouming();
	static void DrawImg(HDC hdc, HBITMAP hBitmap);
	static void DrawNBGImg(HDC hdc, HBITMAP hBitmap,int x,int y);
	afx_msg void OnBnClickedWordmode();
	afx_msg void OnBnClickedScence();
	afx_msg void OnBnClickedAnimal();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedPeoplechange();
};

//HBITMAP CtestDlg::hBitmap[]={0};
//HBITMAP CtestDlg::hBackGround[]={0};