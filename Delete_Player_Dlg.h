#pragma once


// Delete_Player_Dlg 对话框

class Delete_Player_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Delete_Player_Dlg)

public:
	Delete_Player_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Delete_Player_Dlg();

// 对话框数据
	enum { IDD = IDD_Delete_Players };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
