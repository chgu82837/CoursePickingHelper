// ClockChange.cpp : ��@��
//

#include "stdafx.h"
#include "MFC_FinalProj.h"
#include "ClockChange.h"
#include "afxdialogex.h"


// CClockChange ��ܤ��

IMPLEMENT_DYNAMIC(CClockChange, CDialogEx)

	CClockChange::CClockChange(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClockChange::IDD, pParent)
{

}

CClockChange::~CClockChange()
{
}

void CClockChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOHOUR, m_combo_hr);
	DDX_Control(pDX, IDC_COMBOMIN, m_combo_min);
	DDX_Control(pDX, IDC_COMBOSEC, m_combo_sec);
	DDX_Control(pDX, IDC_EDIT1, m_edit_path);
}


BEGIN_MESSAGE_MAP(CClockChange, CDialogEx)
	ON_BN_CLICKED(IDOK, &CClockChange::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SELFILE, &CClockChange::OnBnClickedButtonSelfile)
	ON_MESSAGE(WM_MYMESSAGE_SENDTOCHANGE, &CClockChange::receiver) 
END_MESSAGE_MAP()


// CClockChange �T���B�z�`��


BOOL CClockChange::OnInitDialog()
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

LRESULT CClockChange::receiver(WPARAM wParam, LPARAM lParam)
{
	// ������T���᪺�u�@
	// do something

	// �����ǹL�Ӫ����c��
	CString* pRcv;
	pRcv = (CString*)wParam;

	// ����
	m_combo_hr.SetCurSel(_wtoi(pRcv[0]));
	m_combo_min.SetCurSel(_wtoi(pRcv[1]));
	m_combo_sec.SetCurSel(_wtoi(pRcv[2]));
	m_edit_path.SetWindowTextW(pRcv[3]);
	newclock.index = pRcv[4];

	return LRESULT();
}

void CClockChange::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	if (m_combo_hr.GetWindowTextLengthW() == 0 ||
		m_combo_min.GetWindowTextLengthW() == 0 ||
		m_combo_sec.GetWindowTextLengthW() == 0)
		MessageBox(_T("�ɶ���줣�i�d��"), _T("���~"),  MB_ICONERROR | MB_OK);
	else if (m_edit_path.GetWindowTextLengthW() == 0)
		MessageBox(_T("�п�ܭ����ɮ�"), _T("���~"),  MB_ICONERROR | MB_OK);
	else {
		m_combo_hr.GetWindowText(newclock.newclock.hr);
		m_combo_min.GetWindowText(newclock.newclock.min);
		m_combo_sec.GetWindowText(newclock.newclock.sec);
		m_edit_path.GetWindowText(newclock.newclock.path);

		CWnd* pWnd = CWnd::GetParent();
		pWnd->SendMessageW(WM_MYMESSAGE_SENDTOCLOCKMAIN2, (WPARAM)&newclock);
		CDialogEx::OnOK();
	}
}


void CClockChange::OnBnClickedButtonSelfile()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CString lpszDefExt = L"MP3 Files (*.mp3)|*.mp3||";
	CFileDialog dlg(true, NULL, NULL, OFN_HIDEREADONLY ,lpszDefExt , this);
	if (dlg.DoModal() == IDOK) {
		CString FileName = dlg.GetPathName(); //���o�}���ɮת����W(�]�t���|)
		m_edit_path.SetWindowTextW(FileName);
	}
}
