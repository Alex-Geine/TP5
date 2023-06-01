// DialogApplet.cpp: файл реализации
//

#include "pch.h"
#include "MyApplet.h"
#include "DialogApplet.h"
#include "afxdialogex.h"


// Диалоговое окно DialogApplet

IMPLEMENT_DYNAMIC(DialogApplet, CDialog)

DialogApplet::DialogApplet(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DialogApplet, pParent)
{

}

DialogApplet::~DialogApplet()
{
}

void DialogApplet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT1, EditReview1);
	DDX_Control(pDX, IDC_SLIDER1, slider);
	slider.SetRange(0, 10);
	SystemParametersInfo(SPI_GETMOUSESPEED, 0, &sense, 0);
	slider.SetPos(sense);
}


BEGIN_MESSAGE_MAP(DialogApplet, CDialog)
	ON_BN_CLICKED(IDOK, &DialogApplet::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &DialogApplet::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()


// Обработчики сообщений DialogApplet

//Ok

void DialogApplet::OnBnClickedOk()
{
	
	CDialog::OnOK();
}

//Обработчик слайдера
void DialogApplet::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
	unsigned int speed = slider.GetPos();

	SystemParametersInfo(SPI_SETMOUSESPEED, 0, (PVOID)speed, 0);
}
