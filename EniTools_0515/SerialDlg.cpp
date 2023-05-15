// SerialDlg.cpp: 구현 파일
//

#include "pch.h"
#include "EniTools.h"
#include "afxdialogex.h"
#include "SerialDlg.h"


// SerialDlg 대화 상자

IMPLEMENT_DYNAMIC(SerialDlg, CDialogEx)

SerialDlg::SerialDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SERIAL_DIALOG, pParent)
{

}

SerialDlg::~SerialDlg()
{
}

void SerialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SerialDlg, CDialogEx)
END_MESSAGE_MAP()


// SerialDlg 메시지 처리기
