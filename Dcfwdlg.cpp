
// dcfwdlg.cpp : implementation file
//

#include "stdafx.h"
#include "dcfw.h"
#include "dcfwdlg.h"
#include "formatco.h" 
#include "batchlst.h"
#include "buildlibrarydialog.h"
#include <string.h>
#include <stdlib.h>
#include <afxtempl.h>
#include <io.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


CString	Filters = 	"All Files    (*.*)|*.*|"
					"Text Files   (.txt)|*.txt|"
					"Binary Filed (.bin)|*.bin|"
					"Data files   (.dat)|*.dat|"
					"Source (.c;.cpp;.h;.hpp;.asm)|*.c;*.cpp;*.h;*.hpp;*.asm||";


CBatch	CurrentBatch;
				
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg message handlers

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CenterWindow();
	
	// TODO: Add extra about dlg initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CDcfwDlg::OnAbout() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg c;

	c.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CDcfwDlg dialog

CDcfwDlg::CDcfwDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDcfwDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDcfwDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDcfwDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDcfwDlg)
	DDX_Control(pDX, IDC_FILESINBATCH, m_FilesInBatch);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDcfwDlg, CDialog)
	//{{AFX_MSG_MAP(CDcfwDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FORMATCONVERSION, OnFormatconversion)
	ON_BN_CLICKED(IDC_ADDFILES, OnAddfiles)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	ON_BN_CLICKED(IDC_SAVEBATCH, OnSavebatch)
	ON_BN_CLICKED(IDC_OPENBATCH, OnOpenbatch)
	ON_BN_CLICKED(IDC_REMOVEALL, OnRemoveall)
	ON_BN_CLICKED(IDC_REMOVEMISSING, OnRemovemissing)
	ON_BN_CLICKED(IDC_DELETEBATCH, OnDeletebatch)
	ON_BN_CLICKED(IDC_IMPORTTEXTFILE, OnImporttextfile)
	ON_BN_CLICKED(IDC_REMOVEFILES, OnRemovefiles)
	ON_BN_CLICKED(IDC_CHECKCELS, OnCheckcels)
	ON_BN_CLICKED(IDC_BUILDLIBRARY, OnBuildlibrary)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDcfwDlg message handlers

BOOL CDcfwDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CenterWindow();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	if (!strAboutMenu.IsEmpty())
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDcfwDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDcfwDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDcfwDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDcfwDlg::OnFormatconversion() 
{
	// TODO: Add your control notification handler code here
	CFormatConvertion d;

	
	d.DoModal();
	
}


//Adds files to the default.batch
void CDcfwDlg::OnAddfiles() 
{
	// TODO: Add your control notification handler code here
	//Open up a file selector dialog, get the files  & fill up the list box with them.

	int		r=0,TotalAdded = 0;
	CString	name;
	char	np[_MAX_PATH],dr[_MAX_DRIVE],path[_MAX_DIR],fn[_MAX_FNAME],ext[_MAX_EXT];
	char	names[2048]={0};
	
	CFileDialog	f(TRUE,NULL,NULL,OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY ,
		Filters);

	//Do Nothing if Cancelled.

	f.m_ofn.lpstrFile = names;
	f.m_ofn.nMaxFile = 2048;

	r = f.DoModal();

	if ( r == IDCANCEL)	
		return;

	POSITION	pos=f.GetStartPosition();

	//the first thing in the string is Either an entire path name with file OR a Full path then a space
	//with filenames following

	TotalAdded = 0;

	do 				//pos becomes Zero if No more strings are available! 
	{
		name = f.GetNextPathName(pos);
		_splitpath(name,dr,path,fn,ext);
		if (strncmp(name,"\\\\",2)!=0)		//if name begins with \\ then the name is a UNC name so dont remove \\ in the path!
			if (path[1]=='\\') 
				path[1]=0;						//if theres the silly double slash shite remove it.
		_makepath(np,dr,path,fn,ext);
		TotalAdded++;
		//Update List Box
		m_FilesInBatch.AddString(CString(fn)+CString(ext));
		//List of files to do
		CurrentBatch.Files.Add(CString(dr)+CString(path)+CString(fn)+CString(ext));
		m_TotalFiles++;
	}
	while (pos);

	CurrentBatch.m_Modified = TRUE;

}

void CDcfwDlg::OnSavebatch() 
{
	// TODO: Add your control notification handler code here
	int	r;

	if (!CurrentBatch.m_Modified)
		return;									//nothing to save!!!

	if ( CurrentBatch.m_Modified && (m_FilesInBatch.GetCount()==0) )				//if its been modified && there are no files, say so!
	{
		MessageBox("No files to save!","ERROR !",MB_ICONINFORMATION | MB_OK);
		return;
	}	


	//there are files & theyve been modified!!
		
	CFile f;

	CFileDialog	fn(FALSE,NULL,NULL,OFN_HIDEREADONLY,Filters);

	r = fn.DoModal();

	//Do Nothing if Cancelled.
	if ( r == IDCANCEL)	
		return;

	CString c(fn.GetPathName());

	//Create a CFile Object & Attach a CArchive Object to it.

	try
	{
		f.Open(fn.GetPathName() , CFile::modeCreate | CFile::modeWrite );
	}
	catch (CFileException *e)
	{
	 	//error is in e->m_cause

		e->Delete();
		MessageBox("Couldn't Save Batch File","ERROR !",MB_ICONSTOP | MB_OK);
		return;
	}
	CArchive ar(&f,CArchive::store);

	CurrentBatch.Serialize(ar);

	ar.Close();
	f.Close();
	CurrentBatch.m_Modified = FALSE;

}

void CDcfwDlg::OnOpenbatch() 
{
	// TODO: Add your control notification handler code here
	int	r;
	CFile f;

	if (CurrentBatch.m_Modified)
	{
		//see if user wants to save current batch before proceeding...
		r = MessageBox("Your current batch list is unsaved\nDo you wish to continue?","Lose Changes",MB_ICONQUESTION | MB_YESNO);
		if ( r == IDNO)
			return;
	}

	CFileDialog	fn(TRUE,NULL,NULL,OFN_HIDEREADONLY,Filters);

	r = fn.DoModal();

	//Do Nothing if Cancelled.
	if ( r == IDCANCEL)	
		return;

	CString c(fn.GetPathName());

	//Create a CFile Object & Attach a CArchive Object to it.

	try
	{
		f.Open(fn.GetPathName() , CFile::modeRead );
	}
	catch (CFileException *e)
	{
	 	//error is in e->m_cause

		e->Delete();
		MessageBox("Couldn't Save Batch File","ERROR !",MB_ICONSTOP | MB_OK);
		return;
	}

	CArchive ar(&f,CArchive::load);
		
	CurrentBatch.SetDefaultState();			//remove all old settings & Files
	CurrentBatch.Serialize(ar);				//Read in new ones...

	ar.Close();
	f.Close();
	
	//Delete All the Old Strings from the list box
	for (r=m_FilesInBatch.GetCount();r>=0;r--)
		m_FilesInBatch.DeleteString(0);
	
	//insert the loaded strings into the List box...

	for (r=0;r<CurrentBatch.Files.GetSize();r++)
	{
		char f[_MAX_FNAME],e[_MAX_EXT],name[_MAX_FNAME+_MAX_EXT];
		_splitpath(CurrentBatch.Files[r],NULL,NULL,f,e);
		strcpy(name,f);
		strcat(name,e);
		m_FilesInBatch.AddString(name);
		
	}

	CurrentBatch.m_Modified = FALSE;
}

void CDcfwDlg::OnOK() 
{
	if (CurrentBatch.m_Modified)
	{
		//see if user wants to save current batch before proceeding...
		int	r;
		r = MessageBox("Your current batch list is unsaved\nDo you wish to Save it Now?","Lose Changes",MB_ICONQUESTION | MB_YESNO);
		if ( r == IDYES)
			OnSavebatch();
	}
		
	CDialog::OnOK();
}

void CDcfwDlg::OnRemoveall() 
{
	// TODO: Add your control notification handler code here
	int	r;
	
	if (CurrentBatch.m_Modified)
	{
		//see if user wants to save current batch before proceeding...
		r = MessageBox("Your current batch list is unsaved\nDo you wish to Save it now?","Remove All",MB_ICONQUESTION | MB_YESNO);
		if ( r == IDYES)
			OnSavebatch();
	}
	//reset the state of the Current Batch Object
	CurrentBatch.SetDefaultState();
	//Delete All the Old Strings from the list box
	for (r=m_FilesInBatch.GetCount();r>=0;r--)
		m_FilesInBatch.DeleteString(0);

	//After removing all the batch is unmodified!!!
	CurrentBatch.m_Modified = FALSE;

	
}

void CDcfwDlg::OnRemovemissing() 
{
	// TODO: Add your control notification handler code here
	struct	_finddata_t	f;
	int	r;
	int		RemovedSome=0;
	char	buff[_MAX_PATH];
	
	//remove from our list box & our current batch file list  all the files that no longer exist...

	if (CurrentBatch.Files.GetSize() == 0 )
		return;

	for (r=0;r<CurrentBatch.Files.GetSize();r++)
	{
		strcpy(buff,CurrentBatch.Files[r]);
		if (_findfirst(buff,&f)== -1 )
		{
		m_FilesInBatch.DeleteString(r);
		CurrentBatch.Files.RemoveAt(r);
		r--;								//one less to remove...
		RemovedSome++;
		}
	}

	if (RemovedSome)
	{
		sprintf(buff,"%d file(s) no longer exist.",RemovedSome);
		MessageBox(buff,"Missing Items",MB_ICONINFORMATION | MB_OK);
	}
	else
	{
		sprintf(buff,"All %d files exist! ",CurrentBatch.Files.GetSize());
		MessageBox(buff,"No Missing Files",MB_ICONINFORMATION | MB_OK);
	}
	CurrentBatch.m_Modified = TRUE;
}

void CDcfwDlg::OnDeletebatch() 
{
	// TODO: Add your control notification handler code here
	int	r;
	CFileDialog	fn(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,Filters);

	r = fn.DoModal();

	//Do Nothing if Cancelled.
	if ( r == IDCANCEL)	
		return;

	r = remove(fn.GetPathName());

	
	if ( r != 0 )
	{
	CString	c;
	c.Format("Unable to remove %s",fn.GetPathName());
	MessageBox(c,"Remove Error",MB_ICONSTOP|MB_OK);
	}
	
}

void CDcfwDlg::OnImporttextfile() 
{
	int	r,FilesAdded=0;
	char	buff[256],fullpath[256],d[_MAX_DRIVE],p[_MAX_PATH],f[_MAX_FNAME],e[_MAX_EXT],name[_MAX_FNAME+_MAX_EXT];
	struct	_finddata_t	ff;

	CFileDialog	fn(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,Filters);
	r = fn.DoModal();
	if (r==IDCANCEL)
		return;

	FILE	*i;
	if ((i = fopen(fn.GetPathName(),"r"))==NULL)
	{
	CString	c;
	c.Format("Unable to open %s",fn.GetPathName());
	MessageBox(c,"Import Error",MB_ICONSTOP|MB_OK);
	return;
	}


	fgets(buff,256,i);			//read a line
	while(!feof(i))
	{
		strtok(buff,"\n\t ");		//kill to EOL
		if (isspace(buff[0]) || (buff[0]==0))
			continue;

		if (_findfirst(buff,&ff)== -1 )
		{
			CString	c;
			c.Format("File %s does not exist",buff);
			MessageBox(c,"Import Error",MB_ICONINFORMATION|MB_OK);
		}
		else
		{
			//The file Exists , but is it a normal file???? (exclude dirs etc..)
			//the files atributes can only be _A_NORMAL or _A_ARCH
			if (ff.attrib & (_A_SYSTEM|_A_SUBDIR|_A_RDONLY|_A_HIDDEN) )
			{
				fgets(buff,256,i);			//read a line
				continue;
			}

			_splitpath(buff,d,p,f,e);					//get component parts
			if (d[0]==0)								//the the file has a relative path, so we must create the full path
				_fullpath(fullpath,buff,256);
			else
				strcpy(fullpath,buff);					//its already 

			CurrentBatch.Files.Add(fullpath);			//add the ABSOLUTE path 

			strcpy(name,f);
			strcat(name,e);
			m_FilesInBatch.AddString(name);
			FilesAdded++;
		}
	fgets(buff,256,i);			//read a line
	}
	fclose(i);

	CString	c;
	c.Format("%d Files Added",FilesAdded);
	MessageBox(c,"Import Successful",MB_ICONINFORMATION|MB_OK);

	CurrentBatch.m_Modified = TRUE;
}

void CDcfwDlg::OnRemovefiles() 
{
	// TODO: Add your control notification handler code here
	int	i;
	int	numsel = m_FilesInBatch.GetSelCount();

	//if there's nothing selected then  exit!
	if (!numsel)
		return;

	LPINT	ItemsToDelete = new int[numsel];

	m_FilesInBatch.GetSelItems(numsel,ItemsToDelete);

	for (i=numsel;i!=0;i--)
	{
		m_FilesInBatch.DeleteString(ItemsToDelete[i-1]);
		CurrentBatch.Files.RemoveAt(ItemsToDelete[i-1]);
	}

	delete[] ItemsToDelete;
	CurrentBatch.m_Modified = TRUE;

}

typedef unsigned long uint32;
typedef long int32;

struct CCB
	{
	uint32 ccb_Flags;

	struct CCB *ccb_NextPtr;
	void    *ccb_SourcePtr;
	void       *ccb_PLUTPtr;

	int32 ccb_XPos;
	int32 ccb_YPos;
	int32  ccb_HDX;
	int32  ccb_HDY;
	int32  ccb_VDX;
	int32  ccb_VDY;
	int32  ccb_HDDX;
	int32  ccb_HDDY;
	uint32 ccb_PIXC;
	uint32 ccb_PRE0;
	uint32 ccb_PRE1;

	/* These are special fields, tacked on to support some of the
	 * rendering functions.
	 */
	int32  ccb_Width;
	int32  ccb_Height;
};


void CDcfwDlg::OnCheckcels() 
{
	int	i,numsel = CurrentBatch.Files.GetSize();

	//if there's nothing in the batch window then  exit!
	if (!numsel)
		return;

	for (i=0 ; i < numsel;i++)
	{
		CheckCel(CurrentBatch.Files[i]);
	}
}

int CDcfwDlg::CheckCel(CString name)
{
 	FILE	*in;
	CCB		theCCB;
	int	r;
	unsigned int test;

	CString	m;

	if (( in = fopen (name,"rb")) == NULL )
		return FALSE;

	fseek(in,3*4,SEEK_SET);
	r = fread(&theCCB,1,sizeof(CCB),in);

	fclose(in);

	if ( r != sizeof(CCB))
	{
		m.Format("Couldn't Load the CCB header for\n%s",name);
		MessageBox(m,"CCB Error",MB_ICONSTOP|MB_OK);
		return FALSE;
	}
	test = SwapLong(theCCB.ccb_Width);
	if (test >320)
	{
		m.Format("Error in Cel %s,\nCCB's Width  = %d",name,test);
		MessageBox(m,"CCB Error",MB_ICONSTOP|MB_OK);
		return FALSE;
	}

	test = SwapLong(theCCB.ccb_Height);
	if (test >320)
	{
		m.Format("Error in Cel %s,\nCCB's height  = %d",name,test);
		MessageBox(m,"CCB Error",MB_ICONSTOP|MB_OK);
		return FALSE;
	}

	return TRUE;

}

void CDcfwDlg::OnBuildlibrary() 
{
	// TODO: Add your control notification handler code here

	CBuildLibraryDialog d;
	int		r;


	r = d.DoModal();
	
}
