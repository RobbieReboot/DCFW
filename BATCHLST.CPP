#include "stdafx.h"
#include "batchlst.h"

IMPLEMENT_SERIAL( CBatch , CObject , 1 )


CBatch::CBatch(void)
{
 	m_Modified = m_Loaded = FALSE;
	SetDefaultState();
}

void CBatch::SetDefaultState(void)
{

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
	m_Radix = 16;
	m_nStart = 0;
	m_ByteOrder =0;
	Files.RemoveAll();
	
}

void CBatch::Serialize(CArchive& ar)
{
	int	i;

	DWORD	c=m_ItemsPerLine;
	DWORD	numfiles;
	if (ar.IsStoring())
	{
	numfiles = Files.GetSize();

	ar <<m_LabelPrefix 
		<<m_LabelSuffix 
		<<m_nFormat
		<<m_OutputAs
		<<m_ItemsPerLine
		<<m_ItemSize
		<<m_IncOrDec
		<<m_LabelMethod
		<<m_TextConvertMode
		<<m_SaveAsStrings
		<<m_Radix
		<<m_nStart
		<<numfiles									//local, to keep number of files in this Carchive
		<<m_ByteOrder
		<<m_Description;	

		for(i=0;i<(int)numfiles;i++)
		{
			ar << Files[i];
		}
	}
	else
	{
	CString	fname;
	ar >>m_LabelPrefix 
		>>m_LabelSuffix 
		>>m_nFormat
		>>m_OutputAs
		>>m_ItemsPerLine
		>>m_ItemSize
		>>m_IncOrDec
		>>m_LabelMethod
		>>m_TextConvertMode
		>>m_SaveAsStrings
		>>m_Radix
		>>m_nStart
		>>numfiles
		>>m_ByteOrder
		>>m_Description;	

		for(i=0;i<(int)numfiles;i++)
		{
			ar	>> fname;
			Files.Add(fname);
		}
	}
	return;
}


