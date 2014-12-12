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
	DDX_Control(pDX, IDC_LIST4, playerslist2_);
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
	
	CButton *checkbox1=(CButton*)GetDlgItem(IDC_CHECK3);
	CButton *checkbox2=(CButton*)GetDlgItem(IDC_CHECK4);
	CButton *checkbox3=(CButton*)GetDlgItem(IDC_CHECK5);
	CButton *checkbox4=(CButton*)GetDlgItem(IDC_CHECK6);
	CButton *checkbox5=(CButton*)GetDlgItem(IDC_CHECK7);
	CButton *checkbox6=(CButton*)GetDlgItem(IDC_CHECK8);
	CButton *checkbox7=(CButton*)GetDlgItem(IDC_CHECK9);
	if(checkbox1->GetCheck())   
    {
		/*CEdit* edit4=(CEdit*)GetDlgItem(IDC_EDIT4);

		CEdit* edit8=(CEdit*)GetDlgItem(IDC_EDIT8);
		CEdit* edit16=(CEdit*)GetDlgItem(IDC_EDIT16);
		CEdit* edit13=(CEdit*)GetDlgItem(IDC_EDIT13);
		CEdit* edit15=(CEdit*)GetDlgItem(IDC_EDIT15);
		CEdit* edit6=(CEdit*)GetDlgItem(IDC_EDIT6);
		CEdit* edit5=(CEdit*)GetDlgItem(IDC_EDIT5);
		CEdit* edit7=(CEdit*)GetDlgItem(IDC_EDIT7);
		CEdit* edit10=(CEdit*)GetDlgItem(IDC_EDIT10);*/
		CString str1;
		CString str2;
		CString str3;
		CString str4;
		CString str5;
		CString str6;
		CString str7;
		CString str8;
		CString str9;
		/*CString str10;*/

         CEdit* edit4=(CEdit*)GetDlgItem(IDC_EDIT4);
		 edit4->GetWindowText(str1);
		CEdit* edit8=(CEdit*)GetDlgItem(IDC_EDIT8);
		edit8->GetWindowText(str2);
		CEdit* edit16=(CEdit*)GetDlgItem(IDC_EDIT16);
		edit16->GetWindowText(str3);
		CEdit* edit13=(CEdit*)GetDlgItem(IDC_EDIT13);
		edit13->GetWindowText(str4);
		CEdit* edit15=(CEdit*)GetDlgItem(IDC_EDIT15);
		edit15->GetWindowText(str5);
		CEdit* edit6=(CEdit*)GetDlgItem(IDC_EDIT6);
		edit6->GetWindowText(str6);
		CEdit* edit5=(CEdit*)GetDlgItem(IDC_EDIT5);
		edit5->GetWindowText(str7);
		CEdit* edit7=(CEdit*)GetDlgItem(IDC_EDIT7);
		edit7->GetWindowText(str8);
		CEdit* edit10=(CEdit*)GetDlgItem(IDC_EDIT10);
		edit10->GetWindowText(str9);
		if (checkbox3->GetCheck())
		{
				playerslist2_.InsertItem(0,_T("SG"));//������
		}
		else if (checkbox4->GetCheck())
		{
			playerslist2_.InsertItem(0,_T("PG"));//������
		}
		else if (checkbox5->GetCheck())
		{
			playerslist2_.InsertItem(0,_T("C"));//������
		}
			else if (checkbox6->GetCheck())
		{
			playerslist2_.InsertItem(0,_T("PF"));//������
		}
		else if (checkbox7->GetCheck())
		{
			playerslist2_.InsertItem(0,_T("SF"));//������
		}
		playerslist2_.SetItemText(0,1,str1);//���ø��еĲ�ͬ�е���ʾ�ַ�
		playerslist2_.SetItemText(0,2,str2);
		playerslist2_.SetItemText(0,3,str3);
		playerslist2_.SetItemText(0,4,str4);
		playerslist2_.SetItemText(0,5,str5);
		playerslist2_.SetItemText(0,6,str6);
		playerslist2_.SetItemText(0,7,str7);
		playerslist2_.SetItemText(0,8,str8);
		playerslist2_.SetItemText(0,9,str9);
    }
    else if(checkbox2->GetCheck())
    {
		CString str1;
		CString str2;
		CString str3;
		CString str4;
		CString str5;
		CString str6;
		CString str7;
		CString str8;
		CString str9;
         CEdit* edit4=(CEdit*)GetDlgItem(IDC_EDIT4);
		 edit4->GetWindowText(str1);
		CEdit* edit8=(CEdit*)GetDlgItem(IDC_EDIT8);
		edit8->GetWindowText(str2);
		CEdit* edit16=(CEdit*)GetDlgItem(IDC_EDIT16);
		edit16->GetWindowText(str3);
		CEdit* edit13=(CEdit*)GetDlgItem(IDC_EDIT13);
		edit13->GetWindowText(str4);
		CEdit* edit15=(CEdit*)GetDlgItem(IDC_EDIT15);
		edit15->GetWindowText(str5);
		CEdit* edit6=(CEdit*)GetDlgItem(IDC_EDIT6);
		edit6->GetWindowText(str6);
		CEdit* edit5=(CEdit*)GetDlgItem(IDC_EDIT5);
		edit5->GetWindowText(str7);
		CEdit* edit7=(CEdit*)GetDlgItem(IDC_EDIT7);
		edit7->GetWindowText(str8);
		CEdit* edit10=(CEdit*)GetDlgItem(IDC_EDIT10);
		edit10->GetWindowText(str9);
		playerslist_.InsertItem(0,_T("defender"));//������
		playerslist_.SetItemText(0,1,str1);//���ø��еĲ�ͬ�е���ʾ�ַ�
		playerslist_.SetItemText(0,2,str2);
		playerslist_.SetItemText(0,3,str3);
		playerslist_.SetItemText(0,4,str4);
		playerslist_.SetItemText(0,5,str5);
		playerslist_.SetItemText(0,6,str6);
		playerslist_.SetItemText(0,7,str7);
		playerslist_.SetItemText(0,8,str8);
		playerslist_.SetItemText(0,9,str9);
    }
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


	//playerslist_.SetImageList(&m_listSmall,LVSIL_SMALL);//����ImageList

	
	//playerslist_.DeleteColumn(0);
	//playerslist_.InsertItem(0,_T("player"));//������
	//playerslist_.SetItemText(0,1,_T("good"));//���ø��еĲ�ͬ�е���ʾ�ַ�
	//playerslist_.SetItemText(0,2,_T("average"));
	//playerslist_.InsertColumn(0, _T("�ļ���"));
 //playerslist_.InsertColumn(1, _T("��С"));
 //playerslist_.InsertColumn(2, _T("�޸�����"));
 //playerslist_.InsertColumn(3, _T("�ļ�����"));


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
//BOOL Add_Player_Dlg::OnInitDialog()
//{...
// m_list.InsertColumn(0, _T("�ļ���"));
// m_list.InsertColumn(1, _T("��С"));
// m_list.InsertColumn(2, _T("�޸�����"));
// m_list.InsertColumn(3, _T("�ļ�����"));
// for(int j=0;j<4;j++)
//  m_list.SetColumnWidth(j ,140);          //�ı�ÿһ�п��
// return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
//}
BOOL Add_Player_Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	  CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
    DWORD dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
    SetWindowLong( pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);
	 CListCtrl* pmyListCtrl2 = (CListCtrl*)GetDlgItem(IDC_LIST4);
    DWORD dwStyle2 = GetWindowLong(pmyListCtrl2->m_hWnd, GWL_STYLE);
    SetWindowLong( pmyListCtrl2->m_hWnd, GWL_STYLE, dwStyle2 | LVS_REPORT);
	playerslist_.InsertColumn(0,_T("position"),LVCFMT_CENTER,70);
	playerslist_.InsertColumn(1,_T("defense"),LVCFMT_LEFT,70);
	playerslist_.InsertColumn(2,_T("threepoints"),LVCFMT_RIGHT,70);
	playerslist_.InsertColumn(3,_T("ShotMedium"),LVCFMT_CENTER,70);
	playerslist_.InsertColumn(4,_T("ShotClose"),LVCFMT_LEFT,70);
	playerslist_.InsertColumn(5,_T("BreakThrough"),LVCFMT_RIGHT,70);
	playerslist_.InsertColumn(6,_T("PassBall"),LVCFMT_CENTER,70);
	playerslist_.InsertColumn(7,_T("Rebound"),LVCFMT_LEFT,70);
	playerslist_.InsertColumn(8,_T("ControlBall"),LVCFMT_RIGHT,70);
	playerslist_.InsertColumn(9,_T("KeyBall"),LVCFMT_RIGHT,70);
	playerslist2_.InsertColumn(0,_T("position"),LVCFMT_CENTER,70);
	playerslist2_.InsertColumn(1,_T("defense"),LVCFMT_LEFT,70);
	playerslist2_.InsertColumn(2,_T("threepoints"),LVCFMT_RIGHT,70);
	playerslist2_.InsertColumn(3,_T("ShotMedium"),LVCFMT_CENTER,70);
	playerslist2_.InsertColumn(4,_T("ShotClose"),LVCFMT_LEFT,70);
	playerslist2_.InsertColumn(5,_T("BreakThrough"),LVCFMT_RIGHT,70);
	playerslist2_.InsertColumn(6,_T("PassBall"),LVCFMT_CENTER,70);
	playerslist2_.InsertColumn(7,_T("Rebound"),LVCFMT_LEFT,70);
	playerslist2_.InsertColumn(8,_T("ControlBall"),LVCFMT_RIGHT,70);
	playerslist2_.InsertColumn(9,_T("KeyBall"),LVCFMT_RIGHT,70);
	//	 playerslist_.InsertColumn(0, _T("dad"));
 //playerslist_.InsertColumn(1, _T("da"));
 //playerslist_.InsertColumn(2, _T("dsa"));
 //playerslist_.InsertColumn(3, _T("dsa"));
  //for(int j=0;j<4;j++)
  //playerslist_.SetColumnWidth(j ,100);  
//  CString Foldername = _T("dsdas");
//  CString iDate = _T("dsad");
//  CString iType = _T("dsdas");
//  playerslist_.InsertItem(0,Foldername);
//playerslist_.SetItemText(0,2,iDate);
//playerslist_.SetItemText(0,3,iType);
	return TRUE; // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
