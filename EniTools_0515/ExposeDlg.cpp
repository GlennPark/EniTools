// ExposeDlg.cpp: 구현 파일
//

#include "pch.h"
#include "EniTools.h"
#include "afxdialogex.h"
#include "ExposeDlg.h"


// ExposeDlg 대화 상자

IMPLEMENT_DYNAMIC(ExposeDlg, CDialogEx)

ExposeDlg::ExposeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXPOSE_DIALOG, pParent)
{

}

ExposeDlg::~ExposeDlg()
{
}

void ExposeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ExposeDlg, CDialogEx)
END_MESSAGE_MAP()


// ExposeDlg 메시지 처리기
