// Delete_Player_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AI Final Porject.h"
#include "Delete_Player_Dlg.h"
#include "afxdialogex.h"


// Delete_Player_Dlg 对话框

IMPLEMENT_DYNAMIC(Delete_Player_Dlg, CDialogEx)

Delete_Player_Dlg::Delete_Player_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Delete_Player_Dlg::IDD, pParent)
{

}

Delete_Player_Dlg::~Delete_Player_Dlg()
{
}

void Delete_Player_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, attacker_team_list_);
	DDX_Control(pDX, IDC_LIST2, defender_team_list_);
}

BOOL Delete_Player_Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
    DWORD dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
    SetWindowLong( pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);
	CListCtrl* pmyListCtr2 = (CListCtrl*)GetDlgItem(IDC_LIST2);
    DWORD dwStyle2 = GetWindowLong(pmyListCtr2->m_hWnd, GWL_STYLE);
    SetWindowLong( pmyListCtr2->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);

	attacker_team_list_.InsertColumn(0,_T("potision"),LVCFMT_CENTER,70);
	attacker_team_list_.InsertColumn(1,_T("value"),LVCFMT_LEFT,100);
	defender_team_list_.InsertColumn(0,_T("potision"),LVCFMT_CENTER,70);
	defender_team_list_.InsertColumn(1,_T("value"),LVCFMT_LEFT,100);
	return TRUE;
}





BEGIN_MESSAGE_MAP(Delete_Player_Dlg, CDialogEx)
END_MESSAGE_MAP()


// Delete_Player_Dlg 消息处理程序
