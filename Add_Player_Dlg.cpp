// Add_Player_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AI Final Porject.h"
#include "Add_Player_Dlg.h"
#include "afxdialogex.h"
#include "playerproperty.h"


// Add_Player_Dlg �Ի���

IMPLEMENT_DYNAMIC(Add_Player_Dlg, CDialogEx)

Add_Player_Dlg::Add_Player_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Add_Player_Dlg::IDD, pParent)
{

	EnableAutomation();




}

Add_Player_Dlg::~Add_Player_Dlg()
{
}

void Add_Player_Dlg::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void Add_Player_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DefenseSlider, defense_);
	DDX_Control(pDX, IDC_SLIDER2, threepoints_);
	DDX_Control(pDX, IDC_EDIT4, defense_show_);
	DDX_Control(pDX, IDC_SLIDER3, shotmedium_);
	DDX_Control(pDX, IDC_SLIDER4, shotclose_);
	DDX_Control(pDX, IDC_SLIDER7, rebound_);
	DDX_Control(pDX, IDC_SLIDER5, breakthrough_);
	DDX_Control(pDX, IDC_SLIDER6, passball_);
	DDX_Control(pDX, IDC_SLIDER8, controlball_);
	DDX_Control(pDX, IDC_SLIDER9, keyball_);
	DDX_Control(pDX, IDC_LIST1, playerslist_);
}


BEGIN_MESSAGE_MAP(Add_Player_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Add_Player_Dlg::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_DefenseSlider, &Add_Player_Dlg::OnNMCustomdrawDefenseslider)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &Add_Player_Dlg::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &Add_Player_Dlg::OnNMCustomdrawSlider3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER4, &Add_Player_Dlg::OnNMCustomdrawSlider4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER5, &Add_Player_Dlg::OnNMCustomdrawSlider5)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER6, &Add_Player_Dlg::OnNMCustomdrawSlider6)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER7, &Add_Player_Dlg::OnNMCustomdrawSlider7)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER8, &Add_Player_Dlg::OnNMCustomdrawSlider8)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER9 , &Add_Player_Dlg::OnNMCustomdrawSlider9)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Add_Player_Dlg, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_IAdd_Player_Dlg ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {A024C263-6B3C-49E9-8253-CECE2C091DB4}
static const IID IID_IAdd_Player_Dlg =
{ 0xA024C263, 0x6B3C, 0x49E9, { 0x82, 0x53, 0xCE, 0xCE, 0x2C, 0x9, 0x1D, 0xB4 } };

BEGIN_INTERFACE_MAP(Add_Player_Dlg, CDialogEx)
	INTERFACE_PART(Add_Player_Dlg, IID_IAdd_Player_Dlg, Dispatch)
END_INTERFACE_MAP()


// Add_Player_Dlg ��Ϣ�������



void Add_Player_Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString txt;
	defense_show_.GetWindowTextW(txt);
	int aInt = _ttoi(txt);
	AfxMessageBox(txt);


}


void Add_Player_Dlg::OnNMCustomdrawDefenseslider(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	int nPos = defense_.GetPos();

	CString strText = _T("");
	strText.Format(_T("%d"), nPos);
	SetDlgItemText(IDC_EDIT4, strText);


//	playerslist_.SetImageList(&m_listSmall,LVSIL_SMALL);//����ImageList
//	playerslist_.InsertColumn(0,_T(""));//������
//	playerslist_.InsertColumn(1,_T("position"),LVCFMT_CENTER,300);
//	playerslist_.InsertColumn(2,_T("defense"),LVCFMT_LEFT,300);
//	playerslist_.InsertColumn(3,_T("threepoints"),LVCFMT_RIGHT,300);
//	playerslist_.DeleteColumn(0);
//	playerslist_.InsertItem(0,_T("player"));//������
//	playerslist_.SetItemText(0,1,_T("good"));//���ø��еĲ�ͬ�е���ʾ�ַ�
//	playerslist_.SetItemText(0,2,_T("average"));


//	  playerslist_.InsertColumn( 0,_T("ID"), LVCFMT_LEFT, 40 );//������
//    playerslist_.InsertColumn( 1,_T("NAME"), LVCFMT_LEFT, 50 );
//    int nRow = playerslist_.InsertItem(0, _T("11"));//������
//    playerslist_.SetItemText(nRow, 1, _T("jacky"));//��������

}


void Add_Player_Dlg::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	int nPos = threepoints_.GetPos();
	CString strText = _T("");
	strText.Format(_T("%d"), nPos);
	SetDlgItemText(IDC_EDIT8, strText);
}


void Add_Player_Dlg::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	int nPos = shotmedium_.GetPos();
	CString strText = _T("");
	strText.Format(_T("%d"), nPos);
	SetDlgItemText(IDC_EDIT16, strText);
}


void Add_Player_Dlg::OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	int nPos = shotclose_.GetPos();
	CString strText = _T("");
	strText.Format(_T("%d"), nPos);
	SetDlgItemText(IDC_EDIT13, strText);
}


void Add_Player_Dlg::OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	int nPos = breakthrough_.GetPos();
	CString strText = _T("");
	strText.Format(_T("%d"), nPos);
	SetDlgItemText(IDC_EDIT15, strText);
}


void Add_Player_Dlg::OnNMCustomdrawSlider6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	int nPos = passball_.GetPos();
	CString strText = _T("");
	strText.Format(_T("%d"), nPos);
	SetDlgItemText(IDC_EDIT6, strText);
}


void Add_Player_Dlg::OnNMCustomdrawSlider7(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	int nPos = rebound_.GetPos();
	CString strText = _T("");
	strText.Format(_T("%d"), nPos);
	SetDlgItemText(IDC_EDIT5, strText);
}


void Add_Player_Dlg::OnNMCustomdrawSlider8(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	int nPos = controlball_.GetPos();
	CString strText = _T("");
	strText.Format(_T("%d"), nPos);
	SetDlgItemText(IDC_EDIT7, strText);
}


void Add_Player_Dlg::OnNMCustomdrawSlider9(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	int nPos = keyball_.GetPos();
	CString strText = _T("");
	strText.Format(_T("%d"), nPos);
	SetDlgItemText(IDC_EDIT10, strText);
}
