// FovDlg.cpp: 구현 파일
//

#include "pch.h"
#include "EniTools.h"
#include "afxdialogex.h"
#include "FovDlg.h"


// FovDlg 대화 상자

IMPLEMENT_DYNAMIC(FovDlg, CDialogEx)

FovDlg::FovDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FOV_DIALOG, pParent)
{

}

FovDlg::~FovDlg()
{
}

void FovDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FovDlg, CDialogEx)
END_MESSAGE_MAP()


// FovDlg 메시지 처리기
