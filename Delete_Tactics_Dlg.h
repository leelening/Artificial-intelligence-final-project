#pragma once


// Delete_Tactics_Dlg �Ի���

class Delete_Tactics_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Delete_Tactics_Dlg)

public:
	Delete_Tactics_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Delete_Tactics_Dlg();

// �Ի�������
	enum { IDD = IDD_Delete_Tactics };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};