// formatco.cpp : implementation file
//

#include "stdafx.h"
#include "dcfw.h"
#include "formatco.h"
#include "batchlst.h"
#include "tcprogre.h"
#include "scprogre.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFormatConvertion dialog

CFormatConvertion::CFormatConvertion(CWnd* pParent /*=NULL*/)
	: CDialog(CFormatConvertion::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFormatConvertion)
	m_LabelPrefix = _T("");
	m_LabelSuffix = _T("");
	m_nFormat = _T("%.03d");
	m_OutputAs = 0;
	m_ItemsPerLine = 0;
	m_ItemSize = 0;
	m_IncOrDec = 0;
	m_LabelMethod = 0;
	m_TextConvertMode = 0;
	m_SaveAsStrings = FALSE;
	m_Radix = 10;
	m_nStart = 0;
	m_ByteOrder = -1;
	//}}AFX_DATA_INIT

}


void CFormatConvertion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFormatConvertion)
	DDX_Text(pDX, IDC_LABEL_PREFIX, m_LabelPrefix);
	DDV_MaxChars(pDX, m_LabelPrefix, 32);
	DDX_Text(pDX, IDC_LABEL_SUFFIX, m_LabelSuffix);
	DDV_MaxChars(pDX, m_LabelSuffix, 32);
	DDX_CBString(pDX, IDC_N_FORMAT, m_nFormat);
	DDV_MaxChars(pDX, m_nFormat, 16);
	DDX_CBIndex(pDX, IDC_OUTPUT_AS, m_OutputAs);
	DDX_CBIndex(pDX, IDC_ITEMS_PER_LINE, m_ItemsPerLine);
	DDX_Radio(pDX, IDC_ITEMSIZE_BYTE, m_ItemSize);
	DDX_Radio(pDX, IDC_INC_N, m_IncOrDec);
	DDX_CBIndex(pDX, IDC_LABEL_METHOD, m_LabelMethod);
	DDX_Radio(pDX, IDC_TEXT_PC, m_TextConvertMode);
	DDX_Check(pDX, IDC_SAVEASSTRINGS, m_SaveAsStrings);
	DDX_Text(pDX, IDC_RADIX, m_Radix);
	DDV_MinMaxInt(pDX, m_Radix, 2, 36);
	DDX_Text(pDX, IDC_N_START, m_nStart);
	DDV_MinMaxInt(pDX, m_nStart, 0, 65535);
	DDX_Radio(pDX, IDC_BYTEORDER, m_ByteOrder);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFormatConvertion, CDialog)
	//{{AFX_MSG_MAP(CFormatConvertion)
	ON_BN_CLICKED(IDC_TEXT_MODE, OnTextMode)
	ON_BN_CLICKED(IDC_SOURCE_MODE, OnSourceMode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFormatConvertion::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_LabelPrefix = CurrentBatch.m_LabelPrefix;
	m_LabelSuffix = CurrentBatch.m_LabelSuffix;
	m_nFormat = CurrentBatch.m_nFormat;
	m_OutputAs = CurrentBatch.m_OutputAs;
	m_ItemsPerLine = CurrentBatch.m_ItemsPerLine;
	m_ItemSize = CurrentBatch.m_ItemSize;
	m_IncOrDec = CurrentBatch.m_IncOrDec;
	m_LabelMethod = CurrentBatch.m_LabelMethod;
	m_TextConvertMode = CurrentBatch.m_TextConvertMode;
	m_SaveAsStrings = CurrentBatch.m_SaveAsStrings;
	m_Radix = CurrentBatch.m_Radix;
	m_nStart = CurrentBatch.m_nStart;
	m_ByteOrder = CurrentBatch.m_ByteOrder;
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFormatConvertion::OnOK() 
{
	//Because the dialog was dismissed with OK we need to send our settings to CurrentBatch Object.
	UpdateData(TRUE);
	CurrentBatch.m_LabelPrefix = m_LabelPrefix;
	CurrentBatch.m_LabelSuffix = m_LabelSuffix;
	CurrentBatch.m_nFormat = m_nFormat;
	CurrentBatch.m_OutputAs = m_OutputAs;
	CurrentBatch.m_ItemsPerLine = m_ItemsPerLine;
	CurrentBatch.m_ItemSize = m_ItemSize;
	CurrentBatch.m_IncOrDec = m_IncOrDec;
	CurrentBatch.m_LabelMethod = m_LabelMethod;
	CurrentBatch.m_TextConvertMode = m_TextConvertMode;
	CurrentBatch.m_SaveAsStrings = (char)m_SaveAsStrings;
	CurrentBatch.m_Radix = m_Radix;
	CurrentBatch.m_nStart = m_nStart;
	CurrentBatch.m_ByteOrder = m_ByteOrder;

	CDialog::OnOK();
}


void CFormatConvertion::PutSettingsIntoCurrentBatch(void) 
{
	UpdateData(TRUE);
	CurrentBatch.m_LabelPrefix = m_LabelPrefix;
	CurrentBatch.m_LabelSuffix = m_LabelSuffix;
	CurrentBatch.m_nFormat = m_nFormat;
	CurrentBatch.m_OutputAs = m_OutputAs;
	CurrentBatch.m_ItemsPerLine = m_ItemsPerLine;
	CurrentBatch.m_ItemSize = m_ItemSize;
	CurrentBatch.m_IncOrDec = m_IncOrDec;
	CurrentBatch.m_LabelMethod = m_LabelMethod;
	CurrentBatch.m_TextConvertMode = m_TextConvertMode;
	CurrentBatch.m_SaveAsStrings = (unsigned char)m_SaveAsStrings;
	CurrentBatch.m_Radix = m_Radix;
	CurrentBatch.m_nStart = m_nStart;
	CurrentBatch.m_ByteOrder = m_ByteOrder;
}


void CFormatConvertion::OnTextMode() 
{
	//This Function Converts files in current batch to the selected Text Format!

	int	i;
	CTCProgressBox	c;

	UpdateData(TRUE);

	//open up our status bar dialog....

	c.Create(CTCProgressBox::IDD);				//create MODELESS box...

	m_TCProgressDlg = &c;
	
	for(i = 0;i < CurrentBatch.Files.GetSize() ; i++)
	{
		//upodate the dialog boss...

		c.GetDlgItem(IDC_TCCURRENTFILE)->SetWindowText(CurrentBatch.Files[i]);
		ProcessTextFile(CurrentBatch.Files[i],m_TextConvertMode);
	}

	c.EndDialog(0);
}

void CFormatConvertion::OnSourceMode() 
{
	// TODO: Add your control notification handler code here

	int	i;
	SCProgressDlg	c;

	UpdateData(TRUE);

	//open up our status bar dialog....

	c.Create(SCProgressDlg::IDD);				//create MODELESS box...

	m_SCProgressDlg = &c;
	
	for(i = 0;i < CurrentBatch.Files.GetSize() ; i++)
	{
		//upodate the dialog boss...

		c.GetDlgItem(IDC_SCFILE)->SetWindowText(CurrentBatch.Files[i]);
		BinToSource(CurrentBatch.Files[i]);
	}

	c.EndDialog(0);

	
}
