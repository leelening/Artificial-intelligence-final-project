
// AI Final PorjectDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


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

public:
	virtual BOOL OnInitDialog();
protected:
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
//	CString SGy_;
//	CString SGx_;
//	CString method_;
//	CEdit method_;
//	CString method_;
	CString ballx_;
	CString bally_;
//	CEdit cx_;
	CString cy_;
	CString cx_;
	CString pfx_;
//	CString pf_;
	CString sfx_;
	CString sfy_;
	CString pgx_;
//	CEdit pgy_;
	CString pgy_;
	CString sgy_;
	CString sgx_;
	CString pfy_;
	afx_msg void OnBnClickedButton1();
};
