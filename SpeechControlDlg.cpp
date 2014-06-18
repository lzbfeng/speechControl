// SpeechControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SpeechControl.h"
#include "SpeechControlDlg.h"
#define MAX_LEN 100000
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CBkDialogST
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CBkDialogST(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CBkDialogST::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CBkDialogST)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	
	//}}AFX_MSG_MAP
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpeechControlDlg dialog

CSpeechControlDlg::CSpeechControlDlg(CWnd* pParent /*=NULL*/)
	: CBkDialogST(CSpeechControlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpeechControlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	CString module_path;
	char module[MAX_LEN];
	::GetModuleFileName(AfxGetInstanceHandle(),module,MAX_LEN);
	module_path=module;
	char a='\\';
	module_path=module_path.Left(module_path.ReverseFind(a));

	ini_path=module_path+"\\Config.ini";
	yufaku_path=module_path+"\\action.xml";
	data_path=module_path+"\\data.txt";
// 	ini_path="C:\\Users\\Administrator\\Desktop\\SpeechControl\\Config.ini";
// 	yufaku_path="C:\\Users\\Administrator\\Desktop\\SpeechControl\\action.XmL";
// 	data_path="C:\\Users\\Administrator\\Desktop\\SpeechControl\\data.txt";
	flag_xieru=false;
}

void CSpeechControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CBkDialogST::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpeechControlDlg)
	DDX_Control(pDX, IDC_ADDCONFIG, m_add);
	DDX_Control(pDX, IDC_SPEAK, m_speak);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSpeechControlDlg, CBkDialogST)
	//{{AFX_MSG_MAP(CSpeechControlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SPEAK, OnSpeak)
	ON_BN_CLICKED(IDC_ADDCONFIG, OnAddConfig)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SUCCEED_ADDGOODS,OnSucceedAddGoods)
	ON_MESSAGE(WM_TINGDATA,OnTingData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpeechControlDlg message handlers

BOOL CSpeechControlDlg::OnInitDialog()
{
	CBkDialogST::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	SetBitmap(IDB_SKY);
	//m_btnBack.SetSound(MAKEINTRESOURCE(IDR_WAVHOVER), ::GetModuleHandle(NULL));
	m_speak.SetSound(MAKEINTRESOURCE(IDR_WAVE1),::GetModuleHandle(NULL));
	m_speak.DrawTransparent();
	m_speak.SetIcon(IDI_ICON2, (int)BTNST_AUTO_DARKER);
	m_add.SetSound(MAKEINTRESOURCE(IDR_WAVE1),::GetModuleHandle(NULL));
	m_add.DrawTransparent();
	m_add.SetIcon(IDI_ICON5, (int)BTNST_AUTO_DARKER);
	// TODO: Add extra initialization here

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSpeechControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CBkDialogST::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSpeechControlDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CBkDialogST::OnPaint();
	}
	if(flag_xieru)
	{
		CString showdata;
		showdata.Format("已经将“%s”的命令“%s”写入到data.txt文件中。",inigoods,iniorder);
		
		CRect rect;
		GetClientRect(&rect);
		CClientDC dc(this);
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(rect.left,rect.bottom-20,showdata);
	}

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSpeechControlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSpeechControlDlg::OnSpeak() 
{
	// TODO: Add your control notification handler code here
// 	DWORD a;
// 	GetExitCodeThread(Jianting1,&a);
// 	if(STILL_ACTIVE!=a)
// 	{
	info=new JIANTING;
	info->hWnd=m_hWnd;
	info->yufaku=yufaku_path;
	info->Msg=WM_TINGDATA;
	CreateSRThread(Jianting1,info);
/*	}*/	
}

LRESULT CSpeechControlDlg::OnTingData(WPARAM wParam,LPARAM lParam)
{
	inigoods=*(CString*)wParam;

	//读取配置文件Config.ini

	CString def="def";
	char buf[100];
	GetPrivateProfileString("goods",inigoods,def,buf,100,ini_path);
	if((iniorder=buf)!=def)
	{
		//MessageBox(order);	
		flag_xieru=true;

		CRect rect;
		GetClientRect(&rect);
		

		CRect rect1(rect.left,rect.bottom-20,rect.right,rect.bottom);
		InvalidateRect(rect1);
		
		//把读取的数据存入data.txt中
		CFile file;
		if(!file.Open(data_path,/*CFile::modeCreate|*/CFile::modeWrite|CFile::modeRead))
		{
			MessageBox("写入data.txt数据失败！");
		}
		LONG a=0;
		a=file.GetLength();
		file.Seek(a,CFile::current);
		file.Write(iniorder,iniorder.GetLength());
		file.Flush();
		file.Close();
	}
	else
	{
		return -1;
	}
	
	return -1;
}


void CSpeechControlDlg::OnAddConfig() 
{
	// TODO: Add your control notification handler code here
	CAddConfig dlg;
	dlg.ini_path=ini_path;
	dlg.yufaku_path=yufaku_path;
	dlg.SRThread=Jianting1;
	dlg.hWnd=m_hWnd;
	dlg.DoModal();
}


LRESULT CSpeechControlDlg::OnSucceedAddGoods(WPARAM wParam,LPARAM lParam)
{
// 	if(Jianting1!=NULL)
// 	{
// 		CloseHandle(Jianting1);
// 		CreateSRThread(Jianting1,info);
// 	}
	return -1;
}