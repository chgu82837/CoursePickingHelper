#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "ClockSet.h"
#include "ClockChange.h"

#define WM_MYMESSAGE_SENDTOMAIN (WM_USER + 4)
#define WM_MYMESSAGE_SENDTOCHANGE (WM_USER + 6)

struct ClockRetMain {
	Clock *pClkRet, *pClkLiveRet;
	int clock_ct, enable_clock_ct;
};

const UINT ID_TIMER_SECOND = 0x1002;
const UINT SECOND_ELAPSE = 1000;
int str2int (CString str);

// CClockMain ��ܤ��

class CClockMain : public CDialogEx
{
	DECLARE_DYNAMIC(CClockMain)

public:
	CClockMain(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CClockMain();

	afx_msg LRESULT rcvfromset(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT rcvfromchange(WPARAM wParam, LPARAM lParam);

// ��ܤ�����
	enum { IDD = IDD_DIALOG_CLOCKMAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic m_st_clockct;
	CListCtrl m_ListCtrl;
	afx_msg void OnBnClickedButtonadd();
	afx_msg void OnBnClickedOk();

	Clock clock[1000];
	Clock liveclock[1000];
	ClockRetMain Sender;

	afx_msg void OnBnClickedButtondel();

	CStatic m_st_nowtime;
	CTime nowtime;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void CClockMain::StartTimer();
	void CClockMain::StopTimer();

	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CString tp, tp2;
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
