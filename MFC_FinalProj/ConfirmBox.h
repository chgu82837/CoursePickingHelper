#pragma once
#include "afxwin.h"


// ConfirmBox ��ܤ��

class ConfirmBox : public CDialogEx
{
	DECLARE_DYNAMIC(ConfirmBox)

public:
	ConfirmBox(CString* msg,CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~ConfirmBox();

// ��ܤ�����
	enum { IDD = IDD_DIALOG_CONFIRM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
	CString* msg;
public:
	CStatic m_text_msg;
};
