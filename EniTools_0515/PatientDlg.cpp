// PatientDlg.cpp: 구현 파일
//

#include "pch.h"
#include "EniTools.h"
#include "afxdialogex.h"
#include "PatientDlg.h"


// PatientDlg 대화 상자

IMPLEMENT_DYNAMIC(PatientDlg, CDialogEx)

PatientDlg::PatientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PATIENT_DIALOG, pParent)
{

}

PatientDlg::~PatientDlg()
{
}

void PatientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PatientDlg, CDialogEx)
END_MESSAGE_MAP()


// PatientDlg 메시지 처리기
