// scprogre.cpp : implementation file
//

#include "stdafx.h"
#include "dcfw.h"
#include "scprogre.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SCProgressDlg dialog


SCProgressDlg::SCProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(SCProgressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(SCProgressDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SCProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SCProgressDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SCProgressDlg, CDialog)
	//{{AFX_MSG_MAP(SCProgressDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// SCProgressDlg message handlers
