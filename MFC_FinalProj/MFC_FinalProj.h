
// MFC_FinalProj.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CMFC_FinalProjApp:
// �аѾ\��@�����O�� MFC_FinalProj.cpp
//

class CMFC_FinalProjApp : public CWinApp
{
public:
	CMFC_FinalProjApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CMFC_FinalProjApp theApp;