
// TP5.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CTP5App:
// Сведения о реализации этого класса: TP5.cpp
//

class CTP5App : public CWinApp
{
public:
	CTP5App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CTP5App theApp;
