
// EniToolsDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "EniTools.h"
#include "EniToolsDlg.h"
#include "afxdialogex.h"

#include "SettingDlg.h"
#include "CTDlg.h"
#include "PanoDlg.h"
#include "CephDlg.h"
#include "PatientDlg.h"
#include "SerialDlg.h"
#include "CalibrationDlg.h"
#include "ExposeDlg.h"
#include "BackupDlg.h"
#include "FovDlg.h"
#include "MembrainDlg.h"
#include "AgingDlg.h"
#include "ReconDlg.h"

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
public:
	
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
	ON_BN_CLICKED(IDC_LOAD_BUTTON, &CEniToolsDlg::OnClickedLoadButton)
	ON_NOTIFY(NM_DBLCLK, IDC_SECTION_LIST, &CEniToolsDlg::OnNMDblclkSectionList)
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

	// TODO: 여기에 추가 초기화 작업을 추가합니다.	

	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_SECTION_LIST);

	//pList->SetImageList(&m_imgList, LVSIL_NORMAL);

	// Set the list control to use icons
	pList->SetView(LV_VIEW_ICON);

	// Load the icon (replace IDI_SETTING_ICON with the actual ID of your icon)
	HICON hIcon = AfxGetApp()->LoadIcon(IDB_SETTING_ICON);

	// Create an image list and add the icon to it
	//CImageList imageList;
	//imageList.Add(hIcon);
	m_imgList.Create(32, 32, ILC_COLOR32, 2, 0);		// 아이콘 이미지 리스트 초기화

	// 순서대로 아이콘 이미지를 rc 파일에 넣어서 추가
	m_imgList.Add(AfxGetApp()->LoadIconW(IDI_ICON_SETTING));		// 아이콘 이미지 추가

	
	//

	// Set the image list for the list control
	pList->SetImageList(&m_imgList, LVSIL_NORMAL);
	
	// Item list 정렬과 Dlg list 정렬이 다름
	// Add the [Setting] item

	//저장 역순, 신규 항목은 최상단 후순번으로 추가

	LVITEM reconItem = { 12 };
	reconItem.mask = LVIF_TEXT | LVIF_IMAGE;
	reconItem.pszText = _T("[Recon]");
	reconItem.iImage = 12;
	pList->InsertItem(&reconItem);

	LVITEM agingItem = { 11 };
	agingItem.mask = LVIF_TEXT | LVIF_IMAGE;
	agingItem.pszText = _T("[Aging]");
	agingItem.iImage = 11; // index of the icon in the image list
	pList->InsertItem(&agingItem);

	LVITEM membrainItem = { 10 };
	membrainItem.mask = LVIF_TEXT | LVIF_IMAGE;
	membrainItem.pszText = _T("[Membrain]");
	membrainItem.iImage = 10; // index of the icon in the image list
	pList->InsertItem(&membrainItem);
	
	LVITEM fovItem = { 9 };
	fovItem.mask = LVIF_TEXT | LVIF_IMAGE;
	fovItem.pszText = _T("[Fov]");
	fovItem.iImage = 9; // index of the icon in the image list
	pList->InsertItem(&fovItem);

	LVITEM backupItem = { 8 };
	backupItem.mask = LVIF_TEXT | LVIF_IMAGE;
	backupItem.pszText = _T("[Backup]");
	backupItem.iImage = 8; // index of the icon in the image list
	pList->InsertItem(&backupItem);

	LVITEM exposeItem = { 7 };
	exposeItem.mask = LVIF_TEXT | LVIF_IMAGE;
	exposeItem.pszText = _T("[Expose]");
	exposeItem.iImage = 7; // index of the icon in the image list
	pList->InsertItem(&exposeItem);

	LVITEM calibrationItem = { 6 };
	calibrationItem.mask = LVIF_TEXT | LVIF_IMAGE;
	calibrationItem.pszText = _T("[Calibration]");
	calibrationItem.iImage = 6; // index of the icon in the image list
	pList->InsertItem(&calibrationItem);

	LVITEM serialItem = { 5 };
	serialItem.mask = LVIF_TEXT | LVIF_IMAGE;
	serialItem.pszText = _T("[Serial]");
	serialItem.iImage = 5; // index of the icon in the image list
	pList->InsertItem(&serialItem);

	LVITEM patientItem = { 4 };
	patientItem.mask = LVIF_TEXT | LVIF_IMAGE;
	patientItem.pszText = _T("[Patient]");
	patientItem.iImage = 4; // index of the icon in the image list
	pList->InsertItem(&patientItem);

	LVITEM cephItem = { 3 };
	cephItem.mask = LVIF_TEXT | LVIF_IMAGE;
	cephItem.pszText = _T("[Ceph]");
	cephItem.iImage = 3; // index of the icon in the image list
	pList->InsertItem(&cephItem);

	LVITEM panoItem = { 2 };
	panoItem.mask = LVIF_TEXT | LVIF_IMAGE;
	panoItem.pszText = _T("[Pano]");
	panoItem.iImage = 2; // index of the icon in the image list
	pList->InsertItem(&panoItem);

	LVITEM ctItem = { 1 };
	ctItem.mask = LVIF_TEXT | LVIF_IMAGE;
	ctItem.pszText = _T("[CT]");
	ctItem.iImage = 1; // index of the icon in the image list
	pList->InsertItem(&ctItem);

	LVITEM settingItem = { 0 };
	settingItem.mask = LVIF_TEXT | LVIF_IMAGE;
	settingItem.pszText = _T("[Setting]");
	settingItem.iImage = 0; // index of the icon in the image list
	pList->InsertItem(&settingItem);

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

void CEniToolsDlg::OnClickedLoadButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog fileDlg(TRUE, _T("ini"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("Ini files (*.ini)|*.ini||"));

	if (fileDlg.DoModal() == IDOK)
	{
		CString filePath = fileDlg.GetPathName();
		LoadIniFile(filePath);
	}
}

void CEniToolsDlg::LoadIniFile(CString& filePath)
{
	TCHAR szLanguage[100] = { 0 };
	GetPrivateProfileString(_T("Setting"), _T("language"), _T("Default"), szLanguage, sizeof(szLanguage) / sizeof(TCHAR), _T("parameters.ini"));

	// 이제 buffer에는 읽어온 값이 있습니다.
	// 필요에 따라 이 값을 사용하십시오.
}

void CEniToolsDlg::SaveIniFile(const CString& strLanguage)
{
	WritePrivateProfileString(_T("Setting"), _T("language"), strLanguage, _T("parameters.ini"));
}


void CEniToolsDlg::OnNMDblclkSectionList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	// Check if the [Setting] item was double-clicked
	if (pNMItemActivate->iItem == 0)
	{
		// Open the SettingDlg (replace CSettingDlg with your actual dialog class)
		SettingDlg settingDlg;
		settingDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 1)
	{
		CTDlg ctDlg;
		ctDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 2)
	{
		PanoDlg panoDlg;
		panoDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 3)
	{
		CephDlg cephDlg;
		cephDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 4)
	{
		PatientDlg patientDlg;
		patientDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 5)
	{
		SerialDlg serialDlg;
		serialDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 6)
	{
		CalibrationDlg calibrationDlg;
		calibrationDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 7)
	{
		ExposeDlg exposeDlg;
		exposeDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 8)
	{
		BackupDlg backupDlg;
		backupDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 9)
	{
		FovDlg fovDlg;
		fovDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 10)
	{
		MembrainDlg membrainDlg;
		membrainDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 11)
	{
		AgingDlg agingDlg;
		agingDlg.DoModal();
	}
	else if (pNMItemActivate->iItem == 12)
	{
		ReconDlg reconDlg;
		reconDlg.DoModal();
	}

	*pResult = 0;
}
