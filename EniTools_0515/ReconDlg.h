#pragma once
#include "afxdialogex.h"


// ReconDlg 대화 상자

class ReconDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ReconDlg)

public:
	ReconDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ReconDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECON_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
