// dcfw.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "dcfw.h"
#include "dcfwdlg.h"
#include "batchlst.h"
//#include <afxcmn.h>
#include <afxtempl.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CDcfwApp

BEGIN_MESSAGE_MAP(CDcfwApp, CWinApp)
	//{{AFX_MSG_MAP(CDcfwApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDcfwApp construction

CDcfwApp::CDcfwApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance

}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDcfwApp object

CDcfwApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDcfwApp initialization

BOOL CDcfwApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	Enable3dControls();
	LoadStdProfileSettings();  // Load standard INI file options (including MRU)
	InitCommonControls();
	CDcfwDlg dlg;
	m_pMainWnd = &dlg;

	//Init the state of the Current batch to default.
	CurrentBatch.SetDefaultState();			

	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

