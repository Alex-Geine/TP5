
// TP5Dlg.h: файл заголовка
//

#pragma once
#include "Cpl.h"

// Диалоговое окно CTP5Dlg
class CTP5Dlg : public CDialogEx
{
// Создание
public:
	CTP5Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TP5_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();

	CString File;
	
	CEdit EditFile;

	CString namecpl;
	CString descriptioncpl;
	CStatic iconcpl;
	CButton start;

	HINSTANCE applet;
	APPLET_PROC CPlApplet; 
};
