#pragma once
#include "afxwin.h"

#define WM_MYMESSAGE_SENDCOUNTDOWNDATA (WM_USER + 10)

// CCountDown ��ܤ��

class CCountDown : public CDialogEx
{
	DECLARE_DYNAMIC(CCountDown)

public:
	CCountDown(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCountDown();

// ��ܤ�����
	enum { IDD = IDD_DIALOG_COUNTDOWN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo_hr;
	CComboBox m_combo_min;
	CComboBox m_combo_sec;
	CEdit m_edit_path;
	CString send[5];
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonSelfile();
	CButton m_but_cycle;
};
