// Delete_Tactics_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AI Final Porject.h"
#include "Delete_Tactics_Dlg.h"
#include "afxdialogex.h"


// Delete_Tactics_Dlg �Ի���

IMPLEMENT_DYNAMIC(Delete_Tactics_Dlg, CDialogEx)

Delete_Tactics_Dlg::Delete_Tactics_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Delete_Tactics_Dlg::IDD, pParent)
{

}

Delete_Tactics_Dlg::~Delete_Tactics_Dlg()
{
}

void Delete_Tactics_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Delete_tactics_);
}


BEGIN_MESSAGE_MAP(Delete_Tactics_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Delete_Tactics_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Delete_Tactics_Dlg ��Ϣ�������


void Delete_Tactics_Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}

BOOL Delete_Tactics_Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
    DWORD dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
    SetWindowLong( pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);

	Delete_tactics_.InsertColumn(0,_T("value"),LVCFMT_CENTER,70);
	Delete_tactics_.InsertColumn(1,_T("tactics"),LVCFMT_LEFT,100);
	return TRUE;
}
