// ShutDown.cpp : ��@��
//

#include "stdafx.h"
#include "MFC_FinalProj.h"
#include "ShutDown.h"
#include "afxdialogex.h"


// CShutDown ��ܤ��

IMPLEMENT_DYNAMIC(CShutDown, CDialogEx)

	CShutDown::CShutDown(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShutDown::IDD, pParent)
{

}

CShutDown::~CShutDown()
{
}

void CShutDown::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOHOUR, m_combo_hr);
	DDX_Control(pDX, IDC_COMBOMIN, m_combo_min);
	DDX_Control(pDX, IDC_COMBOSEC, m_combo_sec);
}


BEGIN_MESSAGE_MAP(CShutDown, CDialogEx)
	ON_BN_CLICKED(IDOK, &CShutDown::OnBnClickedOk)
END_MESSAGE_MAP()


// CShutdown �T���B�z�`��


BOOL CShutDown::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �b���[�J�B�~����l��
	CString tp, tp2;

	for (int i=0; i<24; i++) {
		tp.Format(_T("%d%d"), i/10, i%10);
		m_combo_hr.AddString(tp);
	}
	for (int i=0; i<60; i++) {
		tp.Format(_T("%d%d"), i/10, i%10);
		m_combo_min.AddString(tp);
		m_combo_sec.AddString(tp);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}

void CShutDown::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X

	if (m_combo_hr.GetWindowTextLengthW() == 0 ||
		m_combo_min.GetWindowTextLengthW() == 0 ||
		m_combo_sec.GetWindowTextLengthW() == 0)
		MessageBox(_T("�ɶ���줣�i�d��"), _T("���~"),  MB_ICONERROR | MB_OK);
	else {
		ShutDownStruct sender;
		m_combo_hr.GetWindowText(sender.clock.hr);
		m_combo_min.GetWindowText(sender.clock.min);
		m_combo_sec.GetWindowText(sender.clock.sec);
		if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK1) )
			sender.rebootflag = true;
		else
			sender.rebootflag = false;

		CWnd* pWnd = CWnd::GetParent();
		pWnd->SendMessageW(WM_MYMESSAGE_SENDSHUTDOWNTOMAIN, (WPARAM)&sender);
		CDialogEx::OnOK();
	}
}

