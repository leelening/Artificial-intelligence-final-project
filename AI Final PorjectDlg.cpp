
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


neuronsnetwork PGmind;
neuronsnetwork SGmind;
neuronsnetwork SFmind;
neuronsnetwork PFmind;
neuronsnetwork Cmind;




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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAIFinalPorjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
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
	// TODO: 在此添加控件通知处理程序代码
	//PGmind.run();
	//SGmind.run();
	//SFmind.run();
	//PFmind.run();
	//Cmind.run();
	//SGmind.readfile("tain.txt");
}
