
// 2017134025LJT.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMy2017134025LJTApp:
// �� Ŭ������ ������ ���ؼ��� 2017134025LJT.cpp�� �����Ͻʽÿ�.
//

class CMy2017134025LJTApp : public CWinApp
{
public:
	CMy2017134025LJTApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMy2017134025LJTApp theApp;