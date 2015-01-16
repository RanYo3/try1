
// ran2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ran2.h"
#include "ran2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cran2Dlg dialog



Cran2Dlg::Cran2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cran2Dlg::IDD, pParent)
	, m_color(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cran2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO2, m_color);
	DDV_MaxChars(pDX, m_color, 10);
}

BEGIN_MESSAGE_MAP(Cran2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_CBN_SELCHANGE(IDC_COMBOBOXEX1, &Cran2Dlg::OnCbnSelchangeComboboxex1)
ON_CBN_SELCHANGE(IDC_COMBO2, &Cran2Dlg::OnCbnSelchangeCombo2)
ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Cran2Dlg message handlers

BOOL Cran2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_colorsDict[CString("White")]  = White;
	m_colorsDict[CString("Black")]  = Black;
	m_colorsDict[CString("Blue")]   = Blue;
	m_colorsDict[CString("Green")]  = Green;
	m_colorsDict[CString("Red")]    = Red;
	m_colorsDict[CString("Yellow")] = Yellow;

	m_color = "White";
	UpdateData(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cran2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cran2Dlg::OnPaint()
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
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cran2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cran2Dlg::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	m_background.DeleteObject();

	eColor newColor = m_colorsDict[m_color];
	switch (newColor)
	{
	case White:
		m_background.CreateSolidBrush(RGB(255, 255, 255));
		break;
	case Black:
		m_background.CreateSolidBrush(RGB(0, 0, 0));
		break;
	case Blue:
		m_background.CreateSolidBrush(RGB(0, 0, 255));
		break;
	case Green:
		m_background.CreateSolidBrush(RGB(0, 255, 0));
		break;
	case Red:
		m_background.CreateSolidBrush(RGB(255, 0, 0));
		break;
	case Yellow:
		m_background.CreateSolidBrush(RGB(255, 255, 0));
		break;
	default:
		break;
	}

	Invalidate();
}


HBRUSH Cran2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return m_background;
}
