// DrawingAndView.h : DrawingAndView DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDrawingAndViewApp
// �йش���ʵ�ֵ���Ϣ������� DrawingAndView.cpp
//

class CDrawingAndViewApp : public CWinApp
{
public:
	CDrawingAndViewApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
