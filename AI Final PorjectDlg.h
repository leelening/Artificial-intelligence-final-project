
// AI Final PorjectDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CAIFinalPorjectDlg 对话框
class CAIFinalPorjectDlg : public CDialogEx
{
// 构造
public:
	CAIFinalPorjectDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_AIFINALPORJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数

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
