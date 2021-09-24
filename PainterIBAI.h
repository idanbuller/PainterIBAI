//Develop by 
// Avichai Iluz 208626234
// Idan Buller 
// PainterIBAI.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPainterIBAIApp:
// See PainterIBAI.cpp for the implementation of this class
//

class CPainterIBAIApp : public CWinApp
{
public:
	CPainterIBAIApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPainterIBAIApp theApp;
