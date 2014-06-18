// SpeechControl.h : main header file for the SPEECHCONTROL application
//

#if !defined(AFX_SPEECHCONTROL_H__C81FFD5D_B903_43D3_B8E3_55C45233D2AD__INCLUDED_)
#define AFX_SPEECHCONTROL_H__C81FFD5D_B903_43D3_B8E3_55C45233D2AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpeechControlApp:
// See SpeechControl.cpp for the implementation of this class
//

class CSpeechControlApp : public CWinApp
{
public:
	CSpeechControlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpeechControlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSpeechControlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPEECHCONTROL_H__C81FFD5D_B903_43D3_B8E3_55C45233D2AD__INCLUDED_)
