
// ran2Dlg.h : header file
//

#pragma once

#include <map>

enum eColor { White, Black, Blue, Green, Red, Yellow };

// Cran2Dlg dialog
class Cran2Dlg : public CDialogEx
{
// Construction
public:
	Cran2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_RAN2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// Color of background
	CBrush m_background;
	CString m_color;
	std::map<CString, eColor> m_colorsDict;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
