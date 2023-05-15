#pragma once
#include "afxdialogex.h"


// FovDlg 대화 상자

class FovDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FovDlg)

public:
	FovDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~FovDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FOV_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
