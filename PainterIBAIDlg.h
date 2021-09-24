//Develop by 
// Avichai Iluz 208626234
// Idan Buller 
// PainterIBAIDlg.h : header file
//

#pragma once

#include"Figure.h"
#include "LineP.h"
#include "RectangleP.h"
#include "EllipseP.h"
#include "CircleP.h"
#include "SquareP.h"

// CPainterIBAIDlg dialog
class CPainterIBAIDlg : public CDialogEx
{
// Construction
public:
	CPainterIBAIDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAINTERIBAI_DIALOG };
#endif
	CPoint start, end;
	bool isPressed = false;
	bool CheckUndo = false;
	bool clear_btn_activated = false;
	CTypedPtrArray< CObArray, Figure*> figs;
	CTypedPtrArray< CObArray, Figure*> temp_figs; // Save figs[] after "Clear all" Btn clicked to restore figs[] if we press on "undo" Btn
	int KindOfShape = 1; //Rectangle - defult

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedButton5();
};