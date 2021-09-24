
// PainterIBAIDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "PainterIBAI.h"
#include "PainterIBAIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPainterIBAIDlg dialog
// כאן נראה משתנים שמשויכים לפקדים מסוימים ואת האתחול שלהם
// מכיוון שאין כאלו אז הפונקציה ריקה
// Add variable will show here:
CPainterIBAIDlg::CPainterIBAIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAINTERIBAI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPainterIBAIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPainterIBAIDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDOK, &CPainterIBAIDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CPainterIBAIDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPainterIBAIDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CPainterIBAIDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CPainterIBAIDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_RADIO1, &CPainterIBAIDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CPainterIBAIDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CPainterIBAIDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CPainterIBAIDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CPainterIBAIDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_BUTTON5, &CPainterIBAIDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


//Develop by 
// Avichai Iluz 208626234
// Idan Buller 

BOOL CPainterIBAIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	CheckRadioButton(IDC_RADIO1, IDC_RADIO3, IDC_RADIO1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPainterIBAIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else if (CheckUndo == true)
	{
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < (figs.GetSize()) - 1; i++)
			figs[i]->Draw(&dc);
		//CheckUndo = false;
		CDialogEx::OnPaint();
	}
	else {
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < figs.GetSize(); i++)
			figs[i]->Draw(&dc);
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPainterIBAIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPainterIBAIDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	start = point;
	isPressed = true;
	if (CheckUndo)
	{
		if (figs.IsEmpty()) {}
		else
		{
			figs.RemoveAt((figs.GetSize() - 1));
		}
		CheckUndo = false;
	}

	switch (KindOfShape)
	{
		case 1:
			figs.Add(new RectangleP(start, start));
			break;
		case 2:
			figs.Add(new EllipseP(start, start));
			break;

		case 3:
			figs.Add(new LineP(start, start));
			break;
		case 4:
			figs.Add(new CircleP(start, start));
			break;
		case 5:
			figs.Add(new SquareP(start, start));
			break;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CPainterIBAIDlg::OnLButtonUp(UINT nFlags, CPoint point)
{

	if (isPressed)
	{
		end = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate();
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}

void CPainterIBAIDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		end = point;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CPainterIBAIDlg::OnBnClickedOk() // Exit btn
{
	CDialogEx::OnOK();
}

void CPainterIBAIDlg::OnBnClickedRadio1() // Rectangle -- default figure
{
	KindOfShape = 1;
}


void CPainterIBAIDlg::OnBnClickedRadio2() // Ellipse
{
	KindOfShape = 2;
}

void CPainterIBAIDlg::OnBnClickedRadio3() // Line
{
	KindOfShape = 3;
}

void CPainterIBAIDlg::OnBnClickedRadio4() // Circle
{
	KindOfShape = 4;
}

void CPainterIBAIDlg::OnBnClickedRadio5() // Square
{
	KindOfShape = 5;
}

void CPainterIBAIDlg::OnBnClickedButton1() // Save Btn
{
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}

void CPainterIBAIDlg::OnBnClickedButton2() // Load Btn
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName();
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}

void CPainterIBAIDlg::OnBnClickedButton3() // Undo Btn
{
	if (clear_btn_activated) // if we clear all screen and want to undo it
	{
		for (int i = 0; i < (temp_figs.GetSize()); i++) // restore figs[]
			figs.Add(temp_figs[i]);
		temp_figs.RemoveAll(); // delete temp_figs[]
		clear_btn_activated = false; // clear all btn not activated
		Invalidate();
		return;
	}

	CheckUndo = true;
	Invalidate();
}

void CPainterIBAIDlg::OnBnClickedButton4() // Redo Btn
{
	CheckUndo = false;
	Invalidate();
}

void CPainterIBAIDlg::OnBnClickedButton5() // Clear All Btn
{
	clear_btn_activated = true;
	for (int i = 0; i < (figs.GetSize()); i++) // save figs[] in temp_figs[]
		temp_figs.Add(figs[i]);
	figs.RemoveAll(); // delete figs[]
	Invalidate();
}
