// BackupDlg.cpp: 구현 파일
//

#include "pch.h"
#include "EniTools.h"
#include "afxdialogex.h"
#include "BackupDlg.h"


// BackupDlg 대화 상자

IMPLEMENT_DYNAMIC(BackupDlg, CDialogEx)

BackupDlg::BackupDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BACKUP_DIALOG, pParent)
{

}

BackupDlg::~BackupDlg()
{
}

void BackupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BackupDlg, CDialogEx)
END_MESSAGE_MAP()


// BackupDlg 메시지 처리기
