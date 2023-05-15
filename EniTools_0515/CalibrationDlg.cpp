// CalibrationDlg.cpp: 구현 파일
//

#include "pch.h"
#include "EniTools.h"
#include "afxdialogex.h"
#include "CalibrationDlg.h"


// CalibrationDlg 대화 상자

IMPLEMENT_DYNAMIC(CalibrationDlg, CDialogEx)

CalibrationDlg::CalibrationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALIBRATION_DIALOG, pParent)
{

}

CalibrationDlg::~CalibrationDlg()
{
}

void CalibrationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CalibrationDlg, CDialogEx)
END_MESSAGE_MAP()


// CalibrationDlg 메시지 처리기
