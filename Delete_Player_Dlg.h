#pragma once
#include "afxcmn.h"


// Delete_Player_Dlg �Ի���

class Delete_Player_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Delete_Player_Dlg)

public:
	Delete_Player_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Delete_Player_Dlg();

// �Ի�������
	enum { IDD = IDD_Delete_Players };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL  OnInitDialog();
	CListCtrl attacker_team_list_;
	CListCtrl defender_team_list_;
};
