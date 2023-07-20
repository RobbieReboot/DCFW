// BuildLibraryDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBuildLibraryDialog dialog

class CBuildLibraryDialog : public CDialog
{
// Construction
public:
	CBuildLibraryDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBuildLibraryDialog)
	enum { IDD = IDD_BUILDLIB };
	int		m_UseFilesInBatch;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBuildLibraryDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBuildLibraryDialog)
	afx_msg void OnUsefilesinbatch();
	afx_msg void OnUsescript();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
