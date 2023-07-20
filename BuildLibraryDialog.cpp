// BuildLibraryDialog.cpp : implementation file
//

#include "stdafx.h"
#include "dcfw.h"
#include "BuildLibraryDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBuildLibraryDialog dialog


CBuildLibraryDialog::CBuildLibraryDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CBuildLibraryDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBuildLibraryDialog)
	m_UseFilesInBatch = -1;
	//}}AFX_DATA_INIT
}


void CBuildLibraryDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBuildLibraryDialog)
	DDX_Radio(pDX, IDC_USEFILESINBATCH, m_UseFilesInBatch);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBuildLibraryDialog, CDialog)
	//{{AFX_MSG_MAP(CBuildLibraryDialog)
	ON_BN_CLICKED(IDC_USEFILESINBATCH, OnUsefilesinbatch)
	ON_BN_CLICKED(IDC_USESCRIPT, OnUsescript)
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBuildLibraryDialog message handlers

void CBuildLibraryDialog::OnUsefilesinbatch() 
{
	// TODO: Add your control notification handler code here
	CButton *browse;
	CEdit	*name;
	browse = (CButton *)GetDlgItem(IDC_BROWSEFORSCRIPT);
	browse->EnableWindow(FALSE);
	name = (CEdit *)GetDlgItem(IDC_SCRIPTFILENAME);
	name->EnableWindow(FALSE);
}


void CBuildLibraryDialog::OnUsescript() 
{
	// TODO: Add your control notification handler code here
	CButton *browse;
	CEdit	*name;
	browse = (CButton *)GetDlgItem(IDC_BROWSEFORSCRIPT);
	browse->EnableWindow(TRUE);
	name = (CEdit *)GetDlgItem(IDC_SCRIPTFILENAME);
	name->EnableWindow(TRUE);
}



BOOL CBuildLibraryDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	CButton *b;
	b = (CButton*)GetDlgItem(IDC_USEFILESINBATCH);
	b->SetCheck(1);	//Set The files button to be ON

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
