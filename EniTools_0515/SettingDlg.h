#pragma once
#include "afxdialogex.h"


// SettingDlg 대화 상자

class SettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SettingDlg)

public:
	SettingDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SettingDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

private:
	

public:
	virtual BOOL OnInitDialog();
	CComboBox m_cbLanguage;
	afx_msg void OnCbnSelchangeComboLanguage();
};
