// CountDown.cpp : ��@��
//

#include "stdafx.h"
#include "MFC_FinalProj.h"
#include "CountDown.h"
#include "afxdialogex.h"


// CCountDown ��ܤ��

IMPLEMENT_DYNAMIC(CCountDown, CDialogEx)

CCountDown::CCountDown(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCountDown::IDD, pParent)
{

}

CCountDown::~CCountDown()
{
}

void CCountDown::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOHOUR, m_combo_hr);
	DDX_Control(pDX, IDC_COMBOMIN, m_combo_min);
	DDX_Control(pDX, IDC_COMBOSEC, m_combo_sec);
	DDX_Control(pDX, IDC_EDIT1, m_edit_path);
	DDX_Control(pDX, IDC_CHECK1, m_but_cycle);
}


BEGIN_MESSAGE_MAP(CCountDown, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCountDown::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SELFILE, &CCountDown::OnBnClickedButtonSelfile)
END_MESSAGE_MAP()


// CCountDown �T���B�z�`��


BOOL CCountDown::OnInitDialog()
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
	for (int i=0; i<5; i++)
		send[i] = "";

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}


void CCountDown::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
		if (m_combo_hr.GetWindowTextLengthW() == 0 ||
		m_combo_min.GetWindowTextLengthW() == 0 ||
		m_combo_sec.GetWindowTextLengthW() == 0)
		MessageBox(_T("�ɶ���줣�i�d��"), _T("���~"),  MB_ICONERROR | MB_OK);
	else if (m_edit_path.GetWindowTextLengthW() == 0)
		MessageBox(_T("�п�ܭ����ɮ�"), _T("���~"),  MB_ICONERROR | MB_OK);
	else {
		m_combo_hr.GetWindowText(send[0]);
		m_combo_min.GetWindowText(send[1]);
		m_combo_sec.GetWindowText(send[2]);
		m_edit_path.GetWindowText(send[3]);
		if (m_but_cycle.GetCheck() == BST_CHECKED)
			send[4] = L"�O";
		else
			send[4] = L"�_";

		CWnd* pWnd = CWnd::GetParent();
		pWnd->SendMessageW(WM_MYMESSAGE_SENDCOUNTDOWNDATA, (WPARAM)&send);

		CDialogEx::OnOK();
	}
}


void CCountDown::OnBnClickedButtonSelfile()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CString lpszDefExt = L"MP3 Files (*.mp3)|*.mp3||";
	CFileDialog dlg(true, NULL, NULL, OFN_HIDEREADONLY ,lpszDefExt , this);
	if (dlg.DoModal() == IDOK) {
		CString FileName = dlg.GetPathName(); //���o�}���ɮת����W(�]�t���|)
		m_edit_path.SetWindowTextW(FileName);
	}
}
