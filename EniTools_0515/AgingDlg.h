#pragma once
#include "afxdialogex.h"


// AgingDlg 대화 상자

class AgingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AgingDlg)

public:
	AgingDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~AgingDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AGING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
