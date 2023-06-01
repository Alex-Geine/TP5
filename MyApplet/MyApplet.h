// MyApplet.h: основной файл заголовка для библиотеки DLL MyApplet
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы
#include "Cpl.h"
#include "DialogApplet.h"
// CMyAppletApp
// Реализацию этого класса см. в файле MyApplet.cpp
//

class CMyAppletApp : public CWinApp
{
public:
	CMyAppletApp();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
