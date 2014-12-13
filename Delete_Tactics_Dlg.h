#pragma once
#include "afxcmn.h"


// Delete_Tactics_Dlg 对话框

class Delete_Tactics_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Delete_Tactics_Dlg)

public:
	Delete_Tactics_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Delete_Tactics_Dlg();

// 对话框数据
	enum { IDD = IDD_Delete_Tactics };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL  OnInitDialog();
	afx_msg void OnBnClickedOk();
	CListCtrl Delete_tactics_;
};


