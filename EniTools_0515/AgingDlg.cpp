// AgingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "EniTools.h"
#include "afxdialogex.h"
#include "AgingDlg.h"


// AgingDlg 대화 상자

IMPLEMENT_DYNAMIC(AgingDlg, CDialogEx)

AgingDlg::AgingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AGING_DIALOG, pParent)
{

}

AgingDlg::~AgingDlg()
{
}

void AgingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AgingDlg, CDialogEx)
END_MESSAGE_MAP()


// AgingDlg 메시지 처리기
