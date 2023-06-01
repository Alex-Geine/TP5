
// TP5Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "TP5.h"
#include "TP5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CTP5Dlg



CTP5Dlg::CTP5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TP5_DIALOG, pParent)
	, File(_T(""))
	, namecpl(_T(""))
	, descriptioncpl(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTP5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, File);
	DDX_Control(pDX, IDC_EDIT1, EditFile);
	DDX_Text(pDX, IDC_EDIT2, namecpl);
	DDX_Text(pDX, IDC_EDIT3, descriptioncpl);
	DDX_Control(pDX, IDC_ICO, iconcpl);
	DDX_Control(pDX, IDC_BUTTON2, start);
}

BEGIN_MESSAGE_MAP(CTP5Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTP5Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTP5Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CTP5Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений CTP5Dlg

BOOL CTP5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	start.EnableWindow(FALSE);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CTP5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CTP5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//поиск
void CTP5Dlg::OnBnClickedButton1()
{
	LPCTSTR lpcstrFilter = _T("Control Panel Items(*.cpl)\0*.cpl\0");
	CFileDialog fdlg(TRUE);
	fdlg.m_ofn.lpstrFilter = lpcstrFilter;
	fdlg.DoModal();
	File = fdlg.GetPathName();
	EditFile.SetWindowTextW(File);

	applet = LoadLibrary(File);
	
	if (applet != NULL)
	{
		CPlApplet = (APPLET_PROC)GetProcAddress(applet, "CPlApplet");
		
		if (CPlApplet(NULL, CPL_INIT, 0, 0) != 0)
		{
			CPLINFO cplInfo;
			CString buf;

			CPlApplet(NULL, CPL_INQUIRE, 0, (LPARAM)&cplInfo);
			
			buf.LoadString(applet, cplInfo.idName);
			namecpl = buf;
			
			buf.LoadString(applet, cplInfo.idInfo);
			descriptioncpl = buf;
			
			iconcpl.SetIcon((HICON)LoadImage(applet, MAKEINTRESOURCE(cplInfo.idIcon), IMAGE_ICON,0,0, LR_DEFAULTSIZE));
			
			UpdateData(FALSE);
			start.EnableWindow(TRUE);
		}

		else { 
			MessageBox(L"Апплет не удалось инициализировать"); 
			return; 
		}
	}

	else { 
		MessageBox(L"Не удалось загрузить апплет в память"); 
		return; 
	}
}

//Загрузить
void CTP5Dlg::OnBnClickedButton2()
{
	if (CPlApplet != NULL) {
		CPlApplet(0, CPL_DBLCLK, 0, 0);
	}
}

//Закрыть
void CTP5Dlg::OnBnClickedOk()
{
	CDialogEx::OnOK();
}
