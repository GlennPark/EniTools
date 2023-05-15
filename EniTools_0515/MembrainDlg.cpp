// MembrainDlg.cpp: 구현 파일
//

#include "pch.h"
#include "EniTools.h"
#include "afxdialogex.h"
#include "MembrainDlg.h"


// MembrainDlg 대화 상자

IMPLEMENT_DYNAMIC(MembrainDlg, CDialogEx)

MembrainDlg::MembrainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMBRAIN_DIALOG, pParent)
{

}

MembrainDlg::~MembrainDlg()
{
}

void MembrainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MembrainDlg, CDialogEx)
END_MESSAGE_MAP()


// MembrainDlg 메시지 처리기
