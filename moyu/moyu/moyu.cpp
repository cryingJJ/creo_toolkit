// moyu.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "moyu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CmoyuApp

BEGIN_MESSAGE_MAP(CmoyuApp, CWinApp)
END_MESSAGE_MAP()

// CmoyuApp ����

CmoyuApp::CmoyuApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CmoyuApp ����

CmoyuApp theApp;

// CmoyuApp ��ʼ��

BOOL CmoyuApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

int _linenum = 1;
bool _showOrhide = false;
int _maxlinecount = 0;

static uiCmdAccessState AccessDefault(uiCmdAccessMode access_mode)
{
	return ACCESS_AVAILABLE;
}

void PrevLine()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	CString LineStr;
	char *p;
	if(_linenum > 1)
	{
		_linenum--;
		LineStr.Format(_T("IMI%d"),_linenum);
		p = LineStr.GetBuffer();
		status = ProMessageDisplay(NOVELFILE, p);
		LineStr.ReleaseBuffer();

	}
}

void NextLine()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	CString LineStr;
	char *p;
	if(_showOrhide == true)
	{
		if(_linenum < _maxlinecount+1)
		{
			_linenum++;
			LineStr.Format(_T("IMI%d"),_linenum);
			p = LineStr.GetBuffer();
			status = ProMessageDisplay(NOVELFILE, p);
			LineStr.ReleaseBuffer();
		}
	}
}

void ClearLine()
{
	ProMessageClear();
}

void ShowOrHide()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	CString LineStr;
	char *p;
	if(_showOrhide == true)
	{
		ProMessageClear();
	}
	else
	{
		LineStr.Format(_T("IMI%d"),_linenum);
		p = LineStr.GetBuffer();
		status = ProMessageDisplay(NOVELFILE, p);
		LineStr.ReleaseBuffer();
	}
	_showOrhide = !_showOrhide;
}

extern "C" int user_initialize()
{
	ProError status;
	uiCmdCmdId PrevLineID, NextLineID,ShowOrHideLineID,JumpLineID;

	status = ProMenubarMenuAdd("moyu", "moyu", "About", PRO_B_TRUE, MSGFILE);
	status = ProMenubarmenuMenuAdd("moyu", "moyu", "moyu", NULL, PRO_B_TRUE, MSGFILE);

	status = ProCmdActionAdd("PrevLine_Act", (uiCmdCmdActFn)PrevLine, uiProeImmediate, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &PrevLineID);
	status = ProMenubarmenuPushbuttonAdd("moyu", "Prevline", "Prevline", "Prevlinetips", NULL, PRO_B_TRUE, PrevLineID, MSGFILE);

	status = ProCmdActionAdd("NextLine_Act", (uiCmdCmdActFn)NextLine, uiProeImmediate, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &NextLineID);
	status = ProMenubarmenuPushbuttonAdd("moyu", "Nextline", "Nextline", "Nextlinetips", NULL, PRO_B_TRUE, NextLineID, MSGFILE);

	status = ProCmdActionAdd("ShowOrHideLineID_Act", (uiCmdCmdActFn)ShowOrHide, uiProeImmediate, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &ShowOrHideLineID);
	status = ProMenubarmenuPushbuttonAdd("moyu", "ShowOrHideLine", "ShowOrHideLine", "ShowOrHideLinetips", NULL, PRO_B_TRUE, ShowOrHideLineID, MSGFILE);

	status = ProCmdActionAdd("JumpLineID_Act", (uiCmdCmdActFn)ClearLine, uiProeImmediate, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &JumpLineID);
	status = ProMenubarmenuPushbuttonAdd("moyu", "JumpLine", "JumpLine", "JumpLinetips", NULL, PRO_B_TRUE, JumpLineID, MSGFILE);

	ProLine buffer;
	status = ProMessageToBuffer(buffer, NOVELFILE, (char*)"IMILINELENGTH");
	_maxlinecount = atoi(CString(buffer));

	_showOrhide = false;
	return PRO_TK_NO_ERROR;
}

extern "C" void user_terminate()
{
}