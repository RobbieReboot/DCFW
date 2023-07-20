// dcfwdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDcfwDlg dialog

class CDcfwDlg : public CDialog
{
// Construction
public:
	CDcfwDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDcfwDlg)
	enum { IDD = IDD_DCFW_DIALOG };
	CListBox	m_FilesInBatch;
	//}}AFX_DATA

//Robs Public Data
	int		m_TotalFiles;

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDcfwDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON 	m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CDcfwDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFormatconversion();
	afx_msg void OnAddfiles();
	afx_msg void OnAbout();
	afx_msg void OnSavebatch();
	afx_msg void OnOpenbatch();
	virtual void OnOK();
	afx_msg void OnRemoveall();
	afx_msg void OnRemovemissing();
	afx_msg void OnDeletebatch();
	afx_msg void OnImporttextfile();
	afx_msg void OnRemovefiles();
	afx_msg void OnCheckcels();
	afx_msg void OnBuildlibrary();
	//}}AFX_MSG

	int CDcfwDlg::CheckCel(CString name);


	DECLARE_MESSAGE_MAP()
};
extern unsigned short SwapWord(unsigned short a);
extern unsigned long SwapLong(unsigned long a);

