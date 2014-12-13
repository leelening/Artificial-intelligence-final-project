// Add_Tactics_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AI Final Porject.h"
#include "Add_Tactics_Dlg.h"
#include "afxdialogex.h"


// Add_Tactics_Dlg 对话框


int tactics_value = 0;

IMPLEMENT_DYNAMIC(Add_Tactics_Dlg, CDialogEx)

Add_Tactics_Dlg::Add_Tactics_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Add_Tactics_Dlg::IDD, pParent)
	, New_Tactic_(_T(""))
{

}

Add_Tactics_Dlg::~Add_Tactics_Dlg()
{
}

void Add_Tactics_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, New_Tactic_);
	DDX_Control(pDX, IDC_LIST1, tacticslist_);
}


BEGIN_MESSAGE_MAP(Add_Tactics_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Add_Tactics_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Add_Tactics_Dlg 消息处理程序


void Add_Tactics_Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	CString new_tactic;
	new_tactic = New_Tactic_;

	CString strText = _T("");
	strText.Format(_T("%d"), tactics_value);
	CString str1;
	tacticslist_.InsertItem(0,strText);//插入行
	tacticslist_.SetItemText(0,1,new_tactic);
}
BOOL Add_Tactics_Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
    DWORD dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
    SetWindowLong( pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);

	tacticslist_.InsertColumn(0,_T("value"),LVCFMT_CENTER,70);
	tacticslist_.InsertColumn(1,_T("tactics"),LVCFMT_LEFT,100);
	return TRUE;
}
