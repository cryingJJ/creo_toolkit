// JumpLineDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "moyu.h"
#include "JumpLineDialog.h"
#include "afxdialogex.h"


// CJumpLineDialog �Ի���

IMPLEMENT_DYNAMIC(CJumpLineDialog, CDialog)

CJumpLineDialog::CJumpLineDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CJumpLineDialog::IDD, pParent)
	, m_currentlinenumEdit(0)
{

}

CJumpLineDialog::~CJumpLineDialog()
{
}

void CJumpLineDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITLINENUM, m_currentlinenumEdit);
	DDV_MinMaxInt(pDX, m_currentlinenumEdit, 1, 2000);
}

BEGIN_MESSAGE_MAP(CJumpLineDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CJumpLineDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CJumpLineDialog ��Ϣ�������


BOOL CJumpLineDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_currentlinenumEdit = CurrentLineNum>2000? 2000:CurrentLineNum;
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CJumpLineDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}
