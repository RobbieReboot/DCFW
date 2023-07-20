// tcprogre.cpp : implementation file
//

#include "stdafx.h"
#include "dcfw.h"
#include "tcprogre.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTCProgressBox dialog


CTCProgressBox::CTCProgressBox(CWnd* pParent /*=NULL*/)
	: CDialog(CTCProgressBox::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTCProgressBox)
	//}}AFX_DATA_INIT
}


void CTCProgressBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTCProgressBox)
	DDX_Control(pDX, IDC_TCSTATUS, m_TCStatus);
	DDX_Control(pDX, IDC_TCSOURCETYPE, m_TCSourceType);
	DDX_Control(pDX, IDC_TCCURRENTFILE, m_TCCurFile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTCProgressBox, CDialog)
	//{{AFX_MSG_MAP(CTCProgressBox)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTCProgressBox message handlers
