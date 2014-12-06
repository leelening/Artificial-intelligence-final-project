#pragma once


// Add_Tactics_Dlg 对话框

class Add_Tactics_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Add_Tactics_Dlg)

public:
	Add_Tactics_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Add_Tactics_Dlg();

// 对话框数据
	enum { IDD = IDD_Add_Tactics };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
