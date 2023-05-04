
// EniToolsDlg.h: 헤더 파일

#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <afxtempl.h>

// CEniToolsDlg 대화 상자
class CEniToolsDlg : public CDialogEx
{
// 생성입니다.
public:
	CEniToolsDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ENITOOLS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void OnBnClickedLoadini();
	afx_msg void OnBnClickedSaveini();
	afx_msg void OnBnClickedKorean();
	afx_msg void OnBnClickedEnglish();
	
	DECLARE_MESSAGE_MAP()

private:
//	std::map<std::string, std::string> m_iniData;
	CMapStringToString m_iniData;
	
	void UpdateUI();
	CString m_iniFilePath;
	CButton m_chkKorean;
	CButton m_chkEnglish;
	
	void LanguageCheckBox();
	void LoadIniFile(const CString& filePath);
	void SaveIniFile(const CString& filePath);
public:
	
};
