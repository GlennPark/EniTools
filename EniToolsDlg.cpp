
// EniToolsDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "EniTools.h"
#include "EniToolsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEniToolsDlg 대화 상자



CEniToolsDlg::CEniToolsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ENITOOLS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEniToolsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEniToolsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOADINI, &CEniToolsDlg::OnBnClickedLoadini)
	ON_BN_CLICKED(IDC_SAVEINI, &CEniToolsDlg::OnBnClickedSaveini)
	ON_BN_CLICKED(IDC_KOREAN, &CEniToolsDlg::OnBnClickedKorean)
	ON_BN_CLICKED(IDC_ENGLISH, &CEniToolsDlg::OnBnClickedEnglish)
END_MESSAGE_MAP()


// CEniToolsDlg 메시지 처리기

BOOL CEniToolsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_chkKorean.SubclassDlgItem(IDC_KOREAN, this);
	m_chkEnglish.SubclassDlgItem(IDC_ENGLISH, this);
	//LoadIniFile();
	UpdateUI();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CEniToolsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CEniToolsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CEniToolsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CEniToolsDlg::OnBnClickedLoadini()
{
	CFileDialog fileDlg(TRUE, _T("ini"), NULL, OFN_FILEMUSTEXIST, _T("INI Files (*.ini)|*.ini||"));
	if (fileDlg.DoModal() == IDOK)
	{
		m_iniFilePath = fileDlg.GetPathName();
		LoadIniFile(m_iniFilePath);
		LanguageCheckBox();
	}
}

void CEniToolsDlg::OnBnClickedSaveini()
{
	if (!m_iniFilePath.IsEmpty())
	{
		if (m_chkKorean.GetCheck())
		{
			m_iniData[_T("language")] = _T("Korean");
		}
		else if (m_chkEnglish.GetCheck())
		{
			m_iniData[_T("language")] = _T("English");
		}

		SaveIniFile(m_iniFilePath);
	}
	//CFileDialog fileDlg(FALSE, _T("ini"), NULL, OFN_OVERWRITEPROMPT, _T("INI Files (*.ini)|*.ini||"), this);
	//if (fileDlg.DoModal() == IDOK)
	//{
	//	CString filePath = fileDlg.GetPathName();
	//	std::ofstream outFile(filePath.GetString());
	//	for (const auto& pair : m_iniData)
	//	{
	//		outFile << pair.first << "=" << pair.second << std::endl;
	//	}
	//	outFile.close();
	//}

}

void CEniToolsDlg::LoadIniFile(const CString& filePath)
{
	m_iniData.RemoveAll();

	CStdioFile iniFile;
	if (iniFile.Open(filePath, CFile::modeRead | CFile::typeText))
	{
		CString line;
		while (iniFile.ReadString(line))
		{
			int separatorPos = line.Find('=');
			if (separatorPos != -1)
			{
				CString key = line.Left(separatorPos);
				CString value = line.Mid(separatorPos + 1);
				key.Trim();
				value.Trim();

				m_iniData.SetAt(key, value);
			}
		}
		iniFile.Close();
	}
}

void CEniToolsDlg::SaveIniFile(const CString& filePath)
{
	CStdioFile iniFile;
	if (iniFile.Open(filePath, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
	{
		POSITION pos = m_iniData.GetStartPosition();
		CString key, value;
		while (pos != NULL)
		{
			m_iniData.GetNextAssoc(pos, key, value);
			CString line = key + _T("=") + value + _T("\r\n");
			iniFile.WriteString(line);
		}
		iniFile.Close();
	}
}

void CEniToolsDlg::LanguageCheckBox()
{
	CString line;
	if (m_iniData.Lookup(_T("language"), line))
	{
		if (line.CompareNoCase(_T("Korean")) == 0)
		{
			m_chkKorean.SetCheck(TRUE);
			m_chkEnglish.SetCheck(FALSE);
		}
		else if (line.CompareNoCase(_T("English")) == 0)
		{
			m_chkKorean.SetCheck(FALSE);
			m_chkEnglish.SetCheck(TRUE);
		}
	}
}


void CEniToolsDlg::OnBnClickedKorean()
{
	GetDlgItem(IDC_ENGLISH)->SendMessage(BM_SETCHECK, BST_UNCHECKED, 0);
	m_iniData["language"] = "Korean";
	UpdateUI();
}

void CEniToolsDlg::OnBnClickedEnglish()
{
	GetDlgItem(IDC_KOREAN)->SendMessage(BM_SETCHECK, BST_UNCHECKED, 0);
	m_iniData["language"] = "English";
	UpdateUI();
}


void CEniToolsDlg::UpdateUI()
{
	CString line;
	if (m_iniData.Lookup(_T("language"), line))
	{
		if (line.CompareNoCase(_T("korean")) == 0)
		{
			m_chkKorean.SetCheck(TRUE);
			m_chkEnglish.SetCheck(FALSE);
		}
		else if (line.CompareNoCase(_T("english")) == 0)
		{
			m_chkKorean.SetCheck(FALSE);
			m_chkEnglish.SetCheck(TRUE);
		}
	}
}

//void CEniToolsDlg::UpdateUI()
//{
//	auto language = m_iniData.Lookup(_T("language"));
//	if (language != m_iniData.Lookup(_T("language")))
//	{
//		if (lang->second == "Korean")
//		{
//			GetDlgItem(IDC_KOREAN)->SendMessage(BM_SETCHECK, BST_CHECKED, 0);
//			GetDlgItem(IDC_ENGLISH)->SendMessage(BM_SETCHECK, BST_UNCHECKED, 0);
//		}
//		else if (lang->second == "English")
//		{
//			GetDlgItem(IDC_KOREAN)->SendMessage(BM_SETCHECK, BST_UNCHECKED, 0);
//			GetDlgItem(IDC_ENGLISH)->SendMessage(BM_SETCHECK, BST_CHECKED, 0);
//		}
//	}
//}


// 시작


