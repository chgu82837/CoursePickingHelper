
// MFC_FinalProjDlg.h : ���Y��
//

#pragma once
#include "afxwin.h"
#include "ClockMain.h"
#include "CMCI.h"
#include "CountDown.h"
#include "ShutDown.h"
#include "afxcmn.h"
#include "Course.h"

// CMFC_FinalProjDlg ��ܤ��
class CMFC_FinalProjDlg : public CDialogEx
{
// �غc
public:
	CMFC_FinalProjDlg(CWnd* pParent = NULL);	// �зǫغc�禡

	afx_msg LRESULT rcvfromClockMain(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT rcvfromCountDown(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT rcvfromShutDown(WPARAM wParam, LPARAM lParam);
// ��ܤ�����
	enum { IDD = IDD_MFC_FINALPROJ_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	std::vector<Course*>* courses; 
	std::vector<int>* chosen;
	short* class_table;
	bool course_loaded;
	void update();
public:
	afx_msg void OnBnClickedButton1();
	CStatic m_st_clockct;
	CStatic m_st_timertext;
	CStatic m_st_shutdowntext;
	afx_msg void OnBnClickedButtonclock();
	ShutDownStruct rcv;
	ClockRetMain Rcv;
	Clock use[1000];
	CTime nowtime;
	bool isused[1000];
	CStatic m_st_nextclock;
	CStatic m_st_hide;
	CMCI *mymci, *mymci2;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString settimestr, settimepath;
	CString CountDownData[5];
	int settimeid, clock_ct;
	CStatic m_st_nowtime;
	afx_msg void OnBnClickedButtoncountdown();
	afx_msg void OnBnClickedButtonPlaypause();
	CButton m_but_playpause;
	afx_msg void OnBnClickedButtonstop();
	afx_msg void OnBnClickedButtonStopwatch();
	CButton m_stopwatch_playpause;
	afx_msg void OnBnClickedButtonPlaypause2();
	afx_msg void OnBnClickedButtonclear();
	CStatic m_st_stopwatch;
	CString stopwatch[4];
	bool stopwatchflag;
	afx_msg void OnBnClickedButtonshutdown();
	afx_msg void OnBnClickedButtonStopshutdown();
	afx_msg void OnBnClickedImport();
	CComboBox m_com_addclass;
	CListCtrl m_list_classtable;
	afx_msg void OnCbnDropdownAddClass();
	afx_msg void OnNMClickClassTable(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeAddClass();
	CButton m_btn_import_clear;
};
