// dcfw.h : main header file for the DCFW application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "afxtempl.h"

/////////////////////////////////////////////////////////////////////////////
// CDcfwApp:
// See dcfw.cpp for the implementation of this class
//

class CDcfwApp : public CWinApp
{
public:
	CDcfwApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDcfwApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	void LoadBatchLists(CArray *);

	//{{AFX_MSG(CDcfwApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
extern	CDcfwApp theApp;
