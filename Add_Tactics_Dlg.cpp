// Add_Tactics_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AI Final Porject.h"
#include "Add_Tactics_Dlg.h"
#include "afxdialogex.h"


// Add_Tactics_Dlg 对话框

IMPLEMENT_DYNAMIC(Add_Tactics_Dlg, CDialogEx)

Add_Tactics_Dlg::Add_Tactics_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Add_Tactics_Dlg::IDD, pParent)
{

}

Add_Tactics_Dlg::~Add_Tactics_Dlg()
{
}

void Add_Tactics_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1,m_list);
}


BEGIN_MESSAGE_MAP(Add_Tactics_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Add_Tactics_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Add_Tactics_Dlg 消息处理程序


void Add_Tactics_Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	CEdit* c=(CEdit*)GetDlgItem(IDC_EDIT1);
	CString str1;
	c->GetWindowText(str1);
	if (str1=="0")
	{
		/*m_list.InsertColumn(0,"3 point",LVCFMT_CENTER,213);*/
	}
	
}
