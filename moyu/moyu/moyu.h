// moyu.h : moyu DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h" // ������

// CmoyuApp
// �йش���ʵ�ֵ���Ϣ������� moyu.cpp
//

class CmoyuApp : public CWinApp
{
public:
	CmoyuApp();

	// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
