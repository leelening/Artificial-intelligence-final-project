#pragma once


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
};
