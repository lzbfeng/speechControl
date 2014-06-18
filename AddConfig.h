#if !defined(AFX_ADDCONFIG_H__CFCABE5F_315A_4502_8673_F03B41C219D8__INCLUDED_)
#define AFX_ADDCONFIG_H__CFCABE5F_315A_4502_8673_F03B41C219D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddConfig.h : header file
//
#include "BtnST.h"
#include "BkDialogST.h"
#ifndef SpeechSDK
#define SpeechSDK
#endif
#include "CSelfUse.h"
#define WM_SUCCEED_ADDGOODS WM_USER+102
/////////////////////////////////////////////////////////////////////////////
// CAddConfig dialog

class CAddConfig : public CBkDialogST
{
// Construction
public:
	CAddConfig(CWnd* pParent = NULL);   // standard constructor
	CString ini_path;
	CString yufaku_path;
	CButtonST	m_delete;
	CButtonST	m_add;
	CButtonST	m_close;
	HANDLE SRThread;
	HWND hWnd;
// Dialog Data
	//{{AFX_DATA(CAddConfig)
	enum { IDD = IDD_ADDCONFIG };
	CString	m_goods;
	CString	m_order;
	CString	m_goodslist;
	CString	m_delgoods;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddConfig)
	afx_msg void OnAddGoods();
	afx_msg void OnDelete();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCONFIG_H__CFCABE5F_315A_4502_8673_F03B41C219D8__INCLUDED_)
