#include "stdafx.h"
#include "dcfw.h"
#include "dcfwdlg.h"
#include "formatco.h"
#include "tcprogre.h"
#include <string.h>
#include <afxtempl.h>
#include <io.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

static char *SourceTypes[]=
{
	"IBM PC Text",
	"CBM Amiga Text",
	"Apple Mac Text"
};



void CFormatConvertion::ProcessTextFile(CString fname,int DestType)
{
	
	int	SourceType;
	CFile	file;

	try
	{
		file.Open(fname,CFile::modeReadWrite);
	}
	catch(CFileException * e)
	{
		e->Delete();
		CString m;
		m.Format("Couldn't Open %s",fname);	
		MessageBox(m,"     File Open Error     ",MB_ICONSTOP|MB_OK);
		return;
	}

//	printf("Processing : %s",file.name);

	SourceType = ScanFile(file);

	if (SourceType == DestType)
		{
		//Already Dest Type..
		return;
		}

	if (SourceType == TC_BINARY)
		{
		//Binary File....Suspected
		return;
		}

	if (SourceType == TC_ERROR)
 		return;

	m_TCProgressDlg->GetDlgItem(IDC_TCSOURCETYPE)->SetWindowText(SourceTypes[SourceType]);
	
	Convert(SourceType,DestType,file);

	file.Close();
}


int CFormatConvertion::ScanFile(CFile& file)
{
	long	i,fs;
	BYTE	*buffer,*b;
	BOOL	ok;

	b=buffer=new unsigned char[1024];					//1024 should hold 2 lines!

	fs = file.Read(buffer,1024);
	file.SeekToBegin();

	//ignore LEGAL control codes other that cr/lf

	ok = TRUE;

	for (i = 0; (i<1024) && (i < fs) && (ok == TRUE) ; i++)
		{
		if ( *buffer < 32)
			if ( ( *buffer != 0x09) && ( *buffer != 0x1a) )
				{
				ok = FALSE;
				break;
				}
		buffer++;
		}

	//if i == 1024 then we scanned the first 1024 bytes without being able to determine what type of file it was!
	if (i==1024) 
		return TC_ERROR;

	if (*buffer == 0x0a )					//LF only is amiga
		{
		delete[] b;
		return TC_AMIGA;
		}

	if (*buffer == 0x0d )
		if (*(buffer+1) == 0x0a) 				//if 0x0d0a then its pc!
			{
			delete[] b;;					//CRLF is pc
			return TC_PC;
			}
		else
			{
			delete[] b;						//CR without LF is MAC
			return TC_MAC;
			}
	
	return TC_BINARY;							//if none of the above , its BINARY
}

void CFormatConvertion::Convert(int SrcType,int DstType,CFile& file)
{
	long	i,fs;
	BYTE	*buffer,*b;
	CString	buff;
	char	LF=0x0a;
	char	CR=0x0d;
	char	CRLF[2]={0x0d,0x0a};

	fs = file.GetLength();

	b=buffer=new BYTE[fs];

	file.Read(buffer,fs);
	file.SeekToBegin();
	
	for (i=0;i<fs;i++)
		{
		if ( (i & 1023) == 0 )
		{
			buff.Format("%d Bytes Converted.",i);
			m_TCProgressDlg->GetDlgItem(IDC_TCSTATUS)->SetWindowText(buff);
		}
		switch (SrcType)
			{
			case	TC_MAC:								//from just 0x0d
					if (*buffer == 0x0d)
						switch (DstType)
							{
							case	TC_PC:
								file.Write(CRLF,2);	//change to CR/LF
								break;
							case	TC_AMIGA:
								file.Write(&LF,1);	//change to LF only
								break;
							}
					else
						file.Write(buffer,1);
					break;

			case	TC_PC:						//FROM PC
					if (*buffer == 0x0d)			//from 0d0a to
						switch (DstType)
							{
							case	TC_MAC:
								file.Write(&CR,1);	//change to CR
								buffer++;
								fs--;
								break;

							case	TC_AMIGA:
								file.Write(&LF,1);	//change to LF only
								fs--;
								buffer++;
								break;
							}
					else
						file.Write(buffer,1);
					break;

			case	TC_AMIGA:							//FROM PC
					if (*buffer == 0x0a)			//from 0d0a to
						switch (DstType)
							{
							case	TC_MAC:
								file.Write(&CR,1);	//change to CR
								break;

							case	TC_PC:
								file.Write(CRLF,2);//change to CRLF
								break;
							}
					else
						file.Write(buffer,1);
					break;
			}
		buffer++;
		}
	delete[] b;
}



