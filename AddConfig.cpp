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
		MessageBox("������Ҫ��ӵ���Ʒ��");
	}
	else if (m_order=="")
	{
		MessageBox("���������Ʒ�����");
	}
	else
	{
		CFile file;
		CString str;
		file.Open(ini_path,CFile::modeRead);
		FileRead(file,str);
		file.Close();
		if (str.Find(m_goods)!=-1)//���Ҫ��ӵ���Ʒ��ǰ�Ѿ�����
		{
			if (IDCANCEL==AfxMessageBox("����Ʒ�Ѿ����ڣ��Ƿ�ȷ���滻ԭ�������",MB_OKCANCEL))
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
					MessageBox("��ȡ�����ļ�ʧ�ܣ�");
					return ;
				}
				else if(order==m_order)
				{
					WritePrivateProfileString("goods",m_goods,m_order,ini_path);
					WriteXML(yufaku_path,m_goods);
					MessageBox("���ĳɹ���");
					return ;
				}
			}
		}
		if(str.Find(m_order)!=-1)
		{
			m_order="";
			MessageBox("�������Ѿ����ڣ��������������");
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
			MessageBox("��ӳɹ���");
		}
		
	}
	
}

void CAddConfig::OnDelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if (m_delgoods=="")
	{
		MessageBox("������Ҫɾ�������");
	}
	else
	{
		CFile file;
		CString str;
		file.Open(ini_path,CFile::modeRead);
		FileRead(file,str);
		file.Close();
		if (str.Find(m_goods)==-1)											//���Ҫɾ������Ʒ������û��
		{
			m_delgoods="";
			MessageBox("����Ʒ�����ڣ�");
			UpdateData(false);
		}
		else
		{
			WritePrivateProfileString("goods",m_delgoods,NULL,ini_path);
			m_delgoods="";
			MessageBox("ɾ����Ʒ�ɹ���");
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
		pWnd->GetWindowRect( &rcCtrl ); //��ȡ�ؼ�λ��     
		ScreenToClient( &rcCtrl ); //ת�����Ի���     
		
		//��ȡClientDC     
		CDC *pBkDC = GetDC();      
		
		//��������     
		pDC->BitBlt(0, 0, rcCtrl.Width(), rcCtrl.Height(),     
			pBkDC, rcCtrl.left, rcCtrl.top, SRCCOPY);      
		
		//������     
		ReleaseDC( pBkDC ); //�ͷ�ClientDC     
		
		//�����������     
		//     
		
		pDC->SetBkMode(TRANSPARENT); //����͸��ģʽ     
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH); //  
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
