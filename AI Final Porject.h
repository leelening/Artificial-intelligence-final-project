
// AI Final Porject.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAIFinalPorjectApp:
// �йش����ʵ�֣������ AI Final Porject.cpp
//

class CAIFinalPorjectApp : public CWinApp
{
public:
	CAIFinalPorjectApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	afx_msg void OnInitializeplayersAddplayers();
};

extern CAIFinalPorjectApp theApp;