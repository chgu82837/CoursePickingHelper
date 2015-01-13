#pragma once
#include "afxwin.h"
#include "ClockSet.h"
#include "ClockMain.h"

#define WM_MYMESSAGE_SENDTOCLOCKMAIN2 (WM_USER + 8)

struct ClockChange {
	Clock newclock;
	CString index;
};

// CClockChange ��ܤ��


class CClockChange : public CDialogEx
{
	DECLARE_DYNAMIC(CClockChange)

public:
	CClockChange(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CClockChange();
	afx_msg LRESULT receiver(WPARAM wParam, LPARAM lParam);

// ��ܤ�����
	enum { IDD = IDD_DIALOG_CLOCKCHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_combo_hr;
	CComboBox m_combo_min;
	CComboBox m_combo_sec;
	CEdit m_edit_path;
	afx_msg void OnBnClickedOk();
	ClockChange newclock;
	afx_msg void OnBnClickedButtonSelfile();
};
