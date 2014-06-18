// AddConfig.cpp : implementation file
//

#include "stdafx.h"
#include "SpeechControl.h"
#include "AddConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddConfig dialog


CAddConfig::CAddConfig(CWnd* pParent /*=NULL*/)
	: CBkDialogST(CAddConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddConfig)
	m_goods = _T("");
	m_order = _T("");
	m_delgoods = _T("");
	//}}AFX_DATA_INIT
}


void CAddConfig::DoDataExchange(CDataExchange* pDX)
{
	CBkDialogST::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddConfig)
	DDX_Control(pDX, IDCANCEL, m_close);
	DDX_Text(pDX, IDC_GOODS, m_goods);
	DDX_Text(pDX, IDC_ORDER, m_order);
	DDX_Text(pDX, IDC_DELGOODS, m_delgoods);
	DDX_Control(pDX, IDC_DELETE, m_delete);
	DDX_Control(pDX, IDC_ADD, m_add);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddConfig, CBkDialogST)
	//{{AFX_MSG_MAP(CAddConfig)
	ON_BN_CLICKED(IDC_ADD, OnAddGoods)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddConfig message handlers

void CAddConfig::OnAddGoods() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if (m_goods=="")
	{
		MessageBox("请输入要添加的物品！");
	}
	else if (m_order=="")
	{
		MessageBox("请输入此物品的命令！");
	}
	else
	{
		CFile file;
		CString str;
		file.Open(ini_path,CFile::modeRead);
		FileRead(file,str);
		file.Close();
		if (str.Find(m_goods)!=-1)//如果要添加的物品以前已经有了
		{
			if (IDCANCEL==AfxMessageBox("此物品已经存在！是否确认替换原来的命令？",MB_OKCANCEL))
			{
				m_goods="";
				m_order="";
				UpdateData(false);
				return ;
			}
			else
			{
				CString order;
				CString def="def";
				char buf[100];
				GetPrivateProfileString("goods",m_goods,def,buf,100,ini_path);
				if((order=buf)==def)
				{
					MessageBox("读取配置文件失败！");
					return ;
				}
				else if(order==m_order)
				{
					WritePrivateProfileString("goods",m_goods,m_order,ini_path);
					WriteXML(yufaku_path,m_goods);
					MessageBox("更改成功！");
					return ;
				}
			}
		}
		if(str.Find(m_order)!=-1)
		{
			m_order="";
			MessageBox("此命令已经存在！请设置其它命令。");
			UpdateData(false);
		}
		else
		{
			WritePrivateProfileString("goods",m_goods,m_order,ini_path);
			WriteXML(yufaku_path,m_goods);
			if (SRThread!=NULL)
			{
				::SendMessage(hWnd,WM_SUCCEED_ADDGOODS,NULL,NULL);
			}
			MessageBox("添加成功！");
		}
		
	}
	
}

void CAddConfig::OnDelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if (m_delgoods=="")
	{
		MessageBox("请输入要删除的命令！");
	}
	else
	{
		CFile file;
		CString str;
		file.Open(ini_path,CFile::modeRead);
		FileRead(file,str);
		file.Close();
		if (str.Find(m_goods)==-1)											//如果要删除的物品根本就没有
		{
			m_delgoods="";
			MessageBox("此物品不存在！");
			UpdateData(false);
		}
		else
		{
			WritePrivateProfileString("goods",m_delgoods,NULL,ini_path);
			m_delgoods="";
			MessageBox("删除物品成功！");
			UpdateData(false);
		}
		
	}
	
}

void CAddConfig::OnOK() 
{
	// TODO: Add extra validation here
	
	//CBkDialogST::OnOK();
}

BOOL CAddConfig::OnInitDialog() 
{
	CBkDialogST::OnInitDialog();
	
	// TODO: Add extra initialization here
	
// 	CRect rect;
// 	GetClientRect(&rect);
// 	CString str;
// 	str.Format("%d,%d",rect.Width(),rect.Height());
/*	MessageBox(str);*/
	SetBitmap(IDB_SKY);
	m_add.DrawTransparent();
	m_add.SetIcon(IDI_ICON1, (int)BTNST_AUTO_DARKER);
	m_add.SetSound(MAKEINTRESOURCE(IDR_WAVE1),::GetModuleHandle(NULL));
	m_delete.DrawTransparent();
	m_delete.SetIcon(IDI_ICON4,(int)BTNST_AUTO_DARKER);
	m_delete.SetSound(MAKEINTRESOURCE(IDR_WAVE1),::GetModuleHandle(NULL));
	m_close.DrawTransparent();
	m_close.SetIcon(IDI_ICON6,(int)BTNST_AUTO_GRAY);
	m_close.SetSound(MAKEINTRESOURCE(IDR_WAVE1),::GetModuleHandle(NULL));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CAddConfig::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CBkDialogST::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here

	if (pWnd->GetDlgCtrlID()!=IDC_GOODS&&
		pWnd->GetDlgCtrlID()!=IDC_ORDER&&
		pWnd->GetDlgCtrlID()!=IDC_DELGOODS)
	{
		CRect rcCtrl;     
		pWnd->GetWindowRect( &rcCtrl ); //获取控件位置     
		ScreenToClient( &rcCtrl ); //转换到对话框     
		
		//获取ClientDC     
		CDC *pBkDC = GetDC();      
		
		//拷贝背景     
		pDC->BitBlt(0, 0, rcCtrl.Width(), rcCtrl.Height(),     
			pBkDC, rcCtrl.left, rcCtrl.top, SRCCOPY);      
		
		//清理工作     
		ReleaseDC( pBkDC ); //释放ClientDC     
		
		//添加其他代码     
		//     
		
		pDC->SetBkMode(TRANSPARENT); //背景透明模式     
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH); //  
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
