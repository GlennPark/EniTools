// SettingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "EniTools.h"
#include "afxdialogex.h"
#include "SettingDlg.h"
#include "EniToolsDlg.h"


// SettingDlg 대화 상자

IMPLEMENT_DYNAMIC(SettingDlg, CDialogEx)

SettingDlg::SettingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETTING_DIALOG, pParent)
{

}

BOOL SettingDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO: Add extra initialization here
    // You may want to initialize the combo box here

    //Language ComboBox 에 저장된 값 복원
    CEniToolsDlg* pMainDlg = (CEniToolsDlg*)GetParent();
    int nSel = m_cbLanguage.FindStringExact(-1, pMainDlg->m_strLanguage);
    if (nSel != CB_ERR)
    {
        m_cbLanguage.SetCurSel(nSel);
    }
    return TRUE;  // return TRUE  unless you set the focus to a control
}


SettingDlg::~SettingDlg()
{
}

void SettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void SettingDlg::OnCbnSelchangeComboLanguage()
{
    int nSelected = m_cbLanguage.GetCurSel();  // Get the selected item
    if (nSelected != CB_ERR)
    {
        CString strLanguage;
        m_cbLanguage.GetLBText(nSelected, strLanguage);  // Get the text of the selected item

        // Save the selected language to the INI file
        CEniToolsDlg* pMainDlg = (CEniToolsDlg*)GetParent();
        pMainDlg->SaveIniFile(strLanguage);

        // Store the selected language in the main dialog
        pMainDlg->m_strLanguage = strLanguage;
    }
}

BEGIN_MESSAGE_MAP(SettingDlg, CDialogEx)
END_MESSAGE_MAP()


// SettingDlg 메시지 처리기
