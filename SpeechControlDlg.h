// SpeechControlDlg.h : header file
//

#if !defined(AFX_SPEECHCONTROLDLG_H__3D8E6C5F_8F20_4026_B970_1335D542CB12__INCLUDED_)
#define AFX_SPEECHCONTROLDLG_H__3D8E6C5F_8F20_4026_B970_1335D542CB12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSpeechControlDlg dialog
#include "BkDialogST.h"
#include "BtnST.h"

#define SpeechSDK
#include "CSelfUse.h"
#include "AddConfig.h"

#define WM_TINGDATA WM_USER+2
class CSpeechControlDlg : public CBkDialogST
{
// Construction
public:
	CSpeechControlDlg(CWnd* pParent = NULL);	// standard constructor
	afx_msg LRESULT OnTingData(WPARAM wParam,LPARAM lParam);
	CString ini_path;
	CString yufaku_path;
	CString data_path;
	CButtonST	m_add;
	CString iniorder;
	CString inigoods;
	bool flag_xieru;
	JIANTING* info;
// Dialog Data
	//{{AFX_DATA(CSpeechControlDlg)
	enum { IDD = IDD_SPEECHCONTROL_DIALOG };
	
	CButtonST	m_speak;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpeechControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
// 	void FileRead(CFile &file,CString &str);
// 	void WriteXML(CString path,CString goods);
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSpeechControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSpeak();
	afx_msg void OnAddConfig();
	//}}AFX_MSG
	
	afx_msg LRESULT OnSucceedAddGoods(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	HANDLE Jianting1;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPEECHCONTROLDLG_H__3D8E6C5F_8F20_4026_B970_1335D542CB12__INCLUDED_)
