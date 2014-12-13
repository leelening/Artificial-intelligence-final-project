// Delete_Player_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AI Final Porject.h"
#include "Delete_Player_Dlg.h"
#include "afxdialogex.h"


// Delete_Player_Dlg �Ի���

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
//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Delete_Player_Dlg::OnLvnItemchangedList1)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &Delete_Player_Dlg::OnLvnColumnclickList1)
	ON_BN_CLICKED(IDOK, &Delete_Player_Dlg::OnBnClickedOk)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST2, &Delete_Player_Dlg::OnLvnColumnclickList2)
END_MESSAGE_MAP()


// Delete_Player_Dlg ��Ϣ�������


//void Delete_Player_Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//
//
//	*pResult = 0;
//}
int nId;
int iatttacker = 0;

void Delete_Player_Dlg::OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString str; 
	
	POSITION pos = attacker_team_list_.GetFirstSelectedItemPosition(); 
	if(pos==NULL) 
	{ 
	MessageBox(_T("������ѡ��һ��"),_T("����"),MB_ICONEXCLAMATION); 
	return; 
	} 
	//�õ��кţ�ͨ��POSITIONת�� 
	nId=(int)attacker_team_list_.GetNextSelectedItem(pos); 



	*pResult = 0;
}


void Delete_Player_Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (iatttacker ==0)
	{
		attacker_team_list_.DeleteItem(nId);
		
	}
	else{
		defender_team_list_.DeleteItem(nId);
		iatttacker = 0;
	}
}


void Delete_Player_Dlg::OnLvnColumnclickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

		CString str; 
	
	POSITION pos = attacker_team_list_.GetFirstSelectedItemPosition(); 
	if(pos==NULL) 
	{ 
	MessageBox(_T("������ѡ��һ��"),_T("����"),MB_ICONEXCLAMATION); 
	return; 
	} 
	//�õ��кţ�ͨ��POSITIONת�� 
	nId=(int)attacker_team_list_.GetNextSelectedItem(pos); 
	iatttacker = 1;
	*pResult = 0;
}
