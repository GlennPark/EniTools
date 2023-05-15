#pragma once
#include "afxdialogex.h"


// MembrainDlg 대화 상자

class MembrainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MembrainDlg)

public:
	MembrainDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MembrainDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEMBRAIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
