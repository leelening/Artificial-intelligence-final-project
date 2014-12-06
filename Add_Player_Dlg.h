#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// Add_Player_Dlg 对话框

class Add_Player_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Add_Player_Dlg)

public:
	Add_Player_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Add_Player_Dlg();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_Add_Players };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:


	CSliderCtrl defense_;
	CSliderCtrl threepoints_;
	CEdit defense_show_;



	afx_msg void OnBnClickedOk();
	afx_msg void OnNMCustomdrawDefenseslider(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl shotmedium_;
	CSliderCtrl shotclose_;
	CSliderCtrl rebound_;
	CSliderCtrl breakthrough_;
	CSliderCtrl passball_;
	CSliderCtrl controlball_;
	CSliderCtrl keyball_;
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider7(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider8(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider9(NMHDR *pNMHDR, LRESULT *pResult);
//	CListBox playerslist_;
	CListCtrl playerslist_;
};
