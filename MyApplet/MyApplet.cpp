// MyApplet.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "pch.h"
#include "framework.h"
#include "MyApplet.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//
LONG OnDblclk(HWND hWnd)
{
	DialogApplet dialog(CWnd::FromHandle(hWnd));
	dialog.DoModal();
	return 0;
}
//
LONG OnInquire( CPLINFO* lParam2)
{
	lParam2->idIcon = IDI_ICON1;
	lParam2->idName = IDS_NAME;
	lParam2->idInfo = IDS_DESCRIPTION;
	lParam2->lData=NULL;
	return 0;
}
LONG WINAPI CPlApplet(HWND hWnd, UINT uMsg, LONG lParam1, LONG lParam2)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	switch (uMsg)
	{
	case CPL_INIT:
		return 1;
	case CPL_INQUIRE:
		return OnInquire((CPLINFO*) lParam2);
	case CPL_DBLCLK:
		return OnDblclk(hWnd);
	case CPL_GETCOUNT:
		return 1;
	default: break;
	}
}
// CMyAppletApp

BEGIN_MESSAGE_MAP(CMyAppletApp, CWinApp)
END_MESSAGE_MAP()


// Создание CMyAppletApp

CMyAppletApp::CMyAppletApp()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CMyAppletApp

CMyAppletApp theApp;


// Инициализация CMyAppletApp

BOOL CMyAppletApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
