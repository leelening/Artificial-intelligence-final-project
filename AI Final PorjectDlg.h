
// AI Final PorjectDlg.h : ͷ�ļ�
//

#pragma once


// CAIFinalPorjectDlg �Ի���
class CAIFinalPorjectDlg : public CDialogEx
{
// ����
public:
	CAIFinalPorjectDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_AIFINALPORJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void addplayerfunc();
	void deleteplayerfunc();
	void addtacticsfunc();
	void deletetaticsfunc();

public:
	afx_msg void OnInitializeplayersAddplayers();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton2();
};
