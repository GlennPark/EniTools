#pragma once
#include "afxdialogex.h"


// BackupDlg 대화 상자

class BackupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BackupDlg)

public:
	BackupDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~BackupDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BACKUP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
