#pragma once
#include "afxwin.h"
#include "ClockSet.h"

#define WM_MYMESSAGE_SENDSHUTDOWNTOMAIN (WM_USER + 12)

struct ShutDownStruct{
	Clock clock;
	bool rebootflag;
};

// CShutDown ��ܤ��

class CShutDown : public CDialogEx
{
	DECLARE_DYNAMIC(CShutDown)

public:
	CShutDown(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CShutDown();

	// ��ܤ�����
	enum { IDD = IDD_DIALOG_SHUTDOWN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CComboBox m_combo_hr;
	CComboBox m_combo_min;
	CComboBox m_combo_sec;
};