#pragma once


// Add_Tactics_Dlg �Ի���

class Add_Tactics_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Add_Tactics_Dlg)

public:
	Add_Tactics_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Add_Tactics_Dlg();

// �Ի�������
	enum { IDD = IDD_Add_Tactics };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
