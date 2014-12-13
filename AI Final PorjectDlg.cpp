
// AI Final PorjectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AI Final Porject.h"
#include "AI Final PorjectDlg.h"
#include "afxdialogex.h"
#include "Add_Player_Dlg.h"
#include "Delete_Player_Dlg.h"
#include "Add_Tactics_Dlg.h"
#include "Delete_Tactics_Dlg.h"
#include "network.h"
#include "string.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

neuronsnetwork PGmind;
neuronsnetwork SGmind;
neuronsnetwork SFmind;
neuronsnetwork PFmind;
neuronsnetwork Cmind;
int attackerscore = 0; //score
int defensescore = 0;





// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CAIFinalPorjectDlg 对话框



CAIFinalPorjectDlg::CAIFinalPorjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAIFinalPorjectDlg::IDD, pParent)
	, cy_(_T(""))
	, cx_(_T(""))
	, pfx_(_T(""))
	, sfx_(_T(""))
	, sfy_(_T(""))
	, pgx_(_T(""))
	, pgy_(_T(""))
	, sgy_(_T(""))
	, sgx_(_T(""))
	, pfy_(_T(""))
	, Chold_(FALSE)
	, PFhold_(FALSE)
	, SFhold_(FALSE)
	, SGhold_(FALSE)
	, time_(_T(""))
	, defenderx_(_T(""))
	, defendery_(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAIFinalPorjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT10, SGy_);
	//  DDX_Text(pDX, IDC_EDIT9, SGx_);
	//  DDX_Text(pDX, IDC_EDIT17, method_);
	//  DDX_Control(pDX, IDC_EDIT17, method_);
	//  DDX_Text(pDX, IDC_EDIT17, method_);
	//  DDX_Text(pDX, IDC_EDIT1, ballx_);
	//  DDX_Text(pDX, IDC_EDIT2, bally_);
	//  DDX_Control(pDX, IDC_EDIT3, cx_);
	DDX_Text(pDX, IDC_EDIT4, cy_);
	DDX_Text(pDX, IDC_EDIT3, cx_);
	DDX_Text(pDX, IDC_EDIT5, pfx_);
	//  DDX_Text(pDX, IDC_EDIT6, pf_);
	DDX_Text(pDX, IDC_EDIT7, sfx_);
	DDX_Text(pDX, IDC_EDIT8, sfy_);
	DDX_Text(pDX, IDC_EDIT11, pgx_);
	//  DDX_Control(pDX, IDC_EDIT12, pgy_);
	DDX_Text(pDX, IDC_EDIT12, pgy_);
	DDX_Text(pDX, IDC_EDIT10, sgy_);
	DDX_Text(pDX, IDC_EDIT9, sgx_);
	DDX_Text(pDX, IDC_EDIT6, pfy_);
	DDX_Check(pDX, IDC_CHECK3, Chold_);
	DDX_Check(pDX, IDC_CHECK2, PFhold_);
	DDX_Check(pDX, IDC_CHECK1, SFhold_);
	DDX_Check(pDX, IDC_CHECK4, SGhold_);
	//  DDX_Check(pDX, IDC_CHECK5, PGhold_);
	DDX_Control(pDX, IDC_CHECK5, PGhold_);
	DDX_Text(pDX, IDC_EDIT13, time_);
	//  DDX_Text(pDX, IDC_EDIT2, denfendery_);
	DDX_Text(pDX, IDC_EDIT1, defenderx_);
	DDX_Text(pDX, IDC_EDIT2, defendery_);
}

BEGIN_MESSAGE_MAP(CAIFinalPorjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_PLAYER_ADD, addplayerfunc)
	ON_COMMAND(ID_PLAYER_DELETE, deleteplayerfunc)
	ON_COMMAND(ID_TACTICS_ADD, addtacticsfunc)
	ON_COMMAND(ID_TACTICS_DELETE, deletetaticsfunc)
	ON_BN_CLICKED(IDC_BUTTON2, &CAIFinalPorjectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAIFinalPorjectDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAIFinalPorjectDlg 消息处理程序

BOOL CAIFinalPorjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	CString strText = _T("");
	strText.Format(_T("%d"), attackerscore);
	SetDlgItemText(IDC_EDIT14, strText);

	CString strText1 = _T("");
	strText1.Format(_T("%d"), defensescore);
	SetDlgItemText(IDC_EDIT15, strText1);

	int SGx = rand() % (4);
	int SGy = rand() % (4);
	int defenderx = rand() % (4);
	int defendery = rand() % (4);


	CString strText2 = _T("");
	strText2.Format(_T("%d"), SGx);
	SetDlgItemText(IDC_EDIT9, strText2);

	CString strText3 = _T("");
	strText3.Format(_T("%d"), SGy);
	SetDlgItemText(IDC_EDIT10, strText3);

	CString strText4 = _T("");
	strText4.Format(_T("%d"), defenderx);
	SetDlgItemText(IDC_EDIT1, strText4);

	CString strText5 = _T("");
	strText5.Format(_T("%d"), defendery);
	SetDlgItemText(IDC_EDIT2, strText5);

	int time = rand() % (18) + 1;

	CString strText6 = _T("");
	strText6.Format(_T("%d"), time);
	SetDlgItemText(IDC_EDIT13, strText6);





	PGhold_.SetCheck(true);
	UpdateData();


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAIFinalPorjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAIFinalPorjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void CAIFinalPorjectDlg::addplayerfunc()
{
	Add_Player_Dlg addplyer; 
	addplyer.DoModal();
}


void CAIFinalPorjectDlg::deleteplayerfunc()
{
	Delete_Player_Dlg deleteplyer; 
	deleteplyer.DoModal();
}

void CAIFinalPorjectDlg::addtacticsfunc()
{
	Add_Tactics_Dlg deleteplyer; 
	deleteplyer.DoModal();
}

void CAIFinalPorjectDlg::deletetaticsfunc()
{
	Delete_Tactics_Dlg deleteplyer; 
	deleteplyer.DoModal();
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAIFinalPorjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAIFinalPorjectDlg::OnBnClickedButton2()
{
	//TODO: 在此添加控件通知处理程序代码
	//PGmind.run();
	//SGmind.run();
	//SFmind.run();
	//PFmind.run();
	//Cmind.run();
	SGmind.error = 0;	
	CString strText7 = _T("");
	strText7.Format(_T("%d"), attackerscore);
	SetDlgItemText(IDC_EDIT14, strText7);

	CString strText1 = _T("");
	strText1.Format(_T("%d"), defensescore);
	SetDlgItemText(IDC_EDIT15, strText1);


	for(int test=0;test<300;test++)
	{



		int SGx = rand() % (4);
		int SGy = rand() % (4);
		int defenderx = rand() % (4);
		int defendery = rand() % (4);
		int time = rand() % (18) + 1;







		SGmind.readfile("ttttt.txt");
		SGmind.train();

		//SGmind.inputlayer_.PGx = int(pgx_.GetString());
		//SGmind.inputlayer_.PGy = int(pgy_.GetString());
		//SGmind.inputlayer_.SFx = int(sfx_.GetString());
		//SGmind.inputlayer_.SFy = int(sfy_.GetString());	
		//SGmind.inputlayer_.PFx = int(pfx_.GetString());
		//SGmind.inputlayer_.PFy = int(pfy_.GetString());
		//SGmind.inputlayer_.Cx = int(cx_.GetString());
		//SGmind.inputlayer_.Cy = int(cy_.GetString());




		SGmind.inputlayer_.ownx = SGx;
		SGmind.inputlayer_.owny = SGy;
		SGmind.inputlayer_.time = time;
		SGmind.inputlayer_.defenderx = defenderx;
		SGmind.inputlayer_.defendery = defendery;



		CString strText2 = _T("");
		strText2.Format(_T("%d"), SGx);
		SetDlgItemText(IDC_EDIT9, strText2);

		CString strText3 = _T("");
		strText3.Format(_T("%d"), SGy);
		SetDlgItemText(IDC_EDIT10, strText3);

		CString strText4 = _T("");
		strText4.Format(_T("%d"), defenderx);
		SetDlgItemText(IDC_EDIT1, strText4);

		CString strText5 = _T("");
		strText5.Format(_T("%d"), defendery);
		SetDlgItemText(IDC_EDIT2, strText5);



		CString strText6 = _T("");
		strText6.Format(_T("%d"), time);
		SetDlgItemText(IDC_EDIT13, strText6);


	/*	SGmind.inputlayer_.ownx = _ttoi(sgx_);
		SGmind.inputlayer_.owny = _ttoi(sgy_);
		SGmind.inputlayer_.time = _ttoi(time_);
		SGmind.inputlayer_.defenderx = _ttoi(defenderx_);
		SGmind.inputlayer_.defendery = _ttoi(defendery_);*/

		SGmind.inputlayer_.playervalue = 60;

	int jkl=0;
		int method = SGmind.run((4 * SGmind.inputlayer_.ownx + SGmind.inputlayer_.owny),(4 * SGmind.inputlayer_.defenderx + SGmind.inputlayer_.defendery),SGmind.inputlayer_.time, SGmind.inputlayer_.playervalue);
		CString strText = _T("");
		strText.Format(_T("%d"), method);
		SetDlgItemText(IDC_EDIT17, strText);
		if (method == 1)
		{
			if ((SGmind.inputlayer_.ownx - 2)*(SGmind.inputlayer_.ownx - 2)+ (SGmind.inputlayer_.owny -3)*(SGmind.inputlayer_.owny -3)>4)
			{
				attackerscore = attackerscore + 3;
			}
			else
				attackerscore = attackerscore + 2;

		}
		else
		{
			 jkl  = jkl +1;
		}
	}	
	CString strText = _T("");
	strText.Format(_T("%d"), attackerscore);
	SetDlgItemText(IDC_EDIT14, strText);

	CString strText12 = _T("");
	strText12.Format(_T("%d"), SGmind.error);
	SetDlgItemText(IDC_EDIT7, strText12);
}


void CAIFinalPorjectDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

