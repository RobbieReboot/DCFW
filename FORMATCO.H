// formatco.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFormatConvertion dialog

class CTCProgressBox;
class SCProgressDlg;

class CFormatConvertion : public CDialog
{
// Construction
public:
	CFormatConvertion(CWnd* pParent = NULL);   // standard constructor
	void PutSettingsIntoCurrentBatch(void);

	//in textconv.cpp
	int ScanFile(CFile& file);
	void ProcessTextFile(CString fname,int DestType);
	void Convert(int SrcType,int DstType,CFile& file);

	//in srcconv.cpp
	void BinToSource(CString fname);

// Dialog Data
	//{{AFX_DATA(CFormatConvertion)
	enum { IDD = IDD_FORMATCONVERTION };
	CString	m_LabelPrefix;
	CString	m_LabelSuffix;
	CString	m_nFormat;
	int		m_OutputAs;
	int		m_ItemsPerLine;
	int		m_ItemSize;
	int		m_IncOrDec;
	int		m_LabelMethod;
	int		m_TextConvertMode;
	BOOL	m_SaveAsStrings;
	int		m_Radix;
	int		m_nStart;
	int		m_ByteOrder;
	//}}AFX_DATA

	//pointer to the dialog that shows the status of our file...
	
	CTCProgressBox *m_TCProgressDlg;
	SCProgressDlg	*m_SCProgressDlg;

	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormatConvertion)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFormatConvertion)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnTextMode();
	afx_msg void OnSourceMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#define	TC_PC			0
#define TC_AMIGA		1
#define TC_MAC			2
#define	TC_BINARY		3
#define	TC_ERROR		4
