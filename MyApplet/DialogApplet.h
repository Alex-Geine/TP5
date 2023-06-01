#pragma once


// Диалоговое окно DialogApplet

class DialogApplet : public CDialog
{
	DECLARE_DYNAMIC(DialogApplet)

public:
	DialogApplet(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~DialogApplet();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DialogApplet };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:	
	afx_msg void OnBnClickedOk();	
	CSliderCtrl slider;
	int sense;
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
};
