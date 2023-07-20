// tcprogre.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTCProgressBox dialog

class CTCProgressBox : public CDialog
{
// Construction
public:
	CTCProgressBox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTCProgressBox)
	enum { IDD = IDD_TCPROGRESS };
	CStatic	m_TCStatus;
	CStatic	m_TCSourceType;
	CStatic	m_TCCurFile;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCProgressBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTCProgressBox)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
