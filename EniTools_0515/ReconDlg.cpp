// ReconDlg.cpp: 구현 파일
//

#include "pch.h"
#include "EniTools.h"
#include "afxdialogex.h"
#include "ReconDlg.h"


// ReconDlg 대화 상자

IMPLEMENT_DYNAMIC(ReconDlg, CDialogEx)

ReconDlg::ReconDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RECON_DIALOG, pParent)
{

}

ReconDlg::~ReconDlg()
{
}

void ReconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ReconDlg, CDialogEx)
END_MESSAGE_MAP()


// ReconDlg 메시지 처리기
