#pragma once
#include "afxdialogex.h"


// ExposeDlg 대화 상자

class ExposeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ExposeDlg)

public:
	ExposeDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ExposeDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPOSE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
