#pragma once

// CJumpLineDialog �Ի���

class CJumpLineDialog : public CDialog
{
	DECLARE_DYNAMIC(CJumpLineDialog)

public:
	CJumpLineDialog(CWnd *pParent = NULL); // ��׼���캯��
	virtual ~CJumpLineDialog();

	// �Ի�������
	enum
	{
		IDD = IDD_DIALOGJUMPLINE
	};
	int MaxLineNum;
	int CurrentLineNum;

protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_currentlinenumEdit;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
